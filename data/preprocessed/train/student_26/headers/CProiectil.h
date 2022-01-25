#pragma once
#include "CEntity.h"
class CProiectil
	:public CEntity
{
	int speed=2;
	
	char symbol = 62;
public:
	int x;
	int y;
	bool hit = false;
	void deletePos();
	void draw();
	void updatePos();
	CProiectil(int,int);
	~CProiectil();
};

