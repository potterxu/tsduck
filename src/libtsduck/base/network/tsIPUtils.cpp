//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2021, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------

#include "tsIPUtils.h"
#include "tsIPv4Address.h"
#if defined(TS_MAC)
#include <ifaddrs.h>
#endif
TSDUCK_SOURCE;


//----------------------------------------------------------------------------
// Initialize IP usage. Shall be called once at least.
//----------------------------------------------------------------------------

bool ts::IPInitialize(Report& report)
{
#if defined(TS_WINDOWS)
    // Execute only once (except - harmless - race conditions during startup).
    static volatile bool done = false;
    if (!done) {
        // Request version 2.2 of Winsock
        ::WSADATA data;
        int err = ::WSAStartup(MAKEWORD(2, 2), &data);
        if (err != 0) {
            report.error(u"WSAStartup failed, WinSock error %X", {err});
            return false;
        }
        done = true;
    }
#endif

    return true;
}


//----------------------------------------------------------------------------
// Check if a local system interface has a specified IP address.
//----------------------------------------------------------------------------

bool ts::IsLocalIPAddress(const IPv4Address& address)
{
    IPv4AddressVector locals;
    return address == IPv4Address::LocalHost || (GetLocalIPAddresses(locals) && std::find(locals.begin(), locals.end(), address) != locals.end());
}


//----------------------------------------------------------------------------
// This method returns the list of all local IPv4 addresses in the system
// with their network mask.
//----------------------------------------------------------------------------

bool ts::GetLocalIPAddresses(IPv4AddressMaskVector& list, Report& report)
{
    bool status = true;
    list.clear();

#if defined(TS_MAC)

    // Get the list of local addresses. The memory is allocated by getifaddrs().
    ::ifaddrs* start = nullptr;
    if (::getifaddrs(&start) != 0) {
        report.error(u"error getting local addresses: %s", {SysErrorCodeMessage()});
        return false;
    }

    // Browse the list of interfaces.
    for (::ifaddrs* ifa = start; ifa != nullptr; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr != nullptr) {
            IPv4Address addr(*ifa->ifa_addr);
            if (addr.hasAddress() && addr != IPv4Address::LocalHost) {
                list.push_back(IPv4AddressMask(addr, IPv4Address(*ifa->ifa_netmask)));
            }
        }
    }

    // Free the system-allocated memory.
    ::freeifaddrs(start);

#elif defined(TS_WINDOWS) || defined(TS_UNIX)

    // Create a socket to query the system on
    SysSocketType sock = ::socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == SYS_SOCKET_INVALID) {
        report.error(u"error creating socket: %s", {SysSocketErrorCodeMessage()});
        return false;
    }

#if defined(TS_WINDOWS)

    // Windows implementation

    ::INTERFACE_INFO info[32];  // max 32 local interface (arbitrary)
    ::DWORD retsize;
    if (::WSAIoctl(sock, SIO_GET_INTERFACE_LIST, 0, 0, info, ::DWORD(sizeof(info)), &retsize, 0, 0) != 0) {
        report.error(u"error getting local addresses: %s", {SysSocketErrorCodeMessage()});
        status = false;
    }
    else {
        retsize = std::max<::DWORD>(0, std::min(retsize, ::DWORD(sizeof(info))));
        size_t count = retsize / sizeof(::INTERFACE_INFO);
        for (size_t i = 0; i < count; ++i) {
            IPv4Address addr(info[i].iiAddress.Address);
            if (addr.hasAddress() && addr != IPv4Address::LocalHost) {
                list.push_back(IPv4AddressMask(addr, IPv4Address(info[i].iiNetmask.Address)));
            }
        }
    }

#else

    // UNIX implementation (may not work on all UNIX, works on Linux)

    ::ifconf ifc;
    ::ifreq info[32];  // max 32 local interface (arbitrary)

    ifc.ifc_req = info;
    ifc.ifc_len = sizeof(info);

    if (::ioctl(sock, SIOCGIFCONF, &ifc) != 0) {
        report.error(u"error getting local addresses: %s", {SysSocketErrorCodeMessage()});
        status = false;
    }
    else {
        ifc.ifc_len = std::max(0, std::min(ifc.ifc_len, int(sizeof(info))));
        size_t count = ifc.ifc_len / sizeof(::ifreq);
        for (size_t i = 0; i < count; ++i) {
            IPv4Address addr(info[i].ifr_addr);
            IPv4Address mask;
            if (addr.hasAddress() && addr != IPv4Address::LocalHost) {
                // Get network mask for this interface.
                ::ifreq req;
                req = info[i];
                if (::ioctl(sock, SIOCGIFNETMASK, &req) != 0) {
                    const SysSocketErrorCode err = LastSysSocketErrorCode();
                    report.error(u"error getting network mask for %s: %s", {addr, SysSocketErrorCodeMessage(err)});
                }
                else {
                    mask = IPv4Address(req.ifr_netmask);
                }
                list.push_back(IPv4AddressMask(addr, mask));
            }
        }
    }

#endif

    // Close socket
    SysCloseSocket(sock);

#else

    report.error(u"getting local addresses is not implemented");
    status = false;

#endif

    return status;
}


//----------------------------------------------------------------------------
// This method returns the list of all local IPv4 addresses in the system
//----------------------------------------------------------------------------

