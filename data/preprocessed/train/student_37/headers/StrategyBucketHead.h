#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Strategy.h"
using namespace std;

class StrategyBucketHead : public Strategy
{
public:
	StrategyBucketHead();
	~StrategyBucketHead();

	bool execute_move(Zombie* zombie, int surface_number);
};

