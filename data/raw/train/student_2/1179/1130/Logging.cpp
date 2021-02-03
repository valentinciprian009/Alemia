#include "Logging.h"
#include <fstream>
void Logging::logEvent(std::string event)
{
	std::ofstream logFile;
	logFile.open(fileName, std::ofstream::app);

	logFile << event << std::endl;
	logFile.close();
}
