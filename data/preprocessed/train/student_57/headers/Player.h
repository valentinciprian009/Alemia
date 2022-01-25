#pragma once
#include <string>
using namespace std;
class Player
{
private:
	string name;
	int score;
	int resurse;
public:
	Player() :name("Default"), score(0), resurse(50) {};
	Player(string nume, int s,int r) :name(nume), score(s), resurse(r) {};
	Player(string nume, int s) :name(nume), score(s),resurse(50) {};
	void setNume(string n);
	string getNume();
	int getScore();
	int getResurse();
	void modifyScore(int i);
	void modifyRes(int i);
};

