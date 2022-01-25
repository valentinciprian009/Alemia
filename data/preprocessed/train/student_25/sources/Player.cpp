#include "Player.h"


Player* Player::instance = nullptr;

Player& Player::get_instance()
{
	if (!instance)
	{
		instance = new Player;
		return *instance;
	}
	else
	{
		return *instance;
	}
}

int Player::check_player()
{
	auto now = steady_clock::now();
	if (duration_cast<milliseconds>(now - time).count() > sun_rate)
	{
		time = now;
		return rand() % 8;
	}
	else
		return -1;

}

void Player::add_kill(int points)
{
	zombie_kills += points;
	score = zombie_kills / 10;
}

Player::~Player()
{
}
