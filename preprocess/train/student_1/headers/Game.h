#pragma once
#include"UserMenu.h"
#include"Level.h"

class Game : public Menu
{
private:
	Game();
	virtual ~Game();
	static Game* instance;
	UserMenu& userMenu;

public:
	static Game& getInstance();
	static void destroyInstance();
	void runGame();
	int start_menu();
	int user_menu(int path_back);
	int level(int lvl);
	void lostGame();
	void endGame();
	void exitGame();
};