#pragma once
#include <string>

struct PlantInfo
{
public:
	int id;
	int cost;
	int maxHP;

	std::string name;
	std::string filename;

	PlantInfo(int ID, int c, std::string n, std::string fn, int hp) :
		id(ID), cost(c), name(n), filename(fn), maxHP(hp)
	{};

	PlantInfo() : PlantInfo(-1, 0, "", "", 0) {};
};