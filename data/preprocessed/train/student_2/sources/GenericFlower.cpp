#include "GenericFLower.h"

int GenericFLower::baseIndex = -1;

int GenericFLower::getViata()
{
	return this->viata;
}

void GenericFLower::setViata(int viata)
{
	this->viata = viata;
}

int GenericFLower::getCost()
{
	return this->sunCost;
}

GenericFLower::GenericFLower(int viata, int sunCost, std::string filename)
{
	this->viata = viata;
	this->sunCost = sunCost;
	this->filename = new std::string;
	this->filename->append(filename);
}
int GenericFLower::getBaseIndex()
{
	return GenericFLower::baseIndex;
}

std::string GenericFLower::getFilename()
{
	return *filename;
}
