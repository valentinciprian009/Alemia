#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <windows.h>

#define COL_DISTANCE_BETWEEN_ROWS	5
#define COL_LAST_MATRIX_POSITION    150
class teren
{
	char casuta =char ( 178 );
public:
	teren();
	~teren();
	void level1();
	void level2();
	void level3();
	bool click();
	friend class ConsoleOutput;
};

