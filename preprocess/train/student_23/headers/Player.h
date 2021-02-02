#pragma once
#include <string.h>
#include <iostream>

using namespace std;

class Player
{
private:
	string Name;
	int Level;
	int Score;
	int Budget;
	static Player* instance;
	Player() { this->Name = " "; this->Level = 1; this->Score = 0; this->Budget = 0; };
	~Player() {};
	Player(const Player&) {};
public:
	static Player& getInstance(void);
	static void destroyInstance();
	void setPlayer(string name, int level = 1, int score = 0, int budget = 0);
	void setLevel(int level);
	void setScore(int score);
	void setBudget(int budget);
	string getName() { return this->Name; };
	int getLevel() { return this->Level; };
	int getScore() { return this->Score; };
	int getBudget() { return this->Budget; };
};