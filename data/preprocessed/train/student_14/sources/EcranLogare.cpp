#define _CRT_SECURE_NO_WARNINGS
#include "EcranLogare.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<cwchar>

#include<stdio.h>
#include<dos.h>
#include<fstream>


using namespace std;

EcranLogare* EcranLogare::instance = nullptr;

EcranLogare* EcranLogare::getInstance()
{
	if (!EcranLogare::instance)
	{
		EcranLogare::instance = new EcranLogare();
	}

	return instance;
}

void EcranLogare::DestroyInstance()
{
	if (EcranLogare::instance)
	{
		delete EcranLogare::instance;
		EcranLogare::instance = nullptr;
	}
}

void EcranLogare::DisplayTitleScreen()
{

	
	HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\n\n";
	cout << "     ";

	


	std::cout << "Plants vs Zombie";
	

	cout << "\n\n\n";


}

void EcranLogare::getLogs()
{
	string usern;
	string pass;

	cout << "Username: ";
	cin >> usern;
	cout << "Password: ";
	cin >> pass;


	ifstream outfile;
	outfile.open("logs_database.txt");

	string buffer;
	string fileContent;
	int level = 0;

	int lineCounter = 0;

	bool addToLogs = 0;
	bool wrongPass = 0;

	if (outfile.is_open())
	{
		while (!outfile.eof())
		{
			getline(outfile, buffer);
			lineCounter++;
		}
	}

	outfile.close();
	outfile.open("logs_database.txt");

	int counter = 0;

	if (outfile.is_open())
	{
		while (!outfile.eof())
		{
			getline(outfile, buffer);
			counter++;
			if ((counter) % 3 == 2 && buffer == usern)
			{
				addToLogs = 1;
			}
			if (counter == lineCounter)
			{
				fileContent = fileContent + buffer;
			}
			else
			{
				fileContent = fileContent + buffer + "\n";
			}

		}
	}

	outfile.close();
	outfile.open("logs_database.txt");



	bool SearchUser = 0;
	int new_counter = 1;

	if (outfile.is_open())
	{
		while (!outfile.eof())
		{

			getline(outfile, buffer);

			if (SearchUser == 1)
			{
				if (buffer != pass)
				{
					cout << endl;
					cout << "  Wrong Password!\n";
					cout << "  The game will now close.";
					cout << "\n\n\n";
					exit(EXIT_FAILURE);
					break;

				}
				else
				{
					break;
				}
			}

			if ((new_counter) % 3 == 2 && buffer == usern)
			{
				SearchUser = 1;
			}

			new_counter++;
		}
	}

	outfile.close();

	ofstream outfile2("logs_database.txt");

	if (fileContent == "\n")
	{
		outfile2 << usern + "\n" + pass + "\n" + to_string(level);
	}

	if (addToLogs == 0 && fileContent != "\n")
	{
		outfile2 << fileContent + "\n" + usern + "\n" + pass + "\n" + to_string(level);
	}

	if (addToLogs == 1 && fileContent != "\n")
	{
		outfile2 << fileContent;
	}



	Sleep(2000);

	cout << flush;
	system("CLS");
}