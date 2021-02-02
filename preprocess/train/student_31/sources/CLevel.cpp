#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <chrono>
#include "CActions.h"
#include "CLevel.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include <iostream>
#include <math.h>

#include "CPlants.h"
#include "CSunflower.h"
#include "CSnowPea.h"
#include "CPeaShooter.h"
#include "CChery.h"
#include "CWall_nut.h"

#include "CProiectil.h"

#include "CZombie.h"
#include "BucketHeadZZ.h"
#include "CPoleVaulting.h"

#include <conio.h>

#define latura 10

using namespace std::chrono;

int apartine_interval(int y)
{
	if (y > 35 && y < 45)
		return 0;
	if (y > 45 && y < 55)
		return 1;
	if (y > 55 && y < 65)
		return 2;
	if (y > 65 && y < 75)
		return 3;
	if (y > 75 && y < 85)
		return 4;
	if (y > 85 && y < 95)
		return 5;
	if (y > 95 && y < 105)
		return 6;
	if (y > 105 && y < 115)
		return 7;
	if (y > 115 && y < 125)
		return 8;
	return 0;
}//pentru soare

int return_line(int y)
{
	for (int i = 0; i < 5; i++)
	{
		if (y > 10 + 5 * i && y <= 15 + 5 * i)
			return i;
	}
	return 0;
}

int return_col(int x)
{
	for (int i = 0; i < 9; i++)
	{
		if (x > 35 + 10 * i && x <= 45 + 10 * i)
			return i;
	}
	return 0;
}

int CLevel::apartine_interval_planta(int x, int y)
{
	if (x >= 20 && x <= 30)
	{
		if (y > 10 && y < 15)
			return 1;
		if (y > 15 && y < 20)
			return 2;
		if (y > 20 && y < 25)
			return 3;
		if (y > 25 && y < 30)
			return 4;
		if (y > 30 && y < 35)
			return 5;
		return 0;
	}
	else
		return 0;

}

int CLevel::planteaza(int & a, int & b)
{
	return 0;
}

void CLevel::select_plant(int x, int y)
{
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput&conOut = UserInterface::ConsoleOutput::getInstance();
	switch (apartine_interval_planta(y, x))
	{
	case 1:
	{
		if (this->scor_jucator >= 100 && CPeaShooter::return_disponibil()==1)
		{
			
			this->scor_jucator -= 100;
			conOut(5, 27, 9) << "        ";
			conOut(5, 27, 9) << this->scor_jucator;
			int a = 0;
			int b = 0;
			if (this->planteaza(a, b))
			{
				CPeaShooter *p = new CPeaShooter(a,b);
				this->pea_shooter.push_back(*p);
				CPeaShooter::set_indisponibil();

				p->afiseaza_planta(b, a);
				
			}
		}
		break;
	}
	case 2:
	{
		if (this->scor_jucator >= 175 && CSnowPea::return_disponibil()==1)
		{
		
			this->scor_jucator -= 175;
			conOut(5, 27, 9) << "        ";
			conOut(5, 27, 9) << this->scor_jucator;
			int a = 0;
			int b = 0;
			if (this->planteaza(a, b))
			{
				CSnowPea*p = new CSnowPea(a,b);
				this->snow_pea_shooter.push_back(*p);
				CSnowPea::set_indisponibil();
				p->afiseaza_planta(b, a);
			}
		}
		break;
	}
	case 3:
	{
		if (this->scor_jucator >= 50 && CSunflower::return_disponibil()==1) 
		{
		
			this->scor_jucator -= 50;
			conOut(5, 27, 9) << "        ";
			conOut(5, 27, 9) << this->scor_jucator;
			int a = 0;
			int b = 0;
			if (this->planteaza(a, b))
			{
				a--;
				CSunflower*p = new CSunflower(a,b);
				this->sunflowers.push_back(*p);
				CSunflower::set_indisponibil();
				p->afiseaza_planta(b, a);
			}
		}
		break;
	}
	case 4:
	{
		if (this->scor_jucator >= 125 && CChery::return_disponibil()==1)
		{
		
			this->scor_jucator -= 125;
			conOut(5, 27, 9) << "        ";
			conOut(5, 27, 9) << this->scor_jucator;
			int a = 0;
			int b = 0;
			if (this->planteaza(a, b))
			{
				CChery*p = new CChery(a,b);
				this->cherys.push_back(*p);
				CChery::set_indisponibil();

				p->afiseaza_planta(b, a);
			}
		}
		break;
	}
	case 5:
	{
		if (this->scor_jucator >= 125 && CWall_nut::return_disponibil()==1)
		{
		
			this->scor_jucator -= 125;
			conOut(5, 27, 9) << "        ";
			conOut(5, 27, 9) << this->scor_jucator;
			int a = 0;
			int b = 0;
			if (this->planteaza(a, b))
			{
				CWall_nut*p = new CWall_nut(a,b);
				this->nuts.push_back(*p);
				CWall_nut::set_indisponibil();

				p->afiseaza_planta(b, a);
			}
		}
		break;
	}
	default:
		//conOut(40, 100, 7) << L"Resurse insuficiente!";
		break;
	}

}

