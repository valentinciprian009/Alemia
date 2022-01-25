#include<stdio.h>
#include <iostream>
#include <windows.h>
#include <ctime>
#include<string.h>
#include <stdlib.h>
#include <iomanip>
#include<string>
#include <cstdlib>

#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include<iostream>
#include <chrono>
#include"Manager.h"


using namespace std;
using namespace std::chrono;

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

void doLoadingBar()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
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

int main()
{
	UserInterface::ConsoleOutput & conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput & conIn = UserInterface::ConsoleInput::getInstance();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	conOut(ROW_TITLE+2 , COL_FIRST_STAR_POSITION) << "Press A KEY if you want to start the game!";
	
	Log::logare("Deschiderea aplicatiei.");
	bool ok = false;
	while (ok!=true)
	{
		doLoadingBar();
		string action = conIn.getUserActions();

		if (action == "OK")
			ok = true;

		if (action != "")
			conOut(41, 2) << action;
	}

	system("CLS");

	Manager::getInstance().start();

	return 0;
}

