#include "BucketHeadZZ.h"
#include "ConsoleOutput.h"



int BucketHeadZZ::move()
{
	this->delete_zobie(this->x_coordz, this->y_coordz);
	this->x_coordz = this->x_coordz - 10;
	this->print_zombie(this->x_coordz, this->y_coordz);

	if (this->x_coordz < 30)
		return 0;
	return 1;
}

void BucketHeadZZ::print_zombie(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(y + 1, x, 4) << L"████";
	conOut(y + 2, x, 13) << L"  █";
	conOut(y + 3, x, 8) << L"█ ";
	conOut(y + 3, x + 2, 13) << L"█ ";
	conOut(y + 3, x + 4, 8) << L"█";
	conOut(y + 4, x, 8) << L" █ █";

	this->x_coordz = x;
	this->y_coordz = y;
}

BucketHeadZZ::BucketHeadZZ()
{
	this->health = 200;
	this->speed = 3000;
}


BucketHeadZZ::~BucketHeadZZ()
{
}
