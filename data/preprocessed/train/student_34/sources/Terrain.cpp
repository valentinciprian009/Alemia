#include "Terrain.h"
#include "ConsoleOutput.h"
#include <windows.h>
#include "CherryBomb.h"
#include "Peashooter.h"
#include "Snow_Pea.h"
#include "WallNut.h"
#include "Sunflower.h"
#include "Pick_and_plant.h"
UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
Terrain::Terrain()
{
	
}


void Terrain::print_score()
{
	Pick_and_plant q;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	for (int i = 5; i < 14; i++)
		conOut(0,i) << char(219);
	for (int i = 5; i < 14; i++)
     	conOut(6, i) <<char(219);
	for (int i = 1; i < 6; i++)
		conOut(i, 5) << char(221);
	for (int i = 1; i < 6; i++)
		conOut(i, 13) << char(222);
	conOut(1,7) << "COINS";
	conOut(3, 9) << q.get_coins();
}

void Terrain::plant_zone()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),72);
	for (int i = 11; i < 35; i++)
	{
		if (i % 5 == 0)
		{
			conOut(i, 5) << "\n";
			goto x;
		}conOut(i, 5) << char(219);
	x:;
	
	}
	for (int i = 11; i < 35; i++)
	{
		if (i % 5 == 0)
		{
			conOut(i, 13) << "\n";
			goto y;
		}conOut(i, 13) << char(219);
	y:;

	}

	for (int j = 6; j < 35; j++) {
		if (j % 5 == 0) {
			for (int i = 5; i < 14; i++)
			{
				conOut(j, i) << char(220);

			}
		}
	}
	for (int j = 6; j < 35; j++) {
		if(j==14 || j==19 || j==24 || j==29 || j==34){
			for (int i = 6; i < 13; i++)
			{
				conOut(j, i) << char(220);

			}
		}
	}


}

void Terrain::sun_zone()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);


	for (int i = 2; i <= 10; i++) {

		for (int j = 1; j < 7; j++)
			conOut(j, 15 * i - 10) << char(219);
	}

	for (int i = 20; i <= 140; i++)
	{
		if ((i - 5) % 15 == 0) {
			goto r;
	}

		conOut(6, i) << char(220);
	r:;}

		for (int i = 20; i <= 140; i++)
			conOut(0, i) << char(220);


}

void Terrain::print_teren1()
{
	

	for (int i = 20; i <= 140; i++)
	{
		if ((i - 5) % 15 == 0) {
			goto r;
		}

		conOut(24, i) << char(220);
	r:;
	}

	for (int i = 20; i <= 140; i++)
		conOut(20, i) << char(220);
	for (int i = 2; i <= 10; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

		conOut(20, 15 * i - 10) << char(220);
		conOut(24, 15 * i - 10) << char(220);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
}

void Terrain::print_teren2()
{
	

	for (int i = 20; i <= 140; i++)
	{
		if ((i - 5) % 15 == 0) {
			goto jump1;
		}

		conOut(19, i) << char(220);
	jump1:;
	}

	for (int i = 20; i <= 140; i++)
		conOut(15, i) << char(220);
	for (int i = 2; i <= 10; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

		conOut(15, 15 * i - 10) << char(220);
		conOut(19, 15 * i - 10) << char(220);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
}

void Terrain::print_teren3()
{
	

	for (int i = 20; i <= 140; i++)
	{
		if ((i - 5) % 15 == 0) {
			goto jump2;
		}

		conOut(29, i) << char(220);
	jump2:;
	}

	for (int i = 20; i <= 140; i++)
		conOut(25, i) << char(220);
	for (int i = 2; i <= 10; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

		conOut(25, 15 * i - 10) << char(220);
		conOut(29, 15 * i - 10) << char(220);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
}

void Terrain::print_teren4()
{
	

	for (int i = 20; i <= 140; i++)
	{
		if ((i - 5) % 15 == 0) {
			goto jump2;
		}

		conOut(14, i) << char(220);
	jump2:;
	}

	for (int i = 20; i <= 140; i++)
		conOut(10, i) << char(220);
	for (int i = 2; i <= 10; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

		conOut(10, 15 * i - 10) << char(220);
		conOut(14, 15 * i - 10) << char(220);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
}

void Terrain::print_teren5()
{


	for (int i = 20; i <= 140; i++)
	{
		if ((i - 5) % 15 == 0) {
			goto jump2;
		}

		conOut(34, i) << char(220);
	jump2:;
	}

	for (int i = 20; i <= 140; i++)
		conOut(30, i) << char(220);
	for (int i = 2; i <= 10; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

		conOut(30, 15 * i - 10) << char(220);
		conOut(34, 15 * i - 10) << char(220);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
}

void Terrain::print()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	switch (lv) {

	case(1): 
		print_teren1();
		break;
	case(2):{
		print_teren1();
		print_teren2();
		print_teren3();
	}break;
	case(3): {
		print_teren1();
		print_teren2();
		print_teren3(); 
		print_teren4();
		print_teren5();

	}break;

}
	Peashooter c;
	c.draw(11, 8);

	Sunflower d;
	d.draw(16, 7);

	CherryBomb e;
	e.draw(21, 8);

	WallNut f;
	f.draw(26, 8);
	Snow_Pea k;
	k.draw(31, 8);


}

Terrain::~Terrain()
{
}
