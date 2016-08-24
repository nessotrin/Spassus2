#include "ShortFIFO.h"

ShortFIFO::ShortFIFO()
{
    buffer = 0;
    bitCount = 0;
}

void ShortFIFO::addNBits(unsigned char byte, unsigned int addBitCount)
{
    buffer <<= addBitCount;
    buffer |= byte;
    bitCount += addBitCount;
}

bool ShortFIFO::getNBits(unsigned char * byte, unsigned int getBitCount)
{
    if(getBitCount > bitCount)
    {
        return false;
    }
    *byte = (unsigned char) (buffer >> (bitCount - getBitCount));
    bitCount -= getBitCount;
    return true;
}

void ShortFIFO::addByte(unsigned char byte)
{
    buffer <<= 8;
    buffer |= byte;
    bitCount += 8;
}

void ShortFIFO::getByte(unsigned char * byte)
{
    *byte = (unsigned char) (buffer >> (bitCount - 8));
    bitCount -= 8;    
}

unsigned int ShortFIFO::getBitCount()
{
    return bitCount;
}
