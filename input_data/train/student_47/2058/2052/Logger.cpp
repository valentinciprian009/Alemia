#include "Logger.h"

Logger* Logger::instance;

Logger::Logger() {
	stamp = 0;
	f.open("log", std::fstream::in | std::fstream::out | std::fstream::app);
}

Logger::~Logger()
{
	f.close();
}

Logger & Logger::getInstance(void)
{
	if (!instance) {
		instance = new Logger();
	}
	return *instance;
}

void Logger::incrementStamp()
{
	stamp++;
}

void Logger::operator<<(const std::string & s)
{
	f << stamp << ": ";
	f << s;
}