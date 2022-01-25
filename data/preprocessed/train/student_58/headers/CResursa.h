#pragma once
#include"CObject.h"

class CResursa :public CObject
{

protected:
	int val;

public:
	CResursa(int row, int col);



	int getVal() { return val; }
	virtual ~CResursa();
};

