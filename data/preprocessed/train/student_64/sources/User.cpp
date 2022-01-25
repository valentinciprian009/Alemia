#include "User.h"
#include<fstream>


bool User::UserDoesExist(std::string name)
{
	std::ifstream fin("Users.txt");
	std::string currentName;
	int level;

	while (!fin.eof())
	{
		fin >> currentName >> level;
		if (currentName == name)
		{
			_currentName = currentName;
			_currentLevel = level;
			fin.close();
			return true;
		}

	}
	fin.close();
	return false;
}

User::User()
{
}


User::~User()
{
}

void User::CheckUserExistence(std::string name)
{
	if (!UserDoesExist(name))
	{
		_currentName = name;
		_currentLevel = 1;
	}
}