int CLevel::generate_rand()
{
	
	static auto begin = steady_clock::now();

	auto end = steady_clock::now();

	int timp = 7;
	timp = timp - this->sunflowers.size();
	if (timp < 2)
		timp = 2;
	timp *= 1000;
	if (duration_cast<milliseconds>(end - begin).count() > timp)
	{
		begin = end;
		return rand() % 9;
	}
	return -1;
}

void CLevel::generate_sun(int x)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	if (x > -1 && x < 9)
	{
		this->sun[x] = 1;
		conOut( 2 , 37 + latura * x, 6) << L"▄ ██╗▄";
		conOut( 3 , 37 + latura * x, 6) << L" ████╗";
		conOut( 4 , 37 + latura* x, 6)  << L"▀╚██╔▀";
		conOut( 5 , 37 + latura * x, 6) << L"  ╚═╝ ";
	}
}

void CLevel::colect_sun(int x, int y)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	if (x > 1 && x < 6)
	{
		int a = apartine_interval(y);
		if ( this->sun[a]==1)
		{
			this->sun[a] = 0;
			this->scor_jucator += 25;
			conOut(2, 37 + latura * a, 6) << L"      ";
			conOut(3, 37 + latura * a, 6) << L"      ";
			conOut(4, 37 + latura * a, 6) << L"      ";
			conOut(5, 37 + latura * a, 6) << L"      ";
		}
	}
}

