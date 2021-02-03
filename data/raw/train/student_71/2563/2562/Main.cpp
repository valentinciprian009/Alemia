#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "GameSession.h"
#include "Player.h"
#include "Logger.h"
#include <time.h>
#include <chrono>
#include <fcntl.h>
#include <io.h>
#include <fstream>
#include <string>
#pragma comment(lib, "winmm.lib")

// 41 x 154 pixels

#define ROW_TITLE					30			
#define COL_FIRST_STAR_POSITION		67
#define COL_DISTANCE_BETWEEN_STARS	5
#define ROW_USERNAME				31
#define COL_USERNAME				78
#define ROW_CHECKBOX				31
#define COL_CHECKBOX				118

using namespace std::chrono;

// Used for doIntro()
void doLoadingBar()
{
	static UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
				printedChar = " ";
			else
				printedChar = "*";
			col = COL_FIRST_STAR_POSITION;
		}
		else
			col += COL_DISTANCE_BETWEEN_STARS;
	}
}

void doIntro()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput& conIn = UserInterface::ConsoleInput::getInstance();
	mciSendString("play intro.wav", NULL, 0, NULL);
	

	std::wcout << L"\n";
	conOut(17, 35, 242) << L"██▓███   ▒█████   ▒█████  "; 	conOut(17, 67, 240) << L" ██▒   █▓  ██████ ";		conOut(17, 90, 244) << L"   ▒███████▒ ▒█████   ███▄ ▄███▓ ▄▄▄▄    ██▓▓█████   ██████ ";
	conOut(18, 35, 242) << L"▓██░  ██▒▒██▒  ██▒▒██▒  ██▒";	conOut(18, 67, 240) << L"▓██░   █▒▒██    ▒ ";	conOut(18, 90, 244) << L"   ▒ ▒ ▒ ▄▀░▒██▒  ██▒▓██▒▀█▀ ██▒▓█████▄ ▓██▒▓█   ▀ ▒██    ▒ ";
	conOut(19, 35, 242) << L"▓██░ ██▓▒▒██░  ██▒▒██░  ██▒";	conOut(19, 67, 240) << L" ▓██  █▒░░ ▓██▄   ";	conOut(19, 90, 244) << L"   ░ ▒ ▄▀▒░ ▒██░  ██▒▓██    ▓██░▒██▒ ▄██▒██▒▒███   ░ ▓██▄   ";
	conOut(20, 35, 242) << L"▒██▄█▓▒ ▒▒██   ██░▒██   ██░";	conOut(20, 67, 240) << L"  ▒██ █░░  ▒   ██▒";	conOut(20, 90, 244) << L"     ▄▀▒   ░▒██   ██░▒██    ▒██ ▒██░█▀  ░██░▒▓█  ▄   ▒   ██▒";
	conOut(21, 35, 242) << L"▒██▒ ░  ░░ ████▓▒░░ ████▓▒░";	conOut(21, 67, 240) << L"   ▒▀█░  ▒██████▒▒";	conOut(21, 90, 244) << L"   ▒███████▒░ ████▓▒░▒██▒   ░██▒░▓█  ▀█▓░██░░▒████▒▒██████▒▒";
	conOut(22, 35, 242) << L"▒▓▒░ ░  ░░ ▒░▒░▒░ ░ ▒░▒░▒░ ";	conOut(22, 67, 240) << L"   ░ ▐░  ▒ ▒▓▒ ▒ ░";	conOut(22, 90, 244) << L"   ░▒▒ ▓░▒░▒░ ▒░▒░▒░ ░ ▒░   ░  ░░▒▓███▀▒░▓  ░░ ▒░ ░▒ ▒▓▒ ▒ ░";
	conOut(23, 35, 242) << L"░▒ ░       ░ ▒ ▒░   ░ ▒ ▒░ ";	conOut(23, 67, 240) << L"   ░ ▐░  ▒ ▒▓▒ ▒ ░";	conOut(23, 90, 244) << L"   ░░▒ ▒ ░ ▒  ░ ▒ ▒░ ░  ░      ░▒░▒   ░  ▒ ░ ░ ░  ░░ ░▒  ░ ░";
	conOut(24, 35, 242) << L"░░       ░ ░ ░ ▒  ░ ░ ░ ▒  ";	conOut(24, 67, 240) << L"   ░ ░░  ░ ░▒  ░ ░";	conOut(24, 90, 244) << L"   ░ ░ ░ ░ ░░ ░ ░ ▒  ░      ░    ░    ░  ▒ ░   ░   ░  ░  ░  ";
	conOut(25, 35, 242) << L"		         ░ ░      ░ ░ ";	conOut(25, 67, 240) << L"     ░░  ░  ░  ░  ";	conOut(25, 90, 244) << L"     ░ ░        ░ ░         ░    ░       ░     ░  ░      ░  ";
	conOut(26, 67, 240) << L"      ░        ░  ";		conOut(26, 90, 244) << L"		       ░                                  ░  ";
	conOut(27, 67, 240) << L"     ░            ";


	// Loading screen
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	while (duration_cast<seconds>(end - begin).count() < 1)
	{
		end = steady_clock::now();
		doLoadingBar();
	}

	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << " The game has loaded!     ";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 40) << "New user? ";
	conOut(ROW_CHECKBOX, COL_CHECKBOX, 64) << "  ";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 5) << "                       ";
	conOut(ROW_TITLE + 2, COL_FIRST_STAR_POSITION + 2) << "Password: ";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 2) << "Username: ";

	mciSendString("stop intro.wav", NULL, 0, NULL);
}

