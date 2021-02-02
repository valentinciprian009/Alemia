#include "GAME.h"

#define ROW_TITLE					23		
#define COL_FIRST_STAR_POSITION		80
#define COL_DISTANCE_BETWEEN_STARS	4

void doLoadingBar()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 70)
	{
		
		{
			begin = end;
			conOut(ROW_TITLE + 3, col - 1) << printedChar;
			if (col >= COL_FIRST_STAR_POSITION + 7 * COL_DISTANCE_BETWEEN_STARS)
			{
				if (printedChar == "*")
				{
					printedChar = " ";
				}
				else
				{
					printedChar = "*";
				}
				col = COL_FIRST_STAR_POSITION;
			}
			else
			{
				col += COL_DISTANCE_BETWEEN_STARS;
			}
		}		
	}
}

bool fileExists(string filename)
{
	filename += ".txt";
	ifstream file(filename);
	return file.good();
}

void getDataFromFile(string name)
{
	string filename = name + ".txt";
	Player& player = Player::getInstance();
	string nume, password, level, score;
	ifstream file(filename);
	getline(file, nume);
	getline(file, password);
	getline(file, level);
	getline(file, score);
	player.setPlayer(name, stoi(level), stoi(score));
	file.close();
}

void startAgain(string name, string password)
{
	Player& player = Player::getInstance();
	string filename = name + ".txt";
	ofstream file(filename);
	file << name << endl << password << endl << "1" << endl << "0" << endl;
	player.setPlayer(name, 1, 0, 0);
	file.close();
}
bool verifyPassword(string password, string filename)
{
	string name, password1;
	filename += ".txt";
	ifstream file(filename);
	if (file.good())
	{
		getline(file, name);
		getline(file, password1);
		if (password1 == password)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "POO vs ZOMBIES is loading...";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 2) << "Double click to start!";
	bool stop = false;
	string name;
	string password;
	string yn;
	while (!stop)
	{
		doLoadingBar();
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			if (action.find("mouse double clicked at") != std::string::npos)
			{
				system("cls");
				conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 2) << "Game is starting in 3";
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 2) << "Game is starting in 2";
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 2) << "Game is starting in 1";
				std::this_thread::sleep_for(std::chrono::milliseconds(800));
				system("cls");
				conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 5) << "Choose your name -> ";
				cin >> name;
				if (fileExists(name))
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(550));
					system("cls");
					conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 2) << "You have played before. Would you like to resume?";
					conOut(ROW_TITLE + 2, COL_FIRST_STAR_POSITION + 13) << "Tap yes or no -> ";
					cin >> yn;
					std::this_thread::sleep_for(std::chrono::milliseconds(550));
					system("cls");
					conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 2) << "Please enter your password ->           ";
					cin >> password;
					if (verifyPassword(password, name))
					{
						if (yn == "yes")
						{
							getDataFromFile(name);
						}
						else
						{
							startAgain(name, password);
						}
					}
					else
					{
						std::this_thread::sleep_for(std::chrono::milliseconds(550));
						system("cls");
						conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 2) << "You entered a different password. Now you are a new player!";
						std::this_thread::sleep_for(std::chrono::milliseconds(650));
						startAgain(name, password);
					}
				}
				else
				{
					conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 2) << "Set your password ->                ";
					cin >> password;
					startAgain(name, password);
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(550));
				system("cls");
				conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 5) << "Good luck!";				
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				stop = true;
				system("cls");

			}
			else
			{
				conOut(46, 1) << action;
			}
		}
	}

	conOut.destroyInstance();
	conIn.destroyInstance();
	GAME& game = GAME::getInstance();
	game.startGame();
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	system("cls");
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 5) << "You Lost!";
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	return 0;
}