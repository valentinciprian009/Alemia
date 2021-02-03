#pragma once
#include "Container.h"
class SegmentedContainer :
	public Container
{
	int nrRepereOriz=1;
	int nrRepereVer=1;
public:
	SegmentedContainer(Point &p1, Point &p2, Point &p3, Point &p4);
	~SegmentedContainer();
	void doRows(UserInterface::ConsoleOutput &conOut, int distance);
	void doCols(UserInterface::ConsoleOutput &conOut, int distance);
	int getnrRepereOriz();
	int getnrRepereVer();
	Point& getCorner1();
	Point& getCorner2();
};

