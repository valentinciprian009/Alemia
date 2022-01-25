//
// Created by null on 1/9/2020.
//

#ifndef INC_250_PROJECTILLE_H
#define INC_250_PROJECTILLE_H

#include "../drawable/Drawable.h"

enum ProjectileType{
    PEA,
    FROZEN_PEA
};

class Projectile : public Drawable{
protected:
    int speedDamage = 0;
    int healthDamage = 2;
    int speed = 2;
    int lastPosX = 0;
    Projectile(UserInterface::ConsoleOutput*output, int rowOffset, int columnOfset,  int speedDamage, int healthDamage, int speed);

public:
    int getSpeedDamage();
    int getHealthDamage();
    void advance();
    void draw() override ;
    static Projectile projectile(UserInterface::ConsoleOutput* output, int rowOffset, int colOffset, ProjectileType type);
    static Projectile* createProjectile(UserInterface::ConsoleOutput* output, int rowOffset, int colOffset, ProjectileType type);
};


#endif //INC_250_PROJECTILLE_H
