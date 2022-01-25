#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <thread>
#include <chrono>
#include <sstream>
#include <random>
#include "Log.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "IDrawable.h"
#include "PlayGround.h"
#include "Player.h"
#include "Sun.h"
#include "Shop.h"
#include "Cadran.h"
#include "Proiectile.h"
#include "Plant.h"
#include "PeaShooter.h"
#include "FrozenPea.h"
#include "WallNut.h"
#include "SunFlower.h"
#include "CherryBomb.h"
#include "Zombie.h"
#include "SimpleZombie.h"
#include "BucketHeadZ.h"
#include "PoleVaultingZ.h"
#include "SuperZombie.h"

using namespace std;
using namespace std::chrono;

class GAME
{
private:
	GAME() {};
	~GAME() {};
	GAME(const GAME&) {};
	static GAME* instance;
public:
	static GAME& getInstance(void);
	static void destroyInstance();
	bool sunClicked(string action, int& X, int& Y);
	bool clickedInGarden(string action, int level, int& X, int& Y);
	bool searchPlantInVector(vector<Cadran*> locations, int X, int Y);
	void generateWave(vector<Zombie*>& zombies, int level);
	void printFirstWave(vector<Zombie*>& zombies, int level);
	void printSecondWave(vector<Zombie*>& zombies, int level);
	void printThirdWave(vector<Zombie*>& zombies, int level);
	void printForthWave(vector<Zombie*>& zombies, int level);
	void startGame();
};