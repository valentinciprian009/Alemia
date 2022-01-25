#pragma once
#include "Element.h"
#include <fstream>





class Joc
{
	static Joc* instanta;
	ElementeJoc elemente;
	ConsoleInput conIn;
	ConsoleOutput conOut;
	char matrice[5][8];
	bool sori_disponibili[8];
	steady_clock::time_point timp_soare;
	steady_clock::time_point timp_zombi;
	steady_clock::time_point timp_zombi_galeata;
	char cumparat;
	bool sfarsit;

	Joc() :sfarsit(false),conIn(ConsoleInput::getInstance()), conOut(ConsoleOutput::getInstance()), timp_soare(steady_clock::now()), timp_zombi(steady_clock::now()), timp_zombi_galeata(steady_clock::now()), cumparat('\0') { srand(time(NULL)); };
	void afiseaza_magazin();
	void afiseaza_sori();
	void afiseaza_matrice();
	void refresh_total();
	void verifica_final();
	void afiseaza_victorie();
	void afiseaza_infrangere();
	void verifica_click();
	void curata_ecran();
	void adauga_elemente();
	void afiseaza_bani();
	void joc_nou();
	bool continua();
	void afiseaza_scor();
public:
	static Joc& get_instance();
	void initializeaza();
	void joaca();
	bool terminat() { return sfarsit; };


	~Joc();
};

