#pragma once
#include "AbstractDrawable.h"
class BlankSpace : public AbstractDrawable
{
private:
	std::string type = "blank";
	int centerCol;
	int centerLin;
public:
	BlankSpace(int centerLin, int centerCol);
	void draw(int line, int column) override;
	std::string getDrawableType() override;
	void undraw() override;
	int getCenterCol();
	int getCenterLin();
};

