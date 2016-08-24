#ifndef _DOT_OBJECT_H_
#define _DOT_OBJECT_H_

#include "Object.h"

#include "network/NetworkEventReceiver.h"
#include "network/NetworkHandler.h"
#include "keyboard/KeyboardReader.h"

class DotObject  : public Object, public NetworkEventReceiver, public KeyEventReceiver
{
private:
	int x;
	int y;
    NetworkHandler * networkHandler;
    KeyboardReader * keyboardReader;
    
public:

    void init();
    void deinit();
    
    void networkEventHandler(unsigned char type, Buffer * data);
    void keyHandler(unsigned short keyId, bool keyStatus);
    
	void tick();
    void render(Screen * screen);
    void setup(NetworkHandler * newNetworkHandler, KeyboardReader * newKeyboardReader);
};

#endif // _DOT_OBJECT_H_
