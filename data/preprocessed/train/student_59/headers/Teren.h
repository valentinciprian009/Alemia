#pragma once
#include "ConsoleOutput.h"
#include <windows.h>
#include<string>
#include <vector>

using namespace UserInterface;
using namespace std;

class Teren
{
private:
	char teren = char(220);
	int nr_runda;
	Teren(int runda);

public:
	static Teren* getInstance();

	COORD coordonate_click(int x, int y);

	void deseneaza_tot(int culoare);
	void zona_scor();
	void zona_resurse();
	void zona_plante();
	void zona_lupta(int nr_benzi);

	void set_runda(int runda);

	friend class ConsoleOutput;

	Teren();
	~Teren();
};

