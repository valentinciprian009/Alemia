//
// Created by null on 1/9/2020.
//

#ifndef INC_250_HEALTHBAR_H
#define INC_250_HEALTHBAR_H


#include "../drawable/Drawable.h"

class HealthBar : public Drawable {
protected:
    float health = 0;
    int lastCol = 0;
public:
    HealthBar(UserInterface::ConsoleOutput* ouput, int rowOffset, int colOffset, int width);
    void setHealth(float health);
    void draw() override ;
    void clean() override ;
};


#endif //INC_250_HEALTHBAR_H
