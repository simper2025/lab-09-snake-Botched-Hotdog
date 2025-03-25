#pragma once

struct point 
{ 
	int x, y; 

	point operator+(const point& other)
	{
		return point{ this->x + other.x, this->y + other.y };
	}

	point() : x(0), y(0) {};
	point(int X, int Y) : x(X), y(Y) {};
};