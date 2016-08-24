#include "Sprite.h"

#include <tools/IOBitBufferTools.h>

void Sprite::drawBitmap(Coord pos, Bitmap bitmap, Screen * screen)
{
    ScreenLine line;
    unsigned int bitmapY = 0;
    int y = pos.getY();
        
    if (y < 0) //skip the beginning
    {
        bitmapY += (unsigned int)(-y);
        y = 0;
    }
    for(; y < pos.getY()+bitmap.getSize().getY() ; y++)
    {
        if(screen->getScreenLine(&line,(unsigned int)y)) // out of screen
        {
            break;
        }
        IOBitBuffer writeBuffer = line.getAsIOBitBuffer();
        IOBitBuffer readBuffer = IOBitBuffer((unsigned char *)bitmap.getBuffer(), bitmapY*(unsigned int)bitmap.getSize().getX(), (unsigned int)bitmap.getSize().getX());
        
        IOBitBufferTools::copyOntoAt(pos.getX(),readBuffer,writeBuffer);
        bitmapY++;
    }
}
/*
void Sprite::drawMaskedBitmap(Coord pos, Bitmap * bitmap, Bitmap * mask, Screen * screen)
{
    
}
*/