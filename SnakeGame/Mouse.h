#pragma once
#include "Coordinate.h"

class Mouse
{
private:
	point Location;
	point Bounds;
public:
	Mouse() = default;
	Mouse(const point bounds);
	void Move();
};

