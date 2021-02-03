#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Jucator.h"
#include "BattleField.h"

#include "Jurnal.h"
#include "ConsoleInput.h"
#include "DrawingLibrary.h"

#include <time.h>
#include <chrono>
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <chrono>
#include <time.h>

#include "Peashooter.h"
#include "Snow_Pea.h"
#include "Cherry_Bomb.h"
#include "Sunflower.h"
#include "Wall_nut.h"

#include "Zombie.h"
#include "BucketHead_Zombie.h"
#include "PoleVaulting_Zombie.h"
#include "Super_Zombie.h"

#include "CProiectil.h"

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

#define ROW_SCORE 5
#define COL_SCORE 50

#define ROW_Plant 9
#define COL_Plant 49

#define COL_FIRST_SUN              60
#define COL_DISTANCE_BETWEEN_SUNS  10

#define COL_FIRST_FIELD 60
#define COL_DISTANCE_BETWEEN_FIELDS 10
#define ROW_FIELD 9

using namespace std;

class Game
{
	int n, m;
	string name;
	int resurse;

	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();

	void doLoadingBar();
	void printBar();
	void printLevels();
	void logInBar();
	void youWin();
	void gameOver();

	//levels
	void go_lvl1();
	void go_lvl2();
	void go_lvl3();

	char getMyString(string mys);

	void drawScene(int n,int m,int level);
	
	int ZombieComing(int lvl,BattleField &b,int v1);

	class Point
	{
	private:
		int x, y;
	public:
		Point() {}
		Point(int a,int b):x(a),y(b) {}

		int getX() { return x; }
		int getY() { return y; }

	};

	BattleField loc_de_joaca;
	vector<Jucator*> jucatori;

public:

	Game() : name("Plants vs Zombie") { Jurnal *act = Jurnal::getInstance(); act->writeJurnal("Joc creat"); resurse = 0; }

	void setN(int n) { this->n = n; }
	void setM(int m) { this->m = m; }

	Point *getXY(string aux);

	void init_menu();
	void init_game(int n,int m);

	void verify(BattleField *f, int n, int m);

	void print();

	virtual ~Game();
};

