#include "Player.h"

void Player::set_name(string name)
{
	this->name = name;
}

void Player::set_pass(string pass)
{
	this->password = pass;
}

void Player::set_highscore(int high)
{
	this->highscore = high;
}

string Player::get_name()
{
	return string(name);
}

string Player::get_pass()
{
	return string(password);
}

int Player::get_level()
{
	return level;
}

int Player::get_highscore()
{
	return highscore;
}
