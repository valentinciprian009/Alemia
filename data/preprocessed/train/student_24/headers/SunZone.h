#pragma once
#include "iDrawable.h"
#include "ContainerRectangle.h"
#include "Sun.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

class SunZone :
	public iDrawable
{
private:
	std::vector<ContainerRectangle<iResource*>*> sunRectangles;
	const int count = 9;
	void printInteriors() const;

public:
	SunZone();
	~SunZone() {}

	void generateSun(const int& val);
	bool isInside(int x, int y); 
	void print() const override;
};

