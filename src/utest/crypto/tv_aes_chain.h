// AES with chaining modes test vectors

struct TV_AES_CHAIN {
    size_t  key_size;
    uint8_t key[32];
    size_t  iv_size;
    uint8_t iv[16];
    size_t  plain_size;
    uint8_t plain[256];
    size_t  cipher_size;
    uint8_t cipher[256];
};

static const TV_AES_CHAIN tv_ecb_aes [] = {
    {
        16,
        {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F},
        0,
        {},
        16,
        {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF},
        16,
        {0x69, 0xC4, 0xE0, 0xD8, 0x6A, 0x7B, 0x04, 0x30, 0xD8, 0xCD, 0xB7, 0x80, 0x70, 0xB4, 0xC5, 0x5A},
    },
    {
        16,
        {0xA0, 0x3B, 0x8E, 0xC0, 0x7B, 0x60, 0x9C, 0x66, 0x09, 0xC7, 0x9C, 0x09, 0x49, 0x41, 0xCE, 0x28},
        0,
        {},
        16,
        {0x15, 0xB2, 0xAB, 0x88, 0xC9, 0x28, 0x7D, 0xAF, 0xA8, 0xC0, 0x74, 0x36, 0x8D, 0x84, 0x52, 0xE7},
        16,
        {0xE5, 0x3E, 0x04, 0x7F, 0x8B, 0xF9, 0xF2, 0x21, 0xF3, 0xD5, 0x2E, 0x2E, 0x2B, 0x1D, 0xC9, 0x25},
    },
    {
        16,
        {0xA0, 0x3B, 0x8E, 0xC0, 0x7B, 0x60, 0x9C, 0x66, 0x09, 0xC7, 0x9C, 0x09, 0x49, 0x41, 0xCE, 0x28},
        0,
        {},
        32,
        {0x15, 0xB2, 0xAB, 0x88, 0xC9, 0x28, 0x7D, 0xAF, 0xA8, 0xC0, 0x74, 0x36, 0x8D, 0x84, 0x52, 0xE7,
         0x15, 0xB2, 0xAB, 0x88, 0xC9, 0x28, 0x7D, 0xAF, 0xA8, 0xC0, 0x74, 0x36, 0x8D, 0x84, 0x52, 0xE7},
        32,
        {0xE5, 0x3E, 0x04, 0x7F, 0x8B, 0xF9, 0xF2, 0x21, 0xF3, 0xD5, 0x2E, 0x2E, 0x2B, 0x1D, 0xC9, 0x25,
         0xE5, 0x3E, 0x04, 0x7F, 0x8B, 0xF9, 0xF2, 0x21, 0xF3, 0xD5, 0x2E, 0x2E, 0x2B, 0x1D, 0xC9, 0x25},
    },
};

