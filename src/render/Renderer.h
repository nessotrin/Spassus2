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

#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "render/Screen.h"

class Renderer
{
    struct renderBuffer
    {
        Coord buffStart;
        Coord coordStart;
        Coord size;
        Coord realSize;
        unsigned char * dataBuffer;
        unsigned char * alphaBuffer;
    };
    
    private:
        Screen * screen;
        void memDrawRect(renderBuffer buffer, bool invertMask, bool ignoreMask);
        renderBuffer clipRectScreen(Coord start, Coord size, unsigned char * buffer, unsigned char * alpha);
        int getScreenBitId(Coord pointCoord);
        void drawPointUnsafe(Coord point, bool color);
    public:
        void setScreen(Screen * newScreen);
        void drawRect(Coord start, unsigned char * buffer, Coord size);
        void drawRectOrAlpha(Coord start, unsigned char * buffer, Coord size);
        void drawRectAndAlpha(Coord start, unsigned char * buffer, Coord size);
        void drawRectAlpha(Coord start, unsigned char * buffer, unsigned char * alpha, Coord size);
        void drawPoint(Coord point, bool color);
        void drawLine(Coord start, Coord end, bool color);
};
#endif 
//des =  (des & transp) | (col && !transp)
