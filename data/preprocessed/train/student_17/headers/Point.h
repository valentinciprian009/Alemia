#pragma once
class Point
{
	int x;
	int y;
public:
	Point();
	Point(int x, int y);
	~Point();
	int getx();
	int gety();
	friend class Container;
	friend class SegmentedContainer;
	void operator()(int x, int y);
};

