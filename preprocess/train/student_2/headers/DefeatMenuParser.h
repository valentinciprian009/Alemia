#pragma once
#include "IParser.h"
class DefeatMenuParser : public IParser
{
public:
	void parseAction(std::string action) override;
};

