#pragma once

struct point 
{ 
	int x, y; 

	point operator+(const point& other)
	{
		return point{ this->x + other.x, this->y + other.y };
	}
	point operator*(const int& scalar)
	{
		return point{ this->x * scalar, this->y * scalar };
	}
	bool operator==(const point& other)
	{
		return this->x == other.x && this->y == other.y;
	}

	point() : x(0), y(0) {};
	point(int X, int Y) : x(X), y(Y) {};
};