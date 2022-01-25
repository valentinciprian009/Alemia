#include"ConsoleEvent.h"

ConsoleEvent* ConsoleEvent::instance = nullptr;

ConsoleEvent& ConsoleEvent::getInstance()
{
	if (!instance)
		instance = new ConsoleEvent;
	return *instance;
}

void ConsoleEvent::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}