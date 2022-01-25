#pragma once
#include "Entity.h"
class Proiectile :
	public Entity
{
protected:
	int damage;
	int health;
public:
	Proiectile(int x = 0, int y = 0, int dame = 3, std::string name = "Proiectile") :Entity(name, x, y), damage(dame) { health = 1; }
	virtual void draw() ;
	virtual void update();
	int get_damage() { return damage; }
	int get_health() { return health; }
};

