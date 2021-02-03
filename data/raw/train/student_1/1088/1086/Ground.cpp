#include"Ground.h"

Ground::Ground(int row_ul, int col_ul, int nr_rows, int nr_cols) : Entity(row_ul, col_ul), rowCount(nr_rows), columnCount(nr_cols)
{
	for (int i = 0; i < nr_rows; i++)
		ground.push_back(GroundRow(row_ul + 6 * i, col_ul, nr_cols));
}

void Ground::print()
{
	for (auto& row : ground)
		row.print();
}

bool Ground::plantFlower(int type, int &row, int &col)
{
	ConsoleEvent& action = consoleIn.getUserActions();
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			if (ground[i][j].checkInCell(action) && !ground[i][j].getType())
			{
				modifyCellType(i, j, type);
				row = i;
				col = j;
//				consoleOut(1, 1) << "CLK    " << action.getInputRecord().Event.MouseEvent.dwMousePosition.Y << "    " << action.getInputRecord().Event.MouseEvent.dwMousePosition.X << "   " << i + 1 << "    " << j + 1;
				return true;
			}
		}
	}
	return false;
}