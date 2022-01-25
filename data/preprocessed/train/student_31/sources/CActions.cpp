#define _CRT_SECURE_NO_WARNINGS
#include "CActions.h"
#include "CLevel_1.h"
#include "CLevel_2.h"
#include "CLevel_3.h"

#include "CExceptie.h"

#include <iostream>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"

#include <time.h>
#include <ctime>
#include <chrono>

#include <fstream>

using namespace std::chrono;

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

#define ROW_LOGO					7
#define COL_LOGO					55


CActions *CActions::Instance = NULL;

CActions::CActions()
{
}


void CActions::game()
{
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	
	switch (conIn.get_level())
	{
	case 1:
	{
		CLevel_1 &level_1 = CLevel_1::getInstance();
		level_1.game();
		level_1.destroyInstance();
		break;
	}
	case 2:
	{
		CLevel_2 &level_2 = CLevel_2::getInstance();
		level_2.game();
		level_2.destroyInstance();
		break;
	}
	case 3:
	{
		CLevel_3 &level_3 = CLevel_3::getInstance();
		level_3.game();
		level_3.DestroyInstance();
		break;
	}
	default:
		
		break;
	}
}

void CActions::clean_screen()
{
	system("cls");
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_LINE_INPUT);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_MOUSE_INPUT);
}

int CActions::select_level()
{
	UserInterface::ConsoleInput &conIn = conIn.getInstance();
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	CActions &act = CActions::getInstance();
	act.print_Level();

	int x;
	int y=0;
	while (true)
	{
		std::string com = conIn.getUserActions();
		if (com != "")
		{
			char*rez = _strdup(com.c_str());
			if (rez != NULL && strstr(rez, "clicked"))
			{
				 atoi(strtok(rez, "()"));
				x = atoi(strtok(NULL, "(,)"));
				y = atoi(strtok(NULL, "(,)"));
				if (x >= 45 && x <= 55 && y >= 23 && y <= 30)
				{
					conIn.set_level(1);
					this->log_select_level(1);
					return 1;
				}
				if (x >= 76 && x <= 88 && y >= 24 && y < 30)
				{
					conIn.set_level(2);
					this->log_select_level(2);
					return 2;
				}
				if (x >= 108 && x <= 118 && y >= 24 && y <= 30)
				{
					conIn.set_level(3);
					this->log_select_level(3);
					return 3;
				}
			}
		}
	}
	return 0;
}

void CActions::read_id()
{
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_LINE_INPUT);
	try {
		while (true)
		{
			std::string output = conIn.getUserActions();
			if (output != "")
			{
				conOut(20, 87, 7) << output;

			}
			if (output == "\r")
			{
				this->log_sign_in(conIn.get_id().c_str());

				if (conIn.get_id() == "\r")
					throw CExceptie(101, "Numele utilizatorului nu a fost introdus corespunzator!");
				break;
			}
		}
		
	}
	catch (CExceptie &E)
	{
		conOut(1, 1, 7) << E.return_mesaj().c_str() << " code: " << E.return_code();
	}
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_MOUSE_INPUT);
}

void CActions::print_LOGO()
{
	 UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	 std::wcout << L"\n";
	 conOut(10, 35,2) << L"██████╗  ██████╗  ██████╗     ██╗   ██╗███████╗    ███████╗ ██████╗ ███╗   ███╗██████╗ ██╗███████╗███████╗";
	 conOut(11, 35, 2) << L"██╔══██╗██╔═══██╗██╔═══██╗    ██║   ██║██╔════╝    ╚══███╔╝██╔═══██╗████╗ ████║██╔══██╗██║██╔════╝██╔════╝";
	 conOut(12, 35, 2) << L"██████╔╝██║   ██║██║   ██║    ██║   ██║███████╗      ███╔╝ ██║   ██║██╔████╔██║██████╔╝██║█████╗  ███████╗";
	 conOut(13, 35, 2) << L"██╔═══╝ ██║   ██║██║   ██║    ╚██╗ ██╔╝╚════██║     ███╔╝  ██║   ██║██║╚██╔╝██║██╔══██╗██║██╔══╝  ╚════██║";
	 conOut(14, 35, 2) << L"██║     ╚██████╔╝╚██████╔╝     ╚████╔╝ ███████║    ███████╗╚██████╔╝██║ ╚═╝ ██║██████╔╝██║███████╗███████║";
	 conOut(15, 35, 2) << L"╚═╝      ╚═════╝  ╚═════╝       ╚═══╝  ╚══════╝    ╚══════╝ ╚═════╝ ╚═╝     ╚═╝╚═════╝ ╚═╝╚══════╝╚══════╝";
	

}

