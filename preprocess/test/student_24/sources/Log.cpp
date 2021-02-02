#define _CRT_SECURE_NO_WARNINGS
#include "Log.h"
#include <chrono>
#include <ctime>

Log* Log::instance = nullptr;

Log::Log(const char* what) : what(what) {}

Log::Log() {}

Log::~Log()
{
}

Log* Log::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Log();
	}
	return instance;
}

void Log::destroyInstance()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void Log::LogEvent(const char* event)
{
	auto now = std::chrono::system_clock::now();
	std::fstream fp("log.txt", std::fstream::app);

	time_t currentTime = std::chrono::system_clock::to_time_t(now);

	fp << event << " at " << ctime(&currentTime) << "\n";

	fp.close();
}