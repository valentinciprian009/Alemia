#include "Sun.h"

Sun::Sun(int x,int y)
{
	this->row = x;
	this->col = y;
	this->earning = 30;
}

int Sun::get_col()
{
	return this->col;
}

int Sun::get_row()
{
	return this->row;
}

int Sun::get_money()
{
	return this->earning;
}
