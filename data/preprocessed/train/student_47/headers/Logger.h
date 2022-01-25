#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime> 

class Logger
{
private:
	Logger();
	static Logger *instance;
	std::ofstream f;
	int stamp;
public:
	~Logger();
	static Logger & getInstance(void);
	void incrementStamp();

	void operator << (const std::string& s);
};