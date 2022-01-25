#pragma once
#include <string>
#include <fstream>

class Log
{
private:
	static Log* instance;
	Log(const char* what);
	Log();
	Log(const Log& old) = delete;
	~Log();

	std::string what;

public:
	static Log* getInstance();
	static void destroyInstance();
	static void LogEvent(const char* event);
};

