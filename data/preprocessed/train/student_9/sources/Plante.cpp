#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Plante.h"
#include<iostream>
#include<stdio.h>
using namespace std;

void Peashooter::shotpea(char ****a) {
	int help = 0, help2 = 0, proiectil = 0;
	for (int i = 22; i <= 65; i = i + 5)
		if ((*a)[9][i][0] == 'P')
			help = i;
	for (int i = help + 5; i <= 65; i = i + 5)
	{
		if ((*a)[9][i][0] == '*') {
			proiectil = 1;
			help2 = i;
		}

	}
	if (proiectil == 1) {
		(*a)[9][help2 + 5][0] = (*a)[9][help2][0];
		(*a)[9][help2][0] = ' ';
	}
	else
		(*a)[9][help + 5][0] = '*';
}

void Peashooter::death(char ****a) {
	for (int i = 22; i <= 65; i = i + 5)
		if ((*a)[9][i][0] == 'P')
			(*a)[9][i][0] = ' ';
}

int Peashooter::IntalnireProiectil(char ****a) {
	for(int i=22;i<=65;i++)
		if ((*a)[9][i][0] == '*') 
			if (((*a)[9][i + 1][0] == 'Z' || (*a)[9][i + 1][0] == 'B') || ((*a)[9][i + 2][0] == 'Z' || (*a)[9][i + 2][0] == 'B') || ((*a)[9][i][0] == 'Z' || (*a)[9][i][0] == 'B') || ((*a)[9][i - 1][0] == 'Z' || (*a)[9][i - 1][0] == 'B') || ((*a)[9][i - 2][0] == 'Z' || (*a)[9][i - 2][0] == 'B') || ((*a)[9][i - 4][0] == 'Z' || (*a)[9][i - 4][0] == 'B'))
			{
				(*a)[9][i][0] = ' ';
				return 1;
			}
		

}


void Peashooter::setare(char ****a, int y, int x) {
	(*a)[y][x][0] = 'P';
}

void SunFlower::producesun() {


}