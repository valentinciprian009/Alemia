#include "zombie.h"

void Zombie::Draw(int x, int y)
{
    this->x = x;
    this->y = y;
    char d = 219;
    char e = 47;
    char f = 92;
    char p = 254;

    if (this->life == 0) {
        Zombie::Clear(this->x, this->y);
        Zombie::Clear(this->x + 1, this->y);
        is_active = false; //dead

    }
   

    if (this->is_active) {
        conOut.change_color("green");
        conOut(x + 1, y) << p;

        conOut(x, y + 1) << e << d << f;

        conOut.change_color("white");
    }
    else return;

    
}

void Zombie::Clear()
{
    conOut(x + 1, y) <<" ";

    conOut(x, y + 1) <<"   ";


}

void Zombie::Clear(int x, int y)
{
    conOut(x + 1, y) << " ";

    conOut(x, y + 1) << "   ";


}