#pragma once
#include <string>
class AbstractDrawable
{
protected:
	int colorCode;
	int index = -1;
	int drawnAtCol = -1;
	int drawAtLine = -1;
public:
	virtual void draw(int line, int column) = 0;
	virtual std::string getDrawableType() = 0;
	virtual void undraw() = 0;
	void setIndex(int index);
	int getIndex();

	int getDrawnCol();
	int getDrawnLine();

};
