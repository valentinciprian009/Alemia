#include"Game.h"

Game* Game::instance = nullptr;

Game& Game::getInstance()
{
    if (!Game::instance)
    {
        Game::instance = new Game();
    }
    return *Game::instance;
}

void Game::destroyInstance()
{
    if (Game::instance)
    {
        delete Game::instance;
        Game::instance = nullptr;
    }
}

Game::Game() : Menu(), userMenu(UserMenu::getInstance())
{
	SetConsoleTitle("POO vs Zombies");
}

Game::~Game()
{
    ;
}

void Game::exitGame()
{
	UserInterface::ClearScreen();
	Log::getInstance().write("EXITING POO vs Zombies...");
	consoleOut(30, 84) << "EXITING POO vs Zombies...";
	userMenu.destroyInstance();
	auto start = steady_clock::now();
	auto end = steady_clock::now();
	while (true)
	{
		UserInterface::doLoadingBar(ROW_LOADING, COL_FIRST_STAR_POSITION, COL_DISTANCE_BETWEEN_STARS, LOADING_PERIOD, consoleOut);
		end = steady_clock::now();
		if (duration_cast<milliseconds>(end - start).count() > 2000)
		{
			ConsoleEvent::destroyInstance();
			UserInterface::ConsoleInput::destroyInstance();
			UserInterface::ConsoleOutput::destroyInstance();
			destroyInstance();
			exit(0);
		}
	}
}

int Game::start_menu()
{
	UserInterface::ClearScreen();
	Log::getInstance().write("Start Menu POO vs Zombies...");
	UserInterface::printTitle(consoleOut);
	int row_new_user = 36;
	int column_new_user = 92;
	int row_existent_user = row_new_user + 3;
	int column_existent_user = column_new_user;
	int row_exit_button = row_new_user + 6;
	int column_exit_button = column_new_user;
	consoleOut(row_new_user, column_new_user) << "NEW USER";
	consoleOut(row_existent_user, column_existent_user) << "LOAD USER";
	consoleOut(row_exit_button, column_exit_button) << "EXIT GAME";
	while (true)
	{
		if (UserInterface::pressButton(consoleIn, consoleOut, row_exit_button, column_exit_button, "EXIT GAME")) 
		{
			exitGame();
		}
		else if (UserInterface::pressButton(consoleIn, consoleOut, row_new_user, column_new_user, "NEW USER"))
		{
			return 1;
		}
		else if (UserInterface::pressButton(consoleIn, consoleOut, row_existent_user, column_existent_user, "LOAD USER"))
		{
			return 2;
		}
	}
}

int Game::user_menu(int path_back)
{
	int path_next;
	if (path_back == 1)
	{
		path_next = userMenu.newUserMenu();
		if (path_next == 1)
		{
			return 3;
		}
		else if (path_next == 2)
		{
			start_menu();
		}
		else if (path_next == 3)
		{
			exitGame();
		}
	}
	else if (path_back == 2)
	{
		path_next = userMenu.loadUserMenu();
		if (path_next == 1)
		{
			return 3;
		}
		else if (path_next == 2)
		{
			start_menu();
		}
		else if (path_next == 3)
		{
			exitGame();
		}
	}
}

int Game::level(int lvl)
{
	UserInterface::ClearScreen();
	User us = userMenu.getCurrentUser();
	Level level(us);
	level.start();
	int path_next = level.run();
	if (path_next == 2)
	{
		lostGame();
	}
	else if ((path_next == 0) || (path_next == 3))
	{
		userMenu.updateCurrentUser(level.getUser());
	}
	return path_next;
}

void Game::lostGame()
{
	UserInterface::ClearScreen();
	consoleOut(30, 85) << "G A M E   O V E R";
	Log::getInstance().write("GAME OVER!");
	int row_back_button = 34;
	int column_back_button = 88;
	int row_exit_button = 37;
	int column_exit_button = 92;
	consoleOut(row_back_button, column_back_button) << "BACK TO MAIN MENU";
	consoleOut(row_exit_button, column_exit_button) << "EXIT GAME";
	while (true)
	{
		if (UserInterface::pressButton(consoleIn, consoleOut, row_exit_button, column_exit_button, "EXIT GAME"))
		{
			exitGame();
		}
		else if (UserInterface::pressButton(consoleIn, consoleOut, row_back_button, column_back_button, "BACK TO MAIN MENU"))
		{
			start_menu();
		}
	}
}

void Game::endGame()
{
	UserInterface::ClearScreen();
	consoleOut(30, 85) << "CONGRATULATIONS! YOU FINISHED THE GAME!";
	Log::getInstance().write("CONGRATULATIONS! YOU FINISHED THE GAME!");
	consoleOut(31, 90) << userMenu.getCurrentUser().getUsername() << " highscore:  " << userMenu.getCurrentUser().getScoreBoard().getScore();
	int row_back_button = 34;
	int column_back_button = 88;
	int row_exit_button = 37;
	int column_exit_button = 92;
	consoleOut(row_back_button, column_back_button) << "BACK TO MAIN MENU";
	consoleOut(row_exit_button, column_exit_button) << "EXIT GAME";
	while (true)
	{
		if (UserInterface::pressButton(consoleIn, consoleOut, row_exit_button, column_exit_button, "EXIT GAME"))
		{
			exitGame();
		}
		else if (UserInterface::pressButton(consoleIn, consoleOut, row_back_button, column_back_button, "BACK TO MAIN MENU"))
		{
			start_menu();
		}
	}
}

void Game::runGame()
{
	while (true)
	{	
		int start = start_menu();
		int usermenu_path = user_menu(start);
		int level_path = 0;
		if (usermenu_path == 3)
		{
			while (level_path != 3)
			{
				level_path = level(userMenu.getCurrentUser().getMaxLevel() + 1);
				if (level_path == 3)
				{
					endGame();
				}
			}
		}
	}
}