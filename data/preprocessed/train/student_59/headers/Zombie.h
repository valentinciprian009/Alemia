#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Pea.h"
#include "IZombie.h"
#include "Jucatori.h"

using namespace std;

class Zombie :
	public IZombie
{
private:
	char forma;
	int viata;
	int viteza;
	int atac;
	int scor_obtinut;
public:
	Zombie();

	void init(char forma, int atac, int viteza, int viata);
	char get_nume();
	int get_viata();
	int get_viteza();
	int get_atac();
	int get_scor();
	char get_forma();
	void amplasare(Jucatori jucator, string nume, vector<tuple<char, int, int, int>> &X);

	void miscare(Jucatori jucator, string nume, vector<tuple<char, int, int, int>> &X, vector<tuple<char, int, int>> &Y, vector<Pea>& P);

	friend class Jucatori;
	friend class ConsoleOutput;

	~Zombie();
};

