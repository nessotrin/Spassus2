#ifndef _IO_BIT_BUFFER_H_
#define _IO_BIT_BUFFER_H_

class IOBitBuffer
{
public:
    IOBitBuffer(unsigned char * newBuffer, unsigned int newStartBit, unsigned int newLength);
    void readPartial(unsigned char * byte, unsigned int * size);
    void readAligned(unsigned char * byte);
    
    unsigned int getWritePartialSize();
    void writePartial(unsigned char byte);
    void writeAligned(unsigned char byte);
    
    unsigned int getStartBit();
    void setStartBit(unsigned int newStartBit);
    unsigned int getLength();
    void setLength(unsigned int newLenght);

private:
    unsigned char * buffer;
    unsigned int startBit;
    unsigned int length;
};

#endif // _IO_BIT_BUFFER_H_
