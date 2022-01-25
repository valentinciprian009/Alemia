#define _CRT_SECURE_NO_WARNINGS

#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include<stdio.h>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <chrono>
#include "Harta.h"
#include "Soare.h"
#include <time.h>
#include "Zombie.h"
#include "Plante.h"

int valuesoare;

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define y 15
#define x 67

using namespace std::chrono;

void startgame() {
	char nume[999];
	system("CLS");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n						PLANTS VS ZOMBIES");
	printf("\n						USERNAME:");
		std::cin >> nume;
		system("CLS");
}

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";
	auto end = steady_clock::now();
	//while (duration_cast<seconds>(end - begin).count() < 5)
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
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
Harta map;
Soare s1;
Zombie z(100,15,'Z'); BucketZombie b(200,15,'B');
Peashooter p(50,100,25);
int main(void) {
	startgame();
#pragma region Chestii
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	//conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	int random = 0;
	char ***a;
	map.alocare(&a, x, 20);
	map.print(&a, x, y);
	int variabila[] = { 22,27,32,37,42,47,52,57 };
	int caz = 1, variabila1 = 0, variabila2 = 0, spawn = 0, plants = 1, viatazombie = 0, viataplanta = p.getviata(), numananca=1;
	char tipzombie[2];
#pragma region startTime
	double startTime = GetTickCount();
	double startTime2 = GetTickCount();
	double startTime3 = GetTickCount();
	double startTime4 = GetTickCount();
	double startTime5 = GetTickCount();
	double startTime6 = GetTickCount();
#pragma endregion
	while (caz) {

#pragma region Setari timp
		double aparitiesoare = GetTickCount() - startTime;
		double aparitiezombie = GetTickCount() - startTime2;
		double resetareharta = GetTickCount() - startTime3;
		double miscarezombie = GetTickCount() - startTime4;
		double tragereproiectil = GetTickCount() - startTime5;
		double mancareZombie = GetTickCount() - startTime6;
#pragma endregion

		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 2) << action;
		}
		if (resetareharta >= 1) {
			map.afisare(&a, 67, 15);
			startTime3 = GetTickCount();
		}
#pragma region LuatActiuni
		char buffer[100], *token;
		strcpy(buffer, action.c_str());
		token = strtok(buffer, "(),;\n ");
		while (token) {
			token = strtok(NULL, "(),;\n ");
			if (token == NULL)
				break;
			if ((sizeof(token) == 2 * sizeof(int)) && (variabila1 == 0))
				variabila1 = atoi(token);
			else if ((sizeof(token) == 2 * sizeof(int)) && (variabila1 != 0))
				variabila2 = atoi(token);
		}
#pragma endregion

#pragma region click soare
		if (variabila1 < 67 && variabila2 == 2)
			s1.click(&a, variabila1);
#pragma endregion

#pragma region Incercare Planta
		if (valuesoare >= 0)
			if (variabila2 == 5)
				if (variabila1 >= 1 && variabila1 <= 10) {
					p.setare(&a, 17, 1);
				}
#pragma endregion

#pragma region TimpiSetati
		if (aparitiezombie >= 10000 && spawn == 0)//10 seconds
		{
			srand(time(0));
			random = rand() % 2;
			if (random == 0) {
				a[9][63][0] = z.getnume();
				viatazombie = z.getlife();
				strcpy(tipzombie, "Z");		
				spawn = 1;
			}
			else {
				a[9][63][0] = b.getnume();
				viatazombie = b.getlife();
				strcpy(tipzombie, "B");			
				spawn = 1;
			}
				startTime2 = GetTickCount();

		}
		if (miscarezombie >= 5000 && spawn == 1 && numananca==1) {
			z.miscare(&a);
			b.miscare(&a);
			startTime4 = GetTickCount();
		}
		if (aparitiesoare >= 5000) //5 seconds
			{
				srand(time(0));
				random = rand() % 8;
				s1.aparitie(&a, 2, variabila[random]);
				startTime = GetTickCount();
				std::string action = conIn.getUserActions();
			}
		if (tragereproiectil >= 500 && plants == 1 && spawn==1) {
			p.shotpea(&a);
			if (p.IntalnireProiectil(&a) == true)
				viatazombie -= p.getdmg();
			if (viatazombie == 0) {
				if (strstr(tipzombie, "Z")) {
					z.death(&a);
					spawn = 0;
				}
				else if (strstr(tipzombie, "B")) {
					b.death(&a);
					spawn = 0;
				}
			}
			startTime5 = GetTickCount();
		}
		if (mancareZombie >= 500) {
			if (z.mananca(&a) == true) {
				viataplanta -= z.getdmg();
				numananca = 0;
			}
			else if (b.mananca(&a) == true) {
				viataplanta -= b.getdmg();
				numananca = 0;
			}
			if (viataplanta <= 0) {
				p.death(&a);
				numananca = 1;
				plants = 0;
			}
			startTime6 = GetTickCount();
		}
#pragma endregion
	}
	return 0;
}