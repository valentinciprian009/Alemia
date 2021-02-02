#define _CRT_SECURE_NO_WARNINGS
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <conio.h>
#include <chrono>
#include <fstream>
#include "CBucketheadZombie.h"
#include <iostream>
#include "CTeren.h"
#include "CProiectil.h"
#include "CPlayer.h"
#include "CTeren_1.h"
#include "CSunFlower.h"
#include "CZombie.h"
#include "CTeren_2.h"
#include "CWallNut.h"
#include "CTeren_3.h"
#include <Windows.h>
#include "CPlants.h"
#include "CPeaShooter.h"
#include "CSun.h"
#include <vector>
#include "CClassicZombie.h"
#include <sstream>
#include <algorithm>

int scoreboard = 150;
int contor_sori = 0;
string numeUtilizator;


#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

void checkIfClickedSun(int x_mouse, int y_mouse,int &scoreboard,ofstream &log)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	if ((x_mouse > 15) && (x_mouse != 15) && (x_mouse != 25) && (x_mouse != 35) && (x_mouse != 45) &&
		(x_mouse != 55) && (x_mouse != 65) && (x_mouse != 75) && (x_mouse != 85) && (x_mouse != 95))
	{
		x_mouse = x_mouse - 15;
		int numar_chenar = x_mouse / 10;
		CSun sun("test");
		if (sun.spawnPositions[numar_chenar] == 1)
		{
			sun.spawnPositions[numar_chenar] = 0;
			sun.deleteSun(numar_chenar);
			scoreboard += 25;
			conOut(3, 0) << scoreboard;
			log << "S-a facut double-click pe soarele de la pozitia " << numar_chenar << endl;
			contor_sori--;
		}
	}
}

int nr_chenar(int x,int y)
{
	x -= 15;
	y -= 6;
	x = x / 10;
	y = y / 5;
	x++;
	y++;
	int nr = x * 10 + y;
	return nr;
}

using namespace std::chrono;


vector<int> extractIntegerWords(string str)
{
	vector<int> v;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	stringstream ss;

	/* Storing the whole string into string stream */
	ss << str;

	/* Running loop till the end of the stream */
	string temp;
	int found;
	int i = 0;
	while (!ss.eof()) {

		/* extracting word by word from stream */
		ss >> temp;

		/* Checking the given word is integer or not */
		if (stringstream(temp) >> found)
		{
			v.push_back(found);
		}
		/* To save from space at the end of string */
		temp = "";
	}
	return v;
}

void checkIfClickedAfterClicked(char s,int level,vector<vector<CPlants*>> &matrice,int &perioadaAparitieSori,ofstream &log)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	std::string action = conIn.getUserActions();

	while (1)
	{
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			if (action.find("double") != string::npos)
			{
				vector<int> v = extractIntegerWords(action);
				int y = v[1];
				int x = v[0];
				int nr = nr_chenar(x, y);
				int coloana_chenar = nr % 10;
				nr /= 10;
				int linie_chenar = nr;

				if (level == 1)
				{
					if ((coloana_chenar == 4) || (coloana_chenar == 1 || (coloana_chenar == 2) || (coloana_chenar == 5)))
						return;

				}
				if (level == 2)
				{
					if ((coloana_chenar == 1) || (coloana_chenar == 5))
						return;

				}
				coloana_chenar--;
				linie_chenar--;


				y = 16 + 10 * linie_chenar;
				x = 9 + 5 * coloana_chenar;

				int aux = linie_chenar;
				linie_chenar = coloana_chenar;
				coloana_chenar = aux;

				CPeaShooter pea;
				CSunFlower sunFlower;
				CWallNut wallNut;
				switch (s)
				{
				case 'P':
					if (scoreboard >= pea.price)
					{
						if (matrice[linie_chenar][coloana_chenar] == NULL)
						{

							matrice[linie_chenar][coloana_chenar] = new CPeaShooter(x, y);
							log << "S-a creat un peashooter la pozitia [" << linie_chenar << "][" << coloana_chenar << "]\n";
							scoreboard -= pea.price;
							break;
						}
					}

				case 'S':
					if (scoreboard >= sunFlower.price)
					{
						if (matrice[linie_chenar][coloana_chenar] == NULL)
						{
							matrice[linie_chenar][coloana_chenar] = new CSunFlower(x, y);
							log << "S-a creat un sunflower la pozitia [" << linie_chenar << "][" << coloana_chenar << "]\n";
							perioadaAparitieSori--;
							scoreboard -= sunFlower.price;
							break;
						}
					}

				case 'W':
					if (scoreboard >= wallNut.price)
						if (matrice[linie_chenar][coloana_chenar] == NULL)
						{
							matrice[linie_chenar][coloana_chenar] = new CWallNut(x, y);
							log << "S-a creat un wall-nut la pozitia [" << linie_chenar << "][" << coloana_chenar << "]\n";
							scoreboard -= sunFlower.price;
							break;
						}
				}

				conOut(3, 0) << "   ";
				conOut(3, 0) << scoreboard;
				return;
			}
		}
	}
}

