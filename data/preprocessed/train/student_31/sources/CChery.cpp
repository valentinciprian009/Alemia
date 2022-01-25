#include "CChery.h"
#include "ConsoleOutput.h"

#include <time.h>
#include <chrono>

using namespace std::chrono;

int CChery::disponoibil = 1;
int CChery::timp_crestere = 30;


void CChery::afiseaza_planta(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	
	conOut(x , y-1, 12)   << L" ██████";
	conOut(x + 1, y-2, 12) << L"████ ████";
	   conOut(x + 2, y-1, 12) << L"██   ██";

	   this->x_coord = x;
	   this->y_coord = y-1;

}

void CChery::delete_planta(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();


	conOut(x, y - 1, 12) << L"       ";
	conOut(x + 1, y - 2, 12) << L"         ";
	conOut(x + 2, y - 1, 12) << L"       ";
}

int CChery::return_disponibil()
{
	return disponoibil;
}

void CChery::set_indisponibil()
{
	disponoibil = 0;

}

void CChery::set_disponibil()
{
	UserInterface::ConsoleOutput &ConOut = UserInterface::ConsoleOutput::getInstance();

	static auto begin = steady_clock::now();

	auto end = steady_clock::now();

	ConOut(29, 8, 12) << CChery::timp_crestere - duration_cast<seconds>(end - begin).count();

	if (duration_cast<seconds>(end - begin).count() > CChery::timp_crestere)
	{
		begin = end;
		disponoibil = 1;
		ConOut(29, 8, 12) << "        ";
	}
}

CChery::CChery()
{
	this->cost = 125;
	this->n_muscaturi = 3;
	
}

CChery::CChery(int x, int y)
{
	this->cost = 125;
	this->n_muscaturi = 3;
	

	this->x_coord = x;
	this->y_coord = y;
}


CChery::~CChery()
{
}
