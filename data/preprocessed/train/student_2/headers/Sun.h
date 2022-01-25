#pragma once
#include "AbstractDrawable.h"
#include <string>
class Sun : public AbstractDrawable
{
protected:
	const static std::string type;
private:
	const std::string SUN_FILENAME = "sun.txt";
	int drawedAtLineOffset;
	int drawedAtColumnOffset;
public:
	Sun();
	void draw(int lineOffset, int columnOffset) override;
	void undraw() override;
	int getAxisOffset();
	std::string getDrawableType();

};

