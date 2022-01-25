#pragma once
#include < iostream >
#include <Windows.h>
class Fire
{
	COORD bullet_pos;
	char B;
	COORD reset_bullet_pos;
public:
	Fire();
	Fire(int x, int y, char c);
	virtual void print();
	virtual void sterge();
	virtual COORD get_bullet_pos() { return bullet_pos; }
	virtual void set_bullet_pos(COORD aux);
	virtual void set_bullet_pos_from_plant(COORD aux);
	virtual void reset_bullet_poss();
	virtual void increase_X_coord() { bullet_pos.X+=1; }
	virtual~Fire();
};
