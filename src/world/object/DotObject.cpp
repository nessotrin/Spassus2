#include "DotObject.h"

#include <render/shapes/Point.h>

void DotObject::init()
{
    x = 0;
    y = 0;
    handler->registerHandler(this,0x1);
    keyboardReader->registerKey(this,KEY_CTRL_UP);
    keyboardReader->registerKey(this,KEY_CTRL_DOWN);
    keyboardReader->registerKey(this,KEY_CTRL_LEFT);
    keyboardReader->registerKey(this,KEY_CTRL_RIGHT);
}

void DotObject::deinit()
{
    handler->unregisterHandler(this,0x1);
    keyboardReader->unregisterKey(this,KEY_CTRL_UP);
    keyboardReader->unregisterKey(this,KEY_CTRL_DOWN);
    keyboardReader->unregisterKey(this,KEY_CTRL_LEFT);
    keyboardReader->unregisterKey(this,KEY_CTRL_RIGHT);
}

void DotObject::networkEventHandler(unsigned char type, Buffer * data) 
{
//printf("Network !\n");
    if(type != 0x1)
    {
        printf("ERROR: Bad type from handler !\n");
    }
	x = (int) data->getBuffer()[0];
	y = (int) data->getBuffer()[1];
}

void DotObject::keyHandler(unsigned short keyId, bool keyStatus)
{
    //printf("Key !\n");
    if(keyStatus == 0)
    {
        return;
    }
    
    if(keyId == KEY_CTRL_UP)
    {
        y--;
    }
    
    if(keyId == KEY_CTRL_DOWN)
    {
        y++;
    }

    if(keyId == KEY_CTRL_LEFT)
    {
        x--;
    }
    
    if(keyId == KEY_CTRL_RIGHT)
    {
        x++;
    }
    
    //Sends to the other
    unsigned char data[2];
    data[0] = (unsigned char)x;
    data[1] = (unsigned char)y;
    Buffer toSend(data,2);
    handler->sendMessage(0x1,&toSend);
    printf("Sending ...\n");
}

void DotObject::tick()
{
}

#include <memory/Bitmap.h>
#include <render/shapes/Sprite.h>
#include <render/shapes/Line.h>

void DotObject::render(Screen * screen)
{
    printf("Render %d %d\n",x,y);
    Point point(Coord(7,1));    
    point.draw(screen);
    Point point2(Coord(8,1));    
    point2.draw(screen);
    Point point3(Coord(15,1));    
    point3.draw(screen);
    Point point4(Coord(16,1));    
    point4.draw(screen);
    Bitmap bitmap;
    bitmap.alloc(Coord(34,43));


    unsigned char val = 0;
    for(int iy = 0 ; iy < 43 ; iy++)
    {
        for(int ix = 0 ; ix < 34 ; ix++)
        {
            bitmap.set(Coord(ix,iy),val);
            val = !val;
        }
        val = !val;
    }

//    Sprite sprite;
//    sprite.drawBitmap(Coord(x,y), bitmap, screen);
    Line line(Coord(x,y),Coord(80,30));
    line.draw(screen);
}

void DotObject::setup(NetworkHandler * newNetworkHandler, KeyboardReader * newKeyboardReader)
{
    handler = newNetworkHandler;
    keyboardReader = newKeyboardReader;
}