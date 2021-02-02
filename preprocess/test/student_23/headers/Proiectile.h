#pragma once
#include "IDrawable.h"
#include "GAME.h"

using namespace chrono;

class Proiectile :private IDrawable
{
private:
	int theProiectile;
	steady_clock::time_point printedTime;
public:
	Proiectile(int theChar, int x, int y) :IDrawable(x, y) { this->theProiectile = theChar; printedTime = steady_clock::now();};
	~Proiectile() { UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance(); HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(color, 7); conOut(x, y); cout << " "; };
	void setX(int x) { this->x = x; };
	void setY(int y) { this->y = y; };
	int getX() { return this->x; };
	int getY() { return this->y; };
	void printTheProiectile(int colour);
	void moveProiectile(int colour);
	bool testTime(int time);
};