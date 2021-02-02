//
// Created by null on 1/9/2020.
//

#include "HealthBar.h"
#include <algorithm>

void HealthBar::draw() {

    if(lastCol != column_offset){
        clean();
    }
    lastCol = column_offset;
    int full = width * health;

    for (int i = 0; i < full; i++) {
        (*output)(row_offset, column_offset + i) << (unsigned char) 223;
    }
    for (int i = full; i < width; i++)
        (*output)(row_offset, column_offset + i) << (unsigned char) 248;

}

HealthBar::HealthBar(UserInterface::ConsoleOutput *ouput, int rowOffset, int colOffset, int width) : Drawable(ouput,
                                                                                                              rowOffset,
                                                                                                              colOffset) {
    this->width = width;
    this->height = 1;
    lastCol = colOffset;
}

void HealthBar::setHealth(float health) {
    this->health = std::max(health, 0.0f);
}

void HealthBar::clean() {
    int col = column_offset;
    column_offset = lastCol;
    Drawable::clean();
    column_offset = col;
}
