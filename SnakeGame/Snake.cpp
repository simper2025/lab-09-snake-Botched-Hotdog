#include "Snake.h"
#include "ConsoleManager.h"
Snake::Snake(const unsigned char BodyCol, const unsigned char HeadCol, const point StartLoc)
{
	BodyColor = BodyCol;
	HeadColor = HeadCol;

	Body.push_back(StartLoc);
}

bool Snake::Move(const point MousePos, const KeyCommand Direction)
{
	int ArraySize = Body.size();
	point OldPos;
	bool bAteMouse = false;

	for (int i = 0; i < ArraySize; i++)
	{
		point LastPos = Body[i];
		
		if (i == 0) // Head
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
			if (NewDirection * -1 == LastDirection)
			{
				NewDirection = LastDirection;
			}

			Body[i] = Body[i] + NewDirection;
			LastDirection = NewDirection;

			if (Body[i] == MousePos) bAteMouse = true;

			ConsoleManager::txtPlot(Body[i] + point{1,1}, HeadColor);
		}
		else // Body
		{		
			Body[i] = OldPos;
			ConsoleManager::txtPlot(Body[i] + point{ 1,1 }, BodyColor);
		}

		if (i == ArraySize - 1) // End of Body
		{
			if (bAteMouse)
			{
				point TailPiece = LastPos;
				Body.push_back(TailPiece);
			}
			else
			{
				ConsoleManager::txtPlot(LastPos + point{ 1,1 }, 7);
			}
		}

		OldPos = LastPos;
	}

	return bAteMouse;
}

bool Snake::DidSnakeCollide(const point Bounds)
{
	point Head = Body[0];
	
	bool OutOfBounds_X = Head.x < 0 || Head.x >= Bounds.x;
	bool OutOfBounds_Y = Head.y < 0 || Head.y >= Bounds.y;
	bool HitItself = false;


	// start at 1 to skip head
	for (int i = 1; i < Body.size(); i++)
	{
		if (Head == Body[i])
		{
			HitItself = true;
			break;
		}

	}

	return OutOfBounds_X || OutOfBounds_Y || HitItself;
}
