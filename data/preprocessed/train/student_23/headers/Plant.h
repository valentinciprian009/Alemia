#pragma once
#include "IDrawable.h";

class Plant :public IDrawable
{
protected:
	int life;
	int price;
public:
	Plant(int life, int price, int X, int Y)
	{
		this->x = X;
		this->y = Y;
		this->life = life;
		this->price = price;
	};
	int getLife() { return this->life; };
	int getPrice() { return this->price; };
	void getDamaged(int damage) { this->life -= damage; };
};