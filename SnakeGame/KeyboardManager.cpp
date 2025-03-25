#include "KeyboardManager.h"
#include <conio.h>

#define key_W 119
#define key_A 97
#define key_S 115 
#define key_D 100 
#define key_UP 72
#define key_DOWN 80
#define key_LEFT 75
#define key_RIGHT 77
#define key_ESCAPE 27

const KeyCommand KeyboardManager::GetKeyPress()
{
    if (_kbhit())
    {
        int keypress = _getch();
        switch (keypress)
        {
        case key_A:
        case key_LEFT: return KeyCommand::Left;
        case key_D:
        case key_RIGHT: return KeyCommand::Right;
        case key_W:
        case key_UP: return KeyCommand::Up;
        case key_S:
        case key_DOWN: return KeyCommand::Down;
        case key_ESCAPE: return KeyCommand::Quit;
        default: return KeyCommand::None;
        }
    }

    return KeyCommand::None;
}
