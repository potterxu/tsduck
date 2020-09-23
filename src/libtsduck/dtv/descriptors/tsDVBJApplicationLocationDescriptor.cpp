//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2020, Thierry Lelegard
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

#include "tsDVBJApplicationLocationDescriptor.h"
#include "tsDescriptor.h"
#include "tsTablesDisplay.h"
#include "tsPSIRepository.h"
#include "tsPSIBuffer.h"
#include "tsDuckContext.h"
#include "tsxmlElement.h"
TSDUCK_SOURCE;

#define MY_XML_NAME u"dvb_j_application_location_descriptor"
#define MY_CLASS ts::DVBJApplicationLocationDescriptor
#define MY_DID ts::DID_AIT_DVBJ_APP_LOC
#define MY_TID ts::TID_AIT
#define MY_STD ts::Standards::DVB

TS_REGISTER_DESCRIPTOR(MY_CLASS, ts::EDID::TableSpecific(MY_DID, MY_TID), MY_XML_NAME, MY_CLASS::DisplayDescriptor);


//----------------------------------------------------------------------------
// Constructors
//----------------------------------------------------------------------------

ts::DVBJApplicationLocationDescriptor::DVBJApplicationLocationDescriptor() :
    AbstractDescriptor(MY_DID, MY_XML_NAME, MY_STD, 0),
    base_directory(),
    classpath_extension(),
    initial_class()
{
}

ts::DVBJApplicationLocationDescriptor::DVBJApplicationLocationDescriptor(DuckContext& duck, const Descriptor& desc) :
    DVBJApplicationLocationDescriptor()
{
    deserialize(duck, desc);
}

void ts::DVBJApplicationLocationDescriptor::clearContent()
{
    base_directory.clear();
    classpath_extension.clear();
    initial_class.clear();
}


//----------------------------------------------------------------------------
// Serialization
//----------------------------------------------------------------------------

void ts::DVBJApplicationLocationDescriptor::serializePayload(PSIBuffer& buf) const
{
    buf.putStringWithByteLength(base_directory);
    buf.putStringWithByteLength(classpath_extension);
    buf.putString(initial_class);
}

void ts::DVBJApplicationLocationDescriptor::deserializePayload(PSIBuffer& buf)
{
    buf.getStringWithByteLength(base_directory);
    buf.getStringWithByteLength(classpath_extension);
    buf.getString(initial_class);
}


//----------------------------------------------------------------------------
// Static method to display a descriptor.
//----------------------------------------------------------------------------

void ts::DVBJApplicationLocationDescriptor::DisplayDescriptor(TablesDisplay& disp, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    const UString margin(indent, ' ');

    if (size >= 1) {
        size_t len = std::min<size_t>(data[0], size - 1);
        disp << margin << "Base directory: \"" << disp.duck().decoded(data + 1, len) << "\"" << std::endl;
        data += 1 + len; size -= 1 + len;
        if (size >= 1) {
            len = std::min<size_t>(data[0], size - 1);
            disp << margin << "Classpath ext: \"" << disp.duck().decoded(data + 1, len) << "\"" << std::endl
                 << margin << "Initial class: \"" << disp.duck().decoded(data + 1 + len, size - len - 1) << "\"" << std::endl;
            size = 0;
        }
    }

    disp.displayExtraData(data, size, margin);
}


//----------------------------------------------------------------------------
// XML serialization
//----------------------------------------------------------------------------

void ts::DVBJApplicationLocationDescriptor::buildXML(DuckContext& duck, xml::Element* root) const
{
    root->setAttribute(u"base_directory", base_directory);
    root->setAttribute(u"classpath_extension", classpath_extension);
    root->setAttribute(u"initial_class", initial_class);
}

bool ts::DVBJApplicationLocationDescriptor::analyzeXML(DuckContext& duck, const xml::Element* element)
{
    return element->getAttribute(base_directory, u"base_directory", true) &&
           element->getAttribute(classpath_extension, u"classpath_extension", true) &&
           element->getAttribute(initial_class, u"initial_class", true);
}
