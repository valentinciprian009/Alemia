#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <time.h>
//#include <unistd.h>
#include <Windows.h>
#include <chrono>
#include <conio.h>
#include "Field.h"
#include "Resource.h"
#include "Sun.h"
#include "Proiectil.h"
#include "Pea.h"
#include "Frozen_Pea.h"
#include "Plants.h"
#include "PEASHOOTER.h"
#include "SUNFLOWER.h"
#include "Cherry_BOMB.h"
#include "WALL_NUT.h"
#include "SNOW_PEA.h"
#include "Zombie.h"
#include "BucketHead_Zombie.h"
#include "PoleVaulting_Zombie.h"
#include "Super_Zombie.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Log.h"

using namespace std;

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;

void doLoadingBar()
{

	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{

		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS)
		{

			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;

		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}

	}

}

void deseneaza_terenul_de_sori(Resource* sun, int dimensiune_sori, int scor_plants, int scor_zombies)
{
	/*int vect_resurse[8];
	for (int i = 0; i < dimensiune_sori; i++)
	{

		if (strcmp(sun[i].get_string().c_str(), "SS") == 0)
			vect_resurse[sun[i].get_y()] = 1;

	}*/

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();


	conOut(1, 0) << "|  ----------     ----------   |   _______    _______    _______    _______    _______    _______    _______    _______   |";
	conOut(2, 0) << "| |          |   |          |  |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |";

	conOut(3, 0) << "| |    " << scor_plants << "     | : |     " << scor_zombies << "    | ";

	for (int i = 0; i < 8; i++)
		if (sun[i].get_aparitie() == 1)
			conOut(3, 30 + i * 11) << " |  |   SS ";
		else
			conOut(3, 30 + i * 11) << " |  |      ";

	conOut(3, 118) << " |  |";
	conOut(4, 0) << "| |          |   |          |  |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |";
	conOut(5, 0) << "|  ----------     ----------   |  |_______|  |_______|  |_______|  |_______|  |_______|  |_______|  |_______|  |_______|  |";
}

void deseneaza_terenul(Plants **flori, Zombie** monstrii, Plants* floare_next, Resource* sun, int dimensiune_plants, int dimensiune_zombie, int scor_plants, int scor_zombies)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

//	int vect_flori[5];
	int teren[6][9];
//	int teren_mare[41][6][9];
//	int vect_resursa[8];

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 9; j++)
			teren[i][j] = 0;

	for (int i = 0; i < dimensiune_plants; i++)
		if (strcmp(flori[i]->get_plant().c_str(), "PS") == 0)
			teren[flori[i]->get_x()][flori[i]->get_y()] = 4;
		else if (strcmp(flori[i]->get_plant().c_str(), "PF") == 0)
			teren[flori[i]->get_x()][flori[i]->get_y()] = 5;
		else if (strcmp(flori[i]->get_plant().c_str(), "PC") == 0)
			teren[flori[i]->get_x()][flori[i]->get_y()] = 6;
		else if (strcmp(flori[i]->get_plant().c_str(), "PW") == 0)
			teren[flori[i]->get_x()][flori[i]->get_y()] = 7;
		else if (strcmp(flori[i]->get_plant().c_str(), "PN") == 0)
			teren[flori[i]->get_x()][flori[i]->get_y()] = 8;

	for (int i = 0; i < dimensiune_zombie; i++)
		if (strcmp(monstrii[i]->get_zombie().c_str(), "ZZ") == 0)
			teren[monstrii[i]->get_x()][monstrii[i]->get_y()] = 9;
		else if (strcmp(monstrii[i]->get_zombie().c_str(), "ZB") == 0)
			teren[monstrii[i]->get_x()][monstrii[i]->get_y()] = 10;
		else if (strcmp(monstrii[i]->get_zombie().c_str(), "ZP") == 0)
			teren[monstrii[i]->get_x()][monstrii[i]->get_y()] = 11;
		else if (strcmp(monstrii[i]->get_zombie().c_str(), "ZS") == 0)
			teren[monstrii[i]->get_x()][monstrii[i]->get_y()] = 12;




