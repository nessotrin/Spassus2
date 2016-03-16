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

#include "List.h"
#include "error/Error.h"

void testList()
{
    List<int> testList;
    if(testList.getSize() != 0)
    {
        Error::crash((char *)"A");
    }
    testList.add(3);
    if(testList.getSize() != 1)
    {
        Error::crash((char *)"B");
    }
    if(testList.get(0) != 3)
    {
        Error::crash((char*)"C");
    }
    if(testList.getAllocSize() != ((int)(100/4)) +1)
    {
        printf("%d\n",testList.getAllocSize());
        Error::crash((char*)"D");
    }
    testList.remove(0);
    if(testList.getSize() != 0)
    {
        Error::crash((char*)"E");
    }
    if(testList.getAllocSize() != testList.getSize())
    {
        Error::crash((char*)"F");
    }
}