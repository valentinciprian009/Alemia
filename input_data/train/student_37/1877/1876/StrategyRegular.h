#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Strategy.h"

using namespace std;

class Strategy;
class StrategyRegular: public Strategy
{
public:
	StrategyRegular();
	~StrategyRegular();
	bool execute_move(Zombie* zombie, int surface_number);
};

