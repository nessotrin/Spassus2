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

#include "ToCharNoEndian.h"

void ToCharNoEndian::intToChar(unsigned char * toWrite, int value)
{
    toWrite[0] = (unsigned char)(value>>0);
    toWrite[1] = (unsigned char)(value>>8);
    toWrite[2] = (unsigned char)(value>>16);
    toWrite[3] = (unsigned char)(value>>24);
}
void ToCharNoEndian::uintToChar(unsigned char * toWrite, unsigned int value)
{
    toWrite[0] = (unsigned char)(value>>0);
    toWrite[1] = (unsigned char)(value>>8);
    toWrite[2] = (unsigned char)(value>>16);
    toWrite[3] = (unsigned char)(value>>24);
}
void ToCharNoEndian::charToInt(int * value, unsigned char * toRead)
{
    *value = ((int)(toRead[0]<<0)) + ((int)(toRead[1]<<8)) + ((int)(toRead[2]<<16)) + ((int)(toRead[3]<<24));
}
void ToCharNoEndian::charToUint(unsigned int * value, unsigned char * toRead)
{
    *value = ((unsigned int)(toRead[0]<<0)) + ((unsigned int)(toRead[1]<<8)) + ((unsigned int)(toRead[2]<<16)) + ((unsigned int)(toRead[3]<<24));
}


void ToCharNoEndian::shortToChar(unsigned char * toWrite, short value)
{
    toWrite[0] = (unsigned char)(value>>0);
    toWrite[1] = (unsigned char)(value>>8);
}
void ToCharNoEndian::ushortToChar(unsigned char * toWrite, unsigned short value)
{
    toWrite[0] = (unsigned char)(value>>0);
    toWrite[1] = (unsigned char)(value>>8);
}
void ToCharNoEndian::charToShort(short * value, unsigned char * toRead)
{
    *value = ((short)(toRead[0]<<0)) + ((short)(toRead[1]<<8));
}
void ToCharNoEndian::charToUshort(unsigned short * value, unsigned char * toRead)
{
    *value = ((unsigned short)(toRead[0]<<0)) + ((unsigned short)(toRead[1]<<8));
}