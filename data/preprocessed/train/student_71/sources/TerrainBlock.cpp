#include "TerrainBlock.h"
#include "ConsoleOutput.h"

void TerrainBlock::draw(int x, int y, int flag)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	const char* block = "               ";

	conOut(9 + 6 * x, 20 + 15 * y, flag) << block;
	conOut(10 + 6 * x, 20 + 15 * y, flag) << block;
	conOut(11 + 6 * x, 20 + 15 * y, flag) << block;
	conOut(12 + 6 * x, 20 + 15 * y, flag) << block;
	conOut(13 + 6 * x, 20 + 15 * y, flag) << block;
	conOut(14 + 6 * x, 20 + 15 * y, flag) << block;
}

std::string TerrainBlock::identity()
{
	return "Empty";
}