static const TV_AES_CHAIN tv_cbc_aes [] = {
    {
        16,
        {0x59, 0xD0, 0x24, 0xE3, 0x2A, 0x1A, 0x5F, 0xBA, 0xF1, 0xED, 0x6A, 0x94, 0xB1, 0x14, 0xE0, 0x73},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        16,
        {0x79, 0x97, 0x4F, 0x54, 0xF3, 0x3F, 0x46, 0x39, 0x3D, 0x30, 0x64, 0x62, 0x8F, 0xD5, 0x67, 0x0F},
        16,
        {0xA5, 0x12, 0x8E, 0xE5, 0x7F, 0x88, 0xF4, 0xA6, 0x00, 0x6B, 0xE8, 0x6E, 0xFC, 0x57, 0x03, 0x00},
    },
    {
        16,
        {0xA8, 0xB4, 0x78, 0x37, 0xD4, 0xF6, 0x16, 0x10, 0x7D, 0xC0, 0xB8, 0x41, 0x42, 0x83, 0xB0, 0xDC},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        32,
        {0x50, 0x19, 0xE0, 0x69, 0xBA, 0x92, 0x63, 0xAB, 0x02, 0x8E, 0x51, 0xFC, 0x1E, 0x60, 0x40, 0x02,
         0xA2, 0x41, 0x66, 0x60, 0x84, 0x5D, 0x9E, 0x29, 0x6E, 0x53, 0xEF, 0x9B, 0x4C, 0x61, 0x1B, 0x0C},
        32,
        {0x76, 0x3F, 0x97, 0x8C, 0x9D, 0x0C, 0x81, 0xA4, 0x00, 0xFC, 0x25, 0x00, 0xA1, 0xED, 0x40, 0x3C,
         0x65, 0x02, 0xB2, 0x92, 0x9E, 0x59, 0xC0, 0xCE, 0x6A, 0xCB, 0x7C, 0x49, 0x28, 0x54, 0x26, 0xB6},
    },
    {
        16,
        {0x2A, 0x98, 0xF5, 0xF7, 0x79, 0x99, 0x15, 0x24, 0x0B, 0xBA, 0xAA, 0x42, 0x2A, 0x6B, 0x4C, 0x8E},
        16,
        {0x4A, 0x28, 0x80, 0xC6, 0x44, 0x97, 0x9C, 0x8F, 0xD2, 0xBB, 0xF8, 0xD0, 0xCA, 0xB2, 0x10, 0x5F},
        32,
        {0xB7, 0x3D, 0x23, 0xC6, 0x3B, 0x13, 0xE4, 0x3A, 0x31, 0x15, 0x13, 0x42, 0x75, 0xB7, 0xAC, 0xB8,
         0x18, 0xE0, 0x90, 0xFA, 0x57, 0x62, 0xA3, 0xF6, 0xE7, 0x09, 0x6B, 0xAB, 0x20, 0x97, 0x71, 0xA2},
        32,
        {0xD5, 0xED, 0xF0, 0xE1, 0xBA, 0x3E, 0x2D, 0x33, 0xDB, 0xF0, 0xDA, 0xC0, 0xA7, 0x34, 0x72, 0xD6,
         0x69, 0x4F, 0x62, 0x35, 0xC9, 0xBA, 0xE9, 0xB4, 0x82, 0x22, 0x17, 0xF5, 0xE3, 0xA8, 0x8B, 0xEC},
    },
};

