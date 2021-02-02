#pragma once
#include <vector>
#include <string>

using namespace std;

class Log
{
public:
	static Log& getInstance();
	static void destroyInstance();
	void addEvent(string eveniment);
	void printLogInFolder();
private:
	static Log* instance;
	vector<string> evenimente;

	Log() {};
	Log(const Log&) {};
	~Log() {};
};