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
    Bounds = BoundsSize;
    LastKeyPress = KeyCommand::Right;

    MouseObj = Mouse(BoundsSize);
    SnakeObj = Snake(170, 34, { BoundsSize.x / 2, BoundsSize.y / 2 });
}

void GameManager::DrawBoard()
{
    for (int i = 0; i < Bounds.x + 2; i++)
    {
        if (i == 0 || i == Bounds.x + 1)
        {
            for (int ii = 0; ii < Bounds.y + 2; ii++)
            {
                ConsoleManager::txtPlot({ i, ii }, 82);
            }
        }
        else
        {
            for (int ii = 0; ii < Bounds.y + 2; ii++)
            {
                if (ii == 0 || ii == Bounds.y + 1)
                {
                    ConsoleManager::txtPlot({ i, ii }, 82);
                }
                //else
                //{
                //    EmptyPeice.Location = { i, ii };
                //    ConsoleManager::DrawAtPoint(EmptyPeice);
                //}
            }
        }
    }
}

void GameManager::RunGame()
{
    chrono::time_point<chrono::system_clock> runTime;
    chrono::time_point<chrono::system_clock> currentTime;
    runTime = std::chrono::system_clock::now();

    Sleep(300);
    DrawBoard();

    while (bContinueGame)
    {
        KeyCommand CurrentKeyInput = KeyboardManager::GetKeyPress();

        switch (CurrentKeyInput)
        {
        case KeyCommand::Quit:
            bContinueGame = false;
            break;

        case KeyCommand::None: break;

        default: LastKeyPress = CurrentKeyInput;
        }

        currentTime = chrono::system_clock::now();

        double elapsedTime = chrono::duration_cast<chrono::milliseconds>(currentTime - runTime).count();
        if (elapsedTime > 0.3 * 1000) {
            runTime = chrono::system_clock::now();

            bool AteMouse = SnakeObj.Move(MouseObj.GetPosition(), LastKeyPress);
            if (AteMouse)
            {
                MouseObj.Move();
            }

            if (SnakeObj.DidSnakeCollide(Bounds))
            {
                bContinueGame = false;
            }

            ConsoleManager::DisplayLength(Bounds, SnakeObj.GetSnakeSize());
        }


        Sleep(10);
    }
}