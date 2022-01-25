#include "Peashooter.h"


void Peashooter::update(vector<tuple<char, int, int>> Y, vector<Pea> &P)
{
	//updateaza ceasurile pentru toate pea shooterele
	time_point<steady_clock> end = steady_clock::now();
	for (auto plant : Y)
		if (get<0>(plant) == 'a')
		{
			int gasit = 0;
			for (int i = 0; i<ps.size(); i++)
				if (get<1>(plant) == get<0>(ps[i]) && get<2>(plant) == get<1>(ps[i]))
				{
					gasit = 1;
					if (duration_cast<milliseconds>(end - get<2>(ps[i])).count() > 2000)
					{
						get<2>(ps[i]) = end;
						P.push_back(Pea(get<0>(ps[i]) + 1, get<1>(ps[i])));
					}
					break;
				}
			if (gasit == 0)
				ps.push_back(make_tuple(get<1>(plant), get<2>(plant), steady_clock::now()));
		}

	//sterge peashooterele care au fost mancate de zombie
	int i, gasit, ii = -1;

	while (true)
	{
		ii = -1;
		for (i = 0; i<ps.size(); i++)
		{
			gasit = 0;
			for (auto plant : Y)
				if (get<1>(plant) == get<0>(ps[i]) && get<2>(plant) == get<1>(ps[i]))
				{
					gasit = 1;
					break;
				}

			if (gasit == 0)
			{
				ii = i;
				break;
			}
		}
		if (ii != -1)
			ps.erase(ps.begin() + ii);
		else
			break;
	}
}

void Peashooter::amplasare()
{
}

Peashooter::Peashooter()
{
}


Peashooter::~Peashooter()
{
}
