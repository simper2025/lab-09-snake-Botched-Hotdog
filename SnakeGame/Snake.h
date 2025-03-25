#pragma once
#include <vector>
#include "Coordinate.h"
#include "KeyCommands.h"

class Snake
{
private:
	std::vector<point> Body;
	unsigned char BodyColor;
	unsigned char HeadColor;

public:
	Snake() = default;
	Snake(const unsigned char BodyCol, const unsigned char HeadCol, const point StartLoc);

	void Move(const KeyCommand Direction);

	__inline const int GetSnakeSize() const { return Body.size(); };
};

