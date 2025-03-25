#include "GameManager.h"
#include "KeyboardManager.h"
#include "Coordinate.h"
#include "ConsoleManager.h"

#include <chrono>
#include <windows.h>

using namespace std;

GameManager::GameManager(const float refreshrate, const point BoundsSize)
{
    bContinueGame = true;
    RefreshRate = refreshrate;
    LastKeyPress = KeyCommand::Right;

    MouseObj = Mouse(BoundsSize);
    SnakeObj = Snake(179, 34, { BoundsSize.x / 2, BoundsSize.y / 2 });
}

void GameManager::RunGame()
{
    chrono::time_point<chrono::system_clock> runTime;
    chrono::time_point<chrono::system_clock> currentTime;
    runTime = std::chrono::system_clock::now();
    Sleep(300);


    KeyCommand CurrentKeyInput = KeyboardManager::GetKeyPress();
    
    switch (CurrentKeyInput)
    {
    case KeyCommand::Quit:
        bContinueGame = false; 
        return;

    case KeyCommand::None: break;

    default: LastKeyPress = CurrentKeyInput;
    }

    currentTime = chrono::system_clock::now();

    double elapsedTime = chrono::duration_cast<chrono::milliseconds>(currentTime - runTime).count();
    if (elapsedTime > 0.3 * 1000) {
        runTime = chrono::system_clock::now();

        //Most of your game logic goes here.

        SnakeObj.Move(LastKeyPress);

        ConsoleManager::DisplayLength(SnakeObj.GetSnakeSize());
    }

    Sleep(10);
}