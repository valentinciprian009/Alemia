#define _CRT_SECURE_NO_WARNINGS

#include "Sun.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Jucatori.h"
#include "Sunflower.h"

#include <time.h>
#include <chrono>
#include <string>
#include <conio.h>
#include <thread> //for sleep_for
#include <iostream>
#include <stdio.h>

using namespace std::chrono;
using namespace std::this_thread;

Sun::Sun()
{
}

int verificare_sunflower(vector<tuple<char, int, int>> Y)
{
	int sf = 0;
	for (int i = 0; i < Y.size(); i++)
		if (get<0>(Y[i]) == 'b') //daca a gasit o planta de tip sunflower pe teren returneaza true ----'b' e forma sunflower
			sf++;
	return sf;
} 

void Sun::amplasare(Jucatori jucator, string nume, vector<tuple<char, int, int>> Y, tuple<int, COORD> &action)
{
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();

	this->timp = 5000 / (verificare_sunflower(Y) + 1);

	int z[] = { 34, 49, 64, 79, 94, 109, 124, 139, 154 };

	if (duration_cast<milliseconds>(end - begin).count() > this->timp) //asta e timpul cu care apar resursele
	{
		begin = end;
		srand(time(NULL));
		int y = rand() % 9;
		conOut(3, z[y]) << this->forma;
	}

	FILE *v = fopen("file.log", "a");
	fprintf(v, "A fost afisata o resursa de tip SUN.\n");
	fclose(v);

	if (action._Myfirst._Val == DOUBLE_CLICK)
		if (get<1>(action).Y >= 1 && get<1>(action).Y <= 5 && get<1>(action).X >= 30 && get<1>(action).X <= 160)
		{
			for (int i = 0; i < 9; i++)
				if ((std::get<1>(action).X <= z[i] + 5 && std::get<1>(action).X >= z[i] - 5) && (std::get<1>(action).Y == 3 || std::get<1>(action).Y == 2 || std::get<1>(action).Y == 1 || std::get<1>(action).Y == 4 || std::get<1>(action).Y == 5))
				{
					conOut(3, z[i]) << " ";

					jucator.plus_credit(nume, this->cost); 
					break;
				}
		}
}

Sun::~Sun()
{
}