#define _CRT_SECURE_NO_WARNINGS
#include"Log.h"

Log* Log::instance = nullptr;

string get_current_time()
{
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d.%m.%Y  %H:%M:%S --> ", timeinfo);
	string str(buffer);
	return str;
}

Log& Log::getInstance()
{
	if (!Log::instance)
		Log::instance = new Log;
	return *Log::instance;
}

void Log::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void Log::open(const string& filename)
{
	log.open(filename, ios::out);
}

void Log::write(const string& message)
{
	log << get_current_time() << message << endl;
}

void Log::close()
{
	log.clear();
	log.close();
}