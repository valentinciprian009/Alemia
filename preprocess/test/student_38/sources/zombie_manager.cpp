#include "zombie_manager.h"

void Zombie_manager::generate()
{

	if (current_zombie >= 15) return;

	int min = 1;
	int max = 5;
	int line_index = (int)(min + (rand() % static_cast<int>(max - min + 1)));

	zombie_vec[current_zombie].Draw(20+Garden::width,5+(Garden_tile::height-2) + (Garden_tile::height+1) *(line_index-1) );
	zombie_vec[current_zombie].is_active = true;


	if(current_zombie+1 <=15 ) current_zombie++;

}

int Zombie_manager::update_zombies()
{
	for (int i = 0; i < 15; i++)
	{
		if (zombie_vec[i].is_active)
		{
			if (zombie_vec[i].x <= 16) // ajunge in partea stanga final
			{
				player.life-=2;
				zombie_vec[i].is_active = false;
				zombie_vec[i].Clear(zombie_vec[i].x - 1, zombie_vec[i].y - 1);
				zombie_vec[i].Clear(zombie_vec[i].x - 1, zombie_vec[i].y);

			}

			zombie_vec[i].Clear();
			zombie_vec[i].Draw(zombie_vec[i].x - 1, zombie_vec[i].y);
		}
		
	}

	return player.life;
}

void Zombie_manager::check_for_hit_zombies(Garden &gd)
{
	Garden garden = gd;

	for (int i = 0; i < 5; i++)
		for(int j = 0;j<8;j++)
	{

			int bullet_x = garden.lines[i].tiles[j].bullet.x;
			int bullet_y = garden.lines[i].tiles[j].bullet.y;

			for (int k = 0; k < 15; k++)
				if(bullet_x != 0)
					if (zombie_vec[k].x == bullet_x -2 ||
						zombie_vec[k].x == bullet_x+1 || 
						zombie_vec[k].x == bullet_x || 
						zombie_vec[k].x == bullet_x -1)
						if (zombie_vec[k].y == bullet_y + 1 || zombie_vec[k].y == bullet_y - 1 || zombie_vec[k].y == bullet_y)
						{
							zombie_vec[k].life--;
						}

	}


}

void Zombie_manager::check_for_eaten_flower(Garden* gd)
{
	Garden *garden = gd;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 8; j++)
		{
			int flowertile_x = garden->lines[i].tiles[j].x;
			int flowertile_y = garden->lines[i].tiles[j].y+1;

			for (int k = 0; k < 15; k++)
			{
				if (zombie_vec[k].x == flowertile_x + 2 || zombie_vec[k].x == flowertile_x +3|| zombie_vec[k].x == flowertile_x )
					if (zombie_vec[k].y == flowertile_y -3 || zombie_vec[k].y == flowertile_y - 2 || zombie_vec[k].y == flowertile_y)
					{
						garden->lines[i].tiles[j].has_flower = false;
						garden->lines[i].tiles[j].clear_bullet(garden->lines[i].tiles[j].bullet.x, garden->lines[i].tiles[j].bullet.y);
					}

			}


		}

}

bool Zombie_manager::check_for_win()
{
	bool is_won = true;
	for (int k = 0; k < 15; k++)
	{
		if (zombie_vec[k].is_active) is_won = false;

	}

	return is_won;

}
