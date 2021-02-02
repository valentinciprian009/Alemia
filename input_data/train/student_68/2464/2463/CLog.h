#pragma once
#include"CExceptions.h"

class CLog
{
private:
	static CLog* object_;
	virtual ~CLog();
public:
	static const char* filename_;
	static const char* path_;
	static FILE* fLog_;
	CLog();
	
	static CLog& getInstance();
	void printLog(const char* message);
};

