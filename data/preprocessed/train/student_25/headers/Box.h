#pragma once
#include "ConsoleOutput.h"

#define CHR_STANGA_SUS 201
#define CHR_STANGA_JOS 200
#define CHR_DREAPTA_SUS 187
#define CHR_DREAPTA_JOS 188
#define CHR_BARA_VERTICALA 186
#define CHR_BARA_ORIZONTALA 205



struct Point
{
	int x;
	int y;
	Point() {};
	Point(int x, int y) :x(x), y(y) {};
};


class Box
{
	Point upper_point;
	Point lower_point;
public:
	Box();
	Box(int x1, int y1, int x2, int y2) :upper_point(x1, y1), lower_point(x2, y2) {};
	void Draw();
	~Box();
};

