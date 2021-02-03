#pragma once
#include <iostream>

using namespace std;

class PlayGround
{
private:
	PlayGround() {};
	~PlayGround() {};

	static PlayGround* instance;
public:
	static PlayGround& getInstance(void);
	static void destroyInstance();

	void printFirstLevel();
	void printSecondLevel();
	void printThirdLevel();
};
