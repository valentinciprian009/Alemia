#pragma once

typedef enum tipCharacter
{
	PLANT,ZOMBIE,SUN,PROIECTIL
};
class Character
{
protected:
	tipCharacter type;
	int x,y;
public:
	Character();
	Character(tipCharacter tip) :type(tip) {}

	tipCharacter getType() { return type; }
	 
    void operator=(Character &c) { this->type = c.type; this->x = c.getX(); this->y = c.getY(); }

	virtual void draw(int col, int row);

	virtual int getX() { return this->x; }
	virtual int getY() { return this->y; }

	virtual void setX(int x) { this->x = x; }
	virtual void setY(int y) { this->y = y; }

	virtual void actionare(class BattleField *f) {}

	virtual ~Character();
};

