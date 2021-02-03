#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class CLog
{
private:
	CLog() {};
	~CLog() {};
	CLog(const CLog&) {};
	static CLog* instance;


public:
	static CLog& getInstance();
	static void destroyInstance();
	void print_event(string x);
};

