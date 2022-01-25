//
// Created by null on 1/9/2020.
//
#include "Drawable.h"

Drawable::Drawable(UserInterface::ConsoleOutput *output, int rowOffset, int colOffset) : output(output),
                                                                                            row_offset(rowOffset),
                                                                                            column_offset(colOffset){}

void Drawable::setOffset(int row, int column) {
    this->row_offset = row;
    this->column_offset = column;
}

void Drawable::clean() {
    for(int row=0; row<height; row++){
        for(int col=0; col<width; col++){
            (*output)(row_offset + row, column_offset + col) << " ";
        }
    }
}

int Drawable::getHeight() {
    return height;
}

int Drawable::getWidth() {
    return width;
}
