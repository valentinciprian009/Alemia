#pragma once
#include "IParser.h"
class PlayingParser :
	public IParser
{
private:
	typedef enum actionType {
		doubleClick, mouseMove, keyPress, none
	}actionType;
private:
	PlayingParser::actionType getActionType(std::string action);
public:
	void parseAction(std::string action) override;
};

