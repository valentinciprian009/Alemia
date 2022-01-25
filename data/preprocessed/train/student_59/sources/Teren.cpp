#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ConsoleOutput.h"
#include "Teren.h"
#include <Windows.h>

using namespace UserInterface;
using namespace std;

#define lungime_patratele 12
#define inaltime_patratele 5
#define lungime_joc 172
#define latime_joc 40
#define delta_X 15
#define delta_Y 5


Teren* Teren::getInstance()
{
	static Teren inst;
	return &inst;
}

COORD Teren::coordonate_click(int x, int y)
{
	int nr_benzi = nr_runda == 1 ? 1 : (nr_runda == 2 ? 3 : 5);
	x -= 28;
	y -= 7;
	if (x % delta_X > lungime_patratele || x / delta_X > 8 || x < 0 || y < 0 || y / delta_Y > nr_benzi - 1)
		return { -1, -1 };
	return { (short)(x / delta_X), (short)(y / delta_Y) };
}

void Teren::deseneaza_tot(int culoare)
{
	int nr_benzi = nr_runda == 1 ? 1 : (nr_runda == 2 ? 3 : 5);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, culoare);
	zona_scor();
	zona_resurse();
	zona_plante();
	zona_lupta(nr_benzi);
	SetConsoleTextAttribute(hConsole, 15);
}

void Teren::zona_scor()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int aux1 = 1; aux1 <= inaltime_patratele; aux1++)
		for (int aux = 12; aux <= lungime_patratele + 11; aux++)
			if (aux == 12 || aux1 == 1 || aux == lungime_patratele + 11 || aux1 == inaltime_patratele)
			{
				conOut(aux1, aux) << this->teren;
			}
	FILE *v = fopen("file.log", "a");
	fprintf(v, "Chenarul pentru scor a fost afisat.\n");
	fclose(v);
}

void Teren::zona_resurse()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 1; i <= 9; i++)
	{
		int var = i*delta_X;
		var = var + 13; //de aici setez distanta dintre scor si resurse
		for (int aux1 = var; aux1 <= var + lungime_patratele; aux1++) //orizontala cu coloane
		{
			for (int aux = 1; aux <= inaltime_patratele; aux++) //incepe de la prima linie
				if (aux == 1 || aux1 == var || aux == inaltime_patratele || aux1 == var + lungime_patratele)
					conOut(aux, aux1) << this->teren;
		}
	}
	FILE *v = fopen("file.log", "a");
	fprintf(v, "Zona de resurse a fost afisata.\n");
	fclose(v);
}

void Teren::zona_plante()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 1; i <= 5; i++)
	{
		int var = i*delta_Y + 2;
		for (int aux1 = var; aux1 < var + inaltime_patratele; aux1++)
		{
			for (int aux = lungime_patratele; aux <= lungime_patratele + 11; aux++) //aici ma uit pe orizontala
				if (aux == lungime_patratele || aux1 == var || aux == lungime_patratele + 11 || aux1 == var + inaltime_patratele - 1)
					conOut(aux1, aux) << this->teren;

		}
	}
	FILE *v = fopen("file.log", "a");
	fprintf(v, "Biblioteca cu planta a fost afisata.\n");
	fclose(v);
}

void Teren::zona_lupta(int nr_benzi)
{
#define h 7
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int h_aux = h;
	for (int j = 1; j <= nr_benzi; j++)
	{
		for (int i = 1; i <= 9; i++)
		{
			int var = i*delta_X;
			var = var + lungime_patratele + 1; //de aici setez distanta dintre plante si teren
			for (int aux1 = var; aux1 <= var + lungime_patratele; aux1++) //orizontala cu coloane
			{
				for (int aux = h_aux; aux <= inaltime_patratele + h_aux - 1; aux++) //incepe de la prima linie
					if (aux == h_aux || aux1 == var || aux == inaltime_patratele + h_aux - 1 || aux1 == var + lungime_patratele)
						conOut(aux, aux1) << this->teren;
			}
		}
		h_aux = h_aux + 5;
	}
	FILE *v = fopen("file.log", "a");
	fprintf(v, "Zona de lupta a fost afisata.\n");
	fclose(v);
}

void Teren::set_runda(int runda)
{
	nr_runda = runda;
}

Teren::Teren(int runda)
{
	this->nr_runda = runda;
}

Teren::Teren()
{
}

Teren::~Teren()
{
}