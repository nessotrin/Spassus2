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

void Bitmap::alloc(int newSize)
{
    memory = (char *) malloc(newSize>>3);
    if(memory == NULL)
    {
        Error::crash((char*)"Bitmap alloc  out of memory");
    }

    newSize = size;
}
char Bitmap::get(int id)
{
    if(id < 0 || id >= size)
    {
        Error::crash((char*)"Bitmap get  out of range id");
    }
    return (memory[id>>3]>>(id&7) != 0);
}
void Bitmap::set(int id, char value)
{
    if(id < 0 || id >= size)
    {
        Error::crash((char*)"Bitmap set  out of range id");
    }
    if(value == 0)
    {
        memory[id>>3]&= ~(1<<(id&7));
    }
    else
    {
        memory[id>>3]|= (1<<(id&7));
    }
}