#pragma once
#include <Windows.h>
#include "bullet.h"
#include "sun.h"
class Plant
{

    char type = 'P';
    int cost;
    int life=5;
    int created;
    double rate;
    bool slow = 0;
    COORD pos;
public:
    Plant();
    void setcreated(int timp);
    int getcreated();
    void  virtual afiseaza(COORD pos);
    void setype(char type);
    char getype();
    int getCost();
    double getRate();
    void setRate(int time);
    void setCost(int value);
    int getLife();
    void setLife(int newLife);
    void setslow();
    bool getSlow();
    void  setcord(int x, int y);
    COORD  getcord();
    void gotoxy(int x, int y);
    virtual bullet* attack();
    void sterge(COORD pos);
    void aprox_cooord(short& x, short& y);
    void  drawpixel9(unsigned char x, unsigned char y, unsigned char Color);
    void setcolor9(WORD color);

};