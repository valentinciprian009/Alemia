#pragma once
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include "flower.h"
#include "bullet.h"
class Garden_tile
{
private:
    UserInterface::ConsoleOutput conOut;
    UserInterface::ConsoleInput conIn;
    
   

public:
    int x, y;
    static const int width = 5, height = 3;
    Flower* fl;
    Bullet bullet;
    bool has_flower=false;
    int bullet_x=0;

    Garden_tile() {
        UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
        UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
    };
    void Draw(int x, int y);

    bool is_clicked(COORD mp);
    void place_flower(int type);
    void draw_bullet(int move);
    void clear_prev_bullet(int move);
    void clear_bullet(int x, int y);

};

