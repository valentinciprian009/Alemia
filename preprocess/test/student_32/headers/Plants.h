#pragma once
#include<iostream>
using namespace std;
class Plants
{
protected:
	int health;
	int col;
	int row;
	int price;
	string name;
public:
	virtual void set_col(int) = 0;
	virtual void set_row(int) = 0;
	virtual int get_price() = 0;
	virtual int get_health()=0;
	virtual int get_col() = 0;
	virtual int get_row() = 0;
	virtual string get_name() = 0;
	virtual bool delay() = 0;
	virtual void take_damage(int dmg)=0;
};

