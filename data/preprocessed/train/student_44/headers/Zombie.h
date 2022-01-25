#pragma once
#include "Character.h"
#include <iostream>
#include "CProiectil.h"

enum Tip_Zombie
{
	SIMPLE_ZOMBIE ,BH_ZOMBIE,PV_ZOMBIE,S_ZOMBIE
};

//+++ log de nume tip coming... etc

class Zombie : public Character
{
protected:

	std::string name;
	int life;
	Tip_Zombie type;
	CProiectil proiectil;

public:
	Zombie();

	Zombie(std::string nume, Tip_Zombie tip,int lif) : Character(ZOMBIE), name(nume), type(tip),life(lif) {}

	Zombie(Zombie&c) { this->name = c.name; this->life = c.life; this->type = c.type; }

	void operator=(Zombie&c){ this->name = c.name; this->life = c.life; this->type = c.type; }

	std::string getName() { return name; }

	int getLife() { return life; }

	Tip_Zombie getType() { return type; }

	void actionare(BattleField *f);

	
	virtual  ~Zombie();
};

