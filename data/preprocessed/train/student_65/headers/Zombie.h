#ifndef Zombie_HEADER
#define Zombie_HEADER
#include "Entity.h"
class Zombie :
	public Entity
{
private:
	int health;
	int speed;
	int damage;
public:
	Zombie(int x = 0, int y = 0, int dame = 6,int health=6, std::string name = "Zombie") : Entity(name, x, y), damage(dame),health(health) {  }
	virtual void draw() ;
	virtual void update(std::string);
	void damaged(int damage)
	{
		health -= damage;
	}
	int get_health()
	{
		return health;
	}
	~Zombie();
};
#endif