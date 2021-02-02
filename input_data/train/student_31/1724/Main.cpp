#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "CActions.h"
#include <conio.h>


#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5



int main()
{
	
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	CActions &act = act.getInstance();
	

	act.print_LOGO();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION, 7) << "Loading cool game now...";

	Sleep(1000);
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION, 7) << "                        ";
	
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION, 7) << "Id jucator:";
	act.read_id();
	act.select_level();
	act.clean_screen();

	act.game();

	system("cls");
	

	conIn.DestroyInstance();
	conOut.DestroyInstance();
	
	return 0;
}

