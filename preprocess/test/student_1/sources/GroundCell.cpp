#include"GroundCell.h"

void GroundCell::clearCell()
{
	for (int i = 2; i < 5; i++)
		consoleOut(rowUpperLeft + i, colUpperLeft + 1) << "        ";
}

void GroundCell::print()
{
	consoleOut(rowUpperLeft + 0, colUpperLeft) << " __________ ";
	for (int i = 1; i < 5; i++)
	{
		consoleOut(rowUpperLeft + i, colUpperLeft) << "|";
		consoleOut(rowUpperLeft + i, colUpperLeft + 11) << "|";
	}
	consoleOut(rowUpperLeft + 5, colUpperLeft) << "|__________|";
	switch (type)
	{
	case 0:
		break;

	case 1:
		consoleOut(rowUpperLeft + 2, colUpperLeft + 5) << "@=";
		consoleOut(rowUpperLeft + 3, colUpperLeft + 5) << "|";
		consoleOut(rowUpperLeft + 4, colUpperLeft + 5) << "~";
		break;
		
	case 2:
		consoleOut(rowUpperLeft + 2, colUpperLeft + 5) << "&";
		consoleOut(rowUpperLeft + 3, colUpperLeft + 5) << "|";
		consoleOut(rowUpperLeft + 4, colUpperLeft + 5) << "~";
		break;

	case 3:
		consoleOut(rowUpperLeft + 3, colUpperLeft + 5) << "/\\";
		consoleOut(rowUpperLeft + 4, colUpperLeft + 4) << "O  O";
		break;

	case 4:
		consoleOut(rowUpperLeft + 2, colUpperLeft + 4) << " _ ";
		consoleOut(rowUpperLeft + 3, colUpperLeft + 4) << "(_)";
		break;

	case 5:
		consoleOut(rowUpperLeft + 2, colUpperLeft + 4) << "*@=";
		consoleOut(rowUpperLeft + 3, colUpperLeft + 5) << "|";
		consoleOut(rowUpperLeft + 4, colUpperLeft + 5) << "~";
		break;

	case 6:
		consoleOut(rowUpperLeft + 2, colUpperLeft + 3) << " \\|/ ";
		consoleOut(rowUpperLeft + 3, colUpperLeft + 3) << "-=O=-";
		consoleOut(rowUpperLeft + 4, colUpperLeft + 3) << " /|\\ ";
		break;
	}
}

bool GroundCell::checkInCell(const ConsoleEvent& action)
{
	if (action.getInfo() != "")
		consoleOut(3, 2) << action.getInfo();
	if ((action.getInputRecord().EventType == MOUSE_EVENT) && ((action.getInputRecord().Event.MouseEvent.dwEventFlags == DOUBLE_CLICK) || ((action.getInputRecord().Event.MouseEvent.dwEventFlags == 0) && (action.getInputRecord().Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED))))
		if (action.getInputRecord().Event.MouseEvent.dwMousePosition.Y > rowUpperLeft&& action.getInputRecord().Event.MouseEvent.dwMousePosition.Y<rowUpperLeft + 5 && action.getInputRecord().Event.MouseEvent.dwMousePosition.X>colUpperLeft&& action.getInputRecord().Event.MouseEvent.dwMousePosition.X < colUpperLeft + 13)
		{
			return true;
		}
	return false;
}