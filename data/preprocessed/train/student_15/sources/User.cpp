#include "User.h"
#include <fstream>

std::vector<User*> User::getFromFile()
{
	std::vector<User*> v;
	std::ifstream fin("users.txt");
	std::string name;
	std::string password;
	int l, s;
	while (true) 
	{
		fin >> name >> password >> s >> l;
		if (fin.eof())
			break;
		v.push_back(new User(name, password, l, s));
	}

	fin.close();
	return v;
}

void User::printFile(std::vector<User*> users)
{
	std::ofstream fout("users.txt");
	for (auto it : users) 
		fout << it->nume << " " << it->pass << " " << it->scor << " " << it->lvl << "\n";
	fout.close();
}


bool User::check(std::string password)
{
	return pass.compare(password) == 0;
}

User::~User()
{
}
