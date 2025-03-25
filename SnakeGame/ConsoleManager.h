#pragma once
struct point;

class ConsoleManager
{
public:
   static void gotoxy(int x, int y);
   static void txtPlot(point item, unsigned char Color);
   static void setcolor(unsigned char color);
   static void DisplayLength(const point Bounds, const int Value);
};

