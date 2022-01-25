#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Player.h"
#include "Entity.h"
using namespace std;
class Login:public Entity
{
private:
	Player* new_player;
public:
	void draw();
	bool return_tasting(string);
	void set_player(string nume, string pass);
	Player* get_player();
	
};