void CLevel::kill_zombs()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	static auto begin = steady_clock::now();
	auto end = steady_clock::now();


	if (duration_cast<seconds>(end - begin).count() > 4)
	{
		begin = end;
		for (int j = 0; j < this->cherys.size(); j++)
		{
			int coloana_chery = return_col(this->cherys[j].get_x_plant());
			int linie_chery = return_line(this->cherys[j].get_y_plant());

			for (int i = 0; i < this->zombs.size(); i++)
			{
				if (abs(coloana_chery - return_col(this->zombs[i].x_z())) < 4 && abs(linie_chery - return_line(this->zombs[i].y_z())) < 4)
				{
					this->zombs[i].delete_zobie(this->zombs[i].x_z(), this->zombs[i].y_z() - 1);
					this->zombs.erase(this->zombs.begin() + i);
				}
			}
			for (int i = 0; i < this->bzombs.size(); i++)
			{
				if (abs(coloana_chery - return_col(this->bzombs[i].x_z())) < 4 && abs(linie_chery - return_line(this->bzombs[i].y_z())) < 4)
				{
					this->bzombs[i].delete_zobie(this->bzombs[i].x_z(), this->bzombs[i].y_z() - 1);
					this->bzombs.erase(this->bzombs.begin() + i);
				}
			}
			for (int i = 0; i < this->pzombs.size(); i++)
			{
				if (abs(coloana_chery - return_col(this->pzombs[i].x_z())) < 4 && abs(linie_chery - return_line(this->pzombs[i].y_z())) < 4)
				{
					this->pzombs[i].delete_zobie(this->pzombs[i].x_z(), this->pzombs[i].y_z() - 1);
					this->pzombs.erase(this->pzombs.begin() + i);
				}
			}
			this->teren[linie_chery][coloana_chery] = 0;
			this->cherys[j].delete_planta(this->cherys[j].get_y_plant(), this->cherys[j].get_x_plant());
			this->cherys.erase(this->cherys.begin() + j);
			return;
		}
	}

	for (int i = 0; i < this->zombs.size(); i++)
	{
		for (int j = 0; j < this->pea_shooter.size(); j++)
		{
			int xp;
			int yp;
			this->pea_shooter[j].get_proiectil_coord(xp, yp);
			if (return_col(xp) == return_col(this->zombs[i].x_z()) && return_line(yp)==return_line(this->zombs[i].y_z()))
			{
				this->pea_shooter[j].reload();
				if (return_col(this->pea_shooter[j].get_x_plant()) == return_col(this->zombs[i].x_z()))
				{
				
					return;
				}
				else
				if (!this->zombs[i].minus_life(this->pea_shooter[j].get_damage()))
				{
					
					this->zombs[i].delete_zobie(  this->zombs[i].x_z(), this->zombs[i].y_z()-1);
					this->zombs.erase(this->zombs.begin() + i);
					
					return;
				}
			}
		}
		for (int j = 0; j < this->snow_pea_shooter.size(); j++)
		{
			int xp;
			int yp;
			this->snow_pea_shooter[j].get_proiectil_coord(xp, yp);
			if (return_col(xp) == return_col(this->zombs[i].x_z()) && return_line(yp) == return_line(this->zombs[i].y_z()))
			{

				this->snow_pea_shooter[j].reload();

				this->zombs[i].set_free(); 

				if (return_col(this->snow_pea_shooter[j].get_x_plant()) == return_col(this->zombs[i].x_z()))
				{
					
					return;
				}
				else
				if (!this->zombs[i].minus_life(this->snow_pea_shooter[j].get_damage()))
				{
					
					this->zombs[i].delete_zobie(this->zombs[i].x_z(), this->zombs[i].y_z() - 1);
					this->zombs.erase(this->zombs.begin() + i);
					return;
				}
			}
		}
		
	}

	for (int i = 0; i < this->bzombs.size(); i++)
	{
		for (int j = 0; j < this->pea_shooter.size(); j++)
		{
			int xp;
			int yp;
			this->pea_shooter[j].get_proiectil_coord(xp, yp);
			if (return_col(xp) == return_col(this->bzombs[i].x_z()) && return_line(yp) == return_line(this->bzombs[i].y_z()))
			{
				this->pea_shooter[j].reload();
				if (return_col(this->pea_shooter[j].get_x_plant()) == return_col(this->bzombs[i].x_z()))
				{

					return;
				}
				else
					if (!this->bzombs[i].minus_life(this->pea_shooter[j].get_damage()))
					{

						this->bzombs[i].delete_zobie(this->bzombs[i].x_z(), this->bzombs[i].y_z() - 1);
						this->bzombs.erase(this->bzombs.begin() + i);

						return;
					}
			}
		}
		for (int j = 0; j < this->snow_pea_shooter.size(); j++)
		{
			int xp;
			int yp;
			this->snow_pea_shooter[j].get_proiectil_coord(xp, yp);
			if (return_col(xp) == return_col(this->bzombs[i].x_z()) && return_line(yp) == return_line(this->bzombs[i].y_z()))
			{

				this->snow_pea_shooter[j].reload();
				//this->zombs[i].set_free();

				if (return_col(this->snow_pea_shooter[j].get_x_plant()) == return_col(this->bzombs[i].x_z()))
				{

					return;
				}
				else
					if (!this->bzombs[i].minus_life(this->snow_pea_shooter[j].get_damage()))
					{

						this->bzombs[i].delete_zobie(this->bzombs[i].x_z(), this->bzombs[i].y_z() - 1);
						this->bzombs.erase(this->bzombs.begin() + i);
						return;
					}
			}
		}

	}

	for (int i = 0; i < this->pzombs.size(); i++)
	{
		for (int j = 0; j < this->pea_shooter.size(); j++)
		{
			int xp;
			int yp;
			this->pea_shooter[j].get_proiectil_coord(xp, yp);
			if (return_col(xp) == return_col(this->pzombs[i].x_z()) && return_line(yp) == return_line(this->pzombs[i].y_z()))
			{
				this->pea_shooter[j].reload();
				if (return_col(this->pea_shooter[j].get_x_plant()) == return_col(this->pzombs[i].x_z()))
				{

					return;
				}
				else
					if (!this->pzombs[i].minus_life(this->pea_shooter[j].get_damage()))
					{

						this->pzombs[i].delete_zobie(this->pzombs[i].x_z(), this->pzombs[i].y_z() - 1);
						this->pzombs.erase(this->pzombs.begin() + i);

						return;
					}
			}
		}
		for (int j = 0; j < this->snow_pea_shooter.size(); j++)
		{
			int xp;
			int yp;
			this->snow_pea_shooter[j].get_proiectil_coord(xp, yp);
			if (return_col(xp) == return_col(this->pzombs[i].x_z()) && return_line(yp) == return_line(this->pzombs[i].y_z()))
			{

				this->snow_pea_shooter[j].reload();

				this->pzombs[i].set_free();

				if (return_col(this->snow_pea_shooter[j].get_x_plant()) == return_col(this->pzombs[i].x_z()))
				{

					return;
				}
				else
					if (!this->pzombs[i].minus_life(this->snow_pea_shooter[j].get_damage()))
					{

						this->pzombs[i].delete_zobie(this->pzombs[i].x_z(), this->pzombs[i].y_z() - 1);
						this->pzombs.erase(this->pzombs.begin() + i);
						return;
					}
			}
		}

	}


}

