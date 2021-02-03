//
// Created by null on 1/9/2020.
//

#include "Terrain.h"

Terrain::Terrain(UserInterface::ConsoleOutput *output, int row_offset, int col_offset, int rows, int columns,
                 int cellRows, int cellCols) : Drawable(output, row_offset, col_offset),
                                 rows(rows),
                                 columns(columns),
                                 cellRows(cellRows),
                                 cellCols(cellCols)
                                 {
    width = (cellCols+1)*columns;
    height = (cellRows+1)*rows;
}

Terrain::~Terrain() {
    delete this;
}

void Terrain::draw() {

    for (int row = 0; row <= rows * (cellRows + 1); row++) {
        for (int col = 0; col <= columns * (cellCols + 1); col++) {
            int rowMod = row % (cellRows + 1);
            int colMod = col % (cellCols + 1);
            bool row_can = rowMod == 0;
            bool col_can = colMod == 0;
            if (row_can) {
                (*output)(row_offset + row, column_offset + col) << "_";

            }
            if (col_can && row != 0) {
                (*output)(row_offset + row, column_offset + col) << "|";
            }

        }
    }

}


int Terrain::getClickedCellRowOffset(int row){
    int i =  (row-row_offset)/(cellRows+1);
	int diff = row - row_offset;
    if(diff < 0 || i > rows-1)
        return -1;
    return row_offset + i*(cellRows+1);
}
int Terrain::getClickedCellColumnOffset(int col){
    int diff = col - column_offset;
	int i = diff / (cellCols+1);
    if(diff < 0 || i > columns-1)
        return -1;

    return column_offset +  i*(cellCols+1);
}