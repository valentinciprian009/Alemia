#pragma once
#include <string>
class GenericFLower
{
private:
	int viata;
	int sunCost;
protected:
	std::string *filename;
	static int baseIndex;
public:
	virtual void action() = 0;
	int getViata();
	void setViata(int viata);
	int getCost();
	GenericFLower(int viata, int sunCost, std::string filename);
	virtual int getIndex() = 0;
	static int getBaseIndex();
	std::string getFilename();
};