void checkIfClickedPlants(int y_mouse,int level,vector<vector<CPlants*>> &matrice,int &perioadaAparitieSori,ofstream &log)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	y_mouse = y_mouse - 6;
	int numar_chenar = y_mouse / 5;
	switch (numar_chenar)
	{
	case 0:
		checkIfClickedAfterClicked('P',level,matrice, perioadaAparitieSori,log);
		break;
	case 1:
		checkIfClickedAfterClicked('S',level,matrice, perioadaAparitieSori,log);
		break;
	case 2:
		checkIfClickedAfterClicked('C',level,matrice, perioadaAparitieSori,log);
		break;
	case 3:
		checkIfClickedAfterClicked('W',level,matrice, perioadaAparitieSori,log);
		break;
	case 4:
		checkIfClickedAfterClicked('F',level,matrice, perioadaAparitieSori,log);
		break;
	}

}


string getpassword(const string& prompt = "Introduceti parola: ")
{
	string result;

	// Set the console mode to no-echo, not-line-buffered input
	DWORD mode, count;
	HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleMode(ih, &mode))
		throw runtime_error(
			"getpassword: You must be connected to a console to use this program.\n"
		);
	SetConsoleMode(ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

	// Get the password string
	WriteConsoleA(oh, prompt.c_str(), prompt.length(), &count, NULL);
	char c;
	while (ReadConsoleA(ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
	{
		if (c == '\b')
		{
			if (result.length())
			{
				WriteConsoleA(oh, "\b \b", 3, &count, NULL);
				result.erase(result.end() - 1);
			}
		}
		else
		{
			WriteConsoleA(oh, "*", 1, &count, NULL);
			result.push_back(c);
		}
	}

	// Restore the console mode
	SetConsoleMode(ih, mode);

	return result;
}

int autentificare()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	while (1)
	{
		ofstream log;
		log.open("log.log", std::fstream::app);
		cout << "Daca sunteti utilizator nou apasati tasta 1 , pentru a va autentifica apasati tasta 2\n\n";
		int x;
		cin >> x;
		cout << "Introduceti numele de utilizator: ";
		string nume;
		string password;
		if (x == 1)
		{
			cin >> nume;
			numeUtilizator = nume;

			try
			{
				password = getpassword("Introduceti parola: ");
				//cout << "\nYour password is " << password << endl;

			}
			catch (exception& e)
			{
				cerr << e.what();
				return 1;
			}
			CPlayer player;
			player.setNume(nume);
			player.setParola(password);
			//scriu in fisierul players.log
			std::ofstream players;
			players.open("players.log", std::fstream::app);
			players << player.getNume() << "\n" << player.getParola() << "\n" << player.getLevel() << "\n";
			players.close();
			conOut(25, 65) << "V-ati creat contul cu succes!\n\n";
			log << "S-a autentificat utilizatorul cu numele " << nume << endl;
			return 1;
		}
		if(x==2)
		{
			cin >> nume;
			numeUtilizator = nume;
			cout << "Introduceti parola: ";
			
			password = getpassword("Introduceti parola: ");
			ifstream readPlayers;
			readPlayers.seekg(0, ios::beg);
			readPlayers.open("players.log", std::fstream::app);
			string buffer;
			while (getline(readPlayers, buffer))
			{
				if (buffer == nume)
				{
					getline(readPlayers, buffer);
					if (buffer == password)
					{
						getline(readPlayers, buffer);
						conOut(25, 65) << "V-ati autentificat cu succes!\n\n";
						log << "S a autentificat utilizatorul cu numele " << nume << endl;
						readPlayers.close();
						return stoi(buffer);
					}
				}
			}
			cout << "\n\n\nNumele de utilizator sau parola gresite!\n\n\n";
		}
		log.close();
	}
}

void chooseLevel(int level)
{
	if (level == 1)
	{
		CTeren_1 a;
		a.draw();
	}
	if (level == 2)
	{
		CTeren_2 b;
		b.draw();
	}
	if (level == 3)
	{
		CTeren_3 c;
		c.draw();
	}

	CPlants plants;
	plants.draw();
}

int main(void)
{
	
	int levelFromAutentification = autentificare();

	std::ofstream log;
	log.open("log.log", std::fstream::app);

	// stergere tot din consola


	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	
	//conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";


	system("pause");
	//curatare 
	system("CLS");

	CTeren b(levelFromAutentification);
	b.draw();

	int level = b.getlLevel();

	// alegeti de aici level 2 sau 3 deoarece la level 1 am eroare
	level = 2;
	chooseLevel(level);

	int nrZombie;

	if (level == 1)
		nrZombie = 4;
	if (level == 2)
		nrZombie = 6;
	if (level == 3)
		nrZombie = 8;

	int copienrZombie = nrZombie;
	int nrZombieOmorati = 0;

	vector<vector<CPlants*>> matrice(2 * level - 1, vector<CPlants*>(8));
	vector<CProiectil* > proiectile;
	vector<CZombie*>zombies;


	time_t timestamp = time(NULL);
	time_t timestamp_for_proiectil = time(NULL);
	auto timestamp_move_entities = high_resolution_clock::now();
	auto timestamp_for_zombies = high_resolution_clock::now();
	auto timestamp_for_zombies_move = high_resolution_clock::now();
	conOut(3, 0) << scoreboard;


	int perioadaAparitieSori = 11;


	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	while (true)
	{
	
		int x = 0;
		std::string action = conIn.getUserActions();

		if (action != "")
		{
			conOut(41, 2) << action;
			int x_mouse;
			int y_mouse;
			if (action.find("double") != string::npos)
			{
				vector<int> v = extractIntegerWords(action);
				y_mouse = v[1];
				x_mouse = v[0];
				if ((y_mouse >= 0) && (y_mouse < 6))
				{
					checkIfClickedSun(x_mouse, y_mouse, scoreboard,log);
				}
				if ((x_mouse >= 0) && (x_mouse < 15))
				{
					checkIfClickedPlants(y_mouse, level, matrice, perioadaAparitieSori,log);
				}
			}
		}
		
		time_t new_timestamp_for_proiectil = time(NULL);
		if (new_timestamp_for_proiectil - timestamp_for_proiectil > 2)
		{
			for (int lvl = 0; lvl < matrice.size(); lvl++) 
			{
				for (auto peashooter : matrice[lvl])
				{
					if (CPeaShooter* pS = dynamic_cast<CPeaShooter*>(peashooter))
					{
						CProiectil *boom = new CProiectil(pS->x - 1, pS->y);
						proiectile.push_back(boom);
						boom->draw();
					}
				}
			}
			timestamp_for_proiectil = time(NULL);
		}
		auto new_timestamp_move_entities = high_resolution_clock::now();
		if (duration_cast<milliseconds>(new_timestamp_move_entities - timestamp_move_entities).count() > 900) 
		{
			for (auto proiectil : proiectile) 
			{
				if(!proiectil->hit)
					proiectil->updatePos();
			}
			timestamp_move_entities = high_resolution_clock::now();
		}
		
		auto new_timestamp_for_zombie = high_resolution_clock::now();
		if (duration_cast<milliseconds>(new_timestamp_for_zombie - timestamp_for_zombies).count() > 40000) 
		{
			srand(time(NULL));
			int randNumber = rand() % 4;

			if (randNumber % 3 == 0)
			{
				if (nrZombie > 0)
				{
					CBucketheadZombie *BZ = new CBucketheadZombie(level);
					log << "S-a spawnat un BucketHead Zombie\n";
					BZ->draw();
					zombies.push_back(BZ);
					nrZombie--;
				}
			}
			else
			{
				if (nrZombie > 0)
				{
					CClassicZombie *CZ = new CClassicZombie(level);
					log << "S-a spawnat un Classic Zombie\n";
					CZ->draw();
					zombies.push_back(CZ);
					nrZombie--;
				}
			}
			timestamp_for_zombies = new_timestamp_for_zombie;
		}
		
		auto new_timestamp_for_zombies_move = high_resolution_clock::now();
		if (duration_cast<milliseconds>(new_timestamp_for_zombies_move - timestamp_for_zombies_move).count() > 1000)
		{
			for (CZombie *zombie : zombies)
			{
				if (zombie->hit == true)
				{
					continue;
				}
				else
				{
					if (zombie->health <= 0)
					{
						/*delete zombie; EROARE
						zombie = NULL;*/
						zombie->deletePos();
						nrZombieOmorati++;
						zombie->hit = true;
						log << "S-a distrus un zombie\n";
					}
					else
					{
						if ((zombie->y - 95 < 2) || (zombie->y - 85 < 2) || (zombie->y - 75 < 2) ||
							(zombie->y - 65 < 2) || (zombie->y - 55 < 2) || (zombie->y - 45 < 2) ||
							(zombie->y - 35 < 2) || (zombie->y - 25 < 2))
						{
							int linie_chenar = (zombie->x - 6) / 5;
							int coloana_chenar = (zombie->y - 16) / 10;
							if (matrice[linie_chenar][coloana_chenar] != NULL)
							{
								matrice[linie_chenar][coloana_chenar]->hp -= zombie->damage;
								if (matrice[linie_chenar][coloana_chenar]->hp <= 0)
								{
									matrice[linie_chenar][coloana_chenar]->deletepos();
									matrice[linie_chenar][coloana_chenar] = NULL;
									log << "S-a distrus planta de la pozitia [" << linie_chenar << "][" << coloana_chenar << "]\n";
								}
							}
							else
							{
								zombie->updatePos();
							}
						}
						else
							zombie->updatePos();
					}
				}
			//	zombies.erase(std::remove(zombies.begin(), zombies.end(), NULL), zombies.end());      EROARE
			}
			timestamp_for_zombies_move = new_timestamp_for_zombies_move;
		}

		for (auto &proiectil : proiectile)
		{
			for (auto &zombie : zombies)
			{
				if ((proiectil->x == zombie->x) &&
					(abs(proiectil->y - zombie->y) < 2) &&
					(!proiectil->hit) &&
					(zombie->health > 0))
				{
					zombie->health -= 5;
					proiectil->hit = true;
					proiectil->deletePos();
				}
			}
		}

		time_t new_timestamp = time(NULL);
		if (new_timestamp - timestamp > perioadaAparitieSori)
		{
			if (contor_sori < 8)
			{
				CSun sun;
				sun.draw();
				contor_sori++;
				timestamp = time(NULL);
			}
		}
		if (nrZombieOmorati == copienrZombie)
		{
			conOut(40, 75) << "FELICITARI AI CASTIGAT NIVELUL!\n\n";
			log << "Utilizatorul a castigat levelul\n";
			// modific levelul in fisier
			ifstream readPlayers;
			readPlayers.open("players.log");
			readPlayers.seekg(0, ios::beg);
			
			string buffer;

			while (getline(readPlayers, buffer))
			{
				if (buffer == numeUtilizator)
				{
					getline(readPlayers, buffer);
					int pozitieCursor = readPlayers.tellg();
					readPlayers.close();
					int new_level = levelFromAutentification + 1;

					// aici vreau sa modific level-ul in cazul in care utilizatorul a castigat levelul
					std::ofstream players;
				
					players.open("players.log", std::fstream::in | std::fstream::out | std::fstream::trunc | ios::beg);
					players.seekp(pozitieCursor, ios::beg);
					players << new_level;
				
					players.close();
					break;
				}
			}
			system("pause");
			exit(1);
		}
	}
	log.close();
	_getch();
	return 0;
}

