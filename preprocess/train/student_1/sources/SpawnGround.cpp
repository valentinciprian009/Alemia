#include"SpawnGround.h"

SpawnGround::SpawnGround(int row_ul, int col_ul) : Entity(row_ul, col_ul), plantSelected()
{
	for (int i = 0; i < 5; i++)
		spawn.push_back(GroundCell(row_ul + 6 * i, col_ul, i + 1));
}

void SpawnGround::print()
{
	for (auto& cell : spawn)
		cell.print();
	for (int i = 0; i < 5; i++)
		for (int j = 1; j < 6; j++)
			consoleOut(rowUpperLeft + 6 * i + j, colUpperLeft + 13) << "#";
}

void SpawnGround::selectPlant()
{
	string str;
	ConsoleEvent& action = consoleIn.getUserActions();
	for (int i = 1; i < 6; i++)
	{
		if (spawn[i - 1].checkInCell(action))
		{
			plantSelected = i;
		}
		switch (plantSelected)
		{
		case 1:
			str = "PEASHOOTER selected ";
			break;
		case 2:
			str = "SUNFLOWER selected  ";
			break;
		case 3:
			str = "CHERRY BOMB selected";
			break;
		case 4:
			str = "WALL-NUT selected   ";
			break;
		case 5:
			str = "SNOW PEA selected   ";
			break;
		case 0:
			str = "No plant selected   ";
			break;
		}
		consoleOut(1, 2) << str;
		Log::getInstance().write(str);
	}
}