static const TV_AES_CHAIN tv_cts_aes [] = {
    // The following test vectors are extracted from RFC 3962
    {
        16,
        {0x63, 0x68, 0x69, 0x63, 0x6B, 0x65, 0x6E, 0x20, 0x74, 0x65, 0x72, 0x69, 0x79, 0x61, 0x6B, 0x69},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        17,
        {0x49, 0x20, 0x77, 0x6F, 0x75, 0x6C, 0x64, 0x20, 0x6C, 0x69, 0x6B, 0x65, 0x20, 0x74, 0x68, 0x65,
         0x20},
        17,
        {0xC6, 0x35, 0x35, 0x68, 0xF2, 0xBF, 0x8C, 0xB4, 0xD8, 0xA5, 0x80, 0x36, 0x2D, 0xA7, 0xFF, 0x7F,
         0x97},
    },
    {
        16,
        {0x63, 0x68, 0x69, 0x63, 0x6B, 0x65, 0x6E, 0x20, 0x74, 0x65, 0x72, 0x69, 0x79, 0x61, 0x6B, 0x69},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        31,
        {0x49, 0x20, 0x77, 0x6F, 0x75, 0x6C, 0x64, 0x20, 0x6C, 0x69, 0x6B, 0x65, 0x20, 0x74, 0x68, 0x65,
         0x20, 0x47, 0x65, 0x6E, 0x65, 0x72, 0x61, 0x6C, 0x20, 0x47, 0x61, 0x75, 0x27, 0x73, 0x20},
        31,
        {0xFC, 0x00, 0x78, 0x3E, 0x0E, 0xFD, 0xB2, 0xC1, 0xD4, 0x45, 0xD4, 0xC8, 0xEF, 0xF7, 0xED, 0x22,
         0x97, 0x68, 0x72, 0x68, 0xD6, 0xEC, 0xCC, 0xC0, 0xC0, 0x7B, 0x25, 0xE2, 0x5E, 0xCF, 0xE5},
    },
    {
        16,
        {0x63, 0x68, 0x69, 0x63, 0x6B, 0x65, 0x6E, 0x20, 0x74, 0x65, 0x72, 0x69, 0x79, 0x61, 0x6B, 0x69},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        32,
        {0x49, 0x20, 0x77, 0x6F, 0x75, 0x6C, 0x64, 0x20, 0x6C, 0x69, 0x6B, 0x65, 0x20, 0x74, 0x68, 0x65,
         0x20, 0x47, 0x65, 0x6E, 0x65, 0x72, 0x61, 0x6C, 0x20, 0x47, 0x61, 0x75, 0x27, 0x73, 0x20, 0x43},
        32,
        {0x39, 0x31, 0x25, 0x23, 0xA7, 0x86, 0x62, 0xD5, 0xBE, 0x7F, 0xCB, 0xCC, 0x98, 0xEB, 0xF5, 0xA8,
         0x97, 0x68, 0x72, 0x68, 0xD6, 0xEC, 0xCC, 0xC0, 0xC0, 0x7B, 0x25, 0xE2, 0x5E, 0xCF, 0xE5, 0x84},
    },
    {
        16,
        {0x63, 0x68, 0x69, 0x63, 0x6B, 0x65, 0x6E, 0x20, 0x74, 0x65, 0x72, 0x69, 0x79, 0x61, 0x6B, 0x69},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        47,
        {0x49, 0x20, 0x77, 0x6F, 0x75, 0x6C, 0x64, 0x20, 0x6C, 0x69, 0x6B, 0x65, 0x20, 0x74, 0x68, 0x65,
         0x20, 0x47, 0x65, 0x6E, 0x65, 0x72, 0x61, 0x6C, 0x20, 0x47, 0x61, 0x75, 0x27, 0x73, 0x20, 0x43,
         0x68, 0x69, 0x63, 0x6B, 0x65, 0x6E, 0x2C, 0x20, 0x70, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x2C},
        47,
        {0x97, 0x68, 0x72, 0x68, 0xD6, 0xEC, 0xCC, 0xC0, 0xC0, 0x7B, 0x25, 0xE2, 0x5E, 0xCF, 0xE5, 0x84,
         0xB3, 0xFF, 0xFD, 0x94, 0x0C, 0x16, 0xA1, 0x8C, 0x1B, 0x55, 0x49, 0xD2, 0xF8, 0x38, 0x02, 0x9E,
         0x39, 0x31, 0x25, 0x23, 0xA7, 0x86, 0x62, 0xD5, 0xBE, 0x7F, 0xCB, 0xCC, 0x98, 0xEB, 0xF5},
    },
    {
        16,
        {0x63, 0x68, 0x69, 0x63, 0x6B, 0x65, 0x6E, 0x20, 0x74, 0x65, 0x72, 0x69, 0x79, 0x61, 0x6B, 0x69},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        48,
        {0x49, 0x20, 0x77, 0x6F, 0x75, 0x6C, 0x64, 0x20, 0x6C, 0x69, 0x6B, 0x65, 0x20, 0x74, 0x68, 0x65,
         0x20, 0x47, 0x65, 0x6E, 0x65, 0x72, 0x61, 0x6C, 0x20, 0x47, 0x61, 0x75, 0x27, 0x73, 0x20, 0x43,
         0x68, 0x69, 0x63, 0x6B, 0x65, 0x6E, 0x2C, 0x20, 0x70, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x2C, 0x20},
        48,
        {0x97, 0x68, 0x72, 0x68, 0xD6, 0xEC, 0xCC, 0xC0, 0xC0, 0x7B, 0x25, 0xE2, 0x5E, 0xCF, 0xE5, 0x84,
         0x9D, 0xAD, 0x8B, 0xBB, 0x96, 0xC4, 0xCD, 0xC0, 0x3B, 0xC1, 0x03, 0xE1, 0xA1, 0x94, 0xBB, 0xD8,
         0x39, 0x31, 0x25, 0x23, 0xA7, 0x86, 0x62, 0xD5, 0xBE, 0x7F, 0xCB, 0xCC, 0x98, 0xEB, 0xF5, 0xA8},
    },
    {
        16,
        {0x63, 0x68, 0x69, 0x63, 0x6B, 0x65, 0x6E, 0x20, 0x74, 0x65, 0x72, 0x69, 0x79, 0x61, 0x6B, 0x69},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        64,
        {0x49, 0x20, 0x77, 0x6F, 0x75, 0x6C, 0x64, 0x20, 0x6C, 0x69, 0x6B, 0x65, 0x20, 0x74, 0x68, 0x65,
         0x20, 0x47, 0x65, 0x6E, 0x65, 0x72, 0x61, 0x6C, 0x20, 0x47, 0x61, 0x75, 0x27, 0x73, 0x20, 0x43,
         0x68, 0x69, 0x63, 0x6B, 0x65, 0x6E, 0x2C, 0x20, 0x70, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x2C, 0x20,
         0x61, 0x6E, 0x64, 0x20, 0x77, 0x6F, 0x6E, 0x74, 0x6F, 0x6E, 0x20, 0x73, 0x6F, 0x75, 0x70, 0x2E},
        64,
        {0x97, 0x68, 0x72, 0x68, 0xD6, 0xEC, 0xCC, 0xC0, 0xC0, 0x7B, 0x25, 0xE2, 0x5E, 0xCF, 0xE5, 0x84,
         0x39, 0x31, 0x25, 0x23, 0xA7, 0x86, 0x62, 0xD5, 0xBE, 0x7F, 0xCB, 0xCC, 0x98, 0xEB, 0xF5, 0xA8,
         0x48, 0x07, 0xEF, 0xE8, 0x36, 0xEE, 0x89, 0xA5, 0x26, 0x73, 0x0D, 0xBC, 0x2F, 0x7B, 0xC8, 0x40,
         0x9D, 0xAD, 0x8B, 0xBB, 0x96, 0xC4, 0xCD, 0xC0, 0x3B, 0xC1, 0x03, 0xE1, 0xA1, 0x94, 0xBB, 0xD8},
    },
    // The following test vectors were generated using Sun JRE.
    // First test vector commented out.
    // CTS shall not accept a message size equal to block size.
    // Sun JRE has generated the following test vector, but how ?
    // {
    //     16,
    //     {0xEC, 0xCB, 0xE6, 0xE5, 0xF4, 0x52, 0x81, 0x45, 0x94, 0x5B, 0x0D, 0x2E, 0x88, 0x02, 0x8E, 0x10},
    //     16,
    //     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    //     16,
    //     {0x55, 0x19, 0xDF, 0x11, 0xE4, 0x3C, 0x0B, 0x7D, 0xA9, 0x5C, 0xC8, 0x5A, 0xFC, 0xC6, 0x82, 0x4E},
    //     16,
    //     {0xB4, 0xEF, 0xB3, 0x97, 0xA2, 0x72, 0x53, 0x73, 0x43, 0x00, 0xE7, 0x41, 0xCD, 0xDF, 0x85, 0xA8},
    // },
    {
        16,
        {0x79, 0xAA, 0xBC, 0x4E, 0xDA, 0xA4, 0x2C, 0xBF, 0xCF, 0x59, 0x1A, 0x24, 0x56, 0x01, 0x3D, 0xFF},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        20,
        {0x0E, 0x4B, 0x21, 0x97, 0x6E, 0xE7, 0xA6, 0xB8, 0xEA, 0x88, 0x00, 0x95, 0x4F, 0x03, 0x40, 0xA9,
         0x83, 0x07, 0x1B, 0x47},
        20,
        {0x54, 0x79, 0x22, 0xEC, 0x8C, 0x15, 0x93, 0x98, 0xC1, 0x57, 0xFA, 0x84, 0x20, 0xA1, 0x15, 0x3C,
         0x31, 0x2D, 0x43, 0x7D},
    },
    {
        16,
        {0x6F, 0xD1, 0x01, 0x7C, 0x62, 0xC3, 0x22, 0x02, 0x74, 0x9E, 0xB1, 0x16, 0xAE, 0x90, 0x06, 0x78},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        32,
        {0x96, 0xC4, 0x6A, 0xD5, 0xED, 0x26, 0x57, 0xC2, 0xB1, 0xB5, 0x3D, 0x44, 0xDD, 0x6E, 0x2E, 0xED,
         0x72, 0x99, 0x66, 0x2A, 0xD8, 0xD7, 0x29, 0x48, 0x85, 0x7E, 0xD1, 0x4F, 0x5A, 0x86, 0x5A, 0xD3},
        32,
        {0xAF, 0x4B, 0xE0, 0xC6, 0x38, 0xB1, 0x68, 0x7A, 0x1B, 0x28, 0xDE, 0xCD, 0x66, 0x7E, 0x45, 0xE2,
         0x17, 0x1D, 0x0A, 0xF1, 0x30, 0x3C, 0x00, 0xC8, 0xB9, 0x3E, 0x5B, 0xDC, 0xBD, 0x0C, 0xE1, 0x73},
    },
    {
        16,
        {0x17, 0x05, 0xE1, 0x16, 0xD9, 0xFC, 0xE4, 0xE7, 0x42, 0xD4, 0xFF, 0x16, 0xFA, 0x81, 0x92, 0x83},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        64,
        {0x7F, 0x28, 0xEE, 0x1F, 0x3A, 0xBA, 0x7C, 0x99, 0xB3, 0x77, 0xE8, 0x3E, 0x35, 0x31, 0xA6, 0xFE,
         0x2B, 0xD0, 0x78, 0x8D, 0x4A, 0x9E, 0x40, 0x21, 0xB8, 0xB8, 0x34, 0x8E, 0xEE, 0x29, 0x80, 0x8E,
         0xF9, 0x38, 0xE3, 0x99, 0xB0, 0x6D, 0x5B, 0x50, 0xE3, 0x3D, 0x03, 0x6C, 0x82, 0xE7, 0x48, 0x27,
         0x9D, 0xAC, 0x6F, 0xC2, 0xDF, 0x88, 0xB5, 0x43, 0x64, 0x9C, 0x7B, 0x3A, 0x97, 0x33, 0xF3, 0xBA},
        64,
        {0xF7, 0xC0, 0xB5, 0xAB, 0x1E, 0xC0, 0x55, 0x79, 0x2B, 0xD1, 0x36, 0x47, 0x29, 0x12, 0x91, 0x4A,
         0x6D, 0xD8, 0x7C, 0x5B, 0x71, 0x43, 0x82, 0xF4, 0xCA, 0x02, 0x8B, 0x49, 0x25, 0x8F, 0xB2, 0x0D,
         0xF1, 0x31, 0xF0, 0xEF, 0xA8, 0xB3, 0xB0, 0xC6, 0xB8, 0x48, 0x2A, 0xC5, 0xA1, 0x58, 0x78, 0x88,
         0xF6, 0xEE, 0x05, 0xE7, 0x04, 0x95, 0x73, 0x26, 0xA9, 0x2B, 0x84, 0x97, 0x03, 0x15, 0x47, 0x73},
    },
    {
        16,
        {0x0F, 0x3D, 0x6C, 0x1D, 0x3E, 0x29, 0x3A, 0xEA, 0x05, 0xDF, 0xBF, 0x90, 0x86, 0x9D, 0x49, 0xB0},
        16,
        {0x80, 0xE7, 0x6C, 0xA1, 0x84, 0x37, 0x4F, 0x2B, 0x9B, 0x30, 0x0E, 0x61, 0xD9, 0xA5, 0x6E, 0xFF},
        64,
        {0xDF, 0xB1, 0x70, 0xCA, 0xD7, 0x2B, 0xA4, 0x7E, 0x21, 0xBE, 0x6A, 0x9C, 0x21, 0x06, 0xD2, 0x71,
         0xAC, 0x42, 0x9D, 0xDD, 0xC4, 0xCE, 0x07, 0x4B, 0x8D, 0x0F, 0x0D, 0xCE, 0x14, 0x3A, 0x98, 0x31,
         0xDF, 0x18, 0x56, 0xD4, 0x68, 0xFF, 0x56, 0x70, 0x24, 0x66, 0x6A, 0x13, 0xDA, 0x89, 0xF2, 0x54,
         0x61, 0xFB, 0x11, 0x39, 0x73, 0xC3, 0x00, 0xE7, 0xB6, 0x0A, 0x16, 0xF5, 0xC8, 0xA7, 0x52, 0xFB},
        64,
        {0x7C, 0x39, 0xCF, 0xC2, 0x67, 0x2F, 0x6D, 0x3B, 0x39, 0x31, 0x4D, 0x02, 0x1C, 0xBA, 0x09, 0xAE,
         0xBC, 0xEA, 0x08, 0x27, 0x48, 0xE2, 0x2C, 0x99, 0x20, 0x88, 0x83, 0xFB, 0x95, 0x57, 0xFD, 0xAA,
         0xAC, 0xAF, 0xB0, 0xA8, 0xFC, 0x0C, 0x6C, 0xCC, 0xC5, 0xAB, 0xED, 0xDB, 0xB2, 0x1D, 0xBB, 0x0B,
         0x2B, 0x55, 0x5E, 0x06, 0x88, 0x46, 0xAD, 0x85, 0x78, 0xDC, 0x7C, 0x59, 0x8A, 0x7F, 0x52, 0x07},
    },
    {
        16,
        {0x2F, 0x50, 0x69, 0x9F, 0x23, 0xFF, 0x03, 0x80, 0xD4, 0xC5, 0xDF, 0x89, 0xF4, 0x61, 0x1C, 0x4E},
        16,
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        67,
        {0xB3, 0x7D, 0xDC, 0x7E, 0x4E, 0xDA, 0xEF, 0x2F, 0xE8, 0x92, 0x62, 0x94, 0x2C, 0x1D, 0x5E, 0x0D,
         0xE0, 0xEB, 0xA4, 0x3C, 0x94, 0x16, 0x6F, 0x73, 0xF8, 0x7F, 0xF5, 0x32, 0x23, 0x35, 0xBE, 0x28,
         0xAF, 0x15, 0x7C, 0x8F, 0x8A, 0x61, 0x2C, 0xB9, 0x56, 0xD4, 0x0A, 0xCA, 0xCD, 0x47, 0x15, 0xCF,
         0x8B, 0x8B, 0x73, 0xC9, 0x3F, 0x1A, 0xAB, 0x0C, 0x9E, 0x25, 0x8D, 0xD3, 0x7E, 0xC1, 0xAF, 0xD3,
         0xE3, 0x54, 0xC0},
        67,
        {0x92, 0x03, 0x4B, 0x26, 0xAF, 0x5C, 0x4D, 0xC6, 0xFD, 0x23, 0xCB, 0x82, 0xEB, 0x9E, 0xD7, 0xF2,
         0x11, 0xE7, 0x03, 0xB1, 0x92, 0xCB, 0x88, 0x71, 0xFE, 0xBD, 0xBD, 0x18, 0x03, 0xEC, 0x84, 0x34,
         0x5D, 0x98, 0x8B, 0x97, 0xF3, 0x8A, 0x56, 0x81, 0x13, 0x1A, 0x48, 0x93, 0xD0, 0xAD, 0x53, 0x51,
         0x6E, 0x8E, 0xD4, 0x2B, 0x6F, 0xFA, 0x2F, 0xB6, 0xBB, 0xB6, 0xF3, 0x53, 0x55, 0x39, 0x89, 0xF0,
         0xBA, 0x58, 0x7B},
    },
    {
        16,
        {0x73, 0xE7, 0x63, 0xD3, 0xD9, 0x72, 0x75, 0xDC, 0x7C, 0x09, 0x35, 0x98, 0x9D, 0xA6, 0xB1, 0x2E},
        16,
        {0x00, 0xDF, 0xB9, 0x3C, 0xF2, 0x45, 0x9B, 0x6A, 0x8B, 0x56, 0x03, 0xB0, 0x24, 0xE4, 0xE0, 0xA0},
        67,
        {0x12, 0xA6, 0xD3, 0x1F, 0xF5, 0x86, 0xC0, 0xDC, 0x25, 0x87, 0xCC, 0x9A, 0xA3, 0xAB, 0x7C, 0x45,
         0x94, 0x8B, 0x50, 0x4F, 0x92, 0x73, 0xB7, 0xDC, 0x32, 0xD8, 0x98, 0x4D, 0x5F, 0xB6, 0x9C, 0x66,
         0xD2, 0xBC, 0xD9, 0x3D, 0x4B, 0xC3, 0xD8, 0x60, 0x5E, 0x6F, 0x6A, 0x2D, 0x3D, 0x71, 0x89, 0x76,
         0x4C, 0x5E, 0x96, 0x06, 0x61, 0xCE, 0xEB, 0x8F, 0xA4, 0x4F, 0xB0, 0x1A, 0x12, 0xE6, 0x09, 0x64,
         0xEE, 0x63, 0x2E},
        67,
        {0x7F, 0x24, 0xA1, 0xEA, 0x85, 0xDE, 0xCD, 0x73, 0x5E, 0xC5, 0x25, 0x48, 0xF5, 0x48, 0x4A, 0x01,
         0x2D, 0x14, 0x08, 0x2F, 0x70, 0x5F, 0xCF, 0x8D, 0x74, 0x95, 0xDC, 0xE8, 0x58, 0xCE, 0xF6, 0x20,
         0x26, 0xBA, 0xD6, 0xBF, 0x15, 0xC2, 0xB9, 0x13, 0x9E, 0x65, 0x68, 0x4D, 0x03, 0x50, 0x13, 0xB2,
         0x2F, 0x87, 0x07, 0xC4, 0x81, 0x2B, 0xDB, 0x59, 0x4C, 0xD0, 0xD3, 0x96, 0xE4, 0xA7, 0x30, 0xAA,
         0x28, 0x1C, 0x4E},
    },
};

