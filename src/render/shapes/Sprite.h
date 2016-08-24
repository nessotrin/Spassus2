#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <render/Screen.h>
#include <memory/Bitmap.h>

class Sprite
{
public:
    void drawBitmap(Coord pos, Bitmap bitmap, Screen * screen);
    void drawMaskedBitmap(Coord pos, Bitmap bitmap, Bitmap * mask, Screen * screen);
};

#endif // _SPRITE_H_
