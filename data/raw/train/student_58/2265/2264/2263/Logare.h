#pragma once
#include<vector>
#include<Windows.h>
#include"Utilizator.h"
#include"Exception.h"


class Logare
{
	vector<Utilizator>useri;
	
public:
	Logare();
	static Utilizator *userCurent;

	void citesteUseri(string file);
	bool verificaCompatibilitate(string user, string pass);
	void addUser(string name, string pass);

	void DisplayResourceNAMessageBox();
	vector<Utilizator> getUsers();
	

	~Logare();
};

