//
// Created by null on 1/9/2020.
//

#include "Zombie.h"
#include<algorithm>

Zombie::Zombie(UserInterface::ConsoleOutput *output, int rowOffset, int colOffset, ZombieAbilities abilities)
        : Drawable(output, rowOffset,
                   colOffset), abilities(abilities) {
    healthBar = new HealthBar(output, rowOffset - 1, colOffset, 5);
    width = 5;
    height = 4;
    lastCol = colOffset;
}

int Zombie::bitePlant(int plantWidth) {
    if(!metFirstFlower){
        clean();
        column_offset -= plantWidth*2+1;
        healthBar->column_offset -= plantWidth*2+1;
        metFirstFlower = true;
        return 0;
    }
    left_hand = left_hand == '_' ? '\\' : '_';
    head = head == 'O' ? 'U' : 'O';
    justBitAPlant = true;
    return abilities.bytePower;
}

void Zombie::advance() {
    healthBar->column_offset -= 1;
    column_offset -= 1;

}

void Zombie::damage(int healthDecrease, int speedDecrease) {
    abilities.health -= healthDecrease;
    abilities.speed -= speedDecrease;
    abilities.speed = std::max(abilities.speed, 0);
}

void Zombie::draw() {
    if(lastCol != column_offset){
        clean();
    }
    lastCol = column_offset;
    healthBar->setHealth(abilities.health / 60.0);
    healthBar->draw();
    if (!justBitAPlant) {
        head = 'O';
        left_hand = '\\';
    }
    (*output)(row_offset, column_offset) << " " << head;
    (*output)(row_offset + 1, column_offset) << left_hand << "|/";
    (*output)(row_offset + 2, column_offset) << "/ \\";
    justBitAPlant = false;
}

int Zombie::getHealth() { return abilities.health; }

void Zombie::clean() {
    int col = column_offset;
    column_offset = lastCol;
    Drawable::clean();
    healthBar->clean();
    column_offset = col;
}

Zombie *Zombie::create(UserInterface::ConsoleOutput *output, int rowOffset, int colOffset, ZombieType type) {
    ZombieAbilities abilities;
    switch (type){
        case ZombieType ::ZOMBIE:
            break;
        case ZombieType ::BUCKET_HEAD:
            abilities.speed += 2;
            abilities.health += 20;
            abilities.bytePower += 2;
            break;
        case ZombieType ::POLE_VAULTING:
            abilities.jumpOverFirstFlower = true;
            break;
        case ZombieType ::SUPER:
            abilities.speed += 2;
            abilities.health += 20;
            abilities.bytePower += 2;
            abilities.jumpOverFirstFlower = true;
            break;
    }
    return new Zombie(output, rowOffset, colOffset, abilities);
}

