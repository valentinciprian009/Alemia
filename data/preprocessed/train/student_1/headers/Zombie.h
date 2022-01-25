#pragma once
#include"Entity.h"
#define MAX_HEALTH_ZOMBIE 300
#define MOVE_SPEED_ZOMBIE 300
#define DAMAGE 10

class Zombie : public Entity
{
protected:
	int lane;
	int health;
	int damage;
	int moveSpeed;
	int stopPosition;
	int type;
	int startPosition;
	steady_clock::time_point begin = steady_clock::now();

public:
	Zombie() : Entity(), lane(), health(MAX_HEALTH_ZOMBIE), damage(DAMAGE), moveSpeed(MOVE_SPEED_ZOMBIE), stopPosition(), type(1), startPosition() { Log::getInstance().write("Zombie created"); }
	Zombie(int row_ul, int col_ul, int ln, int stop) : Entity(row_ul, col_ul), lane(ln), health(MAX_HEALTH_ZOMBIE), damage(DAMAGE), moveSpeed(MOVE_SPEED_ZOMBIE), stopPosition(stop), type(1), startPosition(col_ul) { Log::getInstance().write("Zombie created"); }
	Zombie(int row_ul, int col_ul, int ln, int stop, int tip) : Entity(row_ul, col_ul), lane(ln), health(MAX_HEALTH_ZOMBIE), damage(DAMAGE), moveSpeed(MOVE_SPEED_ZOMBIE), stopPosition(stop), type(tip), startPosition(col_ul) { Log::getInstance().write("Zombie created"); }
	Zombie(int row_ul, int col_ul, int ln, int hp, int dmg, int move_speed, int stop, int tip) : Entity(row_ul, col_ul), lane(ln), health(hp), damage(dmg), moveSpeed(move_speed), stopPosition(stop), type(tip), startPosition(col_ul) { Log::getInstance().write("Zombie created"); }
	void takeDamage(int dmg) { health -= dmg; }
	void setStop(int stop) { stopPosition = stop; }
	void setType(int tip) { type = tip; }
	void setSpeed(int speed) { moveSpeed = speed; }
	int getHealth() { return health; }
	int getSpeed() { return moveSpeed; }
	int getType() { return type; }
	virtual bool checkJump() { return 0; }
	virtual void vault() { ; }
	bool die();
	bool move();
	bool hit(int& plantHealth);
	virtual void print();
};