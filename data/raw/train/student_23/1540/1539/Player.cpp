#include "Player.h"

Player* Player::instance = nullptr;

Player& Player::getInstance(void)
{
	if (!Player::instance)
	{
		Player::instance = new Player();
	}
	return *Player::instance;
}

void Player::destroyInstance()
{
	if (Player::instance)
	{
		delete Player::instance;
		Player::instance = NULL;
	}
}

void Player::setPlayer(string name, int level, int score, int budget)
{
	this->Name = name;
	this->Level = level;
	this->Score = score;
	this->Budget = budget;
}

void Player::setLevel(int level)
{
	this->Level = level;
}

void Player::setScore(int score)
{
	this->Score = score;
}

void Player::setBudget(int budget)
{
	this->Budget = budget;
}