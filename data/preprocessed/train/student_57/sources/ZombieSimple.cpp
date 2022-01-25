#include "ZombieSimple.h"
#include "Teren.h"
#include <chrono>
int ZombieSimple::getRezistence()
{
	return this->health;
}

int ZombieSimple::getSpeed()
{
	return this->speed;
}

void ZombieSimple::stopZombie()
{
	this->moveable = false;
}

void ZombieSimple::drawZombie(int row,int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0xDD);
	conOut(row, col) << "-----";
	conOut(row + 1, col + 2) << "-";
	conOut(row + 2, col + 1) << "-";
	conOut(row + 2, col + 3) << "-";

	SetConsoleTextAttribute(h, 7);
	conOut(row + 3, col + 1) << this->health;
}

void ZombieSimple::modifyHealth(int i)
{
	this->health -= i;
}

void ZombieSimple::move()
{
	if (this->moveable == true) {
		end = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() > this->speed * 1300)
		{

			begin = std::chrono::steady_clock::now();
			drawZombie(this->rand, this->coloana - 8);
			Teren a;
			a.DrawCasset(this->rand - 1, this->coloana - 1);
			this->coloana -= 8;
		}
	}
}

void ZombieSimple::killZombie()
{
	delete this;
}

int ZombieSimple::getRow()
{
	return this->rand;
}

int ZombieSimple::getCol()
{
	return this->coloana;
}
