#pragma once
#include<math.h>
#include<windows.h>
#include<time.h>
#include"CPea.h"
#include"CPeaShooter.h"
#include"CSunFlower.h"
#include"CSun.h"
#include"CZombie.h"
#include"CBucketHead.h"
#include"Utilizator.h"

#include"ConsoleOutput.h"
#include"ConsoleInput.h"

class CGame
{
	Utilizator *player;

	int NrResurseDisponibile;
	Nivel *level;

	vector<CZombie*>zombie;
	vector<CPlanta*>plante;
	vector<CResursa*>resurse;
	vector<CProiectil*>proiectile;
	vector<bool>locAvailable;

	int TimeLastResources;
	int nrZombies;
	int plantaCurenta;

	void checkResources();
	void checkZombies();
	void checkProjectiles();
	void checkColisions();
	void checkWin();

public:
	CGame(Utilizator *player);
	void init();

	void addResurse(int nr) { NrResurseDisponibile += nr; displayResources(); }
	void consumaResurse(int nr) { NrResurseDisponibile -= nr; displayResources(); }

	void displayObjects();
	void displayResources();
	void displayScore();

	static bool lose;
	void printCH(int row,int col, char ch);
	void play();


	void resetPlante();
	void checkMouse();
	Utilizator* getPlayer();

	~CGame();
};

