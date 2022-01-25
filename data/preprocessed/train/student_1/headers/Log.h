#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<time.h>
using namespace std;

class Log
{
public:
	static Log& getInstance();
	static void destroyInstance();
	void open(const string& filename);
	void write(const string& message);
	void close();
private:
	static Log* instance;
	ofstream log;
	Log() { ; }
	~Log() { ; }
};