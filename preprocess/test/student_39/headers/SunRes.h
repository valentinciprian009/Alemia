//
// Created by null on 1/9/2020.
//

#ifndef INC_250_SUNRES_H
#define INC_250_SUNRES_H


#include "../drawable/Drawable.h"
#include <vector>
class SunRes : public Drawable {

private:
    int cols;
    int colSize;
    std::vector<bool> sunSlothsAvailability;
    int time = 0;
public:
    SunRes(UserInterface::ConsoleOutput* output, int rowOffset, int colOffset, int cols , int colSize = 9);
    int getMoneyFromResource(int row, int col);
    void draw() override ;
};


#endif //INC_250_SUNRES_H
