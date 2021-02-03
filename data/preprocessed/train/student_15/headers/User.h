#pragma once
#include <iostream>
#include <string>
#include <vector>

class User
{
public:
	static std::vector<User*> getFromFile();
	static void printFile(std::vector<User*> users);

private:
	std::string nume;
	std::string pass;
	int lvl;
	int scor;

public:
	User(std::string nm, std::string password, int lv = 1, int scr = 0) :
		nume(nm), lvl(lv), scor(scr), pass(password)
	{};

	std::string name() { return nume; }
	int level() { return lvl; }
	int score() { return scor; }
	bool check(std::string pass);

	void addScore(int inc) { scor += inc; }
	void addlevel() { lvl++; }

	~User();
};

