#define _CRT_SECURE_NO_WARNINGS
#include "CLevel_2.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "CActions.h"

#include <iostream>
#include <time.h>


#include <chrono>

using namespace std::chrono;
#define latura 10

CLevel_2 *CLevel_2::Instance = NULL;

void CLevel_2::destroyInstance()
{
	if (Instance != NULL)
		delete Instance;
	Instance = NULL;
}

CLevel_2::CLevel_2()
{
	for (int i = 0; i < 9; i++)
		this->sun[i] = 0;
	this->scor_jucator = 0;

	this->n_lines = 3;
	this->n_colums = 9;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
			this->teren[i][j] = 0;
	}
	this->n_zombs = 50;
	this->start_time_zombs = 60000;


	this->x_origins = 35;
	this->y_origins = 15;
}

int CLevel_2::planteaza(int &a, int &b)
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
				for (int k = 0; k < 3; k++)
				{
					if (b > this->y_origins + latura/2*k && b < this->y_origins + 4+ latura/2 * k)
					{
						for (int i = 0; i < 9; i++)
						{
							if (a >= this->x_origins + latura * i && a < this->x_origins + latura * i + 10 && teren[k][i] == 0)
							{
								this->teren[k][i] = 1;
								a = this->x_origins + latura * i + 3;
								b = this->y_origins + 1+ latura/2 * k;
								return 1;
							}
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

void CLevel_2::game()
{
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	CActions &act = CActions::getInstance();

	CLevel_2 &level_2 = CLevel_2::getInstance();

	level_2.print_sun();
	level_2.print_plants();
	level_2.print_scena();
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
				level_2.colect_sun(y, x);
				level_2.select_plant(y, x);
			}
		}
		
		if (!this->ruleaza())
			break;
		conOut(40, 22, 9) << clicked;
	}
}

void CLevel_2::print_scena()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < latura * 9; i++)
		{
			conOut(this->y_origins, this->x_origins + i, 15) << L"▀";
			conOut(this->y_origins + latura / 2, this->x_origins + i, 15) << L"▀";

		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < latura / 2; j++)
			{
				conOut(this->y_origins + j, this->x_origins + latura * i, 15) << L"█";
			}
		}
		this->y_origins += 5;
	}
	this->y_origins = 15;
}

CLevel_2 & CLevel_2::getInstance()
{
	if (Instance == NULL)
	{
		Instance = new CLevel_2;
	}
	return *Instance;
}


CLevel_2::~CLevel_2()
{
}
