#pragma once
#include"CLog.h"

#define Zombie 0
#define BucketHead_Zombie 1
#define PoleVaulting_Zombie  2
#define Super_Zombie 3

class IZombie
{
public:
	//static IZombie* createZombie(int health, int speed);
	virtual void Display(string type_Zombie, int x, float y)=0;
	virtual int GetPos_x()=0;
};

