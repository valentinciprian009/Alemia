#pragma once
#include <iostream>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Entity.h"
#include "Box.h"
#include "Player.h"
#include <vector>
#include <time.h>
#include <fstream>
#include <chrono>


using namespace UserInterface;
using namespace std::chrono;


#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std;

void draw_boxes();
void doLoadingBar();

class Game
{
private:
	ConsoleInput conIn;
	ConsoleOutput conOut;
	static Game* instance;
	vector <Entity*> flowers;
	vector <Entity*> zombies;
	vector <Entity*> bullets;
	char board[5][8];
	bool suns[8];
	Player* player;
	steady_clock::time_point timp_basic;
	steady_clock::time_point timp_bucket;
	bool finished;
	bool new_game;
	string player_name;
	string player_password;
	bool logged_in;
	

	Game() :logged_in(false),conIn(ConsoleInput::getInstance()), conOut(ConsoleOutput::getInstance()), timp_bucket(steady_clock::now()), timp_basic(steady_clock::now()), finished(false) { srand(time(NULL)); };
	void draw_shop();
	void deal_action(UserInterface::mouse_event eveniment, char& simbol);
	void display_enitites();
	void print_suns();
	void print_money();
	void add_suns();
	void add_zombies();
	void update_entities();
	void display_score();
	void check_game_end();
	void won();
	void lost(); 
	void clear_screen();
	void first_interface();
	void log_in_screen();
	void sing_in_screen();
	void check_log_in(string name, string pass, ifstream &f);
	void check_sing_in(string name, string pass, ifstream &f);

public:
	static Game& getInstance();
	void init();
	void play();
	bool is_finished() { return finished; };
	~Game();

};

