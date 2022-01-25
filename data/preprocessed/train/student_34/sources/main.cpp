#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <string>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <conio.h>
#include "Terrain.h"
#include "Menu.h"
#include "Sun.h"
#include "Pick_and_plant.h"
#include "Peashooter.h"
#include <stdlib.h>
#include <mmsystem.h>
#include "Sunflower.h"
#include "WallNut.h"
#include "CherryBomb.h"
#include "Snow_Pea.h"
#include "Frozen_Pea.h"
#include "Pea.h"
#include "Zombie.h"
#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;
using namespace std;

void suns(Sun a)
{
	
	while (true) {
		
		static auto begin = steady_clock::now();
		auto end = steady_clock::now();
		if (duration_cast<milliseconds>(end - begin).count() > 10000)
		{
			begin = end;
			a._random();


		}
	}
}
void music() {
	
 PlaySound(TEXT("sound.wav"), NULL, SND_SYNC);
}

int main(void)
{
	FILE *f = fopen("p.txt", "w");
	fclose(f);
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	
	Menu a;
	a.print();
	Pea pea;
	
	while (true)
	{

		std::string action = conIn.getUserActions();
		a.coordonate(action);
		if (strstr(action.c_str(), "CLICK")) {
			if (68 <= atoi(a.get_x()) && atoi(a.get_x()) <= 83 && 20 <= atoi(a.get_y()) && atoi(a.get_y()) <= 25)
				break;
			if (68 <= atoi(a.get_x()) && atoi(a.get_x()) <= 83 && 30 <= atoi(a.get_y()) && atoi(a.get_y()) <= 35)
				exit(0);
		}

		if (action != "")
		{
			conOut(41, 2) << action;
		}
	}

	system("cls");
	char Username[30];
	conOut(19, 65) << "Username: ";
	cin >> Username;
	
	
	int lv;
	conOut(19, 65) << "Level (1,2 sau 3): ";
	cin >> lv;
	system("cls");
	
	Terrain b(lv);
	b.print();
	


	UserInterface::ConsoleInput ConIn = UserInterface::ConsoleInput::getInstance();
	Pick_and_plant pick;
	Peashooter peashooter;
	conOut(1, 145) << Username;
	Sun sun;
	int aux=0;
	

	thread s(suns, sun);
	thread mus(music);
	
	while (true)
	{
		std::string action1 = ConIn.getUserActions();
		a.coordonate(action1);
		pick.shoot_peashooter();	
		pick.spawn();
		
		if (strstr(action1.c_str(), "CLICK")) {
			pick.sun_coins(action1, a);
			pick.peashooter(action1,a,b);
			
			pick.sunflower(action1, a,b);
			pick.cherrybomb(action1, a,b);
			pick.snow_pea(action1, a,b);
			pick.wallnut(action1, a,b);
		}
		if (pick.spawn() == 2) {
			aux = 2;
			system("cls");
			conOut(35, 75) << "GAME OVER";
			goto jump;
		}
		}
	
  mus.join();
	
  s.join();

jump:
  Sleep(3000);
  exit(1);
	_getch();
		return 0;
	
}
