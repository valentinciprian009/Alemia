#pragma once
#include "IComputerAction.h"
class DummyAction : public IComputerAction
{
public:
	void doAction() override;
};

