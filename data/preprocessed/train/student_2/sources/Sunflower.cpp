#include "Sunflower.h"
#include "Game.h"
#include "ConsoleOutput.h"
#include <fstream>
std::string Sunflower::type = "sunflower";

Sunflower::Sunflower(int viata, int sunCost) :GenericFLower(viata, sunCost, std::string("sunflower.txt"))
{
	this->colorCode = 14;
	this->index = GenericFLower::baseIndex + 1;
GenericFLower:baseIndex++;
}

void Sunflower::action()
{
	counter--;
	if (counter == 0)
	{
		Game::getGameInstance().addSori(this->sunAmount);
		counter = 30000;
	}
}

void Sunflower::draw(int line, int column)
{
	ConsoleOutput& CO = ConsoleOutput::getInstance();
	CO.setCursorVisibility(false);
	CO.setOutputColor(this->colorCode);

	std::ifstream sunFile;
	sunFile.open(*(this->filename), std::ifstream::in);

	std::string buffer;
	int lineOffset = 0;
	int colOffset = 0;
	while (std::getline(sunFile, buffer))
	{
		CO = CO(line + lineOffset, column + colOffset);
		CO << buffer;
		lineOffset++;
	}
	sunFile.close();
	CO.resetConsoleColor();

	this->drawAtLine = line;
	this->drawnAtCol = column;
}

std::string Sunflower::getDrawableType()
{
	return this->type;
}

void Sunflower::undraw()
{
}

int Sunflower::getIndex()
{
	return -1;
}
