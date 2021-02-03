#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "game/Game.h"
#include <time.h>
#include <chrono>
#include <stdio.h>

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;

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

bool detectDoubleClick(std::string& action, int* row, int* col) {
	std::size_t found = action.find("clicked", 0);
	if (found != std::string::npos) {
		sscanf_s(action.c_str(), "Mouse event: mouse clicked at (%d, %d)", col, row);
		return true;
	}
	return false;
}

int main(void)
{


	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	//conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";

	bool readWord = true;
	std::string username;
	conOut(20, 50) << "Enter username:";

	while (readWord) {
		std::string action = conIn.getUserActions();
		if (action.size() > 3) {
			if (action[1] == ':') {
				if (action[0] == 'f') {
					readWord = false;
				}
				if (action[0] == 'k') {
					username += action[3];
					conOut(21, 50) << username;
				}
				if (action[0] == 'd') {
					username = username.substr(0, username.size() - 1);
					conOut(21, 50) << username << "  ";
				}
			}
		}
	}
	int row, col;
	Game game(&conIn, &conOut, 1, username);
	conOut(20, 50) << "                                ";
	conOut(21, 50) << "                                ";
	while (true)
	{
		//doLoadingBar();
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 2) << action;
			if (detectDoubleClick(action, &row, &col)) {
				game.onEvent(Event::MOUSE_CLICK, row, col, NULL);
			}
		}
		game.draw();
	}

	return 0;
}

