#pragma once
#include <vector>
#include "Sun.h"
#include "WalkerZombie.h"
#include "Pea.h"
class PeaShooter;
class BlankSpace;
class GenericFLower;
class Map
{
private:
	std::vector<Sun*> sunAssets;
	const int MAX_SUN_NUM = 10;
	const int SunColumnStart = 14;
	const int SunRowStart = 1;
	static Map* instance;

	std::vector<WalkerZombie*> ZombieAssets;
	const int MAX_ZOMBIE_NUM = 5;
	const int ZombieColumnStart = 61;
	const int ZombieRowStart = 7;

	const int sidebarStartRow = 6;
	const int sidebarStartCol = 3;

	std::vector<GenericFLower*> flowers;

	std::vector<Pea*> peas;
private:
	Map();
	~Map();
	Map(Map&);
	void addSun(Sun* Drawable);
	void movePea(Pea *pea);
	void movePeas();
	void removePea(Pea* pea);
	void printPea(Pea *pea, PeaShooter* shooter);
public:
	void printFlowersSidebar();
	static Map& getInstance();
	void addDrawable(AbstractDrawable* drawable);
	int getSunCount();
	AbstractDrawable* getClickedAsset(int col, int line);
	void printScore(int score);
	void printSori(int sori);
	void removeSun(int index);
	void addZombie(WalkerZombie * WZ);
	void plantFlower(BlankSpace* space, GenericFLower* flower);
	void runFlowersEffects();
	void removeZombie(WalkerZombie* WZ);
	void addPea(Pea *pea);
	bool hasPlant(GenericFLower* flower);
};

