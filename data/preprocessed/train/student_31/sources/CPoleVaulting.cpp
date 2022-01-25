#include "CPoleVaulting.h"
#include "ConsoleOutput.h"

int CPoleVaulting::speed = 3;


int CPoleVaulting::move()
{
	this->delete_zobie(this->x_coordz, this->y_coordz);
	this->x_coordz = this->x_coordz - 10;
	this->print_zombie(this->x_coordz, this->y_coordz);

	if (this->x_coordz < 30)
		return 0;
	return 1;
}

void CPoleVaulting::reset_leap()
{
	this->leap = 0;
}

void CPoleVaulting::print_zombie(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(y + 1, x, 8) << L"████";
	conOut(y + 2, x, 1) << L"  █";
	conOut(y + 3, x, 8) << L"█ ";
	conOut(y + 3, x + 2, 1) << L"█ ";
	conOut(y + 3, x + 4, 8) << L"█";
	conOut(y + 4, x, 8) << L" █ █";

	this->x_coordz = x;
	this->y_coordz = y;
}

int CPoleVaulting::return_speed()
{
	return speed;
}

int CPoleVaulting::return_leap()
{
	return this->leap;
}

CPoleVaulting::CPoleVaulting()
{
	this->health = 100;
	this->leap = 1;
	this->free = 0;

}


CPoleVaulting::~CPoleVaulting()
{
}
