#pragma once
#include "Character.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include "Jurnal.h"
#include "Field.h"
#include <chrono>
#include <time.h>
#include <time.h>
#include <chrono>
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <chrono>
#include <time.h>


class CProiectil :
	public Character
{
public:

	CProiectil() : Character(PROIECTIL) {}

	void draw(int col, int row) { static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance(); conOut(row, col) << "o"; }

	void goProiectil(BattleField* f,int col, int row);

	~CProiectil();
};

