#pragma once
#include <iostream>
#include <string>

class Jucator
{
private:
	std::string name;
	int score; //la final de joc
	static int id;
	int n=0;

	int resurse;

public:
	Jucator();
	Jucator(std::string name) :name(name), score(0) ,resurse(0) {  id = n; n++;}

	std::string getName() { return name; }

	int getScore() { return score; }
	int getId() { return id; }

	void setScore(int n) { score = n; }
	~Jucator();
};

