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

#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <tools/Coord.h>
#include <memory/List.h>

#include "ScreenLine.h"

class Screen
{
private:
    unsigned char * bufferAdress = NULL;
    Coord inBufferCoord;
    Coord relativeCoord;
    Coord size;
    Screen * parent = NULL;
    List<Screen*> child;

    Screen * getTopParent();
    List<Screen*> * getChild();
    void updateInBufferCoord();
    unsigned char * getTopBuffer();
    Coord getInBufferCoord();

    
public:
    Screen(Coord newCoord, Coord newSize, Screen * newParent);
    Screen(Coord newSize, unsigned char * newBufferAdress);
    
    Coord getRelativeCoord();
    Coord getSize();

    bool getScreenLine(ScreenLine * line, unsigned int y);

    void addChild(Screen * newChild);
    void removeChild(Screen * oldChild);

    void changeSize(Coord newSize);
    void changeCoord(Coord newCoord);

};

#endif