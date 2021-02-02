#include "SegmentedContainer.h"



SegmentedContainer::SegmentedContainer(Point &p1, Point &p2, Point &p3, Point &p4)
{
	this->corner1 = p1;
	this->corner2 = p2;
	this->corner3 = p3;
	this->corner4 = p4;
}


SegmentedContainer::~SegmentedContainer()
{
}

void SegmentedContainer::doRows(UserInterface::ConsoleOutput &conOut, int distance) {
	int temprow = corner1.y + distance;
	while (temprow < corner3.y) {
		for (int horiz = corner1.x+1; horiz < corner2.x; horiz++)
			conOut(temprow, horiz) << "-"; 
		temprow = temprow + distance;
		nrRepereVer++;
	}
}

void SegmentedContainer::doCols(UserInterface::ConsoleOutput &conOut, int distance) {
	int tempcol = corner1.x + distance;
	while (tempcol < corner2.x) {
		for (int ver = corner1.y + 1; ver < corner3.y; ver++) {
			conOut(ver, tempcol) << "|";
		}
		tempcol = tempcol + distance;
		nrRepereOriz++;
	}
}

int SegmentedContainer::getnrRepereOriz() {
	return nrRepereOriz;
}

int SegmentedContainer::getnrRepereVer() {
	return nrRepereVer;
}

Point& SegmentedContainer::getCorner1() {
	return corner1;
}

Point& SegmentedContainer::getCorner2() {
	return corner2;
}