void CLevel::kill_plants()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();


	for (int i = 0; i < this->zombs.size(); i++)
	{
		for (int j = 0; j < this->pea_shooter.size(); j++)
		{
			if (return_col(this->pea_shooter[j].get_x_plant()) == return_col(this->zombs[i].x_z()) && return_line(this->pea_shooter[j].get_y_plant()) == return_line(this->zombs[i].y_z()))
			{
				this->zombs[i].set_free();
				if (!this->pea_shooter[j].hurt())
				{
					this->zombs[i].reset_free();
					this->pea_shooter[j].delete_planta(this->pea_shooter[j].get_y_plant(), this->pea_shooter[j].get_x_plant());
					this->zombs[i].print_zombie(this->zombs[i].x_z(), this->zombs[i].y_z() - 1);

					this->pea_shooter.erase(this->pea_shooter.begin() + j);
					this->teren[return_line(this->zombs[i].y_z())][return_col(this->zombs[i].x_z())] = 0;
					
					return;
				}
			}
		}
		for (int j = 0; j < this->snow_pea_shooter.size(); j++)
		{
			if (return_col(this->snow_pea_shooter[j].get_x_plant()) == return_col(this->zombs[i].x_z()) && return_line(this->snow_pea_shooter[j].get_y_plant()) == return_line(this->zombs[i].y_z()))
			{
				this->zombs[i].set_free();
				if (!this->snow_pea_shooter[j].hurt())
				{
					this->zombs[i].reset_free();
					this->snow_pea_shooter[j].delete_planta(this->snow_pea_shooter[j].get_y_plant(), this->snow_pea_shooter[j].get_x_plant());
					this->zombs[i].print_zombie(this->zombs[i].x_z(), this->zombs[i].y_z() - 1);

					this->snow_pea_shooter.erase(this->snow_pea_shooter.begin() + j);
					this->teren[return_line(this->zombs[i].y_z())][return_col(this->zombs[i].x_z())] = 0;
					
					return;
				}
			}
		}
		for (int j = 0; j < this->sunflowers.size(); j++)
		{
			if (return_col(this->sunflowers[j].get_x_plant()) == return_col(this->zombs[i].x_z()) && return_line(this->sunflowers[j].get_y_plant()) == return_line(this->zombs[i].y_z()))
			{
				this->zombs[i].set_free();
				if (!this->sunflowers[j].hurt())
				{
					this->zombs[i].reset_free();
					this->sunflowers[j].delete_planta(this->sunflowers[j].get_y_plant(), this->sunflowers[j].get_x_plant());
					this->zombs[i].print_zombie(this->zombs[i].x_z(), this->zombs[i].y_z() - 1);

					this->sunflowers.erase(this->sunflowers.begin() + j);
					this->teren[return_line(this->zombs[i].y_z())][return_col(this->zombs[i].x_z())] = 0;
					
					return;
				}
			}
		}
		for (int j = 0; j < this->cherys.size(); j++)
		{
			if (return_col(this->cherys[j].get_x_plant()) == return_col(this->zombs[i].x_z()) && return_line(this->cherys[j].get_y_plant()) == return_line(this->zombs[i].y_z()))
			{
				this->zombs[i].set_free();
				if (!this->cherys[j].hurt())
				{
					this->zombs[i].reset_free();
					this->cherys[j].delete_planta(this->cherys[j].get_y_plant(), this->cherys[j].get_x_plant());
					this->zombs[i].print_zombie(this->zombs[i].x_z(), this->zombs[i].y_z() - 1);

					this->cherys.erase(this->cherys.begin() + j);
					this->teren[return_line(this->zombs[i].y_z())][return_col(this->zombs[i].x_z())] = 0;
					
					return;
				}
			}
		}
		for (int j = 0; j < this->nuts.size(); j++)
		{
			if (return_col(this->nuts[j].get_x_plant()) == return_col(this->zombs[i].x_z()) && return_line(this->nuts[j].get_y_plant()) == return_line(this->zombs[i].y_z()))
			{
				this->zombs[i].set_free();
				if (!this->nuts[j].hurt())
				{
					this->zombs[i].reset_free();
					this->nuts[j].delete_planta(this->nuts[j].get_y_plant(), this->nuts[j].get_x_plant());
					this->zombs[i].print_zombie(this->zombs[i].x_z(), this->zombs[i].y_z() - 1);
					this->nuts.erase(this->nuts.begin() + j);
					this->teren[return_line(this->zombs[i].y_z())][return_col(this->zombs[i].x_z())] = 0;
					
					return;
				}
			}
		}
	}


	for (int i = 0; i < this->bzombs.size(); i++)
	{
		for (int j = 0; j < this->pea_shooter.size(); j++)
		{
			if (return_col(this->pea_shooter[j].get_x_plant()) == return_col(this->bzombs[i].x_z()) && return_line(this->pea_shooter[j].get_y_plant()) == return_line(this->bzombs[i].y_z()))
			{
				this->bzombs[i].set_free();
				if (!this->pea_shooter[j].hurt())
				{
					this->bzombs[i].reset_free();
					this->pea_shooter[j].delete_planta(this->pea_shooter[j].get_y_plant(), this->pea_shooter[j].get_x_plant());
					this->bzombs[i].print_zombie(this->bzombs[i].x_z(), this->bzombs[i].y_z() - 1);

					this->pea_shooter.erase(this->pea_shooter.begin() + j);
					this->teren[return_line(this->bzombs[i].y_z())][return_col(this->bzombs[i].x_z())] = 0;
					
					return;
				}
			}
		}
		for (int j = 0; j < this->snow_pea_shooter.size(); j++)
		{
			if (return_col(this->snow_pea_shooter[j].get_x_plant()) == return_col(this->bzombs[i].x_z()) && return_line(this->snow_pea_shooter[j].get_y_plant()) == return_line(this->bzombs[i].y_z()))
			{
				this->bzombs[i].set_free();
				if (!this->snow_pea_shooter[j].hurt())
				{
					this->bzombs[i].reset_free();
					this->snow_pea_shooter[j].delete_planta(this->snow_pea_shooter[j].get_y_plant(), this->snow_pea_shooter[j].get_x_plant());
					this->bzombs[i].print_zombie(this->bzombs[i].x_z(), this->bzombs[i].y_z() - 1);

					this->snow_pea_shooter.erase(this->snow_pea_shooter.begin() + j);
					this->teren[return_line(this->bzombs[i].y_z())][return_col(this->bzombs[i].x_z())] = 0;
					
					return;
				}
			}
		}
		for (int j = 0; j < this->sunflowers.size(); j++)
		{
			if (return_col(this->sunflowers[j].get_x_plant()) == return_col(this->bzombs[i].x_z()) && return_line(this->sunflowers[j].get_y_plant()) == return_line(this->bzombs[i].y_z()))
			{
				this->bzombs[i].set_free();
				if (!this->sunflowers[j].hurt())
				{
					this->bzombs[i].reset_free();
					this->sunflowers[j].delete_planta(this->sunflowers[j].get_y_plant(), this->sunflowers[i].get_x_plant());
					this->bzombs[i].print_zombie(this->bzombs[i].x_z(), this->bzombs[i].y_z() - 1);

					this->sunflowers.erase(this->sunflowers.begin() + j);
					this->teren[return_line(this->bzombs[i].y_z())][return_col(this->bzombs[i].x_z())] = 0;
					
					return;
				}
			}
		}
		for (int j = 0; j < this->cherys.size(); j++)
		{
			if (return_col(this->cherys[j].get_x_plant()) == return_col(this->bzombs[i].x_z()) && return_line(this->cherys[j].get_y_plant()) == return_line(this->bzombs[i].y_z()))
			{
				this->bzombs[i].set_free();
				if (!this->cherys[j].hurt())
				{
					this->bzombs[i].reset_free();

					this->cherys[j].delete_planta(this->cherys[j].get_y_plant(), this->cherys[j].get_x_plant());
					this->bzombs[i].print_zombie(this->bzombs[i].x_z(), this->bzombs[i].y_z() - 1);

					this->cherys.erase(this->cherys.begin() + j);
					this->teren[return_line(this->bzombs[i].y_z())][return_col(this->bzombs[i].x_z())] = 0;
					
					return;
				}
			}
		}
		for (int j = 0; j < this->nuts.size(); j++)
		{
			if (return_col(this->nuts[j].get_x_plant()) == return_col(this->bzombs[i].x_z()) && return_line(this->nuts[j].get_y_plant()) == return_line(this->bzombs[i].y_z()))
			{
				this->bzombs[i].set_free();
				if (!this->nuts[j].hurt())
				{
					this->bzombs[i].reset_free();

					this->nuts[j].delete_planta(this->nuts[j].get_y_plant(), this->nuts[j].get_x_plant());
					this->bzombs[i].print_zombie(this->bzombs[i].x_z(), this->bzombs[i].y_z() - 1);
					this->nuts.erase(this->nuts.begin() + j);
					this->teren[return_line(this->bzombs[i].y_z())][return_col(this->bzombs[i].x_z())] = 0;
					
					return;
				}
			}
		}
	}

	for (int i = 0; i < this->pzombs.size(); i++)
	{
		for (int j = 0; j < this->pea_shooter.size(); j++)
		{
			if (return_col(this->pea_shooter[j].get_x_plant()) == return_col(this->pzombs[i].x_z()) && return_line(this->pea_shooter[j].get_y_plant()) == return_line(this->pzombs[i].y_z()))
			{
				if (this->pzombs[i].return_leap() == 0)
				{
				this->pzombs[i].set_free();
					if (!this->pea_shooter[j].hurt())
					{
						this->pzombs[i].reset_free();
						this->pea_shooter[j].delete_planta(this->pea_shooter[j].get_y_plant(), this->pea_shooter[j].get_x_plant());
						this->pzombs[i].print_zombie(this->pzombs[i].x_z(), this->pzombs[i].y_z() - 1);

						this->pea_shooter.erase(this->pea_shooter.begin() + j);
						this->teren[return_line(this->pzombs[i].y_z())][return_col(this->pzombs[i].x_z())] = 0;
						
						return;
					}
				}
				else
				{
					this->pzombs[i].reset_leap();
					this->pzombs[i].move();
				}
			}
		}
		for (int j = 0; j < this->snow_pea_shooter.size(); j++)
		{
			if (return_col(this->snow_pea_shooter[j].get_x_plant()) == return_col(this->pzombs[i].x_z()) && return_line(this->snow_pea_shooter[j].get_y_plant()) == return_line(this->pzombs[i].y_z()))
			{
				if (this->pzombs[i].return_leap() == 0)
				{
					this->pzombs[i].set_free();
					if (!this->snow_pea_shooter[j].hurt())
					{
						this->pzombs[i].reset_free();
						this->snow_pea_shooter[j].delete_planta(this->snow_pea_shooter[j].get_y_plant(), this->snow_pea_shooter[j].get_x_plant());
						this->pzombs[i].print_zombie(this->pzombs[i].x_z(), this->pzombs[i].y_z() - 1);

						this->snow_pea_shooter.erase(this->snow_pea_shooter.begin() + j);
						this->teren[return_line(this->pzombs[i].y_z())][return_col(this->pzombs[i].x_z())] = 0;
						
						return;
					}
				}
				else
				{
					this->pzombs[i].reset_leap();
					this->pzombs[i].move();
				}
			}
		}
		for (int j = 0; j < this->sunflowers.size(); j++)
		{
			if (return_col(this->sunflowers[j].get_x_plant()) == return_col(this->pzombs[i].x_z()) && return_line(this->sunflowers[j].get_y_plant()) == return_line(this->pzombs[i].y_z()))
			{
				if (this->pzombs[i].return_leap() == 0)
				{
					this->pzombs[i].set_free();
					if (!this->sunflowers[j].hurt())
					{
						this->pzombs[i].reset_free();
						this->sunflowers[j].delete_planta(this->sunflowers[j].get_y_plant(), this->sunflowers[j].get_x_plant());
						this->pzombs[i].print_zombie(this->pzombs[i].x_z(), this->pzombs[i].y_z() - 1);

						this->sunflowers.erase(this->sunflowers.begin() + j);
						this->teren[return_line(this->pzombs[i].y_z())][return_col(this->pzombs[i].x_z())] = 0;
						
						return;
					}
				}
				else
				{
					this->pzombs[i].reset_leap();
					this->pzombs[i].move();
				}
			}
		}
		for (int j = 0; j < this->cherys.size(); j++)
		{
			if (return_col(this->cherys[j].get_x_plant()) == return_col(this->pzombs[i].x_z()) && return_line(this->cherys[j].get_y_plant()) == return_line(this->pzombs[i].y_z()))
			{
				if (this->pzombs[i].return_leap() == 0)
				{
					this->pzombs[i].set_free();
					if (!this->cherys[j].hurt())
					{
						this->pzombs[i].reset_free();
						this->cherys[j].delete_planta(this->cherys[j].get_y_plant(), this->cherys[j].get_x_plant());
						this->pzombs[i].print_zombie(this->pzombs[i].x_z(), this->pzombs[i].y_z() - 1);

						this->cherys.erase(this->cherys.begin() + j);
						this->teren[return_line(this->pzombs[i].y_z())][return_col(this->pzombs[i].x_z())] = 0;
						
						return;
					}
				}
				else
				{
					this->pzombs[i].reset_leap();
					this->pzombs[i].move();
				}
			}
		}
		for (int j = 0; j < this->nuts.size(); j++)
		{
			if (return_col(this->nuts[j].get_x_plant()) == return_col(this->pzombs[i].x_z()) && return_line(this->nuts[j].get_y_plant()) == return_line(this->pzombs[i].y_z()))
			{
				if (this->pzombs[i].return_leap() == 0)
				{
					this->pzombs[i].set_free();
					if (!this->nuts[j].hurt())
					{
						this->pzombs[i].reset_free();
						this->nuts[j].delete_planta(this->nuts[j].get_y_plant(), this->nuts[j].get_x_plant());
						this->pzombs[i].print_zombie(this->pzombs[i].x_z(), this->pzombs[i].y_z() - 1);
						this->nuts.erase(this->nuts.begin() + j);
						this->teren[return_line(this->pzombs[i].y_z())][return_col(this->pzombs[i].x_z())] = 0;
						
						return;
					}
				}
				else
				{
					this->pzombs[i].reset_leap();
					this->pzombs[i].move();
				}
			}
		}
	}
}

