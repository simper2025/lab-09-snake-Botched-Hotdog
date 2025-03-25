#pragma once
#include "KeyCommands.h"
#include "Snake.h"
#include "Mouse.h"

struct point;


class GameManager
{
private:
	bool bContinueGame;
	float RefreshRate;
	KeyCommand LastKeyPress;

	Snake SnakeObj;
	Mouse MouseObj;
	point Bounds;

public:
	GameManager(const float refreshrate, const point BoundsSize);
	void DrawBoard();

	void RunGame();
	_inline bool ShouldContinueGame() const { return bContinueGame; };
};

