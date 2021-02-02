#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "ConsoleOutput.h"
#include <Windows.h>
#include <iostream>
UserInterface::ConsoleOutput ConOut = UserInterface::ConsoleOutput::getInstance();

Menu::Menu()
{
	x = new char[5];
	y = new char[5];
}

void Menu::print()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);


	            
	ConOut(7 , 53) << " ______       __   __   ______       ______     ";
	ConOut(8 , 53) << "/_____/\\     /_/\\ /_/\\ /_____/\\     /_____/  ";
	ConOut(9 , 53) << "\\:::_ \\ \\   \\:\\ \\ \ \\::::_\\/_        \\:::__\/   ";
	ConOut(10, 53) << " \\:(_) \\ \\   \\:\\ \\ \ \\:\\ / ___          /: /     ";
	ConOut(11, 53) << "  \\: ___\\/     \\:\\_/.:\ \\_::._\\:\\      /::/_";
	ConOut(12, 53) << "   \\ \\ \\        \\ ..::/ /  /____\\:\   /_:/____/\\ ";
	ConOut(13, 53) << "    \\_\\/         \\___/_(   \_____\/    \\_______\\/ ";




	for (int i = 68; i < 85; i++)
		ConOut(19, i) << char(219);
	for (int i = 68; i < 85; i++)
		ConOut(26, i) << char(219);
	for (int i = 20; i < 26; i++)
		ConOut(i, 68) << char(221);
	for (int i = 20; i < 26; i++)
		ConOut(i, 84) << char(222);
	ConOut(22, 73) << "P L A Y";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	for (int i = 68; i < 85; i++)
		ConOut(29, i) << char(219);
	for (int i = 68; i < 85; i++)
		ConOut(36, i) << char(219);
	for (int i = 30; i < 36; i++)
		ConOut(i, 68) << char(221);
	for (int i = 30; i < 36; i++)
		ConOut(i, 84) << char(222);
	ConOut(32, 72) << "C L O S E";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}

void Menu::coordonate(std::string a)
{
	int k=0, p=0;
	int aux;
	for (int i = 0; i < strlen(a.c_str()); i++)
	{
		if (a.c_str()[i] == ',')aux = i;
		
	}
	for (int i = 0; i < strlen(a.c_str()); i++) {
		if (isdigit(a.c_str()[i]) && i < aux)
			x[k++] = a.c_str()[i];
		else if (isdigit(a.c_str()[i]) && i > aux)
			y[p++] = a.c_str()[i];
	}
	
	x[k] = '\0';
	y[p] = '\0';

}


Menu::~Menu()
{
	
	
}
