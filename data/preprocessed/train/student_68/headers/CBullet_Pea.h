#pragma once
#include "CBullet.h"
class CBullet_Pea :public CBullet

{
	
public:
	CBullet_Pea(int damage) :CBullet() { this->Damage_ = damage;  CLog::getInstance().printLog("S-a apelat constructorul clasei CBullet_Pea\n");
	}
	virtual ~CBullet_Pea();
	static int Damage_;
	int shot = 0;
	void Start_Bullet_Attack(int x, int y) override;
	void Display_attack()override;
};

