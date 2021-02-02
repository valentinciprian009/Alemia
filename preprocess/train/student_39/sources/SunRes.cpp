//
// Created by null on 1/9/2020.
//

#include "SunRes.h"

SunRes::SunRes(UserInterface::ConsoleOutput *output, int rowOffset, int colOffset, int cols, int colSize) : Drawable(
        output, rowOffset, colOffset), cols(cols), colSize(colSize) {
    sunSlothsAvailability.resize(cols, false);
    width = cols*(colSize+1);
    height = 3;
}

void SunRes::draw() {
    time++;
    if(time > 10){
        int newPos = (int)(cols*(float)rand()/RAND_MAX);
        sunSlothsAvailability[newPos] = true;
        time = 0;
    }
    (*output)(row_offset, column_offset) << "Sori:";
    for(int i=0; i<cols; i++){
        int centerCol = column_offset + i * (colSize + 1) + colSize / 2 + 1;
       if(sunSlothsAvailability[i]) {
           unsigned char a = 254;
           (*output)(row_offset, centerCol-1) << "___";
           (*output)(row_offset + 1, centerCol-1) << "|" << (unsigned char)254 << "|";
       }else{
           (*output)(row_offset, centerCol-1) << "___";
           (*output)(row_offset + 1, centerCol-1) << "|O|";
       }

    }
}

int SunRes::getMoneyFromResource(int row, int col){
    if(row == row_offset+1){
        int i = (col-column_offset)/(colSize + 1);
        if(i >= 0 && i < cols){
            if(sunSlothsAvailability[i]) {
                sunSlothsAvailability[i] = false;
                return 25;
            }
        }
    }
    return 0;
}
