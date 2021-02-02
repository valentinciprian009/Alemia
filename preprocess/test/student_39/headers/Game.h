//
// Created by null on 1/9/2020.
//

#ifndef INC_250_GAME_H
#define INC_250_GAME_H


#include "../ConsoleInput.h"
#include "../ConsoleOutput.h"
#include "../drawable/Drawable.h"
#include <vector>
#include "../terrain/Terrain.h"
#include "../menu/SunRes.h"
#include "../zombie/Zombie.h"
#include "../plant/Plant.h"
#include "Event.h"
#include "../projectile/Projectile.h"
#include "../menu/PlantResSelector.h"

class Game : public EventManager {

private:
	UserInterface::ConsoleInput* input;
	UserInterface::ConsoleOutput* output;
	std::vector<Drawable*> drawObjects;
	Terrain* terrain;
	PlantResSelector* plantResSelector;
	SunRes* sunRes;
	std::vector<Zombie*> zombies;
	std::vector<Plant*> plants;
	std::vector<Projectile*> projectiles;
	Plant* getPlantOnPosition(int row, int column);
	Zombie* getZombieOnPosition(int row, int column);
	int money = 300;
	bool isPlantInCell(int rowOffset, int collOffset);
	int time = 0;
	bool firstZombie = false;
	void spawnZombies();
	std::string userName;

	int loadScore(std::string& username);

public:
	Game(UserInterface::ConsoleInput* input, UserInterface::ConsoleOutput* output, int level, std::string username);
	void draw();
	void update();
	~Game();
	void onEvent(Event event, int row, int col, void* data) override;


};


#endif //INC_250_GAME_H
