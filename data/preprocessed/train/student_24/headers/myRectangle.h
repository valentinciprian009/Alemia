#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)

#include "iRectangle.h"
#include "Entity.h"
#include "ConsoleOutput.h"

class myRectangle :
	public virtual iRectangle, public virtual Entity
{
protected:
	const int dimX = 5;
	const int dimY = 9;

	int coordAX;
	int coordBX;
	int coordCX;
	int coordDX;
	int coordAY;
	int coordBY;
	int coordCY;
	int coordDY;

public:
	int getDimX() const override;
	int getDimY() const override;
	int getX() const override;
	int getY() const override;
	int getBXcoord() const override;
	int getCXcoord() const override;
	int getDXcoord() const override;
	int getBYcoord() const override;
	int getCYcoord() const override;
	int getDYcoord() const override;
	bool isInside(int x, int y) const override;


	myRectangle(int x, int y);
	virtual void print() const override;
	
	void printColtStangaSus(int color) const override;
	void printSusInterior(int color) const override;
	void printInterior(int color) const override;
	void printColtDreaptaSus(int color) const override;
	void printJosInterior(int color) const override;
	void printColtStangaJos(int color) const override;
	void printColtDreaptaJos(int color) const override;
	void printStangaInterior(int color) const override;
	void printDreaptaInterior(int color) const override;

	void erase() const override;
	virtual ~myRectangle() override{}
};

#pragma warning (pop)