// Used for choose_level()
void getInput(std::string& input, bool& create_new)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput& conIn = UserInterface::ConsoleInput::getInstance();

	static int flag = 0;
	std::string hidden;

	while (true)
	{
		std::string action = conIn.getUserActions();
		
		if ((action == "Mouse event: mouse clicked at (118, 31)              ")||((action == "Mouse event: mouse clicked at (119, 31)              ")))
		{
			create_new = !create_new;
			create_new? conOut(ROW_CHECKBOX, COL_CHECKBOX, 160) << "  ": conOut(ROW_CHECKBOX, COL_CHECKBOX, 64) << "  ";
			continue;
		}
		if (action == "\r")
			break;
		if (action != "")
		{
			if ((action == "\b") && (input.size() > 0))
			{
				input = input.substr(0, input.size() - 1);
				hidden = hidden.substr(0, hidden.size() - 1);
				conOut(flag ? ROW_USERNAME + 1 : ROW_USERNAME, COL_USERNAME) << "                             ";
				if (flag)
					conOut(ROW_USERNAME + 1, COL_USERNAME + 1) << hidden;
				else
					conOut(ROW_USERNAME, COL_USERNAME + 1) << input;
				continue;
			}
			if ((action.size() == 1) && (input.size() < 12))
			{
				if(flag)
					conOut(ROW_USERNAME + 1 , COL_USERNAME + (int)input.size() + 1) << "*";
				else
					conOut(ROW_USERNAME, COL_USERNAME + (int)input.size() + 1) << action;
			}
		}
		if ((action.size() == 1) && (input.size() < 12) && (isprint(*action.c_str())))
		{
			input.append(action);
			hidden.append("*");
		}
	}
	flag = !flag;
}

