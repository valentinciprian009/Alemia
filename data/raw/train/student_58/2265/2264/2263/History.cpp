#include "History.h"
#include"Utilizator.h"


History::History()
{
}

void History::getHistoryFor(Utilizator& user)
{
	ifstream f("history.txt");

	while (!f.eof())
	{
		string nume;
		int l, scor;
		f >> nume >> l >> scor;

		if (nume ==user.getName())
		{   
			user.setScor(scor);
			user.setLevel(l);
			break;
		}
	}

	f.close();
}


History::~History()
{
}
