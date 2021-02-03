#include "flower.h"

void Flower::Draw(int x, int y)
{
    this->x = x;
    this->y = y;
    char tulp = 180;
    char fl = 178;
    
    switch (type) 
    {
        case 1:
            conOut.change_color("white");
            break;
        case 2:
            conOut.change_color("blue");
            break;
        case 3:
            conOut.change_color("red");
            break;
        case 4:
            conOut.change_color("yellow");
            break;
        case 5:
            conOut.change_color("purple");
            break;

    }
  

    conOut(x + 1, y) << fl;
    conOut.change_color("green");
    conOut(x + 1, y + 1) << tulp;
    conOut.change_color("white");
 
}