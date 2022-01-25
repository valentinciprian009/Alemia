#pragma warning(push)
#pragma warning( disable : 4250)
#pragma once

#include "Plant.h"
#include "ConsoleOutput.h"

class Sunflower :
	public Plant
{
private:
	 bool hasActed;
public:
	void print() const override;
	Sunflower(int x, int y, int price = 50);
	iPlant* clone() override;
	~Sunflower() override;
	void action() override; 
};
 
#pragma warning(pop)