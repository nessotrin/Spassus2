#include "DotObject.h"


void DotObject::init()
{
    x = 10;
    y = 10;
    networkHandler->registerHandler(this,0x1);
    keyboardReader->registerKey(this,KEY_CTRL_UP);
    keyboardReader->registerKey(this,KEY_CTRL_DOWN);
    keyboardReader->registerKey(this,KEY_CTRL_LEFT);
    keyboardReader->registerKey(this,KEY_CTRL_RIGHT);
}

void DotObject::deinit()
{
    networkHandler->unregisterHandler(this,0x1);
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

void DotObject::keyHandler(int keyId, int keyStatus)
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
    data[0] = x;
    data[1] = y;
    Buffer toSend(data,2);
    networkHandler->sendMessage(0x1,&toSend);
}

void DotObject::tick()
{
}

void DotObject::render()
{
    //printf("Render %d %d\n",x,y);
	renderer->drawPoint(Coord(x,y),true);
}

void DotObject::setup(Renderer * newRenderer, NetworkHandler * newNetworkHandler, KeyboardReader * newKeyboardReader)
{
    renderer = newRenderer;
    networkHandler = newNetworkHandler;
    keyboardReader = newKeyboardReader;
}