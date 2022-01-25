#include "CZombie.h"

CZombie::CZombie()
{
	
	this->pos_X = END_LOGIN_BOX_COL;
}



CZombie::~CZombie()
{
	CLog::getInstance().printLog("S-a apelat destructorul clasei CZombie \n");
}

int CZombie::GetPos_x()
{

	return this->pos_X;
}

//IZombie* IZombie::createZombie(int health, int speed)
//{
//	return new CZombie(health, speed);
//}
