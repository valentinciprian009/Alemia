#pragma once
class Point
{
	int x, y;
public:
	Point() = delete;
	Point(int x, int y) : x(x), y(y) {}
	Point(const Point&) = delete;
	Point& operator=(const Point&) = delete;
	~Point(){}

	void setX(int newX)
	{
		x = newX;
	}
	void setY(int newY)
	{
		y = newY;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void setXY(int newX, int newY)
	{
		x = newX;
		y = newY;
	}
};

