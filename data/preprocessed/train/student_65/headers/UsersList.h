#pragma once
#include "Player.h"
#include <fstream>
class UsersList
{
private:
	map<string, Player> list;
	static UsersList* instance;

public:
	UsersList();
	static UsersList& get_instance();
	static void destroy_instance();
	~UsersList();
	void add(Player& new_player);
	bool check(Player p);
	void save_players();
	void get_user_from_file();
};

