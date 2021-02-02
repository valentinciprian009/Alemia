#pragma once
#include "Character.h"
#include <iostream>
#include "ConsoleOutput.h"

typedef enum Tip_Planta
{
	PEASHOOTER,CHERRY_BOMB,SUNFLOWER,WALL_NUT,SNOW_PEA
};

class Plant: public Character
{
protected:
	std::string name;
	Tip_Planta type;

	int price;
	int life;
	int timp_crestere; //sec ,ms

public:
	Plant();
	Plant(std::string name, Tip_Planta tip, int price, int life, int timp);

	std::string getName() { return name; }
	Tip_Planta getType() { return type; }
	
	int getPrice() { return price; }
	int getLife() { return life; }
	int getTime() { return timp_crestere; }

	void operator=(Plant &c) { this->name = c.name; this->type = type; this->price = price; this->life = life; this->timp_crestere = timp_crestere; }

	virtual void draw(int col, int row);

	void actionare(class BattleField * f);

	virtual ~Plant();
};

