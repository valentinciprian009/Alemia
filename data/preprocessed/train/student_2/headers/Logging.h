#pragma once
#include <string>
class Logging
{
private:
	const std::string fileName = "logging.txt";
public:
	void logEvent(std::string event);
};

