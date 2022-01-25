#pragma once
#include "entity.h"

class Plant : public entity
{
	public:

		Plant(int x, int y) :entity::entity(x, y) {
			name = "Plant";
		};
		static const int reuse_time = 0;
		static const int cost = 0;
};

