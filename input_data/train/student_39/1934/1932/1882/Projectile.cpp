//
// Created by null on 1/9/2020.
//

#include "Projectile.h"

int Projectile::getSpeedDamage() {
    return speedDamage;
}

int Projectile::getHealthDamage() {
    return healthDamage;
}

void Projectile::advance() {

    column_offset += speed;
}

void Projectile::draw() {
    if(lastPosX != column_offset){
        (*output)(row_offset, lastPosX) << "  ";
    }
    (*output)(row_offset, column_offset) << "->";
    lastPosX = column_offset;
}

Projectile::Projectile(UserInterface::ConsoleOutput *output, int rowOffset, int columnOfset, int speedDamage,
                       int healthDamage, int speed) : Drawable(output, rowOffset, columnOfset),
                                                      speedDamage(speedDamage), healthDamage(healthDamage),
                                                      speed(speed) {
    lastPosX = columnOfset;
    width = 2;
    height = 1;
}


Projectile
Projectile::projectile(UserInterface::ConsoleOutput *output, int rowOffset, int colOffset, ProjectileType type) {
    switch (type) {
        case PEA:
            return {output, rowOffset, colOffset, 0, 10, 2};
        case FROZEN_PEA:
            return {output, rowOffset, colOffset, 1, 10, 2};
    }
    return {output, rowOffset, colOffset, 0, 10, 2};
}

Projectile *
Projectile::createProjectile(UserInterface::ConsoleOutput *output, int rowOffset, int colOffset, ProjectileType type) {
    switch (type) {
        case PEA:
            return new Projectile(output, rowOffset, colOffset, 0, 10, 2);
        case FROZEN_PEA:
            return new Projectile(output, rowOffset, colOffset, 1, 10, 2);
    }
    return new Projectile(output, rowOffset, colOffset, 0, 10, 2);
}

