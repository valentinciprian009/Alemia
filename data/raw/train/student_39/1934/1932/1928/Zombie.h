//
// Created by null on 1/9/2020.
//

#ifndef INC_250_ZOMBIE_H
#define INC_250_ZOMBIE_H


#include "../drawable/Drawable.h"
#include "../common/HealthBar.h"


enum ZombieType{
    ZOMBIE,
    BUCKET_HEAD,
    POLE_VAULTING,
    SUPER
};

class ZombieAbilities{
public:
    int health = 50;
    int speed = 2;
    int bytePower = 2;
    bool jumpOverFirstFlower = false;
};

class Zombie : public Drawable{
protected:

    HealthBar* healthBar;
    unsigned char left_hand = '\\';
    unsigned char head = 'O';
    bool  justBitAPlant = false;
    ZombieAbilities abilities;
    bool metFirstFlower = false;
    int lastCol = 0;

public:
    Zombie(UserInterface::ConsoleOutput* output, int rowOffset, int colOffset, ZombieAbilities abilities);
    virtual int bitePlant(int plantWidth);
    virtual void advance();
    virtual void damage(int healthDecrease, int speedDecrease);
    virtual void draw() override;
    int getHealth();
    void clean() override ;

    static Zombie* create(UserInterface::ConsoleOutput* output, int rowOffset, int colOffset, ZombieType type);

};


#endif //INC_250_ZOMBIE_H
