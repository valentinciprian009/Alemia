#define _CRT_SECURE_NO_WARNINGS
#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Teren.h"
#include "Sun.h"
#include "Resurse.h"
#include "Jucatori.h"
#include "Plante.h"
#include "IPlante.h"
#include "IZombie.h"
#include "Zombie.h"
#include "BucketHead_Zombie.h"
#include "PoleVaulting_Zombie.h"
#include "Super_Zombie.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "Cherry_Bomb.h"
#include "Wall_nut.h"
#include "Pea.h"

#include <time.h>
#include <chrono>
#include <string>
#include <conio.h>
#include <thread> //sleep_for
#include <string>
#include <array>
#include <vector>

using namespace std::chrono;
using namespace std::this_thread;

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150) //asta e timpul cu care se misca stelutele
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) //cate stelute sa apara si pana unde
		{
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
}

int main(void) 
{
	//interfete
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	//afisari de inceput
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "      ~ POO VS ZOMBIE ~";
	sleep_for(seconds(1));
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "                        ";
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Introduceti numele jucatorului: ";
	char nume[50];
	cin >> nume;
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION + strlen("Introduceti numele jucatorului: ")) << nume;
	string name(nume);

	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION) << "Introduceti parola jucatorului: ";
	char parola[50];
	cin >> parola;
	string password = string(parola);
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + strlen("Introduceti parola jucatorului: ")) << password;
	sleep_for(seconds(1));
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "                                               ";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION) << "                                               ";

	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	int runda;
	int scor;
	int credit;

	//introduc jucator daca nu a fost introdus in trecut
	Jucatori jucator(nume, parola, scor, runda, credit);

	//verificare corespondenta username-parola   
	int ok = 0;

	if (jucator.get_parola(name) == password) { ok = 1; }
	if (ok == 0) { conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Parola introdusa nu corespune cu jucatorul introdus."; sleep_for(seconds(2)); exit(0); }


	//incarc jocul si stiu cate cate benzi trebuie sa aiba terenul
	int nr_benzi;
	if (runda == 1) nr_benzi = 1;
	else if (runda == 2) nr_benzi = 3;
	else nr_benzi = 5;
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	int i = 0;

	//afisez elementele: teren, resurse, plante, zombie
	Teren* teren = Teren::getInstance();
	teren->set_runda(runda);
	Sun sun;

	Peashooter P1;
	Sunflower P2;
	Cherry_Bomb P3;
	Wall_nut P4;

	P1.init('a', 5, 20); //nume, pret, atac, viata
	P2.init('b', 10, 20); // nume, pret, dublare resurse, viata
	P3.init('c', 15, 20);
	P4.init('d', 20, 60); //nume, pret,nu ataca (doar blocheaza), viata

	Zombie Z1;
	BucketHead_Zombie Z2;


	Z1.init('1', 5, 2000, 2); //nume, atac, viteza, viata
	Z2.init('2', 5, 1000, 5); //nume, atac, viteza, viata
							  
	vector<Zombie> Z;
	Z.push_back(Z1);
	Z.push_back(Z2);


	vector<Planta> Plants;
	Plants.push_back(P1);
	Plants.push_back(P2);
	Plants.push_back(P3);
	Plants.push_back(P4);

	sleep_for(seconds(2));

	//generez jocul
	system("Color 0B");
	vector<tuple<char, int, int, int>> X; //nume, x, y, healh pentru ZOMBIE - aici retin numele si pozitia zombie-ului pe care il afisez
	vector<tuple<char, int, int>> Y; //PLANTE
	vector<Pea> P;
	int z[] = { 0,1,2 };

	while (i < 3)
	{
	doLoadingBar();
	i++;
	sleep_for(seconds(1));
	}

	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "                        ";		//sterge bara de loading
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION) << "                        ";   //sterge stelutele alea

	teren->deseneaza_tot(11);

	for (int i = 0; i < 4; i++)
		Plants[i].amplasare(Plants[i].get_nume()); //afisez biblioteca de plante


	while (true)
	{
		std::tuple<int, COORD> action = conIn.getUserActions();
		if (action._Myfirst._Val == MOUSE_MOVED || action._Myfirst._Val == DOUBLE_CLICK)  //asta ar trebui sa imi arate in timp real cum imi misc mouse-ul
		{
			conOut(41, 2) << std::get<1>(action).X << " " << std::get<1>(action).Y << "     ";
		}
		jucator.afisare(name);
		sun.amplasare(jucator, name, Y, action);
		Planta::actiune_plante(jucator, nume, Y, action, Plants);		//functia asta imi ia planta dintr-o parte si o pune in alta

		P1.update(Y, P);
		vector<Pea> PP;
		for (Pea p : P)
			if (p.get_x() < 7)
				PP.push_back(p);
		P = PP;

		int aux = rand() % 2;
		Z[z[aux]].amplasare(jucator, nume, X);	//afisez zombie
		Z[0].miscare(jucator, nume, X, Y, P);			
	}
	return 0;
}