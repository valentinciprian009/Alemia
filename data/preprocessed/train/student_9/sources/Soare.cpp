#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include"ConsoleInput.h"
#include"Soare.h"
#include"Harta.h"

extern int valuesoare;

using namespace std;

void Soare::aparitie(char ****a, int x,int y) {
			(*a)[x][y][0] = 'S';
		/*
		char key = ' ';

		if (_kbhit())
			key = _getch();

		if (key == 13) //The ENTER key.
			break; //Quit the while loop

		else if (key != ' ')
		{
			std::cout << "You pressed: " << key << '\n';


			key = ' ';
		}
		*/
	}

void Soare::click(char ****a,int x) {
	if ((*a)[2][x][0]=='S')
	{
		strcpy((*a)[2][x], " ");
		valuesoare += 50;
	}
	if ((*a)[2][x - 2][0] == 'S')
	{
		strcpy((*a)[2][x-2], " ");
		valuesoare += 50;
	}
	if ((*a)[2][x - 1][0] == 'S')
	{
		strcpy((*a)[2][x-1], " ");
		valuesoare += 50;
	}
	if ((*a)[2][x + 1][0] == 'S')
	{
		strcpy((*a)[2][x+1], " ");
		valuesoare += 50;
	}
	if ((*a)[2][x+2][0] == 'S')
	{
		strcpy((*a)[2][x+2], " ");
		valuesoare += 50;
	}
}
