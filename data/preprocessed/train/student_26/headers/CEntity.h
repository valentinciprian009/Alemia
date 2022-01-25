#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <iostream>
using namespace std;
class CEntity
{
	string name;
public:
	virtual void draw() = 0;
	CEntity();
	~CEntity();
};

