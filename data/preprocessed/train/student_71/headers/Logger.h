#pragma once
#include <string>

class Logger
{
	Logger();
	~Logger() {};
	static Logger* instance;
public:
	static Logger& getInstance();
	static void destroyInstance();
	void add(std::string message);
};

