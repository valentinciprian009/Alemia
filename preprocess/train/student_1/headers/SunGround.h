#pragma once
#include"GroundRow.h"

class SunGround : public Entity
{
private:
	vector<GroundCell> sunRow;
	float timeInterval;
public:
	SunGround() : Entity(), timeInterval() { ; }
	SunGround(int row_ul, int col_ul, int nr_cells, float time_int) : Entity(row_ul, col_ul), timeInterval(time_int)
	{
		for (int i = 0; i < nr_cells; i++)
			sunRow.push_back(GroundCell(row_ul, col_ul + 13 * i));
	}
	//SunGround(int row_ul, int col_ul, int nr_cells, float time_int);
	GroundCell& operator[](int index) { return sunRow[index]; }
	void print();
	void reduceTimeInterval(float rate) { timeInterval *= rate; Log::getInstance().write("Sun appearance interval reduced!"); }
	float getTimeInterval() { return timeInterval; }
	void createSuns();
	int takeSun();
};