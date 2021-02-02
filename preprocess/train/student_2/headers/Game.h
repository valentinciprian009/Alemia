#pragma once
#include <string>
#include <vector>
#include "Map.h"
class GenericFLower;
/*
	Clasa Game este cea care controleaza si detine toti invariantii jocului. Evident singleton
*/
class Game
{
	//starile jocului
public:
	typedef enum State
	{
		MainMenu, NewUser, SelectUser, Playing, Victory, Defeat
	}State;
	//singleton
private:
	static Game* gameInstance;
	Game();
	Game(Game&);
	//Invarianti
private:
	const std::string LEVEL1FILENAME = "map1.txt";
	const std::string LEVEL2FILENAME = "map2.txt";
	const std::string LEVEL3FILENAME = "map3.txt";
	const std::string MAIN_MENU_FILENAME = "mainMenu.txt";
	const std::string USERS_FILENAME = "users.txt";
	const std::string NEW_USER_MENU = "newUserMenu.txt";
	const std::string SELECT_USER_MENU_FILE = "changeUserMenu.txt";

	const int ROW_TITLE = 20;
	const int COL_FIRST_STAR_POSITION = 75;
	const int COL_DISTANCE_BETWEEN_STARS = 5;

private:
	std::vector<std::string> Users;
	std::string user;
	State gameState;
	int sleepTime;
	int score;
	int sori;
	GenericFLower* selectedPlant = nullptr;
	//Functii accesor
private:
	bool verifyCredentials(std::string username, std::string passWord);
	void loadUsers();
	void doLoadingBar();
	void showMainMenu();
	void showNewUserMenu();
	void showSelectUserMenu();
	void showPlayingMap();
public:
	void changeUser(int option);
	void run();
	int getSori();
	int getScore();
	static Game& getGameInstance();
	void changeGameState(State newState);
	bool addUser(std::string uName, std::string passW);
	int getUsersNum();
	void addSun();
	void addZombie(int zombieNum);
	void answerDoubleClick(int col, int line);
	void addScore(int amount);
	void addSori(int amount);
	void removeSori(int amount);
};

