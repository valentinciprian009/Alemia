#pragma once
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
#define ROW_GAME_TITLE			15
#define COLUMN_GAME_TITLE		37
#define ROW_LOADING					33			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	2
#define LOADING_PERIOD				50	//milliseconds
using namespace std::chrono;

namespace UserInterface
{
	void printTitle(ConsoleOutput& consoleOut);
	void ClearScreen();
	void doLoadingBar(int RowLoading, int colFirstStarPosition, int colDistanceBetweenStars, int LoadingPeriod, ConsoleOutput& consoleOut);
	bool pressButton(ConsoleInput& consoleIn, ConsoleOutput& consoleOut, int row_button, int column_button, const string& buttonName);
	bool readTextInput(ConsoleInput& consoleIn, ConsoleOutput& consoleOut, int row_input, int column_input, const string& inputString, string& text);
}