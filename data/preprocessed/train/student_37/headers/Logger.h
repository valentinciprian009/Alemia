#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Surface.h"
#include <map>
#include "Zombie.h"

using namespace std;

class Surface;
class Zombie;

class Logger
{
private:
	string file_name;
public:
	Logger(string file_name);
	~Logger();
	void log(string message) {
		ofstream fisier;
		fisier.open(file_name, ios::app);
		fisier << message << endl;
		
		fisier.close();
	}

	/*void log(Surface* surface) {
		map<Zombie*, int> positions = surface->get_positions();
		string rezultat = "[";

		map<Zombie*, int>::iterator it;

		for (it = positions.begin(); it != positions.end(); it++)
		{
			Zombie* zombie = it->first;
			int position = it->second;
			rezultat += " " + std::to_string(position);
		}
		rezultat += "]";

		ofstream fisier;
		fisier.open(file_name, ios::app);
		fisier << rezultat << endl;

		fisier.close();

	}*/
};

