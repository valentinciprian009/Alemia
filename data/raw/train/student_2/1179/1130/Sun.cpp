#include "Sun.h"
#include "ConsoleOutput.h"
#include <fstream>


const std::string Sun::type = "Sun";

Sun::Sun()
{
	this->colorCode = 14;
}

void Sun::draw(int line, int col)
{
	ConsoleOutput &CO = ConsoleOutput::getInstance();
	CO.setCursorVisibility(false);
	CO.setOutputColor(this->colorCode);

	std::ifstream sunFile;
	sunFile.open(this->SUN_FILENAME, std::ifstream::in);

	std::string buffer;
	int lineOffset = 0;
	int colOffset = 0;
	while (std::getline(sunFile, buffer))
	{
		CO = CO(line + lineOffset, col + colOffset);
		CO << buffer;
		lineOffset++;
	}
	sunFile.close();
	CO.resetConsoleColor();
	this->drawedAtColumnOffset = col;
	this->drawedAtLineOffset = line;
}

void Sun::undraw()
{
	ConsoleOutput& CO = ConsoleOutput::getInstance();
	CO.setCursorVisibility(false);

	std::ifstream sunFile;
	sunFile.open(this->SUN_FILENAME, std::ifstream::in);

	for (int i = 0; i < 3; i++)
	{
		CO = CO(this->drawedAtLineOffset + i, this->drawedAtColumnOffset);
		for (int j = 0; j < 3; j++)
		{

			CO << " ";
		}
	}

}
int Sun::getAxisOffset()
{
	std::ifstream sunFile;
	sunFile.open(this->SUN_FILENAME, std::ifstream::in);

	std::string buffer;

	std::getline(sunFile, buffer);

	sunFile.close();

	return buffer.size() + 1;
}

std::string Sun::getDrawableType()
{
	return Sun::type;
}
