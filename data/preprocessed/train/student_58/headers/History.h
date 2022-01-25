#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"

class Utilizator;
class History
{
	Nivel *level;
	int  scor;
public:
	History();
	void getHistoryFor(Utilizator& user);


	Nivel* getLevel() { return level; }
	int getScor() { return scor; }
	~History();
};

