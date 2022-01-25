#pragma once
#include "COut.h"
class Entity
{
	char img;
	int color;
	int x, y;
	bool finish = false;
public:
	Entity(char img1, int x1, int y1, int color1);
	bool is_finish(){return finish;}
	void set_finish() { finish = true; }
	virtual void update() = 0;
	void const  Draw();
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int newX);
	void setY(int newY);
	
	virtual ~Entity();
private:
	void const clearOld();
};

