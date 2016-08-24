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

void Bit::setBit(unsigned int id, unsigned char * buffer, bool value)
{
    unsigned int idByte = id/8;
    unsigned int idBit = id & 7;
    
    buffer[idByte] &= ~(1<<idBit);
    buffer[idByte] |= (((char)value)<<idBit);
}
bool Bit::getBit(unsigned int id, unsigned char * buffer)
{
    unsigned int idByte = id>>3;
    unsigned int idBit = id & 7;
    
    
    return buffer[idByte] & (1 << idBit);
}
void Bit::setBitInvertedOrder(unsigned int id, unsigned char * buffer, bool value)
{
    unsigned int idByte = id/8;
    unsigned int idBit = 7-(id & 7);
    
    buffer[idByte] &= ~(1<<idBit);
    buffer[idByte] |= (((char)value)<<idBit);
}
void Bit::orBitInvertedOrder(unsigned int id, unsigned char * buffer, bool value)
{
    unsigned int idByte = id/8;
    unsigned int idBit = 7-(id & 7);
    
    buffer[idByte] |= (((char)value)<<idBit);
}
void Bit::andBitInvertedOrder(unsigned int id, unsigned char * buffer, bool value)
{
    unsigned int idByte = id/8;
    unsigned int idBit = 7-(id & 7);
    
    buffer[idByte] &= (((char)value)<<idBit);
}
void Bit::keepBitInvertedOrder(unsigned int id, unsigned char * buffer, bool value, bool keep)
{
    unsigned int idByte = id/8;
    unsigned int idBit = 7-(id & 7);
    
    bool finalValue = (value&&!keep) || ((buffer[idByte] & (1 << idBit))&& keep);
    
    buffer[idByte] &= ~(1<<idBit);
    buffer[idByte] |= ((char)(finalValue)<<idBit);
    
}
bool Bit::getBitInvertedOrder(unsigned int id, unsigned char * buffer)
{
    unsigned int idByte = id>>3;
    unsigned int idBit = 7-(id & 7);
    
    
    return buffer[idByte] & (1 << idBit);
}

unsigned char Bit::readByteCutInBufferAtBit(unsigned int bitStart, unsigned int length, unsigned int bufferLength, unsigned char * buffer)
{
    unsigned char byte = 0x0;
    unsigned char bitOffset = bitStart&7;
    unsigned int bitAlignedByte = (bitStart)>>3;
    byte = (unsigned char) (buffer[bitAlignedByte] << bitOffset);
    if(bitAlignedByte+1 < bufferLength)
    {
        byte |= buffer[bitAlignedByte+1] >> (8-bitOffset);
    }

    return byte & ~((1<<(8-length))-1);
}


void Bit::writeByteWithRightOffsetCut(unsigned char * receiver, unsigned int offset, unsigned int length, unsigned char byte, unsigned char alpha, unsigned char invertMask, unsigned char ignoreMask) // byte is moved to the right
{
    unsigned char mask = ((alpha^invertMask) | ignoreMask)&(~((1<<(8-length))-1));
    receiver[0] &= ~mask >> offset; // blanks the byte
    receiver[0] |= ((byte&(mask)) >> offset);
}
void Bit::writeByteCut(unsigned char * receiver, unsigned int length, unsigned char byte, unsigned char alpha, unsigned char invertMask, unsigned char ignoreMask)
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