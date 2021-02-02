#include "CPeaShooter.h"
#include "ConsoleOutput.h"
#include "CPlants.h"
#include "CProiectil.h"
#include <time.h>
#include <chrono>


#include <iostream>
#include "ConsoleInput.h"

int CPeaShooter::disponoibil = 1;
int CPeaShooter::timp_crestere = 25;


using namespace std::chrono;


void CPeaShooter::delete_planta(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y + 1, 8) << L"    ";
	conOut(x + 1, y + 1, 8) << L" ";
	conOut(x + 2, y - 1, 8) << L"     ";
	conOut(x + 3, y + 1, 8) << L" ";
}

void CPeaShooter::afiseaza_planta(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	this->x_coord = x;
	this->y_coord = y;

	this->p.set_coord(x, y);
	

	conOut(x, y+1, 160) << L"****";
    conOut(x + 1, y+1, 160) << L"*";
    conOut(x + 2, y-1 ,160) << L"*****";
    conOut(x + 3, y+1 , 160) << L"*";


}

void CPeaShooter::shoot()
{
	this->p.set_coord(this->x_coord, this->y_coord);
	this->p.print_proiectil();
}

int CPeaShooter::get_proiectil_speed()
{
	return this->p.get_speed();
}

void CPeaShooter::get_proiectil_coord(int & a, int & b)
{
	a = p.get_x();
	b = p.get_y();
}

int CPeaShooter::get_damage()
{
	return this->p.get_damage();
}

void CPeaShooter::reload()
{
	this->p.reload();
}

int CPeaShooter::return_disponibil()
{
	return disponoibil;
}

void CPeaShooter::set_indisponibil()
{
	disponoibil = 0;

}

void CPeaShooter::set_disponibil()
{
	UserInterface::ConsoleOutput &ConOut = UserInterface::ConsoleOutput::getInstance();

	static auto begin = steady_clock::now();

	auto end = steady_clock::now();

	ConOut(14, 9, 10) << CPeaShooter::timp_crestere-duration_cast<seconds>(end - begin).count();

	if (duration_cast<seconds>(end - begin).count() > CPeaShooter::timp_crestere)
	{
		begin = end;
		disponoibil = 1;
		ConOut(14, 9, 10) << "        ";
	}
}
 

CPeaShooter::CPeaShooter()
{
	this->cost = 100;
	this->n_muscaturi = 3;
}

CPeaShooter::CPeaShooter(int x, int y)
{
	
	this->cost = 100;
	this->n_muscaturi = 3;

	this->x_coord = x;
	this->y_coord = y;

	
}

CPeaShooter::~CPeaShooter()
{
}
