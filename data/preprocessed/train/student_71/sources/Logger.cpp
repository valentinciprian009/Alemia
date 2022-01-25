#include "Logger.h"
#include <fstream>
#include <time.h>

Logger* Logger::instance = NULL;

Logger::Logger()
{
	std::ifstream in("Log.log");
	if (!in)
	{
		std::ofstream out("Log.log");
		out.close();
	}
	else
		in.close();
}


Logger& Logger::getInstance()
{
	if (!instance)
		instance = new Logger;
	return *instance;
}

void Logger::destroyInstance()
{
	delete instance;
}

void Logger::add(std::string message)
{
	std::ofstream out("Log.log", std::ios::app);
	time_t curr_time;
	curr_time = time(NULL);
	tm* ftime = localtime(&curr_time);
	out << ftime->tm_mday << ".";
	out << ftime->tm_mon << ".";
	out << ftime->tm_year + 1900 << " ";
	out << ftime->tm_hour << ":";
	out << ftime->tm_min << ":";
	out << ftime->tm_sec << "  : ";
	out << message << std::endl;

	out.flush();
	out.close();
}
