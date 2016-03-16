/*
Spassus2 is a free game (and powerfull engine) for Casio calculators
Copyright (C) 2016 Hugo KUENY

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "Bit.h"

#include <cstdio>

void Bit::setBit(int id, unsigned char * buffer, bool value)
{
    int idByte = id/8;
    int idBit = id & 7;
    
    buffer[idByte] &= ~(1<<idBit);
    buffer[idByte] |= (((char)value)<<idBit);
}
bool Bit::getBit(int id, unsigned char * buffer)
{
    int idByte = id>>3;
    int idBit = id & 7;
    
    
    return buffer[idByte] & (1 << idBit);
}
void Bit::setBitInvertedOrder(int id, unsigned char * buffer, bool value)
{
    int idByte = id/8;
    int idBit = 7-(id & 7);
    
    buffer[idByte] &= ~(1<<idBit);
    buffer[idByte] |= (((char)value)<<idBit);
}
void Bit::orBitInvertedOrder(int id, unsigned char * buffer, bool value)
{
    int idByte = id/8;
    int idBit = 7-(id & 7);
    
    buffer[idByte] |= (((char)value)<<idBit);
}
void Bit::andBitInvertedOrder(int id, unsigned char * buffer, bool value)
{
    int idByte = id/8;
    int idBit = 7-(id & 7);
    
    buffer[idByte] &= (((char)value)<<idBit);
}
void Bit::keepBitInvertedOrder(int id, unsigned char * buffer, bool value, bool keep)
{
    int idByte = id/8;
    int idBit = 7-(id & 7);
    
    bool finalValue = (value&&!keep) || ((buffer[idByte] & (1 << idBit))&& keep);
    
    buffer[idByte] &= ~(1<<idBit);
    buffer[idByte] |= ((char)(finalValue)<<idBit);
    
}
bool Bit::getBitInvertedOrder(int id, unsigned char * buffer)
{
    int idByte = id>>3;
    int idBit = 7-(id & 7);
    
    
    return buffer[idByte] & (1 << idBit);
}
void binary(int n) // TODO: remove me debug
{
    int exp = 7;
    while (exp>= 0) {
        if (n & (1<<exp))
            printf("1");
        else
            printf("0");

        exp--;
    }
printf("\n");
}

unsigned char Bit::readBitsInBufferAt(int bitStart, int length, int bufferLength, unsigned char * buffer)
{
    unsigned char byte = 0x0;
    unsigned char bitOffset = bitStart&7;
    int bitAlignedByte = (bitStart)>>3;
    byte = buffer[bitAlignedByte] << bitOffset;
    if(bitAlignedByte+1 < bufferLength)
    {
        byte |= buffer[bitAlignedByte+1] >> (8-bitOffset);
    }


    //printf("%d %d %d\n",byte&0b10000000>=1,byte&0b01000000>=1,byte&0b00100000>=1);
    return byte & ~((1<<(8-length))-1);
}


void Bit::writeByteWithRightOffsetCut(unsigned char * receiver, int offset, int length, unsigned char byte, unsigned char alpha, unsigned char invertMask, unsigned char ignoreMask) // byte is moved to the right
{
    unsigned char mask = ((alpha^invertMask) | ignoreMask)&(~((1<<(8-length))-1));
    receiver[0] &= ~mask >> offset; // blanks the byte
    receiver[0] |= ((byte&(mask)) >> offset);
}
void Bit::writeByteCut(unsigned char * receiver, int length, unsigned char byte, unsigned char alpha, unsigned char invertMask, unsigned char ignoreMask)
{
    unsigned char mask = ((alpha^invertMask) | ignoreMask)&(~((1<<(8-length))-1));
    receiver[0] &= ~mask; // blanks the byte
    receiver[0] |= byte&mask;
}
void Bit::writeByte(unsigned char * receiver, unsigned char byte, unsigned char alpha, unsigned char invertMask, unsigned char ignoreMask)
{
    receiver[0] &= ~((alpha^invertMask) | ignoreMask); // blanks the byte
    receiver[0] |= byte&alpha;
}