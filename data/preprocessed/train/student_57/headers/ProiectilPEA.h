#pragma once
#include "Proiectil.h"
class ProiectilPEA:public Proiectil
{
private:
	int damage;
	const int viteza = 2;
	int x;
	int y;
public:
	ProiectilPEA():damage(20),x(0),y(0) {};
	ProiectilPEA(int yy,int xx) :damage(20), x(xx), y(yy) {};
	ProiectilPEA(const ProiectilPEA& a);
	void move() override;
	int getViteza();
	int getDamage();
	int getRow();
	int getCol();
	void drawProiectil(int row,int col);
};

