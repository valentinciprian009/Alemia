#pragma once
#include"GroundRow.h"

class Ground : public Entity
{
protected:
	vector<GroundRow> ground;
	int rowCount;	//1, 3, or 5
	int columnCount;	//8
public:
	Ground() : Entity(), rowCount(), columnCount(), ground() { ; }
	Ground(int row_ul, int col_ul, int nr_row, int nr_cols);
	GroundRow& operator[](int index) { return ground[index]; }
	void modifyCellType(int i, int j, int type) { ground[i][j].changeType(type); ground[i][j].print(); }
	bool plantFlower(int type, int& row, int& col);
	void print();
};