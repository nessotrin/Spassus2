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

#include <Calculib.h>

#include <string.h>

//#include <MonochromeLib.h>

#include "error/Error.h"


void Error::crash(char * text)
{
    printf("CRASH: ");
    printf("%s\n",(char*)text);

    ML_clear_vram();

    locate(1,1);
    Print((const unsigned char *)text);

    ML_display_vram();

    while(1)
    {
        //tickCalcuLib();
        Sleep(10);
    }
}