int CLevel::move_zombs()
{
	
	static auto begin = steady_clock::now();

	auto end = steady_clock::now();

	if (this->zombs.size()> 0 || this->bzombs.size()>0)
	{
		if (duration_cast<milliseconds>(end - begin).count() > 7000)
		{
			begin = end;
			if (this->zombs.size() > 0)
			{
				for (int i = 0; i < this->zombs.size(); i++)
				{
					if (!this->zombs[i].return_free())
					{
						if (!this->zombs[i].move())
						{
							return 0;
						}
					}

				}
			}
			if (this->bzombs.size() > 0)
			{
				for (int i = 0; i < this->bzombs.size(); i++)
				{
					if (!this->bzombs[i].return_free())
					{
						if (!this->bzombs[i].move())
						{
							return 0;
						}
					}
				}
			}
			
		}
	}
		if (this->move_vaulting() == 0)
			return 0;
	return 1;
}

int CLevel::move_vaulting()
{
	static auto begin = steady_clock::now();

	auto end = steady_clock::now();

	if (duration_cast<seconds>(end - begin).count() > CPoleVaulting::return_speed())
	{
		begin = end;
		if (this->pzombs.size() > 0)
		{
			for (int i = 0; i < this->pzombs.size(); i++)
			{
				if (!this->pzombs[i].return_free())
				{
					if (!this->pzombs[i].move())
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

void CLevel::generate_zombs()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	static auto begin = steady_clock::now();

	auto end = steady_clock::now();
	
	if (duration_cast<milliseconds>(end - begin).count() > this->start_time_zombs && this->n_zombs>0)
	{
		begin = end;
		CZombie *z = new CZombie;
		z->print_zombie(120, this->y_origins+ (rand() % this->n_lines)*5);
		this->zombs.push_back(*z);
		this->start_time_zombs = this->start_time_zombs - 15000;
		if (this->start_time_zombs < 1000)
			this->start_time_zombs = 1000;
		this->n_zombs--;
		conOut(5, 150, 9) << "     ";
		conOut(4, 150, 9) <<"N. Zombies:";
		conOut(5, 150, 9) << this->n_zombs;
	if (this->n_zombs % 10 == 0 && this->n_buckets > 0)
	{
		BucketHeadZZ *b = new BucketHeadZZ;
		b->print_zombie(120, this->y_origins + (rand() % this->n_lines) * 5);
		this->bzombs.push_back(*b);

		this->n_buckets--;
	}
	if (this->n_zombs % 20 == 0 && this->n_vaulting > 0)
	{
		CPoleVaulting *p = new CPoleVaulting;
		p->print_zombie(120, this->y_origins + (rand() % this->n_lines) * 5);
		this->pzombs.push_back(*p);

		this->n_vaulting--;
	}

	}
	
}

void CLevel::print_sun()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < latura; j++)
		{
			conOut(1, 35 + j + i * latura, 6) << L"▀";
			conOut(1 + latura / 2, 35 + j + i * latura, 6) << L"▀";
		}
		for (int k = 0; k < latura / 2; k++)
		{
			conOut(1 + k, 35 + i * latura, 6) << L"█";
		}
	}
	for (int k = 0; k <= latura / 2; k++)
	{
		conOut(1 + k, 35 + 9 * latura, 6) << L"█";
	}
	
}

void CLevel::print_plants()
{
	CPeaShooter peas;
	CSnowPea snow_peas;
	CSunflower sunflower;
	CChery chery;
	CWall_nut nut;
	CZombie z;
	BucketHeadZZ bz;
	CPoleVaulting pz;

	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < latura; i++)
		{
			conOut(10 + j * latura / 2, 20 + i, 14) << L"▀";
		}
	}
	for (int i = 0; i < latura / 2 * 5; i++)
	{
		conOut(10 + i, 20, 14) << L"█";
		conOut(10 + i, 20 + latura, 14) << L"█";
	}

	peas.afiseaza_planta(11, 24);
	conOut(11 + 1, 24 - 18, 10) << L"Pea Shooter";
	conOut(11 + 2, 24 - 15, 10) << L"100";
	

	snow_peas.afiseaza_planta(16, 24);
	conOut(16 + 1, 24 - 15, 9) << L"SnowPea";
	conOut(16 + 2, 24 - 13, 9) << L"175";

	sunflower.afiseaza_planta(21, 22);
	conOut(21 + 1, 22 - 15, 6) << L"Sunflower";
	conOut(21 + 2, 22 - 13, 6) << L"50";

	chery.afiseaza_planta(26, 22);
	conOut(26 + 1, 22 - 17, 12) << L"Cherry Bomb";
	conOut(26 + 2, 22 - 14, 12) << L"125";

	nut.afiseaza_planta(31, 22);
	conOut(31 + 1, 22 - 15, 5) << L"Wall-nut";
	conOut(31 + 2, 22 - 13, 5) << L"125";

	z.print_zombie( 140, 10);
	conOut( 12, 148, 8) <<L"Zombie";

	bz.print_zombie( 140, 15);
	conOut(17, 148, 4) << L"Bucket_head_Zombie";

	pz.print_zombie(140, 20);
	conOut(22, 148, 1) << L"PoleVaulting";

}

