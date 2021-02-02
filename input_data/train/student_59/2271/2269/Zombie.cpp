#include "Zombie.h"
#include "Jucatori.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include <time.h>
#include <thread> //sleep_for
#include <tuple>
#include <windows.h>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

Zombie::Zombie()
{
	this->scor_obtinut = 20;
}

void Zombie::init(char forma, int atac, int viteza, int viata)
{
	this->forma = forma;
	this->atac = atac;
	this->viteza = viteza;
	this->viata = viata;
}

char Zombie::get_nume()
{
	return this->forma;
}

int Zombie::get_viata()
{
	return this->viata;
}

int Zombie::get_viteza()
{
	return this->viteza;
}

int Zombie::get_atac()
{
	return this->atac;
}

int Zombie::get_scor()
{
	return this->scor_obtinut;
}

char Zombie::get_forma()
{
	return this->forma;
}

void Zombie::amplasare(Jucatori jucator, string nume, vector<tuple<char, int, int, int>> &X)
{
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 5000) //asta e timpul cu care apar zombie
	{
		begin = end;
		srand(time(NULL));
		int z[] = { 34, 49, 64, 79, 94, 109, 124, 139, 154 };
		int lv2[] = { 9, 14, 19 };
		int lv3[] = { 9, 14, 19, 24, 29 };
		static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

		if (jucator.get_nivel(nume) == 1)
		{
			conOut(9, 154) << this->forma;
			X.push_back(make_tuple(this->forma, 9, 154, this->viata));
		}
		else if (jucator.get_nivel(nume) == 2)
		{
			int y = rand() % 3;
			conOut(lv2[y], 154) << this->forma;
			X.push_back(make_tuple(this->forma, lv2[y], 154, this->viata));
		}
		else if (jucator.get_nivel(nume) == 3)
		{
			int y = rand() % 5;
			conOut(lv3[y], 154) << this->forma;
			X.push_back(make_tuple(this->forma, lv3[y], 154, this->viata));
		}
	}
}

//char get_char_at_xy(int x, int y) /// chestie gasita pe net ca sa vada daca in consola la o anumita pozitie e un caracter; 
//									//ar fi genial daca ati putea face asta sa mearga 
//{									// ar fi un Christmas Gift bun pentru viitorul an 2 ^_^
//	CHAR_INFO ci;
//	COORD xy = { 0, 0 };
//	SMALL_RECT rect = { x, y, x, y };
//	return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, 1, xy, rect)
//		? ci.Char.AsciiChar
//		: '\0';
//}

int verificare_spatiu_liber(vector<tuple<char, int, int, int>> X, int x, int y, vector<tuple<char, int, int>> Y)
{
	//9 + 5 * y0, 34 + 15 * xp
	for (int i = 0; i < Y.size(); i++)
		if (34 + 15 * get<1>(Y[i]) == x && 9 + 5 * get<2>(Y[i]) == y) //daca pe pozitia pe care vreau sa mut obiectul nu e altceva
			return i;
	return -1;
}

void Zombie::miscare(Jucatori jucator, string nume, vector<tuple<char, int, int, int>> &X, vector<tuple<char, int, int>> &Y, vector<Pea> &P)
{
	int maxim;
	if (jucator.get_nivel(nume) == 1) maxim = 9;
	else if (jucator.get_nivel(nume) == 2) maxim = 19;
	else maxim = 29;

	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();

	//ciocnim zombie-ul cu proiectilele
	for (int z = 0; z<X.size(); z++)
	{
		while (true)
		{
			int ii = -1;
			for (int i = 0; i<P.size(); i++)
				if (34 + 15 * P[i].get_x() == get<2>(X[z]))
				{
					ii = i;
					break;
				}
			if (ii != -1)
			{
				P.erase(P.begin() + ii);
				get<3>(X[z])--;
				conOut(get<1>(X[z]), get<2>(X[z])) << get<0>(X[z]);
			}
			else
				break;
		}
	}

	//stergem zombie care au viata 0
	vector<tuple<char, int, int, int>> XX;
	for (auto z : X)
		if (get<3>(z) > 0)
			XX.push_back(z);
		else
			conOut(get<1>(z), get<2>(z)) << " ";
	X = XX;

	if (duration_cast<milliseconds>(end - begin).count() > this->viteza)
	{
		begin = end;
		for (int i = 0; i < X.size(); i++)
		{
			int j = get<1>(X[i]);
			int k = get<2>(X[i]);

			conOut(j, k) << " "; //sterg pozitia precedenta

			if (verificare_spatiu_liber(X, get<2>(X[i]) - 15, get<1>(X[i]), Y) != -1 && get<0>(X[i]) != '3') //daca e o planta in celula urmatoare o omor
			{
				int iplanta = verificare_spatiu_liber(X, get<2>(X[i]) - 15, get<1>(X[i]), Y);
				Y.erase(Y.begin() + iplanta);
			}
			if (verificare_spatiu_liber(X, get<2>(X[i]) - 15, get<1>(X[i]), Y) == -1) //aici verific daca locul unde vreau sa il mut este liber 
			{
				get<2>(X[i]) = k - 15; //il mut la stanga
				if (get<2>(X[i]) == 34) //daca a ajus pe prima coloana am pierdut
				{
					system("cls");
					conOut(20, 85) << "GAME OVER !";
					sleep_for(seconds(2));
					exit(0);
				}
			}
			if (verificare_spatiu_liber(X, get<2>(X[i]) - 30, get<1>(X[i]), Y) == -1 && get<0>(X[i]) == '3') //daca urmatoarea casuta e libera si daca zombie-ul e saltaret il mut
			{
				get<2>(X[i]) = k - 30; //il mut la stanga
				conOut(get<1>(X[i]), get<2>(X[i])) << get<0>(X[i]); //la noile coordonate mut obiectul
			}

			conOut(get<1>(X[i]), get<2>(X[i])) << get<0>(X[i]); //la noile coordonate mut obiectul
		}
	}
}

Zombie::~Zombie()
{
}