#include "BattleField.h"



BattleField::BattleField()
{
}

BattleField::BattleField(int n, int m)
{
	nr_lin = n-1;
	nr_col = m-1;

	int row, col;

	row = ROW_FIELD;
	col = COL_FIRST_FIELD;
	////disvutie in f de lvl
	if (nr_lin < 2)
	{
		col = COL_FIRST_FIELD;
		row = ROW_FIELD+12;
	}

	for (int i = 0; i < n-1; i++)
	{
		vector<Field*> v;
		for (int j = 0; j < m-1; j++)
		{
			Field *f = new Field(row, col);
			v.push_back( f);
			col = col + COL_DISTANCE_BETWEEN_FIELDS;
		}
		loc.push_back(v);
		row = row + 6;
	}
}


BattleField::~BattleField()
{
}
