#include "Log.h"
#include <fstream>
Log *Log::instance = nullptr;

Log &Log::getInstance()
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
		Log::instance = nullptr;
	}
}

void Log::print_log(const char* sir) {
	std::ofstream fout;
	fout.open("LogLastGame.txt", std::ofstream::app);
	fout << sir << std::endl;
	fout.close();
}

void Log::clearLogFile() {
	std::ofstream fout;
	fout.open("LogLastGame.txt");
	fout.close();
}