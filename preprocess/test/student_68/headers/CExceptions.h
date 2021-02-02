#pragma once
#include"IExceptions.h"

class CExceptions:public IExceptions
{
	string message_;
	int code_;
public:
	CExceptions(string message, int code);
	virtual ~CExceptions();
	void printExceptions();
};

