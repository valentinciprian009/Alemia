#pragma once
#include"CBullet.h"

class CBullet_FrozenPea :public CBullet
{
	
	//int Number_Bullet_Active;
	//BulletType Type_;

public:
	CBullet_FrozenPea(int damage) : CBullet() { this->Damge_ = damage;  CLog::getInstance().printLog("S-a apelat constructorul clasei CBullet_FrozenPea\n");
	}
	virtual ~CBullet_FrozenPea();
	static int Damge_;
	//int shot = 0;
	void Start_Bullet_Attack(int x, int y) override;
	void Display_attack()override;
};

