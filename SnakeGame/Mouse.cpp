#include "Mouse.h"
#include "ConsoleManager.h"
#include <random>
#include <ctime>

Mouse::Mouse(const point bounds)
{
	srand(time(0));
	Bounds = bounds;
	Move();
}

void Mouse::Move()
{
	Location.x = std::rand() % Bounds.x;
	Location.y = std::rand() % Bounds.y;

	ConsoleManager::txtPlot(Location, 69); // Draw Red Square
}
