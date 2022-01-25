#define _CRT_SECURE_NO_WARNINGS
#include "CActions.h"

#include "CPlants.h"
#include "CLevel_1.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include <time.h>
#include <chrono>
#include <iostream>

using namespace std::chrono;

#define latura 10



CLevel_1 *CLevel_1::Instance = NULL;

CLevel_1 & CLevel_1::getInstance()
{
	if (Instance == NULL)
		Instance = new CLevel_1;
	return *Instance;
}

void CLevel_1::destroyInstance()
{
	if (Instance != NULL)
		delete Instance;
	Instance = NULL;
}

void CLevel_1::print_scena()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < latura * 9; i++)
	{
		conOut(this->y_origins, this->x_origins + i,15) << L"▀";
		conOut(this->y_origins+latura/2, this->x_origins + i, 15) << L"▀";
		
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < latura / 2; j++)
		{
			conOut(this->y_origins + j, this->x_origins + latura * i , 15) << L"█";
		}
	}
	
}

int CLevel_1::planteaza(int &a, int &b)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();

	while (true)
	{

		std::string com = conIn.getUserActions();
		if (com != "")
		{
			char*sir = _strdup(com.c_str());
			if (strstr(sir, "clicked"))
			{
				a = atoi(strtok(sir, "(),"));
				a = atoi(strtok(NULL, "(),"));
				b = atoi(strtok(NULL, "(),"));
				if (b > this->y_origins && b < this->y_origins+4)
				{
					for (int i = 0; i < 9; i++)
					{
						if (a >= this->x_origins + latura * i && a < this->x_origins + latura * i + 10 && teren[0][i] == 0)
						{
							this->teren[0][i] = 1;
							a = this->x_origins + latura * i + 3;
							b = this->y_origins + 1;
							return 1;
						}
					}
					
				}
			}
		}
		if (!this->ruleaza())
			break;
		conOut(40, 22, 9) << com;
	}
	return 0;
}

void CLevel_1::game()
{

	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	CActions &act = CActions::getInstance();


	CLevel_1 &level_1 = CLevel_1::getInstance();
	level_1.print_sun();
	level_1.print_plants();
	level_1.print_scena();
	while (true)
	{

		std::string clicked = conIn.getUserActions();
		if (clicked != "")
		{
			char* w = _strdup(clicked.c_str());
			if (strstr(w, "clicked"))
			{
				int x = atoi(strtok(w, "(,)"));
				x = atoi(strtok(NULL, "(,)"));
				int y = atoi(strtok(NULL, "(,)"));
				level_1.colect_sun(y, x);
			    level_1.select_plant(y, x);
			}
			
		}
		
		if (!this->ruleaza())
			break;
		conOut(40, 22, 9) << clicked;
	}
}

CLevel_1::CLevel_1()
{
	for (int i = 0; i < 9; i++)
	{
		this->sun[i] = 0;
		this->teren[0][i] = 0;
	}
	this->scor_jucator = 0;

	this->n_zombs = 20;

	this->n_lines = 1;
	this->n_colums = 9;

	this->x_origins = 35;
	this->y_origins = 20;

	this->start_time_zombs = 60000;

}


CLevel_1::~CLevel_1()
{
}
