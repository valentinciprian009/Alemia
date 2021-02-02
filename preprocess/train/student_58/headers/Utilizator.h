#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include"History.h"

class Utilizator
{
	string name;
	string password;
	int scor;
	Nivel* nivel;

	History history;

public:
	Utilizator(string name, string pass);

	void setScor(int nr) { scor = nr; }
	void setLevel(int level);
	void getHistory();

	string getName() { return name; }
	string getPass() { return password; }
	int getScor() { return scor; }
	Nivel *getLvl() { return nivel; }

	~Utilizator(){}
};

