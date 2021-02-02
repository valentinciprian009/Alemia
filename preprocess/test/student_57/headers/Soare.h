#pragma once
#include "Resursa.h"
class Soare:public Resursa
{
private:
	int resourses;
public:
	Soare() :resourses(25) {};
	int getNrOfRes() override;
	void showRes(int row,int col) override;
};