void choose_level()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput& conIn = UserInterface::ConsoleInput::getInstance();
	Player& player = Player::getInstance();
	
	//mciSendString("play crazydaveextralong2.wav", NULL, 0, NULL);

	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	conOut(18, 71, 15) << "Welcome, " << player.getName();
	conOut(20, 70) << "Choose a level:";
	conOut(22, 60, 250) << L" ██╗";		conOut(22, 75, 246) << L"██████╗ ";		conOut(22, 92, 244) << L"██████╗ ";
	conOut(23, 60, 250) << L"███║";		conOut(23, 75, 246) << L"╚════██╗";		conOut(23, 92, 244) << L"╚════██╗";
	conOut(24, 60, 250) << L"╚██║";		conOut(24, 75, 246) << L" █████╔╝";		conOut(24, 92, 244) << L" █████╔╝";
	conOut(25, 60, 250) << L" ██║";		conOut(25, 75, 246) << L"██╔═══╝ ";		conOut(25, 92, 244) << L" ╚═══██╗";
	conOut(26, 60, 250) << L" ██║";		conOut(26, 75, 246) << L"███████╗";		conOut(26, 92, 244) << L"██████╔╝";
	conOut(27, 60, 250) << L" ╚═╝";		conOut(27, 75, 246) << L"╚══════╝";		conOut(27, 92, 244) << L"╚═════╝ ";

	std::string action;
	int x;
	int y;
	while (true)
	{
		action = conIn.getUserActions();
		if (char* p = (char*)strstr(action.c_str(), "mouse clicked at ("))
		{
			// Retrieve the coordinates
			p = strtok(p + 18, "(,)");
			x = atoi(p);
			p = strtok(NULL, "(,)");
			y = atoi(p);
			if ((y >= 22) && (y <= 27))
			{
				if ((x >= 60) && (x <= 64))
				{
					player.setCurrentLevel(1);
					break;
				}
				if ((x >= 75) && (x <= 82))
				{
					player.setCurrentLevel(2);
					break;
				}
				if ((x >= 92) && (x <= 99))
				{
					player.setCurrentLevel(3);
					break;
				}
			}
		}
	}
	mciSendString("stop crazydaveextralong2.wav", NULL, 0, NULL);
	mciSendString("play crazydavescream.wav", NULL, 0, NULL);
	system("cls");
}

void begin_level()
{
	GameSession& session = GameSession::getInstance();
	Sleep(1500);
	mciSendString("play readysetplant.wav", NULL, 0, NULL);
	session.execute();
}

void createPlayer(std::string& username, std::string& password)
{
	system("mkdir Users");
	std::ofstream out( "Users/" + username + ".sav", std::ios::out);
	out << username << std::endl;
	out << password << std::endl;
	out.close();
}

bool verifyPlayer(std::string& username, std::string& password)
{
	std::ifstream in("Users/" + username + ".sav", std::ios::in);
	std::string buffer;
	std::getline(in, buffer);
	if (buffer != username)
		return false;
	std::getline(in, buffer);
	if (buffer != password)
		return false;
	return true;
}

void login()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	Logger& log = Logger::getInstance();
	Player& player = Player::getInstance();

	mciSendString("play intro.wav", NULL, 0, NULL);

	bool create_new = false;

	do
	{
		getInput(player.getName(), create_new);
		getInput(player.getPassword(), create_new);
		if (create_new)
		{
			createPlayer(player.getName(), player.getPassword());
			log.add("New user created: " + player.getName() + ".");
			break;
		}
		else
			if (verifyPlayer(player.getName(), player.getPassword()))    // (deschide fisierul corespunzator si verifica)
			{
				log.add("User " + player.getName() + " logged in.");
				break;
			}
			else
			{
				conOut(ROW_USERNAME + 2, COL_USERNAME - 15, 192) << "Incorrect username or password";
				log.add("Incorrect username or password.");
				player.setName("");
				player.setPassword("");
				conOut(ROW_USERNAME, COL_USERNAME) << "                             ";
				conOut(ROW_USERNAME + 1, COL_USERNAME) << "                             ";
			}
	}
		while (true);
	system("cls");
}


int main(void)
{
	Logger& log = Logger::getInstance();
	log.add("Game started.");
	
	doIntro();
	login();
	choose_level();
	begin_level();



	log.add("Program terminated");
	return 0;
}