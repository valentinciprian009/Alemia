#include "WalkerZombie.h"
#include "ConsoleOutput.h"
#include <fstream>
#include "Map.h"
const std::string WalkerZombie::type = "WalkerZombie";

WalkerZombie::WalkerZombie(int viata, int viteza, std::string fileName) : GenericZombie(viata, viteza)
{
	this->fileName = fileName;
}

void WalkerZombie::draw(int line, int column)
{
	ConsoleOutput& CO = ConsoleOutput::getInstance();
	CO.setCursorVisibility(false);
	CO.setOutputColor(this->colorCode);

	std::ifstream zombieFile;
	zombieFile.open(this->fileName, std::ifstream::in);

	std::string buffer;
	int lineOffset = 0;
	int colOffset = 0;
	while (std::getline(zombieFile, buffer))
	{
		CO = CO(line + lineOffset, column + colOffset);
		CO << buffer;
		lineOffset++;
	}
	zombieFile.close();
	CO.resetConsoleColor();

	this->drawnAtCol = column;
	this->drawAtLine = line;
}

std::string WalkerZombie::getDrawableType()
{
	return type;
}

void WalkerZombie::undraw()
{
	ConsoleOutput& CO = ConsoleOutput::getInstance();


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			CO(this->drawAtLine + i, this->drawnAtCol + j) << " ";
		}
	}
	this->drawnAtCol = -1;
	this->drawAtLine = -1;
}

int WalkerZombie::getAxisOffset()
{
	return 3;
}

void WalkerZombie::moveLeft()
{
}

void WalkerZombie::depleteLife(int amount)
{
	this->viata -= amount;
	if (this->viata <= 0)
	{
		Map::getInstance().removeZombie(this);
	}
}
