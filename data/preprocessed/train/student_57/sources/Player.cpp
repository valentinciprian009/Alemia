#include "Player.h"

void Player::setNume(string n)
{
	this->name = n;
}

string Player::getNume()
{
	return this->name;
}

int Player::getScore()
{
	return this->score;
}

int Player::getResurse()
{
	return this->resurse;
}

void Player::modifyScore(int i)
{
	this->score += i;
}

void Player::modifyRes(int i)
{
	this->resurse += i;
}
