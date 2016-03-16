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

#include "Geometry.h"

void Geometry::cutLineHorizontal(Coord * a, Coord * b, int lineLow, int lineHigh)
{
    Coord * lowPoint;
    Coord * highPoint;
    if(a->getY() < b->getY())
    {
        lowPoint = a;
        highPoint = b;
    }
    else
    {
        lowPoint = b;
        highPoint = a;
    }
    
    if(lowPoint->getY() < lineLow)
    {
        int overLength = lineLow - lowPoint->getY();
        float removeFactor = overLength/(float)(highPoint->getY()-lowPoint->getY());
        lowPoint->add((int)((highPoint->getX()-lowPoint->getX())*removeFactor),overLength);
    }

    if(highPoint->getY() > lineHigh)
    {
        int overLength = highPoint->getY() - lineHigh;
        float removeFactor = overLength/(float)(highPoint->getY()-lowPoint->getY());
        highPoint->add((int)(-(highPoint->getX()-lowPoint->getX())*removeFactor),-overLength);
    }
}

void Geometry::cutLineVertical(Coord * a, Coord * b, int lineLow, int lineHigh)
{
    Coord * lowPoint;
    Coord * highPoint;
    if(a->getX() < b->getX())
    {
        lowPoint = a;
        highPoint = b;
    }
    else
    {
        lowPoint = b;
        highPoint = a;
    }
    
    if(lowPoint->getX() < lineLow)
    {
        int overLength = lineLow - lowPoint->getX();
        float removeFactor = overLength/(float)(highPoint->getX()-lowPoint->getX());
        lowPoint->add(overLength,(int)((highPoint->getY()-lowPoint->getY())*removeFactor));
    }

    if(highPoint->getX() > lineHigh)
    {
        int overLength = highPoint->getX() - lineHigh;
        float removeFactor = overLength/(float)(highPoint->getX()-lowPoint->getX());
        highPoint->add(-overLength,(int)(-(highPoint->getY()-lowPoint->getY())*removeFactor));
    }
}