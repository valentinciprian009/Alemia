#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include"Harta.h"
#include"ConsoleOutput.h"
#include"ConsoleInput.h"
#include<malloc.h>
using namespace std;

extern int valuesoare;

void Harta::alocare(char ****a, int x, int y) {
#pragma region Alocare
	*a = (char***)malloc(sizeof(char**)*(y + 1));
	for (int i = 0; i <= y; i++) {
		(*a)[i] = (char**)malloc(sizeof(char*)*(x + 1));
		for (int j = 0; j <= x; j++) {
			(*a)[i][j] = (char*)malloc(sizeof(char) + 2);
		}
	}
#pragma endregion

#pragma region Spatiu gol
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++) {
			strcpy((*a)[i][j], " ");
		}
#pragma endregion
}

void Harta::print(char ****a, int x, int y) {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	std::string action = conIn.getUserActions();
#pragma region Margini
	for (int j = 0; j < x; j++) {
		strcpy((*a)[0][j], "_");
		strcpy((*a)[14][j], "-");
	}
	for (int i = 1; i < y - 1; i++) {
		strcpy((*a)[i][0], "|");
		strcpy((*a)[i][66], "|");
	}
#pragma endregion

#pragma region Interior
	for (int j = 1; j < x - 1; j++)
		strcpy((*a)[3][j], "-");
	for (int j = 1; j < x - 1; j++) {
		for (int i = 6; i <= 12; i += 2) {
			if (j != 20) {
				strcpy((*a)[i][j], "-");
			}
			else if (j == 20) {
				strcpy((*a)[i][j], "|");
			}
		}
	}
	for (int i = 5; i <= 13; i += 2)
		for (int j = 20; j < 65; j += 5)
			strcpy((*a)[i][j], "|");

	for (int j = 20; j < 65; j += 5)
		strcpy((*a)[2][j], "|");

	for (int j = 14; j <= 65; j++)
		strcpy((*a)[4][j], "-");

	strcpy((*a)[1][1], "S"); strcpy((*a)[1][2], "C"); strcpy((*a)[1][3], "O"); strcpy((*a)[1][4], "R"); strcpy((*a)[1][5], "E"); strcpy((*a)[1][6], "B"); strcpy((*a)[1][7], "O"); strcpy((*a)[1][8], "A"); strcpy((*a)[1][9], "R"); strcpy((*a)[1][10], "D"); strcpy((*a)[1][11], ":");
	strcpy((*a)[1][20], "|");
	strcpy((*a)[1][22], "Z"); strcpy((*a)[1][23], "O"); strcpy((*a)[1][24], "N"); strcpy((*a)[1][25], "A"); strcpy((*a)[1][27], "S"); strcpy((*a)[1][28], "O"); strcpy((*a)[1][29], "R"); strcpy((*a)[1][30], "I"); strcpy((*a)[1][31], ":");
	strcpy((*a)[4][1], "Z"); strcpy((*a)[4][2], "O"); strcpy((*a)[4][3], "N"); strcpy((*a)[4][4], "A"); strcpy((*a)[4][7], "P"); strcpy((*a)[4][8], "L"); strcpy((*a)[4][9], "A"); strcpy((*a)[4][10], "N"); strcpy((*a)[4][11], "T"); strcpy((*a)[4][12], "E"); strcpy((*a)[4][13], ":");
#pragma endregion



#pragma region Plante
	(*a)[5][1][0] = 'P'; (*a)[5][2][0] = 'E'; (*a)[5][3][0] = 'A'; (*a)[5][4][0] = 'S'; (*a)[5][5][0] = 'H'; (*a)[5][6][0] = 'O'; (*a)[5][7][0] = 'O'; (*a)[5][8][0] = 'T'; (*a)[5][9][0] = 'E'; (*a)[5][10][0] = 'R';
	(*a)[7][1][0] = 'S'; (*a)[7][2][0] = 'U'; (*a)[7][3][0] = 'N'; (*a)[7][4][0] = 'F'; (*a)[7][5][0] = 'L'; (*a)[7][6][0] = 'O'; (*a)[7][7][0] = 'W'; (*a)[7][8][0] = 'E'; (*a)[7][9][0] = 'R';
#pragma endregion
/*

#pragma region Verde
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);
	for (int i = 20; i < 66; i++)
		(*a)[9][i][0] = ' ';
#pragma endregion
	SetConsoleTextAttribute(hConsole, 7);

*/
	(*a)[9][22][0] = 'P';
#pragma region Afisare
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++)
			conOut(i, j) << (*a)[i][j][0];
	}
	printf("\nSoare:%d", valuesoare);
	cout << endl << "---" << endl << "| |" << endl << "---" << endl;
#pragma endregion
	}

void Harta::afisare(char ****a, int x, int y) {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	std::string action = conIn.getUserActions();
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++)
			conOut(i, j)<<(*a)[i][j][0];
	}
	printf("\nSoare:%d", valuesoare);
	cout << endl << "---" << endl << "| |" << endl << "---" << endl;

}

void Harta::restrictii(char ****a, int x, int y) {

}