/*	for (int i = 0; i < 6; i++)
	{

		for (int j = 0; j < 9; j++)
			if (teren[i][j] == 0)
				cout << "00";
			else if (teren[i][j] == 1)
				cout << "SS";
			else if (teren[i][j] == 2)
				cout << "--";
			else if (teren[i][j] == 3)
				cout << "**";
			else if (teren[i][j] == 4)
				cout << "PS";
			else if (teren[i][j] == 5)
				cout << "PF";
			else if (teren[i][j] == 6)
				cout << "PC";
			else if (teren[i][j] == 7)
				cout << "PW";
			else if (teren[i][j] == 8)
				cout << "PN";
			else if (teren[i][j] == 9)
				cout << "ZZ";
			else if (teren[i][j] == 10)
				cout << "ZB";
			else if (teren[i][j] == 11)
				cout << "ZP";
			else if (teren[i][j] == 12)
				cout << "ZS";
			else
				cout << "00";

	}*/
	
	for (int i = 0; i < 5; i++)
	{

		conOut(6 + 7*i, 0) << "|______________________________|__________________________________________________________________________________________|";
		conOut(7 + 7*i, 0) << "|                              |                                                                                          |";

		conOut(8 + 7*i, 0) << "|             /  \\             |    __--__     __--__    __--__     __--__     __--__      __--__     __--__     __--__   |";
		conOut(9 + 7 * i, 0) << "|            /    \\            |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |";

		for (int j = 0; j < 9; j++)
		{
			/*if (teren[i][j] == 1)
				conOut(8 +5*i, ) << "SS";
			else if (teren[i][j] == 2)
				cout << "--";
			else if (teren[i][j] == 3)
				cout << "**";*/
			if (teren[i][j] == 4)
			{
				conOut(10 +7 *i, 0) << "|              " << "PS" << "              |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |";
			}
			else if (teren[i][j] == 5)
				conOut(10 +7 * i, 0) << "|              " << "PF" << "              |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |";
			else if (teren[i][j] == 6)
				conOut(10+7*i, 0) << "|              " << "PC" << "              |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |";
			else if (teren[i][j] == 7)
				conOut(10+7*i, 0) << "|              " << "PW" << "              |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |";
			else if (teren[i][j] == 8)
				conOut(10+7*i, 0) << "|              " << "PN" << "              |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |";
		}

	/*	for (int i = 0; i < 6; i++)
			for (int j = 0; j < 9; j++)
			{
					else if (teren[i][j] == 9)
				conOut() << "|              " << "ZZ" << "              |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |" << endl;
			else if (teren[i][j] == 10)
				conOut() << "|              " << "ZB" << "              |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |" << endl;
			else if (teren[i][j] == 11)
				conOut() << "|              " << "ZP" << "              |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |" << endl;
			else if (teren[i][j] == 12)
				conOut() << "|              " << "ZS" << "              |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |" << endl;
		
			}
*/
		conOut(11 + 7 * i, 0) << "|            \\    /            |   |      |   |      |  |      |   |      |   |      |    |      |   |      |   |      |  |";
		conOut(12+7*i, 0) << "|             \\  /             |   |______|   |______|  |______|   |______|   |______|    |______|   |______|   |______|  |";


	}


	//conOut(41, 0) << "|______________________________|__________________________________________________________________________________________|";
}

int main(void)
{

	
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	//conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";

	
	Resource *resursa = new Sun[8];
	Plants* floare_next = new PEASHOOTER[5];


	Plants *floare;
	Plants **flori = new Plants*[5];

	Zombie *monstru;
	Zombie **monstrii = new Zombie*[5];
	
	for (int i = 0; i < 2; i++)
	{

		floare = new PEASHOOTER();
		floare_next[i].set_x(0);
		floare_next[i].set_y(i);

		floare->set_x(i);
		floare->set_y(i);
		flori[i] = floare;

		monstru = new Zombie();
		monstru->set_x(3+i);
		monstru->set_y(4+i);
		monstrii[i] = monstru;

	}

	for (int i = 2; i < 5; i++)
	{

		floare = new SUNFLOWER();
		floare->set_x(i);
		floare->set_y(i);
		flori[i] = floare;

		floare_next[i].set_x(0);
		floare_next[i].set_y(i);

		monstru = new BucketHead_Zombie();
		monstru->set_x(3+i);
		monstru->set_y(i+4);
		monstrii[i] = monstru;

	}

	
	/*system("cls");
	string player = conIn.getUserActions();
	player = "Introduceti player";
	conOut(35, 25)<< player;*/


	//int i = 0;
	int aleator;
	int dimensiune_sori = 0;
	bool first_time = true;

	static auto begin = steady_clock::now();


	while (true)
	{

		auto end = steady_clock::now();
		if (first_time || duration_cast<milliseconds>(end - begin).count() > 1000)
		{
			first_time = false;
			begin = end;
	
			aleator = rand() % 8;
			if (resursa[aleator].get_aparitie() == 0)
			{

				resursa[aleator].set_aparitie(1);
				dimensiune_sori++;

			}

			//system("cls");
			deseneaza_terenul_de_sori(resursa, dimensiune_sori, 0, 0);
			deseneaza_terenul(flori, monstrii, floare_next, resursa, 5, 5, 0, 0);
		}	
		std::string action = conIn.getUserActions();
		//conOut(41, 2) << "mesaj";
		//if (action != "")
		//{
			conOut(41, 2) << action;
		//}
	}

	
	while (true)
	{

		// doLoadingBar();
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 2) << action;
			//break;


		}

	}

	_getch();
	return 0;
}