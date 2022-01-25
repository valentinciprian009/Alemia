#pragma once
#include <string>

class Player
{
	std::string name;
	std::string password;
	int availableSun;
	int currentLevel = 1;
	int maximumLevel = 1;


	static Player* instance;
	Player();
	~Player();
public:
	static Player& getInstance();
	static void destroyInstance();

	void setName(std::string name);
	void setPassword(std::string password);
	void increaseLevel();
	void setCurrentLevel(int x);

	std::string& getName();
	std::string& getPassword();
	int getCurrentLevel();
	int getMaximumLevel();
	int getAvailableSun();

	void increaseScore(int x);
	void decreaseScore(int x);
};