void CActions::print_Level()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION,7) << "            ";


	for (int i = 0; i < strlen(conIn.get_id().c_str()); i++)
	{
		conOut(20, 87 + i, 7) << "    ";
	}

	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION + 5, 7) << "Level: ";


	std::wcout << L"\n";
	conOut(25, 50, 10) << L" ██╗"; conOut(25, 80, 6) << L"██████╗ "; conOut(25, 110, 4) << L"██████╗ ";
	conOut(26, 50, 10) << L"███║"; conOut(26, 80, 6) << L"╚════██╗"; conOut(26, 110, 4) << L"╚════██╗";
	conOut(27, 50, 10) << L"╚██║"; conOut(27, 80, 6) << L" █████╔╝"; conOut(27, 110, 4) << L" █████╔╝";
	conOut(28, 50, 10) << L" ██║"; conOut(28, 80, 6) << L"██╔═══╝ "; conOut(28, 110, 4) << L" ╚═══██╗";
	conOut(29, 50, 10) << L" ██║"; conOut(29, 80, 6) << L"███████╗"; conOut(29, 110, 4) << L"██████╔╝";
	conOut(30, 50, 10) << L" ╚═╝"; conOut(30, 80, 6) << L"╚══════╝"; conOut(30, 110, 4) << L"╚═════╝ ";

}

void CActions::print_GAME_OVER()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10, 45, 4) << L" ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗";
	conOut(11, 45, 4) << L"██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗";
	conOut(12, 45, 4) << L"██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝";
	conOut(13, 45, 4) << L"██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗";
	conOut(14, 45, 4) << L"╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║";
	conOut(15, 45, 4) << L" ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝";

}

void CActions::print_Victory()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(10, 45, 11) << L"██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗";
	conOut(11, 45, 11) << L"██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝";
	conOut(12, 45, 11) << L"██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ ";
	conOut(13, 45, 11) << L"╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝ ";
	conOut(14, 45, 11) << L" ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║  ";
	conOut(15, 45, 11) << L"  ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝ ";
}

void CActions::log_sign_in(const char* username)
{
	FILE*pfile_out = fopen("Jurnal.log", "at+");
	time_t now = time(0);

	char* dt = ctime(&now);
	fprintf(pfile_out, "%s - username: %s \n", dt,username);
	fclose(pfile_out);
}

void CActions::log_select_level(int level)
{
	FILE*pfile_out = fopen("Jurnal.log", "at+");
	time_t now = time(0);

	char* dt = ctime(&now);
	fprintf(pfile_out, "%s - level: %d \n", dt, level);
	fclose(pfile_out);
}

void CActions::log_victory(int score)
{
	FILE*pfile_out = fopen("Jurnal.log", "at+");
	time_t now = time(0);

	char* dt = ctime(&now);
	fprintf(pfile_out, "%s - VICTORY , SCORE: %d \n", dt,score);
	fclose(pfile_out);
}

void CActions::log_game_over()
{
	FILE*pfile_out = fopen("Jurnal.log", "at+");
	time_t now = time(0);

	char* dt = ctime(&now);
	fprintf(pfile_out, "%s -The zombies ate your brains \n", dt);
	fclose(pfile_out);
}

CActions & CActions::getInstance()
{
	if (Instance == NULL)
	{
		Instance = new CActions;
	}
	return *Instance;
}

void CActions::destroyInstance()
{
	if (Instance!=NULL)
	{
		delete Instance;
	}
	Instance = NULL;
}


CActions::~CActions()
{
}
