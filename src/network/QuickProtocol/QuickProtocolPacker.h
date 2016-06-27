#ifndef _QUICK_PROTOCOL_PACKER_H_
#define _QUICK_PROTOCOL_PACKER_H_

#include "memory/Buffer.h"

enum QUICKPROTOCOL_UNPACK_RESULT{
     QUICKPROTOCOL_UNPACK_OK = 0,
     QUICKPROTOCOL_UNPACK_NOTCOMPLETE,
     QUICKPROTOCOL_UNPACK_ERROR,
};


class QuickProtocolPacker
{
public:
    static bool packBuffer(Buffer * outputBuffer, unsigned char type, Buffer * dataBuffer);
    static QUICKPROTOCOL_UNPACK_RESULT unpackBuffer(Buffer * inputBuffer, unsigned char * type, Buffer * dataBuffer);
    
};

#endif // _QUICK_PROTOCOL_PACKER_H_
