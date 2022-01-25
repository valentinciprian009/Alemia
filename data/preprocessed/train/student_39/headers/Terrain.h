//
// Created by null on 1/9/2020.
//

#ifndef INC_250_TERRAIN_H
#define INC_250_TERRAIN_H


#include "../drawable/Drawable.h"

class Terrain : public Drawable {
private:
    int columns;
    int rows;
    int cellRows;
    int cellCols;

public:
    Terrain(UserInterface::ConsoleOutput *output, int row_offset, int col_offset, int rows, int columns = 9,
            int cellRows = 7, int cellCols = 9);

    void draw() override;
    ~Terrain() override;

    int getClickedCellColumnOffset(int row);
    int getClickedCellRowOffset(int col);
};


#endif //INC_250_TERRAIN_H
