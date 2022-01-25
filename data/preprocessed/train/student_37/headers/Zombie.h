#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Strategy.h"

using namespace std;

class Strategy;

class Zombie
{
private:
	Strategy* strategy = NULL;
	int health = 0;
	int damage;
	
public:
	Zombie(Strategy* strategy, int health, int damage);
	Zombie();
	~Zombie();

	Strategy* get_strategy() {
		return this->strategy;
	}

	bool is_dead() {
		return this->health <= 0;
	}

	void take_damage(int damage) {
		this->health -= damage;
	}

	int get_damage() {
		return this->damage;
	}

};

