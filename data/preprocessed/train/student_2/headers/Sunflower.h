#pragma once
#include "GenericFLower.h"
#include "AbstractDrawable.h"
class Sunflower : public GenericFLower, public AbstractDrawable
{
private:
	int sunAmount = 5;
	static std::string type;
	int counter = 30000;
public:
	Sunflower(int viata, int sunCost);
	void action() override;
	void draw(int line, int column) override;
	std::string getDrawableType() override;
	void undraw() override;
	int getIndex() override;
};

