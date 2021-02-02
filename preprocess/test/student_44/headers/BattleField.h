#pragma once
#include "Field.h"
#include <iostream>
#include <vector>
using namespace std;

#define COL_FIRST_FIELD 60
#define COL_DISTANCE_BETWEEN_FIELDS 10
#define ROW_FIELD 12

class BattleField
{
private:
	int nr_lin;
	int nr_col;
	vector<vector<Field*>> loc;
public:
	BattleField();

	BattleField(int n, int m);
	BattleField(BattleField &b) { this->nr_lin = b.nr_lin; this->nr_col = b.nr_col; this->loc = b.loc; }

	Field* getField(int row, int col)
	{
		for (int i = 0; i < loc.size(); i++) {
			for(int j=0;j<loc[i].size();j++)
				if (loc[i][j]->getCol()-row<=2 and loc[i][j]->getRow()==col)
				{
					return loc[i][j];
				}
			 } 
	}

	vector<vector<Field*>> returnLoc() { return loc; }

	virtual ~BattleField();
};

