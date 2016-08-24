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

#include "Bitmap.h"

#include "error/Error.h"

#include <Calculib.h>

Bitmap::Bitmap()
{
    size.setX(0);
    size.setY(0);
}

void Bitmap::alloc(Coord newSize)
{
    memory = (unsigned char *) malloc((size_t)(newSize.getX()*newSize.getY())>>3);
    if(memory == NULL)
    {
        Error::crash((char*)"Bitmap alloc  out of memory");
    }

    size = newSize;
}

void Bitmap::checkInit()
{
    if(size.getX() == 0 || size.getY() == 0)
    {
        Error::crash((char *)"Bitmap is not initialized !");
    }    
}
void Bitmap::checkInBound(Coord coord)
{
    if(coord.getX() >= size.getX() || 
       coord.getY() >= size.getY() || 
       coord.getX() < 0 || 
       coord.getX() < 0)
   {
       Error::crash((char *)"Bitmap getBitId  Out of range !");
   }    
}
unsigned char Bitmap::getBit(Coord coord)
{
    checkInit();
    checkInBound(coord);
    
    unsigned int id = getBitId(coord);
    return (memory[id>>3]>>(7-(id&7)) != 0);
}
unsigned char * Bitmap::getBuffer()
{
    return memory;
}
void Bitmap::set(Coord coord, unsigned char value)
{
    checkInit(); 
    checkInBound(coord);  
    
    if(coord.getX() >= size.getX() || coord.getY() >= size.getY())
    {
        Error::crash((char*)"Bitmap set  out of range id");
    }
    unsigned int id = getBitId(coord);
    if(value == 0)
    {
        memory[id>>3]&= ~(1<<(7-(id&7)));
    }
    else
    {
        memory[id>>3]|= (1<<(7-(id&7)));
    }
}
unsigned int Bitmap::getBitId(Coord coord)
{
    checkInit();
    checkInBound(coord);
    
    return (unsigned int)( coord.getY()*size.getX() + coord.getX());
}

Coord Bitmap::getSize()
{
    return size;
}