#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include <windows.h>
#include<vector>

using namespace std;

class Jucatori
{
private:
	string nume;
	string parola;
	int scor;
	int credit;
	int ultimul_nivel;
public:
	int get_scor(string nume);
	int get_credit(string nume);
	void plus_credit(string nume, int puncte);
	int get_nivel(string nume);
	string get_parola(string nume);
	void afisare(string numele);

	Jucatori(char* nume_1, char* parola_1, int& scor_1, int& nivel_1, int& credit_1);
	Jucatori();
	~Jucatori();
};