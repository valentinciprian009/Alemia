#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)

#include "iEntity.h"
class iRectangle :
	public virtual iEntity
{
public:
	virtual void print() const override = 0;
	virtual void printColtStangaSus(int color) const = 0;
	virtual void printSusInterior(int color) const = 0;
	virtual void printInterior(int color) const = 0;
	virtual void printColtDreaptaSus(int color) const = 0;
	virtual void printJosInterior(int color) const = 0;
	virtual void printColtStangaJos(int color) const = 0;
	virtual void printColtDreaptaJos(int color) const = 0;
	virtual void printStangaInterior(int color) const = 0;
	virtual void printDreaptaInterior(int color) const = 0;
	virtual int getX() const = 0;
	virtual int getY() const = 0;
	virtual int getCXcoord() const = 0;
	virtual int getDXcoord() const = 0;
	virtual int getCYcoord() const = 0;
	virtual int getDYcoord() const = 0;
	virtual int getBXcoord() const = 0;
	virtual int getBYcoord() const = 0;
	virtual int getDimX() const = 0;
	virtual int getDimY() const = 0;
	virtual void erase() const = 0;
	virtual bool isInside(int x, int y) const = 0;

	virtual ~iRectangle() = 0 {}
};

#pragma warning (pop)