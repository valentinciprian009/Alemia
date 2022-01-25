#define _CRT_SECURE_NO_WARNINGS

#include "Plante.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include "Jucatori.h"
#include "Teren.h"

#include <time.h>
#include <chrono>
#include <string>
#include <conio.h>
#include <vector>
#include <thread> //for sleep_for
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std::chrono;
using namespace std::this_thread;
using namespace std;

Planta::Planta()
{
}

void Planta::init(char forma, int pret, int viata)
{
	this->forma = forma;
	this->pret = pret;
	this->viata = viata;
}

void Planta::amplasare(char forma)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	if (forma == 'a') { conOut(9, 17) << forma; FILE *v = fopen("file.log", "a"); fprintf(v, "A fost afisata planta PEASHOOTER.\n");  fclose(v); }
	else if (forma == 'b') { conOut(14, 17) << forma; FILE *v = fopen("file.log", "a"); fprintf(v, "A fost afisata planta SUNFLOWER.\n");   fclose(v); }
	else if (forma == 'c') { conOut(19, 17) << forma; FILE *v = fopen("file.log", "a"); fprintf(v, "A fost afisata planta CHERRY BOMB.\n"); fclose(v); }
	else if (forma == 'd') { conOut(24, 17) << forma; FILE *v = fopen("file.log", "a"); fprintf(v, "A fost afisata planta WALL-NUT.\n");    fclose(v); }
	else if (forma == 'e') { conOut(29, 17) << forma; FILE *v = fopen("file.log", "a"); fprintf(v, "A fost afisata planta SNOW PEASHOOTER.\n");    fclose(v); }
}

int Planta::planta_selectata = -1;

void Planta::actiune_plante(Jucatori jucator, std::string nume, vector<tuple<char, int, int>> &Y, tuple<int, COORD> action_1, vector<Planta> Plants)
{
	static auto conIn = UserInterface::ConsoleInput::getInstance();
	static auto conOut = UserInterface::ConsoleOutput::getInstance();

	int z[] = { 9,14,19,24,29 };

	for (auto t : Y)
		conOut(9 + 5 * get<2>(t), 34 + 15 * get<1>(t)) << get<0>(t);

	int x, y;
	char w;
	if (action_1._Myfirst._Val != DOUBLE_CLICK)
		return;

	if (get<1>(action_1).X >= 12 && get<1>(action_1).X <= 23)
	{
		for (int i = 0; i < 4; i++) 
		{							
			if ((std::get<1>(action_1).Y <= z[i] + 2 && std::get<1>(action_1).Y >= z[i] - 2)) 
			{
				w = Plants[i].forma;
				planta_selectata = i;
				Teren* teren = Teren::getInstance();
				teren->deseneaza_tot(7);
				return;
			}
		}
	}

	if (planta_selectata != -1)
	{
		x = std::get<1>(action_1).X;
		y = std::get<1>(action_1).Y;
		Teren* teren = Teren::getInstance();
		COORD d = teren->coordonate_click(x, y);
		if (d.X != -1)
		{
			if (Plants[planta_selectata].pret <= jucator.get_credit(nume))
			{
				Y.push_back(make_tuple(Plants[planta_selectata].forma, d.X, d.Y));
				jucator.plus_credit(nume, -Plants[planta_selectata].pret);
			}
			teren->deseneaza_tot(11);
			planta_selectata = -1;
		}
	}
}


char Planta::get_nume()
{
	return this->forma;
}

int Planta::get_viata()
{
	return this->viata;
}

int Planta::get_pret()
{
	return this->pret;
}

Planta::~Planta()
{
}