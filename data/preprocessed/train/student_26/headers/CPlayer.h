#pragma once
#include <string>
using namespace std;
class CPlayer
{
	string nume;
	string parola;
	int maxLevel;
public:
	int getLevel() { return maxLevel; }
	void setNume(string);
	void setParola(string);
	string getNume();
	string getParola();
	CPlayer();
	~CPlayer();
};

