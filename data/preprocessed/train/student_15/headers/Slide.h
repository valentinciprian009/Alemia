#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <fstream>

class Slide
{
protected:
	UserInterface::ConsoleOutput conOut;
	UserInterface::ConsoleInput conIn;

public:
	bool active;
	Slide* next;

public:
	static void drawAsciiArt(std::string file, UserInterface::ConsoleOutput conOut, int y, int x);
	static void drawBox(UserInterface::ConsoleOutput conOut, int x, int y, int w, int h);
	static void drawHline(UserInterface::ConsoleOutput conOut, int y, int xs = -1, int xe = -1, char c='=');
	static void drawVline(UserInterface::ConsoleOutput conOut, int x, int ys = -1, int ye = -1, char c='|');
	static void clearZone(UserInterface::ConsoleOutput conOut, int startX = 0, int startY = 0, int endX=-1, int endY=-1);

	Slide(bool clear);
	virtual void update() = 0;
	virtual void reinit() = 0;
	~Slide() {};
};
