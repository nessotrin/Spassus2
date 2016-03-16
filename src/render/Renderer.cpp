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

#include "Renderer.h"

#include "tools/Bit.h"
#include "tools/Geometry.h"

#include <MonochromeLib.h>

#include <algorithm>

void Renderer::setScreen(Screen * newScreen)
{
    screen = newScreen;
}

int Renderer::getScreenBitId(Coord pointCoord)
{
    return (pointCoord.getX() + pointCoord.getY()*(screen->getPhysicalScreen()->getSize().getX()));
}

void Renderer::memDrawRect(renderBuffer buffer, bool invertMask, bool ignoreMask)
{
    unsigned char invertMaskByte = invertMask*255;
    unsigned char ignoreMaskByte = ignoreMask*255;
    
    if(buffer.size.getX() <= 0 || buffer.size.getY() <= 0)
    {
        return;
    }
    
    unsigned char * memoryBuffer = screen->getPhysicalMemoryAdress();
    int screenY = buffer.coordStart.getY();
    
    for(int y = buffer.buffStart.getY() ; y < buffer.buffStart.getY()+buffer.size.getY() ; y++)
    {
        int startXByte = buffer.coordStart.getX()>>3;
        int endXByte = (buffer.coordStart.getX()+buffer.size.getX()-1)>>3;

        int bitmapStartBitId = buffer.buffStart.getX()+y*buffer.realSize.getX();
        int lineStartOffset = buffer.coordStart.getX()&7;

        int bufferTotalSize = buffer.realSize.getX() * buffer.realSize.getY();
        int lineBitDone = 0;
        
        int screenWritePos = getScreenBitId(Coord(startXByte,screenY))>>3;
        
        //first byte
        Bit::writeByteWithRightOffsetCut(memoryBuffer+screenWritePos,
        lineStartOffset,
        8-lineStartOffset,
        Bit::readBitsInBufferAt(bitmapStartBitId,8-lineStartOffset,bufferTotalSize,buffer.dataBuffer),
        Bit::readBitsInBufferAt(bitmapStartBitId,8-lineStartOffset,bufferTotalSize,buffer.alphaBuffer),
        invertMaskByte,
        ignoreMaskByte);
        lineBitDone += 8-lineStartOffset;
        screenWritePos++;
        
        //Full bytes
        for(int x = startXByte+1 ; x < endXByte ; x++)
        {
            Bit::writeByte(memoryBuffer+screenWritePos,
                           Bit::readBitsInBufferAt(bitmapStartBitId+lineBitDone,8,bufferTotalSize,buffer.dataBuffer),
                           Bit::readBitsInBufferAt(bitmapStartBitId+lineBitDone,8,bufferTotalSize,buffer.alphaBuffer),
                           invertMaskByte,
                           ignoreMaskByte);
            lineBitDone += 8;
            screenWritePos++;
        }
        
        //End partial byte
        if(buffer.size.getX()-lineBitDone > 0)
        {
            Bit::writeByteCut(memoryBuffer+screenWritePos,
            buffer.size.getX()-lineBitDone,
            Bit::readBitsInBufferAt(bitmapStartBitId+lineBitDone,buffer.size.getX()-lineBitDone,bufferTotalSize,buffer.dataBuffer),
            Bit::readBitsInBufferAt(bitmapStartBitId+lineBitDone,buffer.size.getX()-lineBitDone,bufferTotalSize,buffer.alphaBuffer),
            invertMaskByte,
            ignoreMaskByte);
        }
        screenY++;
    }
}
Renderer::renderBuffer Renderer::clipRectScreen(Coord start, Coord size, unsigned char * buffer, unsigned char * alpha)
{
    renderBuffer newBuffer;
    newBuffer.buffStart.setX(start.getX()<0?-start.getX():0);
    newBuffer.buffStart.setY(start.getY()<0?-start.getY():0);
    newBuffer.coordStart.setX(std::max(start.getX(),0)+screen->getAbsoluteCoord().getX());
    newBuffer.coordStart.setY(std::max(start.getY(),0)+screen->getAbsoluteCoord().getY());
    newBuffer.size.setX(std::min(std::min(size.getX()-newBuffer.buffStart.getX(),
                                          screen->getSize().getX()-newBuffer.coordStart.getX()-newBuffer.buffStart.getX()),
                                 screen->getPhysicalScreen()->getSize().getX()-newBuffer.coordStart.getX()-newBuffer.buffStart.getX()));
    newBuffer.size.setY(std::min(std::min(size.getY()-newBuffer.buffStart.getY(),
                                          screen->getSize().getY()-newBuffer.coordStart.getY()-newBuffer.buffStart.getY()),
                                 screen->getPhysicalScreen()->getSize().getX()-newBuffer.coordStart.getY()-newBuffer.buffStart.getY()));  
    newBuffer.realSize = size;
    newBuffer.dataBuffer = buffer;
    newBuffer.alphaBuffer = alpha;
    return newBuffer;
}

void Renderer::drawRect(Coord start, unsigned char * buffer, Coord size)
{
    memDrawRect(clipRectScreen(start,size,buffer,buffer),false,true);
}
void Renderer::drawRectOrAlpha(Coord start, unsigned char * buffer, Coord size)
{
    memDrawRect(clipRectScreen(start,size,buffer,buffer),false,false);
}
void Renderer::drawRectAndAlpha(Coord start, unsigned char * buffer, Coord size)
{
    memDrawRect(clipRectScreen(start,size,buffer,buffer),true,false);
}
void Renderer::drawRectAlpha(Coord start, unsigned char * buffer, unsigned char * alpha, Coord size)
{
    memDrawRect(clipRectScreen(start,size,buffer,alpha),false,false);
}

void Renderer::drawPointUnsafe(Coord point, bool color)
{
    unsigned char * memoryBuffer = screen->getPhysicalMemoryAdress();
    Coord renderPoint = point+screen->getAbsoluteCoord();
    Bit::setBit(getScreenBitId(renderPoint)^7,memoryBuffer,color); //^7 -> inverts bits order inside the byte
}

void Renderer::drawPoint(Coord point, bool color)
{
    if(point.getX() < 0 || point.getY() < 0 || point.getX() > screen->getSize().getX() || point.getY() > screen->getSize().getY())
    {
        return;
    }
    drawPointUnsafe(point,color);
}

//si x's > ou < trash



void Renderer::drawLine(Coord start, Coord end, bool color)
{
    unsigned char * memoryBuffer = screen->getPhysicalMemoryAdress();
    Coord renderStart = start;
    Coord renderEnd = end;

    Geometry::cutLineHorizontal(&renderStart,&renderEnd,0,screen->getSize().getY()-1);
    Geometry::cutLineVertical(&renderStart,&renderEnd,0,screen->getSize().getX()-1);
    
    int deltaX = renderEnd.getX() - renderStart.getX();
    int deltaY = renderEnd.getY() - renderStart.getY();

    int loopCount = std::max(abs(deltaX), abs(deltaY));

    float addX = deltaX/(float)loopCount;
    float addY = deltaY/(float)loopCount;

    float posX = renderStart.getX() + screen->getAbsoluteCoord().getX();
    float posY = renderStart.getY() + screen->getAbsoluteCoord().getY(); 

    for(int i = 0 ; i < loopCount ; i++)
    {
        drawPointUnsafe(Coord(posX, posY),color);
        posX += addX;
        posY += addY;
    }

}