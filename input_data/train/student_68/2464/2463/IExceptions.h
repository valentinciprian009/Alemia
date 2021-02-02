#pragma once

#include"MY_UTILS.h"

#define BASE_ERROR 0x00001
#define INEXISTENT_USER (BASE_ERROR+1)
#define STOP_GAME (BASE_ERROR+2)

class IExceptions
{
	int code_;
public:
	virtual void printExceptions()=0;
};

