//
// Created by null on 1/9/2020.
//

#ifndef INC_250_PLANT_H
#define INC_250_PLANT_H


#include "../drawable/Drawable.h"
#include "../common/HealthBar.h"
#include "../game/Event.h"

enum PlantType {
    PEA_SHOOTER,
    SUNFLOWER,
    CHERRY_BOMB,
    WALL_NUT,
    SNOW_PEA
};

class Plant : public Drawable {
protected:
    int health = 50;
    HealthBar *healthBar;
    PlantType type;
    int time = 0;
    bool active = false;
    EventManager *eventManager;
    bool isVisible = true;
    int cost = 50;

public:
    Plant(UserInterface::ConsoleOutput *output, int rowOffset, int colOffset, EventManager *eventManager,
          PlantType type, bool isActive = true);

    void getBitten(int biteDamage);

    int getSunSpawnFrequencyIncrease();

    void draw() override;

    void clean() override;

    void setVisibility(bool visible);
    int getCost();
    int getHealth();
};


#endif //INC_250_PLANT_H
