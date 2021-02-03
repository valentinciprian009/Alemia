#include "CWall_nut.h"
#include "ConsoleOutput.h"

#include <time.h>
#include <chrono>

using namespace std::chrono;

int CWall_nut::disponoibil = 1;
int CWall_nut::timp_crestere = 30;


void CWall_nut::afiseaza_planta(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y, 5) << L"  ██";
	conOut(x + 1, y, 5) << L"██████";
	conOut(x + 2, y, 5) << L" ████";
	conOut(x + 3, y, 5) << L"  ██";
	
	this->x_coord = x;
	this->y_coord = y;

}

void CWall_nut::delete_planta(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y, 5) << L"    ";
	conOut(x + 1, y, 5) << L"      ";
	conOut(x + 2, y, 5) << L"     ";
	conOut(x + 3, y, 5) << L"    ";
}

int CWall_nut::return_disponibil()
{
	return disponoibil;
}

void CWall_nut::set_indisponibil()
{
	disponoibil = 0;
}

void CWall_nut::set_disponibil()
{
	UserInterface::ConsoleOutput &ConOut = UserInterface::ConsoleOutput::getInstance();

	static auto begin = steady_clock::now();

	auto end = steady_clock::now();

	ConOut(34, 9, 5) << CWall_nut::timp_crestere - duration_cast<seconds>(end - begin).count();

	if (duration_cast<seconds>(end - begin).count() > CWall_nut::timp_crestere)
	{
		begin = end;
		disponoibil = 1;
		ConOut(34, 9, 5) << "        ";
	}
}

CWall_nut::CWall_nut(int x, int y)
{
	this->x_coord = x;
	this->y_coord = y;

	this->cost = 125;
	this->n_muscaturi = 25;
	
}

CWall_nut::CWall_nut()
{
	this->cost = 125;
	this->n_muscaturi = 50;
	
}


CWall_nut::~CWall_nut()
{
}
