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
	point LastDirection;

public:
	Snake() = default;
	Snake(const unsigned char BodyCol, const unsigned char HeadCol, const point StartLoc);

	bool Move(const point MousePos, const KeyCommand Direction);
	bool DidSnakeCollide(const point Bounds);
	inline const int GetSnakeSize() const { return Body.size(); };
};

