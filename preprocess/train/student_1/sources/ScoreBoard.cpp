#include"Scoreboard.h"

ScoreBoard& ScoreBoard::operator=(const ScoreBoard& other)
{
	if (this != &other)
	{
		level = other.level;
		score = other.score;
		sunQuantity = other.sunQuantity;
	}
	return *this;
}