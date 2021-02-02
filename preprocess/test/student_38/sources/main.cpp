#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include<iostream>

#include"player.h"

#include "resource_bar.h"
#include "flower_bar.h"
#include "flower.h"
#include "garden.h"
#include "zombie_manager.h"

using namespace std;

using namespace std::chrono;



int main(void)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();


	Player player=Player::getInstance();
	Resource_bar rb;
	Flower_bar fb;
	/////////
	Garden garden = Garden::getInstance();
	Zombie_manager zombie_man;

	////////
	COORD mp; //mouse position

	////////clocks for resources
	auto resource_time1 = system_clock::now();
	auto resource_time2 = system_clock::now();
	////////


	/////clocks for bullets
	auto bullet_time1 = system_clock::now();
	auto bullet_time2 = system_clock::now();
	//////

	/////clocks for zombies
	auto zombie_generate_time1 = system_clock::now();
	auto zombie_generate_time2 = system_clock::now();

	auto zombie_move_time1 = system_clock::now();
	auto zombie_move_time2 = system_clock::now();
	//////

	
	while (true)
	{
		mp = conIn.getUserActions(); //mouse position for every frame

		//// Player stats ///
		if (player.life < 0) { conOut(220, 0) << "GAME OVER!!!!!"; break; };

		conOut(15, 2) << "Life: " << player.life << "  ";
		player.score = rb.get_score();
		conOut(3, 2) << "Score: " << player.score << "  ";
		conOut(4, 32) << "Tip: Double click to collect suns";
		conOut(4,33)  << "Tip: Double click to select flower and double click to place it";
		conOut(4, 34) << "Tip: Zombies have 3 lives";
		////             ///

		/// resource_bar + score start -----------------------------------------------------------------

		resource_time2 = system_clock::now();
		
		duration<float> elapsed_seconds_resource = resource_time2 - resource_time1;
		
		rb.Draw(30, 0);
		
		//generate 1 resource at every n seconds
		if ((int)elapsed_seconds_resource.count() % 2 == 0 && (int)elapsed_seconds_resource.count() > 0)
		{
			resource_time1 = resource_time2; // reset timer to 0 after n seconds 
			rb.generate_resource();
		}	

		rb.taken_resource(mp);
		
		////  resource_bar + score  end----------------------------------------------------------------------

		

		
		/// flower bar selector///
		fb.Draw(3, 4);
		fb.activate_selector(mp);
		///                   ///


		/// Garden - Playfield START ----------------------------------------

		garden.Draw(20, 5);

		if (fb.has_selected) // check for clicked tile in the garden 
		{
						// checks for resources and places the flower 
			COORD tile_coord = garden.get_selected_tile(mp);
			if (tile_coord.X != -1)
			{
				Flower *added_flower = new Flower(fb.sel_index+1);
				if (added_flower->getPrice() <= rb.get_score())
				{
					rb.score = rb.get_score() - added_flower->getPrice();
					fb.has_selected = false;
					garden.place_flower_at(tile_coord.X, tile_coord.Y, fb.sel_index+1);
				}

			}
		}
		
		bullet_time2 = system_clock::now();

		duration<float> elapsed_seconds_bullets = bullet_time2 - bullet_time1;

		if (elapsed_seconds_bullets.count() > 0.06)
		{
			garden.update_bullets();
			bullet_time1 = bullet_time2;
			

		}

		

		/// Garden - Playfield END ----------------------------------------


		/// Zombie action
		zombie_generate_time2 = system_clock::now();

		duration<float> elapsed_seconds_zombie = zombie_generate_time2 - zombie_generate_time1;

		if (elapsed_seconds_zombie.count() > 5)
		{
			
			zombie_man.generate();
			if (zombie_man.check_for_win())
			{
				conOut(220, 0) << "YOU WIN!!!!!"; break;

			}
			zombie_generate_time1 = zombie_generate_time2;
		}


		zombie_move_time2 = system_clock::now();

		elapsed_seconds_zombie = zombie_move_time2 - zombie_move_time1;

		if (elapsed_seconds_zombie.count() > 0.15)
		{
			

			zombie_man.check_for_hit_zombies(garden);
			zombie_man.check_for_eaten_flower(&garden);

			player.life = zombie_man.update_zombies();

			

			zombie_move_time1 = zombie_move_time2;
		}
		
		///
	}

	return 0;
}

