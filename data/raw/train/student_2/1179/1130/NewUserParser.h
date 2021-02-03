#pragma once
#include "IParser.h"
class NewUserParser : public IParser
{
private:
	void addUserProcess();
	bool addUserToFile(std::string uName, std::string passW);
public:
	void parseAction(std::string action) override;
};

