#include "CSnowPea.h"

#include "ConsoleOutput.h"

#include <time.h>
#include <chrono>

int CSnowPea::disponoibil = 1;
int CSnowPea::timp_crestere = 25;

using namespace std::chrono;

int CSnowPea::get_damage()
{
	return this->p_snow.get_damage();
}

void CSnowPea::delete_planta(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y + 1, 8) << L"    ";
	conOut(x + 1, y + 1, 8) << L" ";
	conOut(x + 2, y - 1, 8) << L"     ";
	conOut(x + 3, y + 1, 8) << L" ";
}

int CSnowPea::get_proiectil_speed()
{
	return this->p_snow.get_speed();
}

void CSnowPea::afiseaza_planta(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	conOut(x, y + 1, 144) << L"****";
	conOut(x + 1, y + 1, 144) << L"*";
	conOut(x + 2, y - 1, 144) << L"*****";
	conOut(x + 3, y + 1, 144) << L"*";
	this->x_coord = x;
	this->y_coord = y;

}

void CSnowPea::shoot()
{
	this->p_snow.set_coord(this->x_coord, this->y_coord);
	this->p_snow.print_proiectil();
}

void CSnowPea::get_proiectil_coord(int & a, int & b)
{
	a = this->p_snow.get_x();
	b = this->p_snow.get_y();
}

void CSnowPea::reload()
{
	this->p_snow.reload();
}

int CSnowPea::return_disponibil()
{
	return disponoibil;
}

void CSnowPea::set_indisponibil()
{
	disponoibil = 0;
}

void CSnowPea::set_disponibil()
{
	UserInterface::ConsoleOutput &ConOut = UserInterface::ConsoleOutput::getInstance();

	static auto begin = steady_clock::now();

	auto end = steady_clock::now();

	ConOut(19, 11, 9) << CSnowPea::timp_crestere - duration_cast<seconds>(end - begin).count();

	if (duration_cast<seconds>(end - begin).count() > CSnowPea::timp_crestere)
	{
		begin = end;
		disponoibil = 1;
		ConOut(19, 11, 9) << "        ";
	}
}

CSnowPea::CSnowPea(int x, int y)
{
	this->cost = 175;
	this->n_muscaturi = 5;
	
	this->x_coord = x;
	this->y_coord = y;

}
CSnowPea::CSnowPea()
{
	this->cost = 175;
	this->n_muscaturi = 5;
}

CSnowPea::~CSnowPea()
{
	
}
