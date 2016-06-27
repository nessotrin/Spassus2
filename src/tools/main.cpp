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

#include <CalcuLib.h>

#include <MonochromeLib.h>

#include <tools/GameInstance.h>

#include "MainMenu.h"

#include "network/PinSocket.h"

#include "memory/tests/ListTests.h"
#include "memory/tests/BufferOrganizerTests.h"

#include "network/QuickProtocol/QuickProtocol.h"


#ifndef CALCULIB
int main(int isAppli, unsigned short OptionNum)
#else
int main()

#endif
{
    initCalcuLib(0,5);
    int calcKey[] = {KEY_CTRL_UP,      KEY_CTRL_DOWN,      KEY_CTRL_EXE,         KEY_CTRL_LEFT,      KEY_CTRL_RIGHT};
    #ifdef CALCULIB
	int sfmlKey[] = {sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Return, sf::Keyboard::Left, sf::Keyboard::Right};
    registerKeys(calcKey,sfmlKey,5);
    #endif
    locate(1,1);
    
    Print((const unsigned char *)"Spassus2");
    locate(1,2);
    
    Renderer globalRenderer;
    Screen calcScreen(Coord(128,64),(unsigned char *)ML_vram_adress());
    KeyboardReader globalKeyboardReader;
    
    globalRenderer.setScreen(&calcScreen);

    testList();
    testBufferOrganizer();
    
    QuickProtocol testProtocol;
    PinSocket socket;
    testProtocol.setSocket(&socket);
    
    
    unsigned char testBufferData[64];
    Buffer testBuffer(testBufferData,64);
    
    printf("SENDING...\n");
    if(testProtocol.sendMessage(0x55,&testBuffer,1000))
    {
        printf("ERROR !\n");
    }
    else
    {
        printf("DONE...\n");        
    }
    
    
    MainMenu mainMenu;
    mainMenu.setupMenu(&globalRenderer, &globalKeyboardReader);

    char choice = mainMenu.loopMenu();

    if(choice == MainMenu::mainMenuAction::START_GAME)
    {
        GameInstance gameInstance(&globalRenderer, &globalKeyboardReader);
        gameInstance.run();
    }


    return 0;
}
