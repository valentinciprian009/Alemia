//
// Created by null on 1/9/2020.
//

#include "Plant.h"
#include "../game/Event.h"
#include "../projectile/Projectile.h"


Plant::Plant(UserInterface::ConsoleOutput *output, int rowOffset, int colOffset, EventManager *eventManager,
             PlantType type, bool isActive)
        : Drawable(output,
                   rowOffset,
                   colOffset),
          eventManager(eventManager),
          type(type),
          active(isActive) {
    healthBar = new HealthBar(output, rowOffset - 1, colOffset, 5);
    width = 5;
    height = 6;
}

void Plant::draw() {

    if (active) {
        if (type == PlantType::PEA_SHOOTER) {
            if (time == 50) {
                Projectile *p = Projectile::createProjectile(output, row_offset, column_offset + 5,
                                                             ProjectileType::PEA);
                eventManager->onEvent(
                        Event::SPAWN_NEW_PROJECTILE,
                        row_offset, column_offset + 5, p
                );
                time = 0;
            }

        }

        if (type == PlantType::SNOW_PEA) {
            if (time == 70) {
                Projectile *p = Projectile::createProjectile(output, row_offset, column_offset + 5,
                                                             ProjectileType::FROZEN_PEA);
                eventManager->onEvent(
                        Event::SPAWN_NEW_PROJECTILE,
                        row_offset, column_offset + 5, p
                );
                time = 0;
            }
        }
        time++;
        healthBar->setHealth(health / 50.0);
        healthBar->draw();
    }
    (*output)(row_offset, column_offset) << " w";
    (*output)(row_offset + 1, column_offset) << "\\|/";
    (*output)(row_offset + 2, column_offset) << (unsigned char) 176 << (unsigned char) 176 << (unsigned char) 176;
    switch (type) {
        case PlantType::SUNFLOWER:
            (*output)(row_offset, column_offset) << " " << (unsigned char) 148;
            break;
        case PlantType::PEA_SHOOTER:
            (*output)(row_offset + 1, column_offset) << "\\|/" << (unsigned char) 201;
            break;
        case PlantType::CHERRY_BOMB:
            (*output)(row_offset, column_offset) << " " << (unsigned char) 148;
            (*output)(row_offset + 2, column_offset) << (unsigned char) 144 << (unsigned char) 144
                                                     << (unsigned char) 144;
            break;
        case PlantType::WALL_NUT:
            (*output)(row_offset + 2, column_offset) << (unsigned char) 178 << (unsigned char) 178
                                                     << (unsigned char) 178;
            break;
        case PlantType::SNOW_PEA:
            (*output)(row_offset, column_offset) << " " << (unsigned char) 236;
            (*output)(row_offset + 1, column_offset) << ")|" << (unsigned char) 244;
            break;
    }
}


void Plant::getBitten(int biteDamage) {
    if (type == PlantType::WALL_NUT)
        health -= biteDamage / 2;
    else
        health -= biteDamage;
}

int Plant::getSunSpawnFrequencyIncrease() {
    if (type == PlantType::SUNFLOWER)
        return 2;
    return 0;
}

int Plant::getHealth() { return health; }
int Plant::getCost() { return cost; }

void Plant::clean() {
    Drawable::clean();
    healthBar->clean();
}