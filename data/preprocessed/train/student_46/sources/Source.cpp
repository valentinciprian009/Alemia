#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <iostream>
#include "Sun.h"
#include "Zombie.h"
#include "PeaShooter.h"

using namespace std;
#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define COL_START 1
#define ROW_START 1

using namespace std::chrono;

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";


	auto end = steady_clock::now();

	if (duration_cast<milliseconds>(end - begin).count() > 150)//la cat timp apar stelutele. pot sa le fac si mai dese si mai rare, dar si sa imi apara la un interval mai scurt de timp
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;//pentru afisarea stelutelor imediat sub titlul cu cool game
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS)// imi apar exact 5 stelute ca sa fie estetic
		{
			if (printedChar == "*")
			{
				printedChar = " ";
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

void drawTheTable()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar1 = "-";
	static std::string printedChar2 = "|";

	int sunZone[5][105];
	int line1[5][105];
	int line2[5][105];
	int line3[5][105];
	int line4[5][105];

	for (int i = 1; i < 106; i++)
		conOut(ROW_START, COL_START + i) << printedChar1;

	for (int i = 0; i < 106; i++)
		conOut(ROW_START + 5, COL_START + i) << printedChar1;
	for (int i = 1; i < 5; i++)
		for (int j = 0; j <= 105; j += 15)
			conOut(ROW_START + i, COL_START + j) << printedChar2;
	
	for (int i = 1; i < 106; i++)
		conOut(ROW_START + 10, COL_START + i) << printedChar1;
	for (int i = 6; i < 10; i++)
		for (int j = 0; j <= 105; j += 15)
			conOut(ROW_START + i, COL_START + j) << printedChar2;

	for (int i = 1; i < 106; i++)
		conOut(ROW_START + 15, COL_START + i) << printedChar1;
	for (int i = 11; i < 15; i++)
		for (int j = 0; j <= 105; j += 15)
			conOut(ROW_START + i, COL_START + j) << printedChar2;

	for (int i = 1; i < 106; i++)
		conOut(ROW_START + 20, COL_START + i) << printedChar1;
	for (int i = 16; i < 20; i++)
		for (int j = 0; j <= 105; j += 15)
			conOut(ROW_START + i, COL_START + j) << printedChar2;

	for (int i = 1; i < 106; i++)
		conOut(ROW_START + 25, COL_START + i) << printedChar1;
	for (int i = 21; i < 25; i++)
		for (int j = 0; j <= 105; j += 15)
			conOut(ROW_START + i, COL_START + j) << printedChar2;

	for (int i = 1; i < 106; i++)
		conOut(ROW_START + 30, COL_START + i) << printedChar1;
	for (int i = 26; i < 30; i++)
		for (int j = 0; j <= 105; j += 15)
			conOut(ROW_START + i, COL_START + j) << printedChar2;

}

int main(void)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	//conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	Sun snn;

	Zombie zomb;
	
	PeaShooter plant;
	plant.printThePeaSh();
	plant.printThePeaSh();
	plant.printThePeaSh();

	conOut(ROW_TITLE - 17, COL_FIRST_STAR_POSITION +22) << "z";
	conOut(ROW_TITLE - 7, COL_FIRST_STAR_POSITION + 22) << "z";
	conOut(ROW_TITLE - 12, COL_FIRST_STAR_POSITION +23) << "z";
	
	//zomb.drawTheZombie();
	
	
	drawTheTable();
	/*while(true)
		zomb.appear();
*/
	while (true)
	{
		
		plant.attack1();
		plant.attack2();
		plant.attack3();
		//zomb.appear();
	}

	//zomb.appear();


	while (true)
	{
		//doLoadingBar();

		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 2) << action;
			
				
		}
		if (!DOUBLE_CLICK)
		{
			
		}
	}
	
	return 0;
}

