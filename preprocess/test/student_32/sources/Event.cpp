#include "Event.h"

Event::Event(string aux)
{
	istringstream ss(aux);

	do {
		string word;
		ss >> word;
		if (word == "clicked")
		{
			this->aux = word;
			ss >> word;
			ss >> word;
			this->row = stoi(word);
			ss >> word;
			this->col = stoi(word);
		}

	} while (ss);
}

int Event::get_col()
{
	return this->col;
}

int Event::get_row()
{
	return this->row;
}

string Event::get_event()
{
	return this->aux;
}
