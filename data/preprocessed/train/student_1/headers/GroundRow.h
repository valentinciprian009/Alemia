#pragma once
#include<vector>
#include"GroundCell.h"

class GroundRow : public Entity
{
protected:
	vector<GroundCell> row;
public:
	GroundRow() : Entity(), row() { ; }
	GroundRow(int row_ul, int col_ul, int nr_cells);
	virtual void print();
	vector<GroundCell> getRowVector() { return row; }
	GroundCell& operator[](int index) { return row[index]; }
};