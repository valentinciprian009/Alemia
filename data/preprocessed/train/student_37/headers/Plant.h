#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Plant
{
protected:
	int health;
	string type;
public:
	Plant(int health, string type);
	~Plant();

	virtual int fire(int surface_number) = 0;

	bool is_dead();

	void take_damage(int damage);
	string get_type() {
		return this->type;
	}
};

