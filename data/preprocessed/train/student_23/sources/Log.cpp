#include "Log.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

Log* Log::instance = NULL;

void Log::addEvent(string eveniment)
{
	Log::evenimente.push_back(eveniment);
}

void Log::printLogInFolder()
{
	ofstream myfile;
	myfile.open("Log.txt");

	for (int i = 0; i < Log::evenimente.size(); i++)
	{
		myfile << Log::evenimente[i] << endl;
	}
	myfile.close();
}

Log& Log::getInstance()
{
	if (!Log::instance)
	{
		Log::instance = new Log();
	}
	return *Log::instance;
}

void Log::destroyInstance()
{
	if (Log::instance)
	{
		delete Log::instance;
		Log::instance = NULL;
	}
}