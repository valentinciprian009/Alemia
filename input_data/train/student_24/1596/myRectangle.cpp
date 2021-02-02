#pragma warning(push)
#pragma warning (disable : 4309)
#include "myRectangle.h"

myRectangle::myRectangle(int x, int y) :
	coordAX(x),
	coordAY(y),
	coordBX(x),
	coordBY(y + dimY),
	coordCX(x + dimX),
	coordCY(y + dimY),
	coordDX(x + dimX),
	coordDY(y),
	Entity(x, y)
{}

void myRectangle::print() const
{
	const char culcat = 205;
	const char inPicioare = 186;
	const char coltStangaSus = 201;
	const char coltDreaptaSus = 187;
	const char coltStangaJos = 200;
	const char coltDreaptaJos = 188;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

//	conOut.setColor(15);

	conOut(coordAX, coordAY) << coltStangaSus;
	conOut(coordDX, coordDY) << coltStangaJos;
	conOut(coordCX, coordCY) << coltDreaptaJos;
	conOut(coordBX, coordBY) << coltDreaptaSus;

	for (int i = coordAY + 1; i < coordBY; i++)
	{
		conOut(coordAX, i) << culcat;
		conOut(coordDX, i) << culcat;
	}

	for (int i = coordAX + 1; i < coordCX; i++)
	{
		conOut(i, coordAY) << inPicioare;
		conOut(i, coordBY) << inPicioare;
	}
	
}

void myRectangle::printColtStangaSus(int color) const
{
	const char culcat = 205;
	const char inPicioare = 186;
	const char coltStangaSus = 201;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(color);

	conOut(coordAX, coordAY) << coltStangaSus;

	for (int i = coordAY + 1; i < coordBY; i++)
	{
		conOut(coordAX, i) << culcat;
	}

	for (int i = coordAX + 1; i < coordCX; i++)
	{
		conOut(i, coordAY) << inPicioare;
	}

}

void myRectangle::printSusInterior(int color) const
{
	const char culcat = 205;
	const char inPicioare = 186;
	const char coltStangaSus = 203;
	const char coltDreaptaJos = 202;
	const char coltDreaptaSus = 203;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(color);

	conOut(coordAX, coordAY) << coltStangaSus;
	conOut(coordCX, coordCY) << coltDreaptaJos;
	conOut(coordBX, coordBY) << coltDreaptaSus;

	for (int i = coordAY + 1; i < coordBY; i++)
	{
		conOut(coordAX, i) << culcat;
		conOut(coordDX, i) << culcat;
	}

	for (int i = coordAX + 1; i < coordCX; i++)
	{
		conOut(i, coordAY) << inPicioare;
	}

}

void myRectangle::printInterior(int color) const
{
	const char culcat = 205;
	const char inPicioare = 186;
	const char coltStangaSus = 206;
	const char coltDreaptaSus = 206;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(color);

	conOut(coordAX, coordAY) << coltStangaSus;
	conOut(coordBX, coordBY) << coltDreaptaSus;

	for (int i = coordAY + 1; i < coordBY; i++)
	{
		conOut(coordAX, i) << culcat;
	}

	for (int i = coordAX + 1; i < coordCX; i++)
	{
		conOut(i, coordAY) << inPicioare;
	}
}

void myRectangle::printColtDreaptaSus(int color) const
{
	const char culcat = 205;
	const char inPicioare = 186;
	const char coltDreaptaSus = 187;
	const char coltStangaSus = 203;


	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(color);
	conOut(coordBX, coordBY) << coltDreaptaSus;
	conOut(coordAX, coordAY) << coltStangaSus;

	for (int i = coordAY + 1; i < coordBY; i++)
	{
		conOut(coordAX, i) << culcat;
	}

	for (int i = coordAX + 1; i < coordCX; i++)
	{
		conOut(i, coordBY) << inPicioare;
		conOut(i, coordAY) << inPicioare;
	}
}

void myRectangle::printJosInterior(int color) const
{
	const char culcat = 205;
	const char inPicioare = 186;
	const char coltDreaptaSus = 206;
	const char coltDreaptaJos = 202;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(color);

	conOut(coordCX, coordCY) << coltDreaptaJos;
	conOut(coordBX, coordBY) << coltDreaptaSus;

	for (int i = coordAY + 1; i < coordBY; i++)
	{
		conOut(coordAX, i) << culcat;
		conOut(coordDX, i) << culcat;
	}

	for (int i = coordAX + 1; i < coordCX; i++)
	{
		conOut(i, coordAY) << inPicioare;
	}
	
}

