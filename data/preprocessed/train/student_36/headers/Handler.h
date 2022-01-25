#pragma once
#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

#include <time.h>
#include <chrono>

#include "ConsoleInput.h"
#include "ConsoleOutput.h"

#include "Menu.h"

#include "Terrain.h"

#include "Sunflower.h"
#include "Wall_nut.h"
#include "Cherry_Bomb.h"
#include "Snow_Pea.h"

#include "Normal_Zombie.h"
#include "BucketHead_Zombie.h"
#include "PoleVaulting_Zombie.h"
#include "Super_Zombie.h"

#include "Sun.h"
#include "Frozen_Pea.h"

using namespace std;

class Handler
{
private:
	static Handler* mpInstance;

	int resources = 400;

	Handler() {};
	virtual ~Handler() {};

public:
	static Handler& getInstance();

	void color(int color);

	void get_pos_on_console(int& x, int& y);
	void get_pos_on_matrix(int& x, int& y);
	void get_y_sun(int& y);
	void reverse_get_y_sun(int& y);
	void gotoXY(int x, int y);

	void collect_sun(int x);
	void show_resources();
	int spend_resources(int x);
	void generate_sun(vector<vector<int>> fight_matrix, vector<vector<int>>& sun_matrix, int i, int j, int runs);

	void set_action(UserInterface::ConsoleInput conIn, int& action, int &ok, int number_zombies_killed);
	void set_pos_and_coord(int conIn_x, int conIn_y, int& position_in_vector, int& coord_on_x);
	void choose_vector(vector<Entities*>& v, int action, int position_in_vector, int coord_on_x, int coord_on_y);
	void set_object_in_vector_and_in_fight_matrix(int conIn_x, int conIn_y, vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, int action, int position_in_vector, int coord_on_x);

	void set_projectiles(vector<vector<int>> fight_matrix, vector<vector<int>>& projectile_matrix);
	void remove_projectiles_from_the_screen(vector<vector<int>> fight_matrix);

	void check_if_any_button_is_pressed(UserInterface::ConsoleInput conIn, int& start_next_round, int round);

	void collect_resources(UserInterface::ConsoleInput conIn, vector<vector<int>>& sun_matrix);

	void generate_Zombie(vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, int round, int row, int number_zombies, int& nr_PV_Zombies_Created, int& number_zombies_created);
	void spawn_Zombies(vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, int& number_zombies_created, int number_zombies, int& nr_PV_Zombies_Created, int round);
	void verif_if_Zombie_is_killed(vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, int& number_zombies_killed, int i, int j, int j_for_Lines);
	void move_Zombies(int i, vector<vector<int>>& fight_matrix, vector<vector<int>>& projectile_matrix, vector<vector<Entities*>>& Lines, vector<vector<int>>& sun_matrix, int& number_zombies_killed, int runs);

	void cherrybomb_explode(vector<vector<int>>& fight_matrix, vector<vector<Entities*>>& Lines, int x, int y, int& number_zombies_killed);

	void set_plants(UserInterface::ConsoleInput& conIn, vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, int& action, int& ok_set_action, int& ok_set_plants, int& number_zombies_killed);

	void move_projectiles(vector<vector<int>>& projectile_matrix, vector<vector<int>>& fight_matrix, vector<vector<Entities*>>& Lines, int i, int& number_zombies_killed);

	void verif_game_lost(vector<vector<int>> fight_matrix, int& ok, int& round);

	void start_battle(vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, vector<vector<int>>& projectile_matrix, vector<vector<int>>& sun_matrix, int& round, int& ok);

	void show_boundaries(int x);

	void start_game(UserInterface::ConsoleInput& conIn, vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, vector<vector<int>>& projectile_matrix, vector<vector<int>>& sun_matrix, int& start_next_round, int& action, int& ok_set_action, int& round, int& ok_set_plants, int& ok);

	void game();
};