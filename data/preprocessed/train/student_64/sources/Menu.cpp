#include "Menu.h"
#include <iostream>
#include<Windows.h>
#include "User.h"
#include<string>
#include<chrono>

#include "ConsoleInput.h"
#include "ConsoleOutput.h"

using namespace std::chrono;

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75



void Menu::PrintAnimation()
{	
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	conout(ROW_TITLE, COL_FIRST_STAR_POSITION - 20) << "######  ####### #######                     #######";
	conout(ROW_TITLE + 1, COL_FIRST_STAR_POSITION - 20) << "#     # #     # #     #    #    #  ####          # ";
	conout(ROW_TITLE + 2, COL_FIRST_STAR_POSITION - 20) << "#     # #     # #     #    #    # #             #  ";
	conout(ROW_TITLE + 3, COL_FIRST_STAR_POSITION - 20) << "######  #     # #     #    #    #  ####        #   ";
	conout(ROW_TITLE + 4, COL_FIRST_STAR_POSITION - 20) << "#       #     # #     #    #    #      #      #    ";
	conout(ROW_TITLE + 5, COL_FIRST_STAR_POSITION - 20) << "#       #     # #     #     #  #  #    #     #      ";
	conout(ROW_TITLE + 6, COL_FIRST_STAR_POSITION - 20) << "#       ####### #######      ##    ####     ####### ";

	auto begin = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	while (std::chrono::duration_cast<seconds>(end - begin).count() < 3)
	{
		end = std::chrono::system_clock::now();
	}
	system("cls");

	SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

User Menu::AskUserInput()
{
	User user;
	std::string name;
	//conout(0,0) << "Nume utilizator : ";
	//conin(0,16) >> name;
	user.CheckUserExistence(name);

	return user;
}

Menu::Menu()
{
}


Menu::~Menu()
{
}
