#include "CLog.h"

CLog* CLog::instance = nullptr;

CLog& CLog::getInstance()
{
	if (!CLog::instance)
	{
		CLog::instance = new CLog();
	}
	return *CLog::instance;
}

void CLog::destroyInstance()
{
	if (CLog::instance)
	{
		delete CLog::instance;
		CLog::instance = nullptr;
	}
}

void CLog::print_event(string x)
{
	ofstream f;
	f.open("log.txt", ios::app);
	f << x<<"\n";
	f.close();
}
