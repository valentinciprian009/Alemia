#pragma once

#include <iostream>
#include <Windows.h>
class Monster
{
	
	char type = 'M';
	int health=5;
	int speed=1;
	double rate;
	int value=10;
	bool slowed = 0;
	int attack = 2;
	bool jump = false;
	COORD pos;

public :
	Monster();
	Monster(int x,int y);
	void virtual afiseaza(COORD pos);
	void setLife(int newlife);
	void setSlowed();
	void setSpeed();
	void setValue(int val);
	int getLife();
	int getValue();
	void setcord(int x, int y);
	int getdamage();
	void setdamage();
	COORD getcord();
	void gotoxy(int x, int y);
	void sterge(COORD num);

};

