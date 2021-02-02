#include "PeaShooter.h"



PeaShooter::PeaShooter()
{
}

void PeaShooter::printThePeaSh()
{
	
	cout << "\t" << "" << endl;
	cout << "\t" << "" << endl;
	cout << "\t" << "o~" << endl;
	cout << "\t" << "|" << endl;
	cout << "\t" << "``" <<endl;
}

void PeaShooter::costInSun()
{
}

void PeaShooter::lifePlant()
{
}

void PeaShooter::attack2()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "* ";


	auto end = steady_clock::now();


	if (duration_cast<milliseconds>(end - begin).count() > 1900)//la cat timp apar stelutele. pot sa le fac si mai dese si mai rare, dar si sa imi apara la un interval mai scurt de timp
	{
		begin = end;

		conOut(ROW_TITLE+7, col + 8) << printedChar;//pentru afisarea stelutelor imediat sub titlul cu cool game
		if (col >= COL_FIRST_STAR_POSITION+3 + 10 * COL_DISTANCE_BETWEEN_STARS)// imi apar exact 5 stelute ca sa fie estetic
		{
			if (printedChar == "*")
			{
				printedChar = "  ";
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

void PeaShooter::attack3()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "* ";


	auto end = steady_clock::now();


	if (duration_cast<milliseconds>(end - begin).count() > 1800)//la cat timp apar stelutele. pot sa le fac si mai dese si mai rare, dar si sa imi apara la un interval mai scurt de timp
	{
		begin = end;

		conOut(ROW_TITLE+12, col + 8) << printedChar;//pentru afisarea stelutelor imediat sub titlul cu cool game
		if (col >= COL_FIRST_STAR_POSITION + 10 * COL_DISTANCE_BETWEEN_STARS)// imi apar exact 5 stelute ca sa fie estetic
		{
			if (printedChar == "*")
			{
				printedChar = "  ";
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

void PeaShooter::attack1()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "* ";


	auto end = steady_clock::now();


	if (duration_cast<milliseconds>(end - begin).count() > 2000)//la cat timp apar stelutele. pot sa le fac si mai dese si mai rare, dar si sa imi apara la un interval mai scurt de timp
	{
		begin = end;
		
		conOut(ROW_TITLE+2, col+8) << printedChar;//pentru afisarea stelutelor imediat sub titlul cu cool game
		if (col >= COL_FIRST_STAR_POSITION + 10 * COL_DISTANCE_BETWEEN_STARS)// imi apar exact 5 stelute ca sa fie estetic
		{
			if (printedChar == "*")
			{
				printedChar = "  ";
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


PeaShooter::~PeaShooter()
{
}
