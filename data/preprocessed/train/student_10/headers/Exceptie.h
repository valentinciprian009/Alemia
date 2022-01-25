#pragma once
#include <string>
#include <iostream>
#include <conio.h>


using namespace std;


class Exceptie
{
	string mesaj_eroare;
	int cod_eroare;
public:
	Exceptie();
	Exceptie(int cod, string mesaj) :mesaj_eroare(mesaj), cod_eroare(cod) {};
	void afiseaza_exceptia();
	~Exceptie();
};