bool ts::GetLocalIPAddresses(IPv4AddressVector& list, Report& report)
{
    IPv4AddressMaskVector full_list;
    list.clear();

    if (GetLocalIPAddresses(full_list, report)) {
        list.resize(full_list.size());
        for (size_t i = 0; i < full_list.size(); ++i) {
            list[i] = full_list[i].address;
        }
        return true;
    }
    else {
        return false;
    }
}


//----------------------------------------------------------------------------
// Get the size in bytes of an IPv4 header.
//----------------------------------------------------------------------------

size_t ts::IPHeaderSize(const void* data, size_t size)
{
    const uint8_t* ip = reinterpret_cast<const uint8_t*>(data);
    size_t headerSize = 0;

    // The first byte of the header contains the IP version and the number
    // of 32-bit words in the header.
    if (ip != nullptr && size >= IPv4_MIN_HEADER_SIZE && ((ip[0] >> 4) & 0x0F) == IPv4_VERSION) {
        headerSize = sizeof(uint32_t) * size_t(ip[0] & 0x0F);
    }

    return headerSize <= size ? headerSize : 0;
}


//----------------------------------------------------------------------------
// Compute the checksum of an IPv4 header.
//----------------------------------------------------------------------------

uint16_t ts::IPHeaderChecksum(const void* data, size_t size)
{
    const size_t hSize = IPHeaderSize(data, size);
    const uint8_t* ip = reinterpret_cast<const uint8_t*>(data);
    uint32_t checksum = 0;

    // Add all 16-bit words in the header (except checksum).
    for (size_t i = 0; i < hSize; i += 2) {
        if (i != IPv4_CHECKSUM_OFFSET) {
            checksum += GetUInt16(ip + i);
        }
    }

    // Add carries until they are all gone.
    while (checksum > 0xFFFF) {
        checksum = (checksum & 0xFFFF) + (checksum >> 16);
    }

    // Take the complement.
    return hSize == 0 ? 0 : uint16_t(checksum ^ 0xFFFF);
}


//----------------------------------------------------------------------------
// Verify or update the checksum of an IPv4 header.
//----------------------------------------------------------------------------

bool ts::VerifyIPHeaderChecksum(const void* data, size_t size)
{
    const bool ok = IPHeaderSize(data, size) > 0;
    const uint8_t* ip = reinterpret_cast<const uint8_t*>(data);
    return ok && GetUInt16(ip + IPv4_CHECKSUM_OFFSET) == IPHeaderChecksum(data, size);
}

bool ts::UpdateIPHeaderChecksum(void* data, size_t size)
{
    const bool ok = IPHeaderSize(data, size) > 0;
    if (ok) {
        uint8_t* ip = reinterpret_cast<uint8_t*>(data);
        PutUInt16(ip + IPv4_CHECKSUM_OFFSET, IPHeaderChecksum(data, size));
    }
    return ok;
}


//----------------------------------------------------------------------------
// Validate and analyze an IPv4 packet.
//----------------------------------------------------------------------------

bool ts::AnalyzeIPPacket(const void* data,
                         size_t ip_size,
                         uint8_t& proto,
                         size_t& ip_header_size,
                         size_t& proto_header_size,
                         IPv4SocketAddress& source,
                         IPv4SocketAddress& destination)
{
    const uint8_t* ip = reinterpret_cast<const uint8_t*>(data);

    // For invalid IP packets.
    proto = 0;
    proto_header_size = 0;
    source.clear();
    destination.clear();

    // Check that this looks like an IPv4 packet.
    if ((ip_header_size = IPHeaderSize(ip, ip_size)) == 0 ||
        GetUInt16(ip + IPv4_CHECKSUM_OFFSET) != IPHeaderChecksum(ip, ip_header_size))
    {
        return false; // not a valid IP packet.
    }

    // Get IP addresses and protocal from IP header.
    proto = ip[IPv4_PROTOCOL_OFFSET];
    source.setAddress(GetUInt32(ip + IPv4_SRC_ADDR_OFFSET));
    destination.setAddress(GetUInt32(ip + IPv4_DEST_ADDR_OFFSET));

    // Validate and filter by protocol.
    switch (proto) {
        case IPv4_PROTO_TCP: {
            const size_t hsize = 4 * size_t(ip[ip_header_size + TCP_HEADER_LENGTH_OFFSET]);
            if (ip_size < ip_header_size + hsize || hsize < TCP_MIN_HEADER_SIZE) {
                return false; // packet too short
            }
            source.setPort(GetUInt16(ip + ip_header_size + TCP_SRC_PORT_OFFSET));
            destination.setPort(GetUInt16(ip + ip_header_size + TCP_DEST_PORT_OFFSET));
            proto_header_size = hsize;
            break;
        }
        case IPv4_PROTO_UDP: {
            if (ip_size < ip_header_size + UDP_HEADER_SIZE) {
                return false; // packet too short
            }
            const size_t udp_length = GetUInt16BE(ip + ip_header_size + UDP_LENGTH_OFFSET);
            if (ip_size < ip_header_size + udp_length ) {
                return false; // packet too short
            }
            source.setPort(GetUInt16(ip + ip_header_size + UDP_SRC_PORT_OFFSET));
            destination.setPort(GetUInt16(ip + ip_header_size + UDP_DEST_PORT_OFFSET));
            proto_header_size = UDP_HEADER_SIZE;
            break;
        }
        default:
            proto_header_size = 0;
            break;
    }

    // Packet is valid.
    return true;
}
