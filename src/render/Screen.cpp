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
    updateInBufferCoord();
}
Screen::Screen(Coord newSize, unsigned char * newBufferAdress)
{
    size = newSize;
    relativeCoord = Coord(0,0);
    parent = NULL;
    updateInBufferCoord();
    bufferAdress = newBufferAdress;
}
void Screen::changeCoord(Coord newCoord)
{
    relativeCoord = newCoord;
    updateInBufferCoord();
}

void Screen::changeSize(Coord newSize)
{
    size = newSize;
}

Coord Screen::getSize()
{
    return size;
}

Coord Screen::getRelativeCoord()
{
    return relativeCoord;
}

Coord Screen::getInBufferCoord()
{
    return inBufferCoord;
}

void Screen::addChild(Screen * newChild)
{
    child.add(newChild);
}

void Screen::removeChild(Screen * oldChild)
{
    child.searchAndRemove(oldChild);
}

void Screen::updateInBufferCoord()
{
    if(parent == NULL)
    {
        inBufferCoord = relativeCoord;
    }
    else
    {
        inBufferCoord = relativeCoord + parent->getInBufferCoord();
    }
    for(unsigned int i = 0 ; i < child.getSize() ; i++)
    {
        child.get(i)->updateInBufferCoord();
    }
}

unsigned char * Screen::getTopBuffer()
{
    return getTopParent()->bufferAdress;
}

bool Screen::getScreenLine(ScreenLine * lineToFill, unsigned int lineY)
{
    unsigned int bufferLineLength = (unsigned int) getTopParent()->getSize().getX();
    if(lineY >= (unsigned int) (getTopParent()->getSize().getY()-inBufferCoord.getY()))
    {
        return true;
    }
    lineToFill->setup(getTopBuffer(),
                      (bufferLineLength*((unsigned int)inBufferCoord.getY()+lineY) + (unsigned int)inBufferCoord.getX()),
                      (bufferLineLength-(unsigned int)inBufferCoord.getX()));
    return false;
}

Screen * Screen::getTopParent()
{
    if(parent == NULL)
    {
        return this;
    }
    else
    {
        return parent->getTopParent();
    }
}