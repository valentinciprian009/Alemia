#pragma once
#include <string>

namespace Arena
{
	struct ZombieInfo
	{
		std::string filename;
		std::string name;
		int maxHP;
		int speed; //smaller value = faster
		int points;

		ZombieInfo(std::string nom, std::string fn, int hp, int v, int score)
			: name(nom), filename(fn), maxHP(hp), speed(v), points(score)
		{};
	};
}