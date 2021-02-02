#include "UsersList.h"
UsersList* UsersList::instance = NULL;
UsersList& UsersList::get_instance()
{
	// TODO: insert return statement here
	if (instance == NULL)
		instance = new UsersList();
	return *instance;
}
void UsersList::destroy_instance()
{
	if (instance)
		delete instance;
}
UsersList::UsersList()
{
	get_user_from_file();
}
UsersList::~UsersList()
{
	save_players();
}
void UsersList::add(Player& new_player)
{
	string name = new_player.get_name();
	list[name] = new_player;
}

bool UsersList::check(Player p)
{
	map<string, Player>::iterator it;
	it = list.find(p.get_name());
	if (it != list.end())
		return 1;
	else
		return 0;
}

void UsersList::save_players()
{
	ofstream f("users\\player_list.xlsx");
	for (auto a : list)
	{
		f << a.second.get_name() << a.second.get_pass() << a.second.get_highscore()<<a.second.get_level();
	}
}

void UsersList::get_user_from_file()
{
	ifstream f("users\\player_list.xlsx");

	while (f) {
		string name, pass;
		int high,level;
		f >> name >> pass >> high>>level;
		Player p(name, pass, high,level);
		list.insert(pair<string, Player>(name, p));
	}
}
