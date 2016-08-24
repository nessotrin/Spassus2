#ifndef _SHORT_FIFO_H_
#define _SHORT_FIFO_H_

class ShortFIFO
{
public:
    ShortFIFO();
    void addNBits(unsigned char byte, unsigned int addBitCount);
    bool getNBits(unsigned char * byte, unsigned int getBitCount);
    void addByte(unsigned char byte);
    void getByte(unsigned char * byte);
    unsigned int getBitCount();
private:
    unsigned short buffer;
    unsigned int bitCount;

};

#endif // _SHORT_FIFO_H_
