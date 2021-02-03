#include "Zombie.h"



Zombie::Zombie()
{
}

void Zombie::drawTheZombie()
{
	cout << endl<<endl;
	//cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
	cout <<"\t\t\t\t\t\t" << " o" << endl;
	cout <<"\t\t\t\t\t\t" << "~|" << endl;
	cout <<"\t\t\t\t\t\t" << " ``" <<endl ;
}

void Zombie::appear()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "z";


	auto end = steady_clock::now();

	if (duration_cast<milliseconds>(end - begin).count() > 700)//la cat timp apar stelutele. pot sa le fac si mai dese si mai rare, dar si sa imi apara la un interval mai scurt de timp
	{
		begin = end;
		conOut(ROW_TITLE + 1, col-10) << "z";//pentru afisarea stelutelor imediat sub titlul cu cool game
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS)// imi apar exact 5 stelute ca sa fie estetic
		{
			if (printedChar == "z")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "z";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col -= COL_DISTANCE_BETWEEN_STARS;
		}
	}
}

int Zombie::zombieLife()
{
	return 0;
}


Zombie::~Zombie()
{
}
