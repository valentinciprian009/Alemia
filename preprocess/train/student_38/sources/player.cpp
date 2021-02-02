#include "player.h"

Player& Player::getInstance()
{
	Player* pl = new Player();
	return *pl;
}