#pragma once
#include <Windows.h>

class bullet
{

	int damage=1;
	COORD pos;
	bool slow = 0;

public:
	void gotoxy(int x, int y);
	bullet(int x,int y);
	bullet();
	void afiseaza();
	void sterge();
	void  setcord(int x, int y);
	COORD getcord();
	void setslow();
	bool getslow();
	void setdamge();
	int getdamage();
};

