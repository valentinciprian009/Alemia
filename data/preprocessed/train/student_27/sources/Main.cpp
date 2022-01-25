#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "teren.h"
#include"Resurse.h"
#include"Zombie.h"
#include"ZombieBanal.h"
#include"Plante.h"
#include"PSunflower.h"
#include <time.h>
#include <chrono>
#include<thread>

#define ROW_TITLE					20
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define COL_FIRST_MATRIX_POSITION  60
#define COL_DISTANCE_BETWEEN_ROWS	5
#define ROW_MATRIX					5
#define COL_LAST_MATRIX_POSITION    110

using namespace std::chrono;
using namespace std::this_thread;

void eraseLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";
		conOut(ROW_TITLE + 1, col) << printedChar;
		

		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{

				printedChar = " ";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
void eraseWriteBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = " ";
	conOut(ROW_TITLE, col) << printedChar;


	if (col >= COL_FIRST_STAR_POSITION && col<= COL_FIRST_STAR_POSITION+25) {

			printedChar = " ";
		col += 1;
	}
}

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
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

int main(void)
{
	srand(time(NULL));

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "    POO VS ZOMBIE";
	for (int i = 0; i < 10000000; i++)
		doLoadingBar();
	for (int i = 0; i < 10000; i++)
	{
		eraseWriteBar();
		eraseLoadingBar();
	}
	while (true)
	{

		teren p;
		p.level1();
		p.level2();
		p.level3();
		Resurse s;
		s.creeaza_resurse();
		ZombieBanal z1;
		z1.pune_zombie();
		//PSunflower fsun;
		//fsun.pune_planta();
	
	//sleep_for(seconds(1));
		std::string action = conIn.getUserActions();
	
		if (action != "")
		{
			conOut(41, 2) << action;
		}
	}

	return 0;
}

