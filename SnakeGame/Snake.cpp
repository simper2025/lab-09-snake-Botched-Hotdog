#include "Snake.h"
#include "ConsoleManager.h"
Snake::Snake(const unsigned char BodyCol, const unsigned char HeadCol, const point StartLoc)
{
	BodyColor = BodyCol;
	HeadColor = HeadCol;

	Body.push_back(StartLoc);
}

void Snake::Move(const KeyCommand Direction)
{
	int ArraySize = Body.size();

	for (int i = 0; i < ArraySize; i++)
	{
		if (i == ArraySize - 1) // Head
		{
			point NewDirection;
			switch (Direction)
			{
			case KeyCommand::Up:
				NewDirection = { 0, -1 };
				break;
			case KeyCommand::Down:
				NewDirection = { 0, 1 };
				break;
			case KeyCommand::Left:
				NewDirection = { -1, 0 };
				break;
			case KeyCommand::Right:
				NewDirection = { 1, 0 };
				break;
			default:
				break;
			}
			Body[i] + NewDirection;

			ConsoleManager::txtPlot(Body[i], HeadColor);
		}
		else // Body
		{
			Body[i] = Body[i + 1];
			ConsoleManager::txtPlot(Body[i], BodyColor);
		}	
	}
}