void CLevel::pea_shoot()
{
	static auto begin = steady_clock::now();

	auto end = steady_clock::now();

	if (this->pea_shooter.size() > 0)
	{
		if (duration_cast<milliseconds>(end - begin).count() > CProiectil::get_speed())
		{
			begin = end;
			for (int i = 0; i < this->pea_shooter.size(); i++)//peashoter_actions
			{
				this->pea_shooter[i].shoot();
			}
		}
	}
}

void CLevel::snow_pea_shoot()
{
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();

	if (this->snow_pea_shooter.size() > 0)
	{
		if (duration_cast<milliseconds>(end - begin).count() > CProiectil_snow::get_speed())
		{
			begin = end;
			for (int i = 0; i < this->snow_pea_shooter.size(); i++)// snow_peashooter_actions
			{
				this->snow_pea_shooter[i].shoot();
			}
		}
	}
}

void CLevel::load_plants()
{
	if (CPeaShooter::return_disponibil() == 0)
	{
		CPeaShooter::set_disponibil();
	}
	if (CSnowPea::return_disponibil() == 0)
	{
		CSnowPea::set_disponibil();
	}
	if (CSunflower::return_disponibil() == 0)
	{
		CSunflower::set_disponibil();
	}
	if (CChery::return_disponibil() == 0)
	{
		CChery::set_disponibil();
	}
	if (CWall_nut::return_disponibil() == 0)
	{
		CWall_nut::set_disponibil();
	}
}

int CLevel::ruleaza()
{
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	CActions &act = CActions::getInstance();

	int r = this->generate_rand();

	if (r > -1 && this->sun[r] == 0)
	{
		this->generate_sun(r);
		this->sun[r] = 1;
	}

	this->pea_shoot();
	this->snow_pea_shoot();

	this->generate_zombs();


	this->kill_zombs();
	this->kill_plants();

	this->load_plants();

	if (!this->move_zombs())
	{
		act.print_GAME_OVER();
		act.log_game_over();
		Sleep(10000);
		return 0;
	}
	if (this->zombs.empty() && this->bzombs.empty() && this->n_zombs < 1 && this->n_buckets == 0)
	{
		act.print_Victory();
		act.log_victory(this->scor_jucator);
		Sleep(10000);
		return 0;
	}

	conOut(4, 22, 9) << conIn.get_id();
	//conOut(40, 22, 9) << clicked;
	conOut(5, 20, 9) << L"SCOR:";
	conOut(5, 27, 9) << this->scor_jucator;
	return 1;
}


CLevel::CLevel()
{
}

CLevel::~CLevel()
{
}
