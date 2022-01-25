#pragma once
#include "GenericZombie.h"
#include "AbstractDrawable.h"
class WalkerZombie : public GenericZombie, public AbstractDrawable
{
private:
	const static std::string type;
	const int colorCode = 4;

	std::string fileName;
public:
	WalkerZombie(int viata, int viteza, std::string fileName);
	void draw(int line, int column) override;
	std::string getDrawableType() override;
	void undraw() override;
	int getAxisOffset();
	void moveLeft() override;
	void depleteLife(int amount) override;
};

