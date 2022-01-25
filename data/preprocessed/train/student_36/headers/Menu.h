#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

class Menu
{
private:
	static Menu* mpInstance;

	int score = 0;
	char username[11] = "\0";
	char password[11] = "\0";

	int verify_username_length();
	int verify_username_existence(FILE* f);
	void set_password();
	void gotoXY(int x, int y);

	Menu();
	virtual ~Menu() {};

public:
	static Menu& getInstance();

	void login();
	void save_infos(int runde);
	void set_score(int x);
	void show_score();

};