#pragma once
#include "Point.h"
#include "ConsoleOutput.h"

class Container
{
	Point corner1;
	Point corner2;
	Point corner3;
	Point corner4;
public:
	Container();
	Container(Point &p1, Point &p2, Point &p3, Point &p4); //ar trebui sa pun si conout la parametrii
	~Container();
	void doMargin(UserInterface::ConsoleOutput &conOut);
	friend class SegmentedContainer;
	Point& getCorner1();
};

