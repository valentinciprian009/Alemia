#pragma once
#include "IParser.h"
class VictoryMenuParser : public IParser
{
public:
	void parseAction(std::string action) override;
};

