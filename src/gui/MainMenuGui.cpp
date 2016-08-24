#include "MainMenuGui.h"

void MainMenuGui::init(KeyboardReader * keyboardReader)
{
    printf("Init main menu\n");
    
    if(netHandler == NULL)
    {
        printf("Warning, netHandler must be set before init ! (hacky dev' structure) \n");
    }
    dot.setup(netHandler,keyboardReader);
    dot.init();
    
    keyboardReader->registerKey(this,KEY_CTRL_UP);
    keyboardReader->registerKey(this,KEY_CTRL_DOWN);
    keyboardReader->registerKey(this,KEY_CTRL_EXE);
}

void MainMenuGui::deinit(KeyboardReader * keyboardReader)
{
    printf("Deinit main menu\n");
    
    dot.deinit();
    
    keyboardReader->unregisterKey(this,KEY_CTRL_UP);
    keyboardReader->unregisterKey(this,KEY_CTRL_DOWN);
    keyboardReader->unregisterKey(this,KEY_CTRL_EXE);
}

void MainMenuGui::render(Screen * screen)
{
    dot.render(screen);
}

void MainMenuGui::keyHandler(unsigned short keyId, bool keyStatus)
{
    if(keyStatus == false)
    {
        return;
    }
    
    if(keyId == KEY_CTRL_UP)
    {
        choice--;
    }
    if(keyId == KEY_CTRL_DOWN)
    {
        choice--;
    }
    if(keyId == KEY_CTRL_EXE)
    {
        validated = true;
    }
}

bool MainMenuGui::isValidated()
{
    return validated;
}

char MainMenuGui::getChoice()
{
    return choice;
}

void MainMenuGui::setNetHandler(NetworkHandler * newNetHandler)
{
    netHandler = newNetHandler;
}