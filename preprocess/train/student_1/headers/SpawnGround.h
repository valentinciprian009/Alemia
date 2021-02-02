#pragma once
#include <vector>
#include "GroundCell.h"

class SpawnGround : public Entity //pentru plante
{
private:
	vector<GroundCell> spawn;
	int plantSelected;	//0 - no plant, 1-5 plants
public:
	SpawnGround() : Entity(), spawn(), plantSelected() { ; }
	SpawnGround(int row_ul, int col_ul);
	void print();
	void selectPlant();
	int getSelectedPlant() { return plantSelected; }
	GroundCell& operator[](int index) { return spawn[index]; }
};