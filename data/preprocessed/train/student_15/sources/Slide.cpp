#include "Slide.h"

void Slide::drawAsciiArt(std::string file, UserInterface::ConsoleOutput conOut, int y, int x)
{
	std::ifstream fin(file);
	std::string line;
	int w, h;
	fin >> h >> w;
	std::getline(fin, line);
	if (y == -1)
		y = (conOut.height() - h) / 2;
	if (x == -1)
		x = (conOut.width() - w) / 2;
	for (int i = 0; i < h; i++)
	{
		std::getline(fin, line);
		if (x + w > conOut.width())
			line = line.substr(0, conOut.width() - x);
		conOut(y + i, x) << line;
	}
}

void Slide::drawBox(UserInterface::ConsoleOutput conOut, int x, int y, int w, int h)
{
	w++, h++;
	conOut(y, x) << "O";
	conOut(y, x + w) << "O";
	conOut(y + h, x) << "O";
	conOut(y + h, x + w) << "O";
	for (int i = x + 1; i < x + w; i++)
	{
		conOut(y, i) << "-";
		conOut(y + h, i) << "-";
	}
	for (int i = y + 1; i < y + h; i++)
	{
		conOut(i, x) << "|";
		conOut(i, x + w) << "|";
	}
}

void Slide::drawHline(UserInterface::ConsoleOutput conOut, int y, int xs, int xe, char c)
{
	if (xs == -1) xs = 0;
	if (xe == -1) xe = conOut.width()-1;
	std::string s(xe - xs + 1, c);
	conOut(y, xs) << s;
	conOut(0, 0) << "";
}

void Slide::drawVline(UserInterface::ConsoleOutput conOut, int x, int ys, int ye, char c)
{
	if (ys == -1) ys = 0;
	if (ye == -1) ye = conOut.height()-1;
	for (int i = ys; i <= ye; i++)
		conOut(i, x) << c;
	conOut(0, 0) << "";
}

void Slide::clearZone(UserInterface::ConsoleOutput conOut, int startX, int startY, int endX, int endY)
{
	if (endX == -1)
		endX = conOut.width() - 1;
	if (endY == -1)
		endY = conOut.height() - 1;
	std::string s(endX - startX + 1, ' ');
	for (int i = startY; i <= endY; i++)
		conOut(i, startX) << s;
	conOut(0, 0) << "";
}

Slide::Slide(bool clear) :
	conOut(UserInterface::ConsoleOutput::getInstance()),
	conIn(UserInterface::ConsoleInput::getInstance())
{
	active = true;
	next = nullptr;
	if (clear)
		clearZone(conOut, 0, 0, conOut.width() - 1, conOut.height() - 1);
};