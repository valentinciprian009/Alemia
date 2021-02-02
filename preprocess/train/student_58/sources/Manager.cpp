#include "Manager.h"
#include"Logare.h"


Manager* Manager::instance = nullptr;
Manager::Manager() :game(Logare::userCurent)
{
}

Manager::~Manager()
{
}

Manager & Manager::getInstance()
{
	if (!instance)
		instance = new Manager();
	return *instance;
}

void Manager::destroyInstance()
{
	if (instance)
	{
		delete[] instance;
		instance = nullptr;
	}
}

void Manager::updateUser(string name, int scorp, int nivelp)
{
	ifstream g("history.txt");
	if (!g.is_open())
		throw Exception("Fisierul: history.txt nu a fost gasit.");

	string nume;
	int scor, nivel;
	string text;
	while (g >> nume >> nivel >> scor)
	{
		if (nume != name)
		{
			text += nume;
			text += ' ';
			text += to_string(nivel);
			text += ' ';
			text += to_string(scor);
			text += '\n';
		}
		else
		{
			text += nume;
			text += ' ';
			text += to_string(nivelp);
			text += ' ';
			text += to_string(scorp);
			text += '\n';
		}
	}
	g.close();
	Log::logare("S-au actualizat  cu succes informatiile despre utilizatorul curent.");
	ofstream f("history.txt");
	f << text;
	f.close();
}

void Manager::start()
{
	this->useri = log.getUsers();
	Log::logare("Pornire joc.");
	while (!CGame::lose)
	{
		game.init();
		game.play();
		game = CGame(game.getPlayer());
	}
}