static const TV_AES_CHAIN tv_ctr_aes [] = {
    // Test vector from NIST SP 800-38A
    {
        16,
        {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C},
        16,
        {0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF},
        64,
        {0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96, 0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 0x17, 0x2A,
         0xAE, 0x2D, 0x8A, 0x57, 0x1E, 0x03, 0xAC, 0x9C, 0x9E, 0xB7, 0x6F, 0xAC, 0x45, 0xAF, 0x8E, 0x51,
         0x30, 0xC8, 0x1C, 0x46, 0xA3, 0x5C, 0xE4, 0x11, 0xE5, 0xFB, 0xC1, 0x19, 0x1A, 0x0A, 0x52, 0xEF,
         0xF6, 0x9F, 0x24, 0x45, 0xDF, 0x4F, 0x9B, 0x17, 0xAD, 0x2B, 0x41, 0x7B, 0xE6, 0x6C, 0x37, 0x10},
        64,
        {0x87, 0x4D, 0x61, 0x91, 0xB6, 0x20, 0xE3, 0x26, 0x1B, 0xEF, 0x68, 0x64, 0x99, 0x0D, 0xB6, 0xCE,
         0x98, 0x06, 0xF6, 0x6B, 0x79, 0x70, 0xFD, 0xFF, 0x86, 0x17, 0x18, 0x7B, 0xB9, 0xFF, 0xFD, 0xFF,
         0x5A, 0xE4, 0xDF, 0x3E, 0xDB, 0xD5, 0xD3, 0x5E, 0x5B, 0x4F, 0x09, 0x02, 0x0D, 0xB0, 0x3E, 0xAB,
         0x1E, 0x03, 0x1D, 0xDA, 0x2F, 0xBE, 0x03, 0xD1, 0x79, 0x21, 0x70, 0xA0, 0xF3, 0x00, 0x9C, 0xEE},
    },
};
