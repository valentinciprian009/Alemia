#pragma once
#include<string>

class User
{
	std::string _currentName;
	int _currentLevel;
	bool UserDoesExist(std::string name);

public:
	User();
	User(std::string name, int level) {
		_currentName = name;
		_currentLevel = level;
	}
	~User();

	void set_name(std::string name) { _currentName = name; }
	void set_level(int level) { _currentLevel = level; }
	std::string get_name() {return _currentName;}
	int get_level() { return _currentLevel; }
	void CheckUserExistence(std::string name);

};