void myRectangle::printColtStangaJos(int color) const
{
	const char culcat = 205;
	const char inPicioare = 186;
	const char coltStangaSus = 204;
	const char coltDreaptaSus = 206;
	const char coltStangaJos = 200;
	const char coltDreaptaJos = 202;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(color);

	conOut(coordAX, coordAY) << coltStangaSus;
	conOut(coordDX, coordDY) << coltStangaJos;
	conOut(coordCX, coordCY) << coltDreaptaJos;
	conOut(coordBX, coordBY) << coltDreaptaSus;

	for (int i = coordAY + 1; i < coordBY; i++)
	{
		conOut(coordAX, i) << culcat;
		conOut(coordDX, i) << culcat;
	}

	for (int i = coordAX + 1; i < coordCX; i++)
	{
		conOut(i, coordAY) << inPicioare;
	}
}

void myRectangle::printColtDreaptaJos(int color) const
{
	const char culcat = 205;
	const char inPicioare = 186;
	const char coltDreaptaSus = 185;
	const char coltStangaJos = 202;
	const char coltDreaptaJos = 188;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(color);

	conOut(coordDX, coordDY) << coltStangaJos;
	conOut(coordCX, coordCY) << coltDreaptaJos;
	conOut(coordBX, coordBY) << coltDreaptaSus;

	for (int i = coordAY + 1; i < coordBY; i++)
	{
		conOut(coordAX, i) << culcat;
		conOut(coordDX, i) << culcat;
	}

	for (int i = coordAX + 1; i < coordCX; i++)
	{
		conOut(i, coordAY) << inPicioare;
		conOut(i, coordBY) << inPicioare;
	}
}

void myRectangle::printStangaInterior(int color) const
{
	const char culcat = 205;
	const char inPicioare = 186;
	const char coltStangaSus = 204;
	const char coltDreaptaSus = 206;
	const char coltStangaJos = 204;
	const char coltDreaptaJos = 206;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(color);

	conOut(coordAX, coordAY) << coltStangaSus;
	conOut(coordDX, coordDY) << coltStangaJos;
	conOut(coordCX, coordCY) << coltDreaptaJos;
	conOut(coordBX, coordBY) << coltDreaptaSus;

	for (int i = coordAY + 1; i < coordBY; i++)
	{
		conOut(coordAX, i) << culcat;
		conOut(coordDX, i) << culcat;
	}

	for (int i = coordAX + 1; i < coordCX; i++)
	{
		conOut(i, coordAY) << inPicioare;
		conOut(i, coordBY) << inPicioare;
	}
}

void myRectangle::printDreaptaInterior(int color) const
{
	const char culcat = 205;
	const char inPicioare = 186;
	const char coltStangaSus = 206;
	const char coltDreaptaSus = 185;
	const char coltStangaJos = 206;
	const char coltDreaptaJos = 185;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(color);

	conOut(coordAX, coordAY) << coltStangaSus;
	conOut(coordDX, coordDY) << coltStangaJos;
	conOut(coordCX, coordCY) << coltDreaptaJos;
	conOut(coordBX, coordBY) << coltDreaptaSus;

	for (int i = coordAY + 1; i < coordBY; i++)
	{
		conOut(coordAX, i) << culcat;
		conOut(coordDX, i) << culcat;
	}

	for (int i = coordAX + 1; i < coordCX; i++)
	{
		conOut(i, coordAY) << inPicioare;
		conOut(i, coordBY) << inPicioare;
	}

}

void myRectangle::erase() const
{
	for (int i = coordAY + 1; i < coordBY; i++)
	{
		for (int j = coordAX + 1; j < coordCX; j++)
		{
			UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
			conOut(j, i) << " ";
		}
	}
}

int myRectangle::getDimX() const { return dimX; }
int myRectangle::getDimY() const { return dimY; }
int myRectangle::getX() const { return coordAX; }
int myRectangle::getY() const { return coordAY; }
int myRectangle::getBXcoord() const { return coordBX; }
int myRectangle::getCXcoord() const { return coordBY; }
int myRectangle::getDXcoord() const { return coordDX; }
int myRectangle::getBYcoord() const { return coordBY; }
int myRectangle::getCYcoord() const { return coordCY; }
int myRectangle::getDYcoord() const { return coordDY; }

bool myRectangle::isInside(int x, int y) const
{
	if ((x >= coordAX) && (x <= coordCX))
	{
		if ((y >= coordAY) && (y <= coordBY))
		{
			return true;
		}
	}

	return false;
}

#pragma warning (pop)