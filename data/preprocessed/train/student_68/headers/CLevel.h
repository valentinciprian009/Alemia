#pragma once
#include"CLog.h"


class CLevel
{
public:
	int level_;
	int Nb_Zombies_;
	int lives_;
public:
	CLevel();
	virtual ~CLevel();
	virtual void DrawLand();

};