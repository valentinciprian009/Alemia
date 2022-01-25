#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "ConsoleHandler.h"


#include "Entity.h"
#include "LifeForm.h"
#include "SunFlower.h"
#include "PeaShooter.h"
#include "Zombie.h"
#include"BucketZombie.h"

#include<vector>
#include<Windows.h>
#include <time.h>
#include <chrono>
#include<iostream>

using namespace std;

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

#define COL_M 100
#define ROW_M 3

#define terr_1 11
#define terr_2 15
#define terr_3 19

#define zmb 130

using namespace std::chrono;


void doTerrain() {
	Entity icons[2];
	icons[0].set_all(terr_1, 10, "PS");
	icons[1].set_all(terr_2, 10, "S");
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(terr_1, 10) << "PS";
	conOut(terr_1 + 1, 10) << "50";
	conOut(terr_2, 10) << "S";
	conOut(terr_2 + 1, 10) << "25";
	for (int i = 0; i < ROW_M; ++i)
		conOut(10 + i, 20) << "|";
	for (int j = 0; j < COL_M; ++j)
	{
		conOut(9, 20 + j) << "#";
		if (j%10==0 && j<80)
		{
			for (int i = 0; i < ROW_M; ++i)
				conOut(10 + i, 30+j) << ".";
		}
		else if (j % 10 == 5 && j<80)
			{
				//conOut(11, 20+j) << "p";
			}
	}
	for (int i = 0; i < ROW_M; ++i)
		conOut(14 + i, 20) << "|";
	for (int j = 0; j < COL_M; ++j)
	{
		conOut(13, 20 + j) << "#";
		if (j % 10 == 0 && j<80)
		{
			for (int i = 0; i < ROW_M; ++i)
				conOut(14 + i, 30 + j) << ".";
		}
	}
	for (int i = 0; i < ROW_M; ++i)
		conOut(18 + i, 20) << "|";
	for (int j = 0; j < COL_M; ++j)
	{
		conOut(17, 20 + j) << "#";
		if (j % 10 == 0 && j<80)
		{
			for (int i = 0; i < ROW_M; ++i)
				conOut(18 + i, 30 + j) << ".";
		}
		conOut(21, 20 + j) << "#";
	}

}

int main(void)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	doTerrain();
	cout << '\n';
	int cor1 = zmb;
	while (true)
	{
		int i = 0;
	
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 2) << action;
		}
		vector <Zombie> Zomb;
		Zomb[i].set_coord(terr_1, cor1--);
		//Zomb[i].print_icon();
		Sleep(100);
		i++;
	}
	conOut(11, 10) << "z";

	return 0;
}

