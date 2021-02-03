#pragma once
#include"Logare.h"
#include"CGame.h"
#include"Log.h"

class Manager
{
	Manager();
	~Manager();
	static Manager *instance;

	Logare log;
	vector<Utilizator>useri;

	CGame game;

public:
	static Manager& getInstance();
	static void destroyInstance();
	void updateUser(string name, int scor, int nivel);

	void start();
};

