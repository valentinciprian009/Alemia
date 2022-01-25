#pragma once
#include"Entity.h"
#include"Ground.h"
#include"Pea.h"
#include<chrono>

class Plant : public Entity
{
protected:
	const int cost;
	const int maxHP;
	const int cooldown;
	int currentHP;
	int rowGround;
	int columnGround;
	int type;

public:
	Plant() : Entity(), currentHP(), cost(), maxHP(), cooldown(), rowGround(-1), columnGround(-1), type() { ; }
	Plant(int currHP, int cost, int maxhp, int cooldown, int tip) : Entity(), currentHP(currHP), cost(cost), maxHP(maxhp), cooldown(cooldown), rowGround(-1), columnGround(-1), type(tip) { ; }
	Plant(int row_ul, int col_ul, int currHP, int cost, int maxhp, int cooldown, int tip) : Entity(row_ul, col_ul), currentHP(currHP), cost(cost), maxHP(maxhp), cooldown(cooldown), rowGround(-1), columnGround(-1), type(tip) { ; }
	void setCoords(int i, int j) { rowGround = i; columnGround = j; }
	void setType(int tip) { type = tip; }
	int getType() { return type; }
	int getCost() const { return cost; }
	int getMaxHP() const { return maxHP; }
	int getCurrentHP() const { return currentHP; }
	int getCooldown() const { return cooldown; }
	int getRowGround() const { return rowGround; }
	int getColumnGround() const { return columnGround; }
	virtual int printCooldown(bool& canPlant, steady_clock::time_point& lastPlantedTime) = 0;
	virtual void plant(bool& canPlant, steady_clock::time_point& lastPlantedTime) = 0;
	virtual bool canPlantFlower(bool& canPlant, steady_clock::time_point& lastPlantedTime) = 0;
	virtual void takeDamage(int dmg) { currentHP -= dmg; }
	virtual bool die();
	virtual bool getHitZombie(Zombie* zombie);
};