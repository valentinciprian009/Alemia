#pragma once
#include <string>

class GameObject
{
protected:
	int x;
	int y;
public:
	virtual void draw(int y) {}; // for entities on ItemSlots
	virtual void draw(int x, int y) = 0; // for entities on the terrain
	virtual void draw(int x, int y, int flag) {}; // for TerrainBlocks

	virtual int getX();
	virtual int getY();
	virtual void setX(int x);
	virtual void setY(int y);
	virtual std::string identity() = 0;
	virtual void useSkill() = 0;
	virtual void damage(int damage = 0, bool slowed = false) = 0;
	virtual GameObject* clone() = 0;

	virtual ~GameObject() {};
};

