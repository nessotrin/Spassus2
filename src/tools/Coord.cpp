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

#include "Coord.h"

Coord::Coord()
{
    
}

Coord::Coord(int newX, int newY)
{
    posX = newX;
    posY = newY;
}

int Coord::getX()
{
    return posX;
}

int Coord::getY()
{
    return posY;
}

void Coord::setX(int newX)
{
    posX = newX;
}

void Coord::setY(int newY)
{
    posY = newY;
}

Coord& Coord::operator+(Coord toAdd)
{
    posX += toAdd.getX();
    posY += toAdd.getY();
    return *this;
}

void Coord::add(int addX, int addY)
{
    posX += addX;
    posY += addY;
}

Coord& Coord::operator*(Coord toMult)
{
    posX *= toMult.getX();
    posY *= toMult.getY();
    return *this;
}

void Coord::mult(int multX, int multY)
{
    posX *= multX;
    posY *= multY;
}