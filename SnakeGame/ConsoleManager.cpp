#include "ConsoleManager.h"
#include "Coordinate.h"
#include <conio.h>
#include <Windows.h>

void ConsoleManager::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleManager::txtPlot(point item, unsigned char Color)
{
    setcolor(Color);
    gotoxy(item.x * 2, item.y);
    _cprintf("  ");
}

void ConsoleManager::setcolor(unsigned char color)
{
    WORD Color = static_cast<WORD>(color);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ConsoleManager::DisplayLength(const point Bounds, const int Value)
{
    setcolor(7);
    gotoxy(0, Bounds.y);
    _cprintf("Length: %d", Value);
}

