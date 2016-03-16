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

#include "Screen.h"

Screen::Screen(Coord newCoord, Coord newSize, Screen * newParent)
{
    size = newSize;
    relativeCoord = newCoord;
    parent = newParent;
    updateAbsoluteCoord();
}
Screen::Screen(Coord newSize, unsigned char * newMemoryAdress)
{
    size = newSize;
    relativeCoord = Coord(0,0);
    parent = NULL;
    updateAbsoluteCoord();
    memoryAdress = newMemoryAdress;
}
void Screen::changeCoord(Coord newCoord)
{
    relativeCoord = newCoord;
    updateAbsoluteCoord();
}

void Screen::changeSize(Coord newSize)
{
    size = newSize;
}

Screen * Screen::getParent()
{
    return parent;
}

Coord Screen::getSize()
{
    return size;
}

Coord Screen::getRelativeCoord()
{
    return relativeCoord;
}

Coord Screen::getAbsoluteCoord()
{
    return absoluteCoord;
}

void Screen::addChild(Screen * newChild)
{
    child.add(newChild);
}

void Screen::removeChild(Screen * oldChild)
{
    child.searchAndRemove(oldChild);
}

void Screen::updateAbsoluteCoord()
{
    if(parent == NULL)
    {
        absoluteCoord = relativeCoord;
    }
    else
    {
        absoluteCoord = relativeCoord + parent->getAbsoluteCoord();
    }
    for(unsigned int i = 0 ; i < child.getSize() ; i++)
    {
        child.get(i)->updateAbsoluteCoord();
    }
}

Screen * Screen::getPhysicalScreen()
{
    if(parent == NULL)
    {
        return this;
    }
    else
    {
        return parent->getPhysicalScreen();
    }
}

unsigned char * Screen::getPhysicalMemoryAdress()
{
    if(parent == NULL)
    {
        return memoryAdress;
    }
    else
    {
        return parent->getPhysicalMemoryAdress();
    }
}