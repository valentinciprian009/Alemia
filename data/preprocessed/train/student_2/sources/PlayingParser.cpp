#include "PlayingParser.h"
#include "Game.h"
PlayingParser::actionType PlayingParser::getActionType(std::string action)
{
	if (action.find("dc") == 0)
	{
		return doubleClick;
	}
	else if (action.find("moved") == 0)
	{
		return mouseMove;
	}
	else if (action.length() == 1)
	{
		return keyPress;
	}
	else return none;
}
int getClickedCol(std::string action)
{
	int start = action.find("(");
	int end = action.find(",");
	std::string number = action.substr(start + 1, end - start - 1);

	int Col = std::stoi(number);

	return Col;
}
int getClickedRow(std::string action)
{
	int start = action.find(",");
	int end = action.find(")");
	std::string number = action.substr(start + 1, end - start - 1);

	int row = std::stoi(number);

	return row;
}
void PlayingParser::parseAction(std::string action)
{
	PlayingParser::actionType actionType = getActionType(action);
	switch (actionType)
	{
	case none:
	{
		break;
	}
	case doubleClick:
	{
		int ClickedCol = getClickedCol(action);
		int ClickedRow = getClickedRow(action);

		Game::getGameInstance().answerDoubleClick(ClickedCol, ClickedRow);

		break;
	}
	case mouseMove:
	{
		break;
	}
	case keyPress:
	{
		break;
	}
	default:
	{
		break;
	}
	}

}
