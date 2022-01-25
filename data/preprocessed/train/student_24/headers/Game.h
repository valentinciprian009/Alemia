#pragma once
#include "User.h"
#include "PlantChooser.h"
#include "BattleZone.h"
#include "ConsoleInput.h"
#include <conio.h>
#include "ConsoleOutput.h"
#include <string>
#include "SunZone.h"
#include "ConsoleInput.h"
#include <stdlib.h>
#include "Zombie.h"
#include "MyException.h"

class Game
{
private:
	static Game* instance;
	int resourceValue;
	int resourceFreq;
	User currentUser;
	bool state;
	PlantChooser* plants;
	SunZone* sunZone;
	BattleZone* battleZone;
	int iteration;

	int getNrLanes();
	Game();
	~Game();
	Game(const Game& old) = delete;
	static void manageClicks();
	static void updateScreen();
	static void buyPlant(int x, int y);
	static bool level1();
	static bool level2();
	static bool level3();
	void generateZombie(int lane);
	static bool checkLoss();
	static void operations();
	static void finishLevelWin();
	static void finishLevelLoss();
	static void recreateBattleZone();
	static void printExit();

public:
	static void setIteration(const int iter);
	static int getIteration();
	static void run();
	static void printScoreBoard();
	static Game* getInstance();
	static void destroyInstance();
	static void setResourceVal(int val);
	static void addToScore(int toAdd);
	static void addResourceFreq(int freq);
	static BattleZone* getBattleZone();
};

