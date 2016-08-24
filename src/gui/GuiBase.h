#ifndef _GUI_BASE_H_
#define _GUI_BASE_H_

#include <keyboard/KeyEventReceiver.h>
#include <keyboard/KeyboardReader.h>
#include <render/Screen.h>

class GuiBase : public KeyEventReceiver
{
private:    
    virtual void init(KeyboardReader * keyboardReader) = 0;
    virtual void deinit(KeyboardReader * keyboardReader) = 0;
    virtual void render(Screen * screen) = 0;
};

#endif // _GUI_BASE_H_
