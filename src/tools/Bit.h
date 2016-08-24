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

#ifndef _BIT_H_
#define _BIT_H_

class Bit
{
public:
    static void setBit(unsigned int id, unsigned char * buffer, bool value);
    static void setBitInvertedOrder(unsigned int id, unsigned char * buffer, bool value);
    static void orBitInvertedOrder(unsigned int id, unsigned char * buffer, bool value);
    static void andBitInvertedOrder(unsigned int id, unsigned char * buffer, bool value);
    static void keepBitInvertedOrder(unsigned int id, unsigned char * buffer, bool value, bool keep);
    static bool getBit(unsigned int id, unsigned char * buffer);
    static bool getBitInvertedOrder(unsigned int id, unsigned char * buffer);
    static unsigned char readByteCutInBufferAtBit(unsigned int bitStart, unsigned int lengh, unsigned int bufferLength, unsigned char * buffer);
    static void writeByteWithRightOffsetCut(unsigned char * receiver, unsigned int offset, unsigned int length, unsigned char byte, unsigned char alpha, unsigned char invertMask, unsigned char ignoreMask); // byte must be moved left
    static void writeByteCut(unsigned char * receiver, unsigned int length, unsigned char byte, unsigned char alpha, unsigned char invertMask, unsigned char ignoreMask);
    static void writeByte(unsigned char * receiver, unsigned char byte, unsigned char alpha, unsigned char invertMask, unsigned char ignoreMask);
};

#endif // _BIT_H_
