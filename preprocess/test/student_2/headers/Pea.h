#pragma once
#include "AbstractDrawable.h"
class Pea : public AbstractDrawable
{
private:
	int shooterIndex;
	int damage;
	const std::string type = "pea";

	int drawnAtLine = -1;
	int drawnAtCol = -1;

	int potentialLine = -1;
	int potentialCol = -1;

public:
	Pea(int shooterIndex, int damage);
	void draw(int line, int column) override;
	std::string getDrawableType() override;
	void undraw() override;
	int getDamage();
	int getShooterIndex();
	void move(int line, int column);
	int getDrawnAtLine();
	int getDrawnAtCol();

	int getPotentialLine();
	int getPotentialCol();

	void setPotentialCol(int newCol);
};

