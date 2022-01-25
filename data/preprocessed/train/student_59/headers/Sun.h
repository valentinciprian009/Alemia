#pragma once
#include "Resurse.h"
#include "Jucatori.h"
#include "Sunflower.h"

#include<iostream>
#include<string>

using namespace std;
class Sun :
	public Resurse
{
private:
	int	timp = 6000;
	int cost = 10;
	char forma = '#';

public:
	Sun();
	void amplasare(Jucatori jucator, string nume, vector<tuple<char, int, int>> Y, tuple<int, COORD> &action);
	friend class Jucatori;
	friend class Sunflower;
	~Sun();
};

