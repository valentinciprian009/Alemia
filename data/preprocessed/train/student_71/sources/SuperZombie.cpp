#include "SuperZombie.h"
#include "ConsoleOutput.h"

void SuperZombie::draw(int x, int y)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(9 + 6 * x, 20 + 15 * y + 7, 96) << L"▲▲";
	conOut(10 + 6 * x, 20 + 15 * y + 7, 176) << L"◂○";
	conOut(10 + 6 * x, 20 + 15 * y + 5, 192) << " "; conOut(10 + 6 * x, 20 + 15 * y + 10, 192) << " ";
	conOut(11 + 6 * x, 20 + 15 * y + 6, 192) << "    ";
	conOut(12 + 6 * x, 20 + 15 * y + 7, 1) << "  ";
	conOut(13 + 6 * x, 20 + 15 * y + 5, 192) << "  "; conOut(13 + 6 * x, 20 + 15 * y + 9, 192) << "  ";


}

std::string SuperZombie::identity()
{
	return "SuperZombie";
}

void SuperZombie::useSkill()
{
	this->PoleVaultingZombie::useSkill();
}

GameObject* SuperZombie::clone()
{
	SuperZombie* monster = new SuperZombie;
	monster->health = this->health;
	monster->x = this->x;
	monster->y = this->y;
	monster->slowed = this->slowed;
	monster->jumped = this->jumped;
	return monster;
}
