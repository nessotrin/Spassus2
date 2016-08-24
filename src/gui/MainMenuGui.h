#ifndef _MAIN_MENU_GUI_H_
#define _MAIN_MENU_GUI_H_

#include "GuiBase.h"

#include <world/object/DotObject.h>

class MainMenuGui : GuiBase
{
    DotObject dot;
    char choice;
    bool validated = false;
    NetworkHandler * netHandler = NULL;
    
    
public:
    void init(KeyboardReader * keyboardReader);
    void deinit(KeyboardReader * keyboardReader);
    void setNetHandler(NetworkHandler * newNetHandler);
    void render(Screen * screen);
    void keyHandler(unsigned short keyId, bool keyStatus);
    bool isValidated();
    char getChoice();
};

#endif // _MAIN_MENU_GUI_H_
