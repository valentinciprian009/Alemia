#pragma once
#include "IParser.h"
class MainMenuParser : public IParser
{
public:
	void parseAction(std::string action) override;
};

