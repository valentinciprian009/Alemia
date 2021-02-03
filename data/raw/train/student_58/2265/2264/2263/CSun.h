#pragma once
#include"CResursa.h"
#define CHR_SUN 79

class CSun:public CResursa
{
public:
	CSun(int loc);

	int locatie;
	~CSun();
};

