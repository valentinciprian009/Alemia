#include "Menu.h"

Menu* Menu::mpInstance = NULL;

Menu& Menu::getInstance()
{
	if (mpInstance == NULL)
	{
		mpInstance = new Menu();
	}
	return *mpInstance;
}

int Menu::verify_username_length()
{
	char* p = new char[256];
	try
	{
		cout << "Dati username-ul pe care doriti sa-l folositi: ";
		cin >> p;
		if (strlen(p) < 3 || strlen(p) > 10)
		{
			throw 1;
		}
		else
		{
			strcpy(username, p);
			delete[] p;
			username[strlen(username)] = '\0';
		}
	}
	catch (...)
	{
		system("cls");
		cout << "Username-ul trebuie sa aiba intre 3 si 10 caractere. Introduceti alt username." << endl;
		system("pause");
		system("cls");
		return 1;
	}
	return 0;
}

int Menu::verify_username_existence(FILE* f)
{
	try
	{
		char name[10];
		char rest_string[20];
		fseek(f, 0, SEEK_SET);
		while (!feof(f))
		{
			fscanf(f, "%s", name);
			name[strlen(name)] = '\0';
			if (strcmp(name, username) == 0)
			{
				throw 1;
			}
			fgets(rest_string, 20, f);
		}
	}
	catch (...)
	{
		system("cls");
		cout << "Acest username exista deja. Introduceti alt username." << endl;
		system("pause");
		system("cls");
		return 1;
	}
	return 0;
}

void Menu::set_password()
{
	start:
	char* p = new char[256];
	try
	{
		cout << "Dati password-ul pe care doriti sa-l folositi: ";
		cin >> p;
		if (strlen(p) < 3 || strlen(p) > 10)
		{
			throw 1;
		}
		else
		{
			strcpy(password, p);
			delete[] p;
			password[strlen(password)] = '\0';
		}
	}
	catch (...)
	{
		system("cls");
		cout << "Password-ul trebuie sa aiba intre 3 si 10 caractere. Introduceti alt password." << endl;
		system("pause");
		system("cls");
		goto start;
	}
}

void Menu::set_score(int x)
{
	score += x;
}

void Menu::login()
{
start:

	int ok;
	ok = verify_username_length();
	if (ok == 1)
	{
		goto start;
	}
	FILE* f;
	f = fopen("login.log", "r");
	if (f == NULL)
	{
		f = fopen("login.log", "w");
	}
	else // daca fisierul este deja creat se verifica daca exista o inregistrare cu username-ul dat mai sus
	{
		ok = verify_username_existence(f);
		if (ok == 1)
		{
			goto start;
		}
	}
	system("cls");

	set_password();

	fclose(f);
}

void Menu::gotoXY(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Menu::show_score()
{
	int verif = score;
	int digits = 0;

	while (verif)
	{
		verif /= 10;
		digits++;
	}

	gotoXY(8-digits, 2);
	cout << score;
}

void Menu::save_infos(int runde)
{
	FILE* f;
	f = fopen("login.log", "a+");
	fprintf(f, "%s %s %d %d\n\n", username, password, runde, score);
	fclose(f);
}

Menu::Menu()
{
	login();
	system("cls");
}