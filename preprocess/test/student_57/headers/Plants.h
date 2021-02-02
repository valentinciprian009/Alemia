#pragma once
class Plants
{

public:
	virtual void showPlat(int row,int col) = 0;
	virtual void showPlatB(int row, int col) = 0;
	virtual int getCost() = 0;
	virtual int getNrMuscaturi() = 0;
	virtual int getRegenerare() = 0;
};

