#ifndef _SCREEN_LINE_H_
#define _SCREEN_LINE_H_

#include <memory/IOBitBuffer.h>

class ScreenLine
{
public:
    void setup(unsigned char * newBuffer, unsigned int newBitStartPos, unsigned int newLineBitLength);
    void orPoint(unsigned int x, bool value);
    void setPoint(unsigned int x, bool value);
    IOBitBuffer getAsIOBitBuffer();
    unsigned int getLength();

private:
    
    /*
    //legacy
    void copyPoints(int x, unsigned char * source, unsigned int sourceStartBit, unsigned int sourceLength);
    bool checkAndWrite(unsigned short * workBuffer, unsigned int * workBufferBitCount, unsigned int * outputWritePos, unsigned int outputWriteLength, unsigned int outputWriteStart);
    bool addToBuffer(unsigned char toAdd, unsigned int toAddCount, unsigned short * workBuffer, unsigned int * workBufferBitCount, unsigned int * outputWritePos, unsigned int outputWriteLength, unsigned int outputWriteStart);
    */

    unsigned char * buffer;
    unsigned int startBitOffset;
    unsigned int lineLength;
};

#endif // _SCREEN_LINE_H_
