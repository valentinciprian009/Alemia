#include "PlayersList.h"
#include <fstream>
PlayersList &PlayersList::getInstance()
{
	if (!PlayersList::instance) {
		PlayersList::instance = new PlayersList();
	}
	return *PlayersList::instance;
}

void PlayersList::destroyInstance()
{
	if (PlayersList::instance) {
		delete PlayersList::instance;
		PlayersList::instance = nullptr;
	}

}

void PlayersList::checkFile()
{
	string file = "PlayersList.log";//verifica daca este creat fisierul cu fostii  jucatori,daca nu il creaza
	ifstream f;
	f.open(file.c_str());
	if (f.fail()) {
		ofstream fp;
		fp.open(file);
	}
}

void PlayersList::getListFromFile()
{
	checkFile();
	ifstream f;
	f.open("PlayersList.log");
	int i = 0;
	string name;
	int score;
	while (!f.eof()) {
		f >> score >> name;
		Player aux(name, score);
		this->v.push_back(aux);
		i++;
	}
	this->nr_players = i;
}
