#pragma once
#include "Plants.h"
class CherryBomb :
	public Plants
{
private:
	int dmg;


public:
	CherryBomb(string name,int dmg,int row,int col,int health,int price);
	virtual void set_col(int x);
	virtual void set_row(int x);
	virtual int get_price();
	virtual int get_health();
	virtual int get_col();
	virtual int get_row();
	virtual string get_name();
	virtual bool delay();
	virtual void take_damage(int dmg);
	~CherryBomb() {};
};

