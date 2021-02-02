#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Game.h"

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

int main(void)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	 
	Game PvsZ;
	string s;
	int n=0;
	
	PvsZ.init_menu();

	return 0;
}

