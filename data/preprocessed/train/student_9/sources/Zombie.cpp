#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Zombie.h"

using namespace std;

int Zombie::mananca(char ****a) {
	int help;
	for (int i = 22; i <= 65; i = i + 5)
		if ((*a)[9][i][0] == 'P')
			help = i;
	if ((*a)[9][help][0] == 'P' && (*a)[9][help + 1][0] == 'Z')
		return 1;
}

void Zombie::miscare(char ****a) {
	for (int i = 63; i >= 28; i = i - 5)
		if ((*a)[9][i][0] == 'Z'){
			(*a)[9][i - 5][0] = (*a)[9][i][0];
			(*a)[9][i][0] = ' ';
			break;
		}
		else if ((*a)[9][23][0] == 'Z') {
			system("CLS");
			cout << "AI PIERDUT";
			while (true) {
				
			}
		}
}

void Zombie::death(char ****a) {
	for(int i=63;i>=28;i--)
		if ((*a)[9][i][0] == 'Z') {
			(*a)[9][i][0] = ' ';
		}
}

void BucketZombie::death(char ****a) {
	for (int i = 63; i >= 28; i--)
		if ((*a)[9][i][0] == 'B') {
			(*a)[9][i][0] = ' ';
		}
}

void BucketZombie::miscare(char ****a) {
	for (int i = 63; i > 22; i = i - 5)
		if ((*a)[9][i][0] == 'B') {
			(*a)[9][i - 5][0] = (*a)[9][i][0];
			(*a)[9][i][0] = ' ';
			break;
		}
		else if ((*a)[9][23][0] == 'B') {
			system("CLS");
			cout << "AI PIERDUT";
			while (true) {
				
			}
		}
}

int BucketZombie::mananca(char ****a) {
	int help;
	for (int i = 22; i <= 65; i = i + 5)
		if ((*a)[9][i][0] == 'P')
			help = i;
	if ((*a)[9][help][0] == 'P' && (*a)[9][help + 1][0] == 'B')
		return 1;
}