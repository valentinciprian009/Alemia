#pragma once
#include <conio.h>
#include <fstream>
#include "ConsoleOutput.h"
#include <string>

class User
{
private:
	bool m_Error;
	std::string m_Nume;
	int m_Score;
	int m_Level;
	int m_Resource;

	std::string retrieveUsername(UserInterface::ConsoleOutput& conOut);
	bool checkExistence();
	std::string getUserFile() const;
	void retrieveStats();
	bool isNewUser(UserInterface::ConsoleOutput& conOut) const;
	void addToUserFile();

public:
	User();
	~User() {}
	bool checkIdentity() const;
	void setScore(int toAdd);
	void setLevel(int lvl);
	void setResources(int toAdd);
	void printDataToFile() const;
	std::string getNume() const;
	int getScore() const;
	int getLevel() const;
	int getResources() const;
	void printDataToScreen() const;
};

