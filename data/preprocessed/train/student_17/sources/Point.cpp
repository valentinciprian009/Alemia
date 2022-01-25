#include "Point.h"

Point::Point()
{
}


Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}


Point::~Point()
{
}


int Point::getx() {
	return this->x;
}

int Point::gety() {
	return this->y;
}

void Point::operator()(int x, int y) {
	this->x = x;
	this->y = y;
}