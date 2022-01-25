#include "Player.h"

Player* Player::instance = NULL;

Player::Player()
{
	name = "";
	password = "";
	availableSun = 0;
	currentLevel = 0;
}

Player::~Player()
{
	delete Player::instance;
	instance = NULL;
}

void Player::setName(std::string name)
{
	this->name = name;
}

void Player::setPassword(std::string password)
{
	this->password = password;
}

void Player::increaseLevel()
{
	currentLevel++;
}

void Player::setCurrentLevel(int x)
{
	currentLevel = x;
}

std::string& Player::getName()
{
	return name;
}

std::string& Player::getPassword()
{
	return password;
}


Player& Player::getInstance()
{
	if (!instance)
		instance = new Player;
	return *instance;
}

void Player::destroyInstance()
{
	delete instance;
}

int Player::getCurrentLevel()
{
	return currentLevel;
}

int Player::getMaximumLevel()
{
	return maximumLevel;
}

int Player::getAvailableSun()
{
	return availableSun;
}

void Player::increaseScore(int x)
{
	availableSun += x;
}

void Player::decreaseScore(int x)
{
	availableSun -= x;
}
