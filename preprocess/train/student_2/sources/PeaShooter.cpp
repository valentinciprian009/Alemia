#include "PeaShooter.h"
#include "ConsoleOutput.h"
#include <fstream>
#include "Pea.h"
#include "Map.h"


void PeaShooter::draw(int line, int column)
{
	ConsoleOutput& CO = ConsoleOutput::getInstance();
	CO.setCursorVisibility(false);
	CO.setOutputColor(this->colorCode);

	std::ifstream plantFile;
	plantFile.open(*(this->filename), std::ifstream::in);

	std::string buffer;
	int lineOffset = 0;
	int colOffset = 0;
	while (std::getline(plantFile, buffer))
	{
		CO = CO(line + lineOffset, column + colOffset);
		CO << buffer;
		lineOffset++;
	}
	plantFile.close();
	CO.resetConsoleColor();

	this->drawAtLine = line;
	this->drawnAtCol = column;

}

std::string PeaShooter::getDrawableType()
{
	return this->type;
}

void PeaShooter::undraw()
{
}

void PeaShooter::action()
{
	counter--;
	if (counter == 0)
	{
		counter = 90000;
		Pea* p = new Pea(this->index, this->damage);
		Map::getInstance().addPea(p);
	}
}

PeaShooter::PeaShooter(int viata, int sunCost, int damage) :GenericFLower(viata, sunCost, "peashooter.txt")
{
	this->damage = damage;
	this->colorCode = 10;
	this->index = GenericFLower::baseIndex + 1;
	GenericFLower::baseIndex++;
}

int PeaShooter::getIndex()
{
	return this->index;
}