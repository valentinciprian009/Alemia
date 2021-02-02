#pragma once
#include"Entity.h"

class GroundCell: public Entity
{
protected:
	int type;	//	0 - empty,	1 - Peashooter,	2 - Sunflower,	3 - Cherry Bomb,	4 - Wall-nut,	5 - Snow Pea,	6 - Sun
public:
	GroundCell() : Entity(), type() { ; }
	GroundCell(int row_ul, int col_ul) : Entity(row_ul, col_ul), type() { ; }
	GroundCell(int row_ul, int col_ul, int tip) : Entity(row_ul, col_ul), type(tip) { ; }
	void changeType(int type) { this->type = type; print(); }
	int getType() const { return type; }
	void clearCell();
	void print();
	bool checkInCell(const ConsoleEvent& action);
};