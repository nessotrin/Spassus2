#ifndef _DOT_OBJECT_H_
#define _DOT_OBJECT_H_

#include "Object.h"

#include "network/NetworkEventReceiver.h"
#include "render/Renderer.h"
#include "network/NetworkHandler.h"
#include "keyboard/KeyboardReader.h"

class DotObject  : public Object, public NetworkEventReceiver, public KeyEventReceiver
{
private:
	int x;
	int y;
    Renderer * renderer;
    NetworkHandler * networkHandler;
    KeyboardReader * keyboardReader;
    
public:

    void init();
    void deinit();
    
    void networkEventHandler(unsigned char type, Buffer * data);
    void keyHandler(int keyId, int keyStatus);
    
	void tick();
    void render();
    void setup(Renderer * newRenderer, NetworkHandler * newNetworkHandler, KeyboardReader * newKeyboardReader);
};

#endif // _DOT_OBJECT_H_
