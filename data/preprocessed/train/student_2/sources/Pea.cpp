#include "Pea.h"
#include "ConsoleOutput.h"

Pea::Pea(int shooterIndex, int damage)
{
	this->shooterIndex = shooterIndex;
	this->damage = damage;
	this->colorCode = 10;
}
void Pea::draw(int line, int column)
{
	ConsoleOutput& CO = ConsoleOutput::getInstance();
	CO.setOutputColor(this->colorCode);
	CO(line, column) << "pea";
	CO.resetConsoleColor();

	this->drawnAtCol = column;
	this->drawnAtLine = line;

	this->potentialLine = line;
	this->potentialCol = column;
}

std::string Pea::getDrawableType()
{
	return this->type;
}

void Pea::undraw()
{
	ConsoleOutput& CO = ConsoleOutput::getInstance();
	CO(this->drawnAtLine, this->drawnAtCol) << "   ";
}

int Pea::getDamage()
{
	return this->damage;
}

int Pea::getShooterIndex()
{
	return this->shooterIndex;
}

void Pea::move(int line, int column)
{
	this->undraw();
	this->draw(line, column);
}

int Pea::getDrawnAtLine()
{
	return this->drawnAtLine;
}

int Pea::getDrawnAtCol()
{
	return this->drawnAtCol;
}

int Pea::getPotentialLine()
{
	return this->potentialLine;
}

int Pea::getPotentialCol()
{
	return this->potentialCol;
}

void Pea::setPotentialCol(int newCol)
{
	this->potentialCol = newCol;
}
