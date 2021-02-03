#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <string>
#include <map>
using namespace std;
class Player
{
private:
	string name, password;
	int highscore,level;
public:
	Player():name(""),password(""),highscore(0),level(0){}
	Player(string nume,string pass,int high=0,int lev=0) :name(nume), password(pass), highscore(high),level(lev) {}
	void set_name(string name);
	void set_pass(string pass);
	void set_highscore(int high);
	string get_name();
	string get_pass();
	int get_level();
	int get_highscore();
};

