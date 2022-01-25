#pragma once
#include <string>
class IParser
{
public:
	virtual void parseAction(std::string) = 0;
};

