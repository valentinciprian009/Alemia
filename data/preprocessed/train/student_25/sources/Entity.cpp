#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::die(vector<Entity*>&those)
{
	for (auto i = those.begin(); i < those.end(); i++)
	{
		if (*i == this)
		{
			those.erase(i);
			return;
		}
	}
}



void Zombie::check (vector <Entity*> flowers, vector<Entity*> zombies)
{
	if (!stopped)
	{
		for (auto flower : flowers)
		{
			if (flower->get_x() == location.x - 1 && flower->get_y() == location.y)
			{
				plant_attacked = flower;
				stopped = true;
				eating = true;
				flower->set_eater(this);
				return;
			}
		}
		for (auto zombie : zombies)
		{
			if (zombie->get_x() == location.x - 1 && zombie->get_y() == location.y)
			{
				stopped = true;
				return;
			}
		}
	}
	else
	{
		bool has_food = false;
		for (auto flower : flowers)
		{
			if (flower->get_x() == location.x - 1 && flower->get_y() == location.y)
			{
				has_food = true;
				break;
			}
		}
		if (!has_food)
			stopped = false;
	}
	
}

void Zombie::move()
{
	
	auto now=steady_clock::now();
	if (duration_cast<milliseconds>(now - time).count() > move_frequency)
	{
		time = now;
		location.x--;
	}
}

void Zombie::eat()
{
	auto now = steady_clock::now();
	if (duration_cast<milliseconds>(now - time).count() > move_frequency)
	{
		time = now;
		plant_attacked->take_damage(damage);
	}
}

void Zombie::update(vector <Entity*>&flowers, vector <Entity*>& zombies, vector <Entity*>&bullets, Player &player)
{
	if (health <= 0)
	{
		die(zombies);
		player.add_kill(points);
		return;
	}
	check(flowers,zombies);
	if (!stopped)move();
	else
	{
		if (eating)
			eat();
	}
}


void Plant::update(vector<Entity*>&flowers, vector<Entity*>&zombies, vector <Entity*>&bullets, Player &player)
{
	if (health <= 0)
	{
		die(flowers);
		return;
	}
}

void Bullet::move()
{

	auto now = steady_clock::now();
	if (duration_cast<milliseconds>(now - timp).count() > frequency)
	{
		timp = now;
		location.x++;
	}
}

void Bullet::update(vector<Entity*>&flowers,  vector <Entity*>&zombies, vector <Entity*>&bullets, Player &player)
{
	for (auto i : zombies)
	{
		if (i->get_y() == location.y&&i->get_x() == location.x - 1)
		{
			if (freezing)
			{
				i->take_damage(damage);
				i->get_slowed();
			}
			else
				i->take_damage(damage);
			die(bullets);

			return;
		}
	}
	move();
	if (location.x > 11)
		die(bullets);
}

void ShootingPlant::shoot(bool freeze,vector<Entity*>&bullets)
{
	auto now = steady_clock::now();
	int i = 0;
	if (duration_cast<milliseconds>(now - timp).count() > frequency)
	{
		timp = now;
		char icon;
		if (freeze)
		{
			icon = '*';
			bullets.push_back(std::move(new Bullet(location.x + 1, location.y, freeze, icon)));
		}
		else
		{
			icon = 'o';
			bullets.push_back(std::move(new Bullet(location.x + 1, location.y, freeze, icon)));
			cout << i;
			i++;

		}
	}
}

void PeaShooter::update(vector<Entity*>&flowers, vector <Entity*>&zombies, vector <Entity*>&bullets, Player &player)
{
	Plant::update(flowers, zombies, bullets,player);
	shoot(0, bullets);
}

void SnowPea::update(vector<Entity*>&flowers, vector <Entity*>&zombies, vector <Entity*>&bullets, Player &player)
{
	Plant::update(flowers, zombies, bullets,player);
	shoot(1, bullets);
}