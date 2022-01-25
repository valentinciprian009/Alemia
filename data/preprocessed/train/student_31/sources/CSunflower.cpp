#include "CSunflower.h"
#include "ConsoleOutput.h"

#include <time.h>
#include <chrono>

using namespace std::chrono;

int CSunflower::disponoibil = 1;
int CSunflower::timp_crestere = 15;


void CSunflower::afiseaza_planta(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	conOut(x, y, 6) << L"█ █ █ █";
	conOut(x + 1, y, 6) << L"███████";
	conOut(x + 2, y, 6) << L"   █   ";
	conOut(x + 3, y, 6) << L"   █   ";
	
	this->x_coord = x;
	this->y_coord = y;

}

void CSunflower::delete_planta(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	conOut(x, y, 8) << L"       ";
	conOut(x + 1, y, 8) << L"       ";
	conOut(x + 2, y, 8) << L"       ";
	conOut(x + 3, y, 8) << L"       ";

}

int CSunflower::return_disponibil()
{
	return disponoibil;
}

void CSunflower::set_indisponibil()
{
	disponoibil = 0;
}

void CSunflower::set_disponibil()
{
	UserInterface::ConsoleOutput &ConOut = UserInterface::ConsoleOutput::getInstance();

	static auto begin = steady_clock::now();

	auto end = steady_clock::now();

	ConOut(24, 9, 6) << CSunflower::timp_crestere - duration_cast<seconds>(end - begin).count();

	if (duration_cast<seconds>(end - begin).count() > CSunflower::timp_crestere)
	{
		begin = end;
		disponoibil = 1;
		ConOut(24, 9, 6) << "        ";
	}
}

CSunflower::CSunflower()
{
	this->cost = 50;
	this->n_muscaturi = 2;

}

CSunflower::CSunflower(int x, int y)
{
	this->cost = 50;
	this->n_muscaturi = 5;
	
	this->x_coord = x;
	this->y_coord = y;
}

CSunflower::~CSunflower()
{
}
