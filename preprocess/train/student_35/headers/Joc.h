#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "ConsoleHandler.h"


#include "Entity.h"
#include "LifeForm.h"
#include "SunFlower.h"
#include "PeaShooter.h"
#include "Zombie.h"
#include"BucketZombie.h"
#include<Windows.h>
#include <time.h>
#include <chrono>
#include<iostream>

#define COL_M 100
#define ROW_M 3


#define terr_1 11
#define terr_2 15
#define terr_3 19

class Joc
{
public:
	Joc() {}
	~Joc(){}
	void doTerrain() {
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		//UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
		for (int i = 0; i < ROW_M; ++i)
			conOut(10 + i, 20) << "|";
		for (int j = 0; j < COL_M; ++j)
		{
			conOut(9, 20 + j) << "#";
			if (j % 10 == 0 && j < 80)
			{
				for (int i = 0; i < ROW_M; ++i)
					conOut(10 + i, 30 + j) << ".";
			}
			else if (j % 10 == 5 && j < 80)
			{
				//conOut(11, 20+j) << "p";
			}
		}
		for (int i = 0; i < ROW_M; ++i)
			conOut(14 + i, 20) << "|";
		for (int j = 0; j < COL_M; ++j)
		{
			conOut(13, 20 + j) << "#";
			if (j % 10 == 0 && j < 80)
			{
				for (int i = 0; i < ROW_M; ++i)
					conOut(14 + i, 30 + j) << ".";
			}
		}
		for (int i = 0; i < ROW_M; ++i)
			conOut(18 + i, 20) << "|";
		for (int j = 0; j < COL_M; ++j)
		{
			conOut(17, 20 + j) << "#";
			if (j % 10 == 0 && j < 80)
			{
				for (int i = 0; i < ROW_M; ++i)
					conOut(18 + i, 30 + j) << ".";
			}
			conOut(21, 20 + j) << "#";
		}
	}
};

