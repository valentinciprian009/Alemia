#pragma once
#include "ConsoleOutput.h"
#include "Terrain.h"
#include "User.h"
#include "PlantTypes.h"

class Game
{
	void doLoadingBar();
	User user;
	PlantTypes selected_plant;
public:
	Terrain terrain;
	std::chrono::system_clock::time_point begin[20];
	std::chrono::system_clock::time_point end[20];
	std::vector<Projectiles> projectile;
	Game();
	~Game();
	void Loading();
	void ShowMenu();
	void BuildTerrain();
	void ShowCoordinates();
	void SpawnSuns();
	void CheckSun(std::string);
	void CheckPlant(std::string);
	void StorePlant(std::string action);
	void Move();
};

