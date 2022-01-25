#pragma once
#include "IParser.h"
class SelectUserParser : public IParser
{
public:
	void parseAction(std::string action) override;
};

