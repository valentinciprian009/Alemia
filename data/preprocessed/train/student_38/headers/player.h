#pragma once
class Player
{
public:
	int life = 20;
	int score;

	static Player& getInstance(void);
};

