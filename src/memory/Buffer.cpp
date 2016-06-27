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

#include "Buffer.h"

Buffer::Buffer()
{
}
Buffer::Buffer(unsigned char * newBuffer, unsigned int newSize)
{
    buffer = newBuffer;
    size = newSize;
}

unsigned char * Buffer::getBuffer()
{
    return buffer;
}
unsigned int Buffer::getSize()
{
    return size;
}
void Buffer::setBuffer(unsigned char * newBuffer)
{
    buffer = newBuffer;
}
void Buffer::setSize(unsigned int newSize)
{
    size = newSize;
}
