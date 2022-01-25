#define _CRT_SECURE_NO_WARNINGS
#include "Jucatori.h"
#include "ConsoleOutput.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include <fstream>
#include<vector>
#include <windows.h>

using namespace std;

int Jucatori::get_scor(string numele)
{
	FILE *p;
	p = fopen("nume_jucatori.txt", "r");
	char linie[100];
	char nume[50];
	char space;
	char password[50];
	int scor;
	int nivel;
	int credit;
	char aux[50];
	while (!feof(p)) 
	{
		fscanf(p, "%s", nume);
		fscanf(p, "%s", password);
		fscanf(p, "%s", aux);
		scor = atoi(aux);
		fscanf(p, "%s", aux);
		nivel = atoi(aux);
		fscanf(p, "%s", aux);
		credit = atoi(aux);
		fgets(linie, 100, p);

		if ((string)nume == numele)
		{
			fclose(p);
			return scor;
		}
	}
	fclose(p);
}	

int Jucatori::get_credit(string numele)
{
	FILE *p;
	p = fopen("nume_jucatori.txt", "r");
	char linie[100];
	char nume[50];
	char space;
	char password[50];
	int scor;
	int nivel;
	int credit;
	char aux[50];
	while (!feof(p))
	{
		fscanf(p, "%s", nume);
		fscanf(p, "%s", password);
		fscanf(p, "%s", aux);
		scor = atoi(aux);
		fscanf(p, "%s", aux);
		nivel = atoi(aux);
		fscanf(p, "%s", aux);
		credit = atoi(aux);
		fgets(linie, 100, p);

		if ((string)nume == numele)
		{
			fclose(p);
			return credit;
		}
	}
	fclose(p);
}

void Jucatori::plus_credit(string numele, int puncte)
{
	ifstream fin("nume_jucatori.txt");
	string nume[100], pass[100], linie;
	int scor[100], nivel[100], credit[100];
	int n = 0;
	while (!fin.eof())
	{
		getline(fin, nume[n]);
		getline(fin, pass[n]);
		fin >> scor[n] >> nivel[n] >> credit[n];
		getline(fin, linie);
		n++;
	}
	n--;
	fin.close();
	ofstream fout("nume_jucatori.txt");
	for (int i = 0; i < n; i++)
	{
		if (nume[i] == numele)
			credit[i] += puncte;
		fout << nume[i] << "\n" << pass[i] << "\n" << scor[i] << " " << nivel[i] << " " << credit[i] << "\n";
	}
}

int Jucatori::get_nivel(string numele)
{
	FILE *p;
	p = fopen("nume_jucatori.txt", "r");

	char linie[100];
	char nume[50];
	char space;
	char password[50];
	int scor;
	int nivel;
	int credit;
	char aux[50];
	while (!feof(p))
	{
		fscanf(p, "%s", nume);
		fscanf(p, "%s", password);
		fscanf(p, "%s", aux);
		scor = atoi(aux);
		fscanf(p, "%s", aux);
		nivel = atoi(aux);
		fscanf(p, "%s", aux);
		credit = atoi(aux);
		fgets(linie, 100, p);

		if ((string)nume == numele)
		{
			fclose(p);
			return nivel;
		}
	}
	fclose(p);
}

string Jucatori::get_parola(string numele)
{
	FILE *p;
	p = fopen("nume_jucatori.txt", "r");
	char linie[100];
	char nume[50];
	char space;
	char password[50];
	int scor;
	int nivel;
	int credit;
	char aux[50];
	while (!feof(p))
	{
		fscanf(p, "%s", nume);
		fscanf(p, "%s", password);
		fscanf(p, "%s", aux);
		scor = atoi(aux);
		fscanf(p, "%s", aux);
		nivel = atoi(aux);
		fscanf(p, "%s", aux);
		credit = atoi(aux);
		fgets(linie, 100, p);

		if ((string)nume == numele)
		{
			fclose(p);
			return password;
		}
	}
	fclose(p);
}

void Jucatori::afisare(string numele)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(2, 16) << "Scor";
	conOut(3, 17) << get_scor(numele);
	conOut(36, 63) << "Jucator: " << numele << "           " << "Nivel: " << get_nivel(numele) << "           " << "Credit: " << get_credit(numele);
}

Jucatori::Jucatori(char* nume_1, char* parola_1, int &scor_1, int &nivel_1, int &credit_1)
{
	FILE *p;
	p = fopen("nume_jucatori.txt", "r");
	char linie[50] = "";
	fscanf(p, "%s", &linie);
	if (strcmp(linie, "") == 0) //asta e cazul pt primul jucator din fisier
	{
		fclose(p);
		p = fopen("nume_jucatori.txt", "a");
		fprintf(p, "%s\n%s\n%d %d %d\n", nume_1, parola_1, scor_1, nivel_1, credit_1); //nume parola scor nivel credit
		FILE *v = fopen("file.log", "a");
		fprintf(v, "Un nou jucator a fost introdus.\n");
		fclose(v);
		fclose(p);
	}
	else
	{
		int unic = 1;
		rewind(p);
		int scor, nivel, credit;
		while (!feof(p)) //verific daca numele nu a fost introdus deja
		{
			char aux[100];
			char nume_linie[50];
			char pass_linie[50];
			fscanf(p, "%s", nume_linie);
			fscanf(p, "%s", pass_linie);
			fscanf(p, "%s", aux);
			scor = atoi(aux);
			fscanf(p, "%s", aux);
			nivel = atoi(aux);
			fscanf(p, "%s", aux);
			credit = atoi(aux);
			fgets(linie, 100, p);


			if (strcmp(nume_1, nume_linie) == 0)
			{
				unic = 0;
				if (strcmp(pass_linie, parola_1) == 0)
				{
					scor_1 = scor;
					nivel_1 = nivel;
					credit_1 = credit;
					break;
				}
			}
		}
		fclose(p);

		if (unic == 1)		//daca fisierul este unic il introduce
		{
			p = fopen("nume_jucatori.txt", "a");
			scor_1 = 0;
			nivel_1 = 1;
			credit_1 = 0;
			fprintf(p, "%s\n%s\n%d %d %d\n", nume_1, parola_1, scor_1, nivel_1, credit_1); //nume parola scor nivel credit

			FILE *v = fopen("file.log", "a");
			fprintf(v, "Un nou jucator a fost introdus.\n");
			fclose(v);
			fclose(p);
		}
	}
}

Jucatori::Jucatori()
{
}

Jucatori::~Jucatori()
{
}