#include "CBullet.h"

CBullet::CBullet()
{
	CLog::getInstance().printLog("S-a apelat constructorul clasei CBullet\n");
}

CBullet::~CBullet()
{
	const char* StoreBulletPeaFiles = "StorBulletPea.txt";
	FILE* store = fopen(StoreBulletPeaFiles, "w");
	fclose(store);
	CLog::getInstance().printLog("S-a apelat destructorul clasei parinte CBullet\n");
}

void CBullet::Start_Bullet_Attack(int x, int y)
{

}

void CBullet::Display_attack()
{


}
