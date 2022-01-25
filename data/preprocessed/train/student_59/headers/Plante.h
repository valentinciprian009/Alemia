#pragma once
#include<iostream>
#include<string>
#include <windows.h>
#include <vector>
#include "IPlante.h"
#include "Jucatori.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Jucatori.h"

using namespace std;


class Planta
{
public:
	static void actiune_plante(Jucatori jucator, std::string nume, vector<tuple<char, int, int>>&Y, tuple<int, COORD> action, vector<Planta> Plants);
	static int planta_selectata;

private:
	char forma;
	int viata;
	int pret;

public:
	Planta();

	void init(char forma, int pret, int viata);
	void amplasare(char forma);
	char get_nume();
	int get_viata();
	int get_pret();
	~Planta();
};

