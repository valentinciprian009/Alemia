#pragma once
class Log
{
public:
	static Log &getInstance();
	static void destroyInstance();
	void print_log(const char* sir);
	void clearLogFile();
private:
	static Log *instance;

	Log() {};
	Log(const Log&) {};
	~Log() {};
};

