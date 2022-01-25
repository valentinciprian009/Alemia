#pragma once
#include "AbstractDrawable.h"
#include "GenericFLower.h"
class PeaShooter :public GenericFLower, public AbstractDrawable
{
private:
	int damage;
	const std::string type = "peaShooter";
	int index = -1;
	int counter = 1000;
public:
	void draw(int line, int column) override;
	std::string getDrawableType() override;
	void undraw() override;
	void action() override;
	PeaShooter(int viata, int sunCost, int damage);
	int getIndex() override;

};

