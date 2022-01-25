#include"GroundRow.h"

GroundRow::GroundRow(int row_ul, int col_ul, int nr_cells) : Entity(row_ul, col_ul)
{
	for (int i = 0; i < nr_cells; i++)
		row.push_back(GroundCell(row_ul, col_ul + 13 * i));
}

void GroundRow::print()
{
	for (auto& cell : row)
		cell.print();
}