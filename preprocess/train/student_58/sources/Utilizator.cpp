#include "Utilizator.h"

Utilizator::Utilizator(string name, string pass)
{
	this->name = name;
	password = pass;
	scor = 50;
	getHistory();
}

void Utilizator::setLevel(int level)
{
	if (level == 1)
		nivel = new Nivel1();
	else if (level == 2)
		nivel = new Nivel2();
	else
		nivel = new Nivel3();
}

void Utilizator::getHistory()
{
	history.getHistoryFor(*this);
}
