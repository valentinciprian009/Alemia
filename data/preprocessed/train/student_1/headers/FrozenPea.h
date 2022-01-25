#pragma once
#include"Pea.h"

class FrozenPea : public Pea
{
private:
	int speedDecrease;
public:
	FrozenPea() : Pea(), speedDecrease() { ; }
	FrozenPea(int row_ul, int col_ul) : Pea(row_ul, col_ul), speedDecrease() { Log::getInstance().write("FrozenPea created"); }
	FrozenPea(int row_ul, int col_ul, int stopPos) : Pea(row_ul, col_ul, stopPos), speedDecrease() { ; }
	FrozenPea(int row_ul, int col_ul, int stopPos, int speedDcrs) : Pea(row_ul, col_ul, stopPos), speedDecrease(speedDcrs) { Log::getInstance().write("FrozenPea created"); }
	FrozenPea(const FrozenPea& fp) : Pea(fp.rowUpperLeft, fp.colUpperLeft, fp.stopPosition), speedDecrease(fp.speedDecrease) { Log::getInstance().write("FrozenPea created"); }
	int getSpeedDecrease() const { return speedDecrease; }
	void print() { consoleOut(rowUpperLeft, colUpperLeft) << "*"; }
	void shoot() { Pea::shoot(); }
	void hitZombie(Zombie* zombie);
};