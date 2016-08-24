#ifndef BITBUFFERTOOLS_H
#define BITBUFFERTOOLS_H

#include <memory/IOBitBuffer.h>

class IOBitBufferTools
{
public:
    static void copyOntoAt(int startBit, IOBitBuffer original, IOBitBuffer target);
private:
    static bool clipOntoAt(int startBit, IOBitBuffer * original, IOBitBuffer * target);

};

#endif // BITBUFFERTOOLS_H
