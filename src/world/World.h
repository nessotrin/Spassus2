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

#ifndef _WORLD_H_
#define _WORLD_H_

#define MAX_OBJECT_COUNT 64

#include <world/object/Object.h>
#include <render/Screen.h>

class World
{
public:
    World();
    void tick();
    void render(Screen * screen);
    
private:
    Object * objectTable[MAX_OBJECT_COUNT];
    
};
#endif