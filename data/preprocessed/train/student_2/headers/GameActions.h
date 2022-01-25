#pragma once
#include "IComputerAction.h"
class GameActions : public IComputerAction
{
private:
	static int sunCounter;
	static int zombieCounter;
public:
	void doAction() override;
};

