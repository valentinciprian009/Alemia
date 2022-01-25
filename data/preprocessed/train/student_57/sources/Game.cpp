#include "Game.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "PlayersList.h"
#include <sstream>
#include <chrono>

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define LOGO_TITLE	4
#define COL_LOGO	57
using namespace std::chrono;
using namespace std;

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
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

void clear() {
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\x1B[2J";
}

void Game::getUsername()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION - 20) << "Introduceti username:";

	string juc;
	string action;
	do {
		action = conIn.getUserActions();
		if (action.length() == 1) {
			juc += action;
		}

		conOut(ROW_TITLE, COL_FIRST_STAR_POSITION + 2) << juc;
	} while (action != "\r");
	this->jucator.setNume(juc);
}

void Game::initial_loading()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	conOut(LOGO_TITLE, COL_LOGO) << " _____   ____   ____                __________  __  __ ____ _____ ______ ";//logo
	conOut(LOGO_TITLE + 1, COL_LOGO) << "|  __ \\ / __ \\ / __ \\              |___  / __ \\|  \\/  |  _ \\_   _|  ____|";
	conOut(LOGO_TITLE + 2, COL_LOGO) << "| |__) | |  | | |  | | __   _____     / / |  | | \\  / | |_) || | | |__   ";
	conOut(LOGO_TITLE + 3, COL_LOGO) << "|  ___/| |  | | |  | | \\ \\ / / __|   / /| |  | | |\\/| |  _ < | | |  __|  ";
	conOut(LOGO_TITLE + 4, COL_LOGO) << "| |    | |__| | |__| |  \\ V /\\__ \\  / /_| |__| | |  | | |_) || |_| |____ ";
	conOut(LOGO_TITLE + 5, COL_LOGO) << "|_|     \\____/ \\____/    \\\_/ |___/ /_____\\____/|_|  |_|____/_____|______|";
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	auto start = steady_clock::now();
	auto sfarsit = steady_clock::now();
	while (duration_cast<seconds>(sfarsit - start).count() < 5)
	{
		
		sfarsit = steady_clock::now();
		doLoadingBar();
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 2) << action;
		}
	}

}

void Game::print_first_menu()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_BLUE);
	conOut(15, 75) << "-------------";
	conOut(16, 75) << "-------------";
	conOut(17, 75) << "-------------";
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_GREEN);
	conOut(16, 80) << "PLAY";

	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_BLUE);
	conOut(23, 75) << "-------------";
	conOut(24, 75) << "-------------";
	conOut(25, 75) << "-------------";
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_GREEN);
	conOut(24, 80) << "BEST";

	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_BLUE);
	conOut(31, 75) << "-------------";
	conOut(32, 75) << "-------------";
	conOut(33, 75) << "-------------";
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_GREEN);
	conOut(32, 80) << "EXIT";

}

int Game::select_option()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 7);
	conOut(1, 1) << "Username:" << this->jucator.getNume();

	string action;
	string aux2;
	stringstream aux;
	int x=0, y=0,i=1;
	do {
		action = conIn.getUserActions();
		char s[] = "Mouse event: mouse clicked";
		char* p;
		p =(char*) strstr(action.c_str(), s);
		if (p) {
			aux << action;
			while (!aux.eof()) {
				aux >> aux2;
				if ((i == 2) && (stringstream(aux2) >> y)) {
					
					i++;
				}

				if ((i == 1) && (stringstream(aux2) >> x)) {
					
					i++;
				}

			}
			
			if ((y >= 15 && y <= 17) && (x >= 75 && x <= 89))
				return 1; //1 pentru start
			else if ((y >= 23 && y <= 25) && (x >= 75 && x <= 89))
				return 2;//2 pentru best
			else if ((y >= 31 && y <= 33) && (x >= 75 && x <= 89)) {
				clear();
				exit(1);
			}
			
				
		}
	} while (true);

}

void Game::showSuns()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	
	srand(time(NULL));
	int i;
	
	end_sun =std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::seconds>(end_sun-begin_sun).count() > 3)
	{

		begin_sun = std::chrono::steady_clock::now();

		i = rand() % 8;
		if (i == 0) {
			while (sori[i] == TRUE) break;
			sori[i] = TRUE;
			sun.showRes(2, 52);
		}
		if (i == 1) {
			while (sori[i] == TRUE) break;
			sori[i] = TRUE;
			sun.showRes(2, 60);
		}
		if (i == 2) {
			while (sori[i] == TRUE) break;
			sori[i] = TRUE;
			sun.showRes(2, 68);
		}
		if (i == 3) {
			while (sori[i] == TRUE) break;
			sori[i] = TRUE;
			sun.showRes(2, 76);
		}
		if (i == 4) {
			while (sori[i] == TRUE) break;
			sori[i] = TRUE;
			sun.showRes(2, 84);
		}
		if (i == 5) {
			while (sori[i] == TRUE) break;
			sori[i] = TRUE;
			sun.showRes(2, 92);
		}
		if (i == 6) {
			while (sori[i] == TRUE) break;
			sori[i] = TRUE;
			sun.showRes(2, 100);
		}
		if (i == 7) {
			while (sori[i] == TRUE) break;
			sori[i] = TRUE;
			sun.showRes(2, 108);
		}

	}
}

void Game::showZombie(int level)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	srand(time(NULL));
	int line;
	end_zombie = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::seconds>(end_zombie - begin_zombie).count() > 20)
	{

		begin_zombie = std::chrono::steady_clock::now();
		if (level == 1) {
			zs.push_back(ZombieSimple(21, 115));
			zs[zs.size() - 1].drawZombie(21, 115);
		}
		if (level == 2) {
			line = rand() % 3;
			if (line == 0) {
				zs.push_back(ZombieSimple(16, 115));
				zs[zs.size() - 1].drawZombie(16, 115);
			}
			if (line == 1) {
				zs.push_back(ZombieSimple(21, 115));
				zs[zs.size() - 1].drawZombie(21, 115);
			}
			if (line == 2) {
				zs.push_back(ZombieSimple(26, 115));
				zs[zs.size() - 1].drawZombie(26, 115);
			}
		}
	}
}

void Game::catchSun(int x, int y)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	if ((y >= 2 && y <= 4) && (x >= 52 && x <= 56) && (sori[0] == TRUE)) {
		this->jucator.modifyRes(sun.getNrOfRes());
		conOut(4, 41) << "R: " << this->jucator.getResurse();
		this->sori[0] = FALSE;
		ground.DrawCasset(1, 50);
		return;
	}
	if ((y >= 2 && y <= 4) && (x >= 60 && x <= 64) && (sori[1] == TRUE)) {
		this->jucator.modifyRes(sun.getNrOfRes());
		conOut(4, 41) << "R: " << this->jucator.getResurse();
		this->sori[1] = FALSE;
		ground.DrawCasset(1, 58);
		return;
	}
	if ((y >= 2 && y <= 4) && (x >= 68 && x <= 72) && (sori[2] == TRUE)) {
		this->jucator.modifyRes(sun.getNrOfRes());
		conOut(4, 41) << "R: " << this->jucator.getResurse();
		this->sori[2] = FALSE;
		ground.DrawCasset(1, 66);
		return;
	}
	if ((y >= 2 && y <= 4) && (x >= 74 && x <= 78) && (sori[3] == TRUE)) {
		this->jucator.modifyRes(sun.getNrOfRes());
		conOut(4, 41) << "R: " << this->jucator.getResurse();
		this->sori[3] = FALSE;
		ground.DrawCasset(1, 74);
		return;
	}
	if ((y >= 2 && y <= 4) && (x >= 82 && x <= 86) && (sori[4] == TRUE)) {
		this->jucator.modifyRes(sun.getNrOfRes());
		conOut(4, 41) << "R: " << this->jucator.getResurse();
		this->sori[4] = FALSE;
		ground.DrawCasset(1, 82);
		return;
	}
	if ((y >= 2 && y <= 4) && (x >= 90 && x <= 94) && (sori[5] == TRUE)) {
		this->jucator.modifyRes(sun.getNrOfRes());
		conOut(4, 41) << "R: " << this->jucator.getResurse();
		this->sori[5] = FALSE;
		ground.DrawCasset(1, 90);
		return;
	}
	if ((y >= 2 && y <= 4) && (x >= 98 && x <= 102) && (sori[6] == TRUE)) {
		this->jucator.modifyRes(sun.getNrOfRes());
		conOut(4, 41) << "R: " << this->jucator.getResurse();
		this->sori[6] = false;
		ground.DrawCasset(1, 98);
		return;
	}
	if ((y >= 2 && y <= 4) && (x >= 106 && x <= 110) && (sori[7] == TRUE)) {
		this->jucator.modifyRes(sun.getNrOfRes());
		conOut(4, 41) << "R: " << this->jucator.getResurse();
		this->sori[7] = false;
		ground.DrawCasset(1, 106);
		return;
	}
	
}

void Game::showWeapons()
{
	pea.showPlat(11, 42);
	snow.showPlat(16, 42);
	cherry.showPlat(21, 42);
	flower.showPlat(26, 42);
	wall.showPlat(31, 42);
}

int Game::checkIfaPlantWasSelected(int x, int y)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();


	if ((y >= 11 && y <= 12) && (x >= 42 && x <= 45)) {
		if (pea.getCost() <= this->jucator.getResurse()) {
			conOut(37, 42) << "PeaShooter was selected!";
			this->jucator.modifyRes(-pea.getCost());
			conOut(4, 41) << "R: " << this->jucator.getResurse();
			if (this->jucator.getResurse() < 100) {
				conOut(4, 46) << " ";
			}
			if (this->jucator.getResurse() < 10) {
				conOut(4, 45) << " ";
			}
			return 1;
		}
		else {
			conOut(37, 42) << "Resurse insuficiente!!**";
			return 0;
		}
	}
	else if ((y >= 16 && y <= 17) && (x >= 42 && x <= 45)) {
		if (snow.getCost() <= this->jucator.getResurse()) {
			conOut(37, 42) << "SnowPea was selected!***";
			this->jucator.modifyRes(-snow.getCost());
			conOut(4, 41) << "R: " << this->jucator.getResurse();
			if (this->jucator.getResurse() < 100) {
				conOut(4, 46) << " ";
			}
			if (this->jucator.getResurse() < 10) {
				conOut(4, 45) << " ";
			}
			return 2;
		}
		else {
			conOut(37, 42) << "Resurse insuficiente!!**";
			return 0;
		}
	}
	else if ((y >= 21 && y <= 22) && (x >= 42 && x <= 45)) {
		if (cherry.getCost() <= this->jucator.getResurse())
		{
			conOut(37, 42) << "CherryBomb was selected!";
			this->jucator.modifyRes(-cherry.getCost());
			conOut(4, 41) << "R: " << this->jucator.getResurse();
			if (this->jucator.getResurse() < 100) {
				conOut(4, 46) << " ";
			}
			if (this->jucator.getResurse() < 10) {
				conOut(4, 45) << " ";
			}
			return 3;
		}
		else {
			conOut(37, 42) << "Resurse insuficiente!!**";
			return 0;
		}
	}
	else if ((y >= 26 && y <= 27) && (x >= 42 && x <= 45)) {
		if (flower.getCost() <= this->jucator.getResurse()) {
			conOut(37, 42) << "SunFlower was selected!*";
			this->jucator.modifyRes(-flower.getCost());
			conOut(4, 41) << "R: " << this->jucator.getResurse();
			if (this->jucator.getResurse() < 100) {
				conOut(4, 46) << " ";
			}
			if (this->jucator.getResurse() < 10) {
				conOut(4, 45) << " ";
			}
			return 4;
		}
		else {
			conOut(37, 42) << "Resurse insuficiente!!**";
			return 0;
		}
	}
	else if ((y >= 31 && y <= 32) && (x >= 42 && x <= 45)) {
		if (wall.getCost() <= this->jucator.getResurse()) {
			conOut(37, 42) << "WallNut was selected!***";
			this->jucator.modifyRes(-wall.getCost());
			conOut(4, 41) << "R: " << this->jucator.getResurse();
			if (this->jucator.getResurse() < 100) {
				conOut(4, 46) << " ";
			}
			if (this->jucator.getResurse() < 10) {
				conOut(4, 45) << " ";
			}
			return 5;
		}
		else {
			conOut(37, 42) << "Resurse insuficiente!!**";
			return 0;
		}
	}
	else return 0;

}

void Game::putPlantOnMap(int k,int level)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();


	string action;
	string aux2;
	stringstream aux;
	int x = 0, y = 0, i = 1;
	do {
		action = conIn.getUserActions();
		char s[] = "Mouse event: mouse clicked";
		char* p;
		p = (char*)strstr(action.c_str(), s);
		if (p) {
			aux << action;
			while (!aux.eof()) {
				aux >> aux2;
				if ((i == 2) && (stringstream(aux2) >> y)) {

					i++;
				}

				if ((i == 1) && (stringstream(aux2) >> x)) {

					i++;
				}

			}
			if (level == 1) {
				if ((y >= 20 && y <= 24) && (x >= 50 && x <= 56))
				{
					if (k == 1) {
						pea.showPlatB(22, 52);
						shooterPEA.push_back(PlantsPeaShooter(22, 52));
						conOut(24, 52) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 52);
					if (k == 3) cherry.showPlatB(22, 52);
					if (k == 4) flower.showPlatB(22, 52);
					if (k == 5) wall.showPlatB(22, 52);
					this->plant[16] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 58 && x <= 64))
				{
					if (k == 1) {
						pea.showPlatB(22, 60);
						shooterPEA.push_back(PlantsPeaShooter(22, 60));
						conOut(24, 60) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 60);
					if (k == 3) cherry.showPlatB(22, 60);
					if (k == 4) flower.showPlatB(22, 60);
					if (k == 5) wall.showPlatB(22, 60);
					this->plant[17] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 66 && x <= 72))
				{
					if (k == 1) {
						pea.showPlatB(22, 68);
						shooterPEA.push_back(PlantsPeaShooter(22, 68));
						conOut(24, 68) << pea.getNrMuscaturi();
					};
					if (k == 2) snow.showPlatB(22, 68);
					if (k == 3) cherry.showPlatB(22, 68);
					if (k == 4) flower.showPlatB(22, 68);
					if (k == 5) wall.showPlatB(22, 68);
					this->plant[18] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 74 && x <= 80))
				{
					if (k == 1) {
						pea.showPlatB(22, 76);
						shooterPEA.push_back(PlantsPeaShooter(22, 76));
						conOut(24, 76) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 76);
					if (k == 3) cherry.showPlatB(22, 76);
					if (k == 4) flower.showPlatB(22, 76);
					if (k == 5) wall.showPlatB(22, 76);
					this->plant[19] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 82 && x <= 88))
				{
					if (k == 1) {
						pea.showPlatB(22, 84);
						shooterPEA.push_back(PlantsPeaShooter(22, 84));
						conOut(24, 84) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 84);
					if (k == 3) cherry.showPlatB(22, 84);
					if (k == 4) flower.showPlatB(22, 84);
					if (k == 5) wall.showPlatB(22, 84);
					this->plant[20] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 90 && x <= 96))
				{
					if (k == 1) {
						pea.showPlatB(22, 92);
						shooterPEA.push_back(PlantsPeaShooter(22, 92));
						conOut(24, 92) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 92);
					if (k == 3) cherry.showPlatB(22, 92);
					if (k == 4) flower.showPlatB(22, 92);
					if (k == 5) wall.showPlatB(22, 92);
					this->plant[21] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 98 && x <= 104))
				{
					if (k == 1) {
						pea.showPlatB(22, 100);
						shooterPEA.push_back(PlantsPeaShooter(22, 100));
						conOut(24, 100) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 100);
					if (k == 3) cherry.showPlatB(22, 100);
					if (k == 4) flower.showPlatB(22, 100);
					if (k == 5) wall.showPlatB(22, 100);
					this->plant[22] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 106 && x <= 112))
				{
					if (k == 1) {
						pea.showPlatB(22, 108);
						shooterPEA.push_back(PlantsPeaShooter(22, 108));
						conOut(24, 108) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 108);
					if (k == 3) cherry.showPlatB(22, 108);
					if (k == 4) flower.showPlatB(22, 108);
					if (k == 5) wall.showPlatB(22, 108);
					this->plant[23] = true;
					return;
				}
			}
			if (level == 2) {
				if ((y >= 15 && y <= 19) && (x >= 50 && x <= 56))
				{
					if (k == 1) {
						pea.showPlatB(17, 52);
						shooterPEA.push_back(PlantsPeaShooter(17, 52));
						conOut(19, 52) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 52);
					if (k == 3) cherry.showPlatB(17, 52);
					if (k == 4) flower.showPlatB(17, 52);
					if (k == 5) wall.showPlatB(17, 52);
					this->plant[8] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 58 && x <= 64))
				{
					if (k == 1) {
						pea.showPlatB(17, 60);
						shooterPEA.push_back(PlantsPeaShooter(17, 60));
						conOut(19, 60) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 60);
					if (k == 3) cherry.showPlatB(17, 60);
					if (k == 4) flower.showPlatB(17, 60);
					if (k == 5) wall.showPlatB(17, 60);
					this->plant[9] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 66 && x <= 72))
				{
					if (k == 1) {
						pea.showPlatB(17, 68);
						shooterPEA.push_back(PlantsPeaShooter(17, 68));
						conOut(19, 68) << pea.getNrMuscaturi();
					};
					if (k == 2) snow.showPlatB(17, 68);
					if (k == 3) cherry.showPlatB(17, 68);
					if (k == 4) flower.showPlatB(17, 68);
					if (k == 5) wall.showPlatB(17, 68);
					this->plant[10] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 74 && x <= 80))
				{
					if (k == 1) {
						pea.showPlatB(17, 76);
						shooterPEA.push_back(PlantsPeaShooter(17, 76));
						conOut(19, 76) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 76);
					if (k == 3) cherry.showPlatB(17, 76);
					if (k == 4) flower.showPlatB(17, 76);
					if (k == 5) wall.showPlatB(17, 76);
					this->plant[11] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 82 && x <= 88))
				{
					if (k == 1) {
						pea.showPlatB(17, 84);
						shooterPEA.push_back(PlantsPeaShooter(17, 84));
						conOut(19, 84) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 84);
					if (k == 3) cherry.showPlatB(17, 84);
					if (k == 4) flower.showPlatB(17, 84);
					if (k == 5) wall.showPlatB(17, 84);
					this->plant[12] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 90 && x <= 96))
				{
					if (k == 1) {
						pea.showPlatB(17, 92);
						shooterPEA.push_back(PlantsPeaShooter(17, 92));
						conOut(19, 92) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 92);
					if (k == 3) cherry.showPlatB(17, 92);
					if (k == 4) flower.showPlatB(17, 92);
					if (k == 5) wall.showPlatB(17, 92);
					this->plant[13] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 98 && x <= 104))
				{
					if (k == 1) {
						pea.showPlatB(17, 100);
						shooterPEA.push_back(PlantsPeaShooter(17, 100));
						conOut(19, 100) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 100);
					if (k == 3) cherry.showPlatB(17, 100);
					if (k == 4) flower.showPlatB(17, 100);
					if (k == 5) wall.showPlatB(17, 100);
					this->plant[14] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 106 && x <= 112))
				{
					if (k == 1) {
						pea.showPlatB(17, 108);
						shooterPEA.push_back(PlantsPeaShooter(17, 108));
						conOut(19, 108) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 108);
					if (k == 3) cherry.showPlatB(17, 108);
					if (k == 4) flower.showPlatB(17, 108);
					if (k == 5) wall.showPlatB(17, 108);
					this->plant[15] = true;
					return;
				}

				if ((y >= 20 && y <= 24) && (x >= 50 && x <= 56))
				{
					if (k == 1) {
						pea.showPlatB(22, 52);
						shooterPEA.push_back(PlantsPeaShooter(22, 52));
						conOut(24, 52) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 52);
					if (k == 3) cherry.showPlatB(22, 52);
					if (k == 4) flower.showPlatB(22, 52);
					if (k == 5) wall.showPlatB(22, 52);
					this->plant[16] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 58 && x <= 64))
				{
					if (k == 1) {
						pea.showPlatB(22, 60);
						shooterPEA.push_back(PlantsPeaShooter(22, 60));
						conOut(24, 60) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 60);
					if (k == 3) cherry.showPlatB(22, 60);
					if (k == 4) flower.showPlatB(22, 60);
					if (k == 5) wall.showPlatB(22, 60);
					this->plant[17] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 66 && x <= 72))
				{
					if (k == 1) {
						pea.showPlatB(22, 68);
						shooterPEA.push_back(PlantsPeaShooter(22, 68));
						conOut(24, 68) << pea.getNrMuscaturi();
					};
					if (k == 2) snow.showPlatB(22, 68);
					if (k == 3) cherry.showPlatB(22, 68);
					if (k == 4) flower.showPlatB(22, 68);
					if (k == 5) wall.showPlatB(22, 68);
					this->plant[18] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 74 && x <= 80))
				{
					if (k == 1) {
						pea.showPlatB(22, 76);
						shooterPEA.push_back(PlantsPeaShooter(22, 76));
						conOut(24, 76) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 76);
					if (k == 3) cherry.showPlatB(22, 76);
					if (k == 4) flower.showPlatB(22, 76);
					if (k == 5) wall.showPlatB(22, 76);
					this->plant[19] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 82 && x <= 88))
				{
					if (k == 1) {
						pea.showPlatB(22, 84);
						shooterPEA.push_back(PlantsPeaShooter(22, 84));
						conOut(24, 84) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 84);
					if (k == 3) cherry.showPlatB(22, 84);
					if (k == 4) flower.showPlatB(22, 84);
					if (k == 5) wall.showPlatB(22, 84);
					this->plant[20] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 90 && x <= 96))
				{
					if (k == 1) {
						pea.showPlatB(22, 92);
						shooterPEA.push_back(PlantsPeaShooter(22, 92));
						conOut(24, 92) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 92);
					if (k == 3) cherry.showPlatB(22, 92);
					if (k == 4) flower.showPlatB(22, 92);
					if (k == 5) wall.showPlatB(22, 92);
					this->plant[21] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 98 && x <= 104))
				{
					if (k == 1) {
						pea.showPlatB(22, 100);
						shooterPEA.push_back(PlantsPeaShooter(22, 100));
						conOut(24, 100) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 100);
					if (k == 3) cherry.showPlatB(22, 100);
					if (k == 4) flower.showPlatB(22, 100);
					if (k == 5) wall.showPlatB(22, 100);
					this->plant[22] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 106 && x <= 112))
				{
					if (k == 1) {
						pea.showPlatB(22, 108);
						shooterPEA.push_back(PlantsPeaShooter(22, 108));
						conOut(24, 108) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 108);
					if (k == 3) cherry.showPlatB(22, 108);
					if (k == 4) flower.showPlatB(22, 108);
					if (k == 5) wall.showPlatB(22, 108);
					this->plant[23] = true;
					return;
				}
				
				if ((y >= 25 && y <= 2) && (x >= 50 && x <= 56))
				{
					if (k == 1) {
						pea.showPlatB(27, 52);
						shooterPEA.push_back(PlantsPeaShooter(27, 52));
						conOut(29, 52) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 52);
					if (k == 3) cherry.showPlatB(27, 52);
					if (k == 4) flower.showPlatB(27, 52);
					if (k == 5) wall.showPlatB(27, 52);
					this->plant[24] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 58 && x <= 64))
				{
					if (k == 1) {
						pea.showPlatB(27, 60);
						shooterPEA.push_back(PlantsPeaShooter(27, 60));
						conOut(29, 60) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 60);
					if (k == 3) cherry.showPlatB(27, 60);
					if (k == 4) flower.showPlatB(27, 60);
					if (k == 5) wall.showPlatB(27, 60);
					this->plant[25] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 66 && x <= 72))
				{
					if (k == 1) {
						pea.showPlatB(27, 68);
						shooterPEA.push_back(PlantsPeaShooter(27, 68));
						conOut(29, 68) << pea.getNrMuscaturi();
					};
					if (k == 2) snow.showPlatB(27, 68);
					if (k == 3) cherry.showPlatB(27, 68);
					if (k == 4) flower.showPlatB(27, 68);
					if (k == 5) wall.showPlatB(27, 68);
					this->plant[26] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 74 && x <= 80))
				{
					if (k == 1) {
						pea.showPlatB(27, 76);
						shooterPEA.push_back(PlantsPeaShooter(27, 76));
						conOut(29, 76) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 76);
					if (k == 3) cherry.showPlatB(27, 76);
					if (k == 4) flower.showPlatB(27, 76);
					if (k == 5) wall.showPlatB(27, 76);
					this->plant[27] = true;
					return;
				}
				if ((y >= 25 && y <= 25) && (x >= 82 && x <= 88))
				{
					if (k == 1) {
						pea.showPlatB(27, 84);
						shooterPEA.push_back(PlantsPeaShooter(27, 84));
						conOut(29, 84) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 84);
					if (k == 3) cherry.showPlatB(27, 84);
					if (k == 4) flower.showPlatB(27, 84);
					if (k == 5) wall.showPlatB(27, 84);
					this->plant[28] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 90 && x <= 96))
				{
					if (k == 1) {
						pea.showPlatB(27, 92);
						shooterPEA.push_back(PlantsPeaShooter(27, 92));
						conOut(29, 92) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 92);
					if (k == 3) cherry.showPlatB(27, 92);
					if (k == 4) flower.showPlatB(27, 92);
					if (k == 5) wall.showPlatB(27, 92);
					this->plant[29] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 98 && x <= 104))
				{
					if (k == 1) {
						pea.showPlatB(27, 100);
						shooterPEA.push_back(PlantsPeaShooter(27, 100));
						conOut(29, 100) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 100);
					if (k == 3) cherry.showPlatB(27, 100);
					if (k == 4) flower.showPlatB(27, 100);
					if (k == 5) wall.showPlatB(27, 100);
					this->plant[30] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 106 && x <= 112))
				{
					if (k == 1) {
						pea.showPlatB(27, 108);
						shooterPEA.push_back(PlantsPeaShooter(27, 108));
						conOut(29, 108) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 108);
					if (k == 3) cherry.showPlatB(27, 108);
					if (k == 4) flower.showPlatB(27, 108);
					if (k == 5) wall.showPlatB(27, 108);
					this->plant[31] = true;
					return;
				}
			}
			if (level == 3) {
				if ((y >= 10 && y <= 14) && (x >= 50 && x <= 56))
				{
					if (k == 1) {
						pea.showPlatB(12, 52);
						shooterPEA.push_back(PlantsPeaShooter(12, 52));
						conOut(14, 52) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(12, 52);
					if (k == 3) cherry.showPlatB(12, 52);
					if (k == 4) flower.showPlatB(12, 52);
					if (k == 5) wall.showPlatB(12, 52);
					this->plant[0] = true;
					return;
				}
				if ((y >= 10 && y <= 14) && (x >= 58 && x <= 64))
				{
					if (k == 1) {
						pea.showPlatB(12, 60);
						shooterPEA.push_back(PlantsPeaShooter(12, 60));
						conOut(14, 60) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(12, 60);
					if (k == 3) cherry.showPlatB(12, 60);
					if (k == 4) flower.showPlatB(12, 60);
					if (k == 5) wall.showPlatB(12, 60);
					this->plant[1] = true;
					return;
				}
				if ((y >= 10 && y <= 14) && (x >= 66 && x <= 72))
				{
					if (k == 1) {
						pea.showPlatB(12, 68);
						shooterPEA.push_back(PlantsPeaShooter(12, 68));
						conOut(14, 68) << pea.getNrMuscaturi();
					};
					if (k == 2) snow.showPlatB(12, 68);
					if (k == 3) cherry.showPlatB(12, 68);
					if (k == 4) flower.showPlatB(12, 68);
					if (k == 5) wall.showPlatB(12, 68);
					this->plant[2] = true;
					return;
				}
				if ((y >= 10 && y <= 14) && (x >= 74 && x <= 80))
				{
					if (k == 1) {
						pea.showPlatB(12, 76);
						shooterPEA.push_back(PlantsPeaShooter(12, 76));
						conOut(14, 76) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(12, 76);
					if (k == 3) cherry.showPlatB(12, 76);
					if (k == 4) flower.showPlatB(12, 76);
					if (k == 5) wall.showPlatB(12, 76);
					this->plant[3] = true;
					return;
				}
				if ((y >= 10 && y <= 14) && (x >= 82 && x <= 88))
				{
					if (k == 1) {
						pea.showPlatB(12, 84);
						shooterPEA.push_back(PlantsPeaShooter(12, 84));
						conOut(14, 84) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(12, 84);
					if (k == 3) cherry.showPlatB(12, 84);
					if (k == 4) flower.showPlatB(12, 84);
					if (k == 5) wall.showPlatB(12, 84);
					this->plant[4] = true;
					return;
				}
				if ((y >= 10 && y <= 14) && (x >= 90 && x <= 96))
				{
					if (k == 1) {
						pea.showPlatB(12, 92);
						shooterPEA.push_back(PlantsPeaShooter(12, 92));
						conOut(14, 92) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(12, 92);
					if (k == 3) cherry.showPlatB(12, 92);
					if (k == 4) flower.showPlatB(12, 92);
					if (k == 5) wall.showPlatB(12, 92);
					this->plant[5] = true;
					return;
				}
				if ((y >= 10 && y <= 14) && (x >= 98 && x <= 104))
				{
					if (k == 1) {
						pea.showPlatB(12, 100);
						shooterPEA.push_back(PlantsPeaShooter(12, 100));
						conOut(14, 100) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(12, 100);
					if (k == 3) cherry.showPlatB(12, 100);
					if (k == 4) flower.showPlatB(12, 100);
					if (k == 5) wall.showPlatB(12, 100);
					this->plant[6] = true;
					return;
				}
				if ((y >= 10 && y <= 14) && (x >= 106 && x <= 112))
				{
					if (k == 1) {
						pea.showPlatB(12, 108);
						shooterPEA.push_back(PlantsPeaShooter(12, 108));
						conOut(14, 108) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(12, 108);
					if (k == 3) cherry.showPlatB(12, 108);
					if (k == 4) flower.showPlatB(12, 108);
					if (k == 5) wall.showPlatB(12, 108);
					this->plant[7] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 50 && x <= 56))
				{
					if (k == 1) {
						pea.showPlatB(17, 52);
						shooterPEA.push_back(PlantsPeaShooter(17, 52));
						conOut(19, 52) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 52);
					if (k == 3) cherry.showPlatB(17, 52);
					if (k == 4) flower.showPlatB(17, 52);
					if (k == 5) wall.showPlatB(17, 52);
					this->plant[8] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 58 && x <= 64))
				{
					if (k == 1) {
						pea.showPlatB(17, 60);
						shooterPEA.push_back(PlantsPeaShooter(17, 60));
						conOut(19, 60) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 60);
					if (k == 3) cherry.showPlatB(17, 60);
					if (k == 4) flower.showPlatB(17, 60);
					if (k == 5) wall.showPlatB(17, 60);
					this->plant[9] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 66 && x <= 72))
				{
					if (k == 1) {
						pea.showPlatB(17, 68);
						shooterPEA.push_back(PlantsPeaShooter(17, 68));
						conOut(19, 68) << pea.getNrMuscaturi();
					};
					if (k == 2) snow.showPlatB(17, 68);
					if (k == 3) cherry.showPlatB(17, 68);
					if (k == 4) flower.showPlatB(17, 68);
					if (k == 5) wall.showPlatB(17, 68);
					this->plant[10] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 74 && x <= 80))
				{
					if (k == 1) {
						pea.showPlatB(17, 76);
						shooterPEA.push_back(PlantsPeaShooter(17, 76));
						conOut(19, 76) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 76);
					if (k == 3) cherry.showPlatB(17, 76);
					if (k == 4) flower.showPlatB(17, 76);
					if (k == 5) wall.showPlatB(17, 76);
					this->plant[11] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 82 && x <= 88))
				{
					if (k == 1) {
						pea.showPlatB(17, 84);
						shooterPEA.push_back(PlantsPeaShooter(17, 84));
						conOut(19, 84) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 84);
					if (k == 3) cherry.showPlatB(17, 84);
					if (k == 4) flower.showPlatB(17, 84);
					if (k == 5) wall.showPlatB(17, 84);
					this->plant[12] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 90 && x <= 96))
				{
					if (k == 1) {
						pea.showPlatB(17, 92);
						shooterPEA.push_back(PlantsPeaShooter(17, 92));
						conOut(19, 92) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 92);
					if (k == 3) cherry.showPlatB(17, 92);
					if (k == 4) flower.showPlatB(17, 92);
					if (k == 5) wall.showPlatB(17, 92);
					this->plant[13] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 98 && x <= 104))
				{
					if (k == 1) {
						pea.showPlatB(17, 100);
						shooterPEA.push_back(PlantsPeaShooter(17, 100));
						conOut(19, 100) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 100);
					if (k == 3) cherry.showPlatB(17, 100);
					if (k == 4) flower.showPlatB(17, 100);
					if (k == 5) wall.showPlatB(17, 100);
					this->plant[14] = true;
					return;
				}
				if ((y >= 15 && y <= 19) && (x >= 106 && x <= 112))
				{
					if (k == 1) {
						pea.showPlatB(17, 108);
						shooterPEA.push_back(PlantsPeaShooter(17, 108));
						conOut(19, 108) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(17, 108);
					if (k == 3) cherry.showPlatB(17, 108);
					if (k == 4) flower.showPlatB(17, 108);
					if (k == 5) wall.showPlatB(17, 108);
					this->plant[15] = true;
					return;
				}

				if ((y >= 20 && y <= 24) && (x >= 50 && x <= 56))
				{
					if (k == 1) {
						pea.showPlatB(22, 52);
						shooterPEA.push_back(PlantsPeaShooter(22, 52));
						conOut(24, 52) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 52);
					if (k == 3) cherry.showPlatB(22, 52);
					if (k == 4) flower.showPlatB(22, 52);
					if (k == 5) wall.showPlatB(22, 52);
					this->plant[16] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 58 && x <= 64))
				{
					if (k == 1) {
						pea.showPlatB(22, 60);
						shooterPEA.push_back(PlantsPeaShooter(22, 60));
						conOut(24, 60) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 60);
					if (k == 3) cherry.showPlatB(22, 60);
					if (k == 4) flower.showPlatB(22, 60);
					if (k == 5) wall.showPlatB(22, 60);
					this->plant[17] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 66 && x <= 72))
				{
					if (k == 1) {
						pea.showPlatB(22, 68);
						shooterPEA.push_back(PlantsPeaShooter(22, 68));
						conOut(24, 68) << pea.getNrMuscaturi();
					};
					if (k == 2) snow.showPlatB(22, 68);
					if (k == 3) cherry.showPlatB(22, 68);
					if (k == 4) flower.showPlatB(22, 68);
					if (k == 5) wall.showPlatB(22, 68);
					this->plant[18] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 74 && x <= 80))
				{
					if (k == 1) {
						pea.showPlatB(22, 76);
						shooterPEA.push_back(PlantsPeaShooter(22, 76));
						conOut(24, 76) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 76);
					if (k == 3) cherry.showPlatB(22, 76);
					if (k == 4) flower.showPlatB(22, 76);
					if (k == 5) wall.showPlatB(22, 76);
					this->plant[19] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 82 && x <= 88))
				{
					if (k == 1) {
						pea.showPlatB(22, 84);
						shooterPEA.push_back(PlantsPeaShooter(22, 84));
						conOut(24, 84) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 84);
					if (k == 3) cherry.showPlatB(22, 84);
					if (k == 4) flower.showPlatB(22, 84);
					if (k == 5) wall.showPlatB(22, 84);
					this->plant[20] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 90 && x <= 96))
				{
					if (k == 1) {
						pea.showPlatB(22, 92);
						shooterPEA.push_back(PlantsPeaShooter(22, 92));
						conOut(24, 92) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 92);
					if (k == 3) cherry.showPlatB(22, 92);
					if (k == 4) flower.showPlatB(22, 92);
					if (k == 5) wall.showPlatB(22, 92);
					this->plant[21] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 98 && x <= 104))
				{
					if (k == 1) {
						pea.showPlatB(22, 100);
						shooterPEA.push_back(PlantsPeaShooter(22, 100));
						conOut(24, 100) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 100);
					if (k == 3) cherry.showPlatB(22, 100);
					if (k == 4) flower.showPlatB(22, 100);
					if (k == 5) wall.showPlatB(22, 100);
					this->plant[22] = true;
					return;
				}
				if ((y >= 20 && y <= 24) && (x >= 106 && x <= 112))
				{
					if (k == 1) {
						pea.showPlatB(22, 108);
						shooterPEA.push_back(PlantsPeaShooter(22, 108));
						conOut(24, 108) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(22, 108);
					if (k == 3) cherry.showPlatB(22, 108);
					if (k == 4) flower.showPlatB(22, 108);
					if (k == 5) wall.showPlatB(22, 108);
					this->plant[23] = true;
					return;
				}

				if ((y >= 25 && y <= 2) && (x >= 50 && x <= 56))
				{
					if (k == 1) {
						pea.showPlatB(27, 52);
						shooterPEA.push_back(PlantsPeaShooter(27, 52));
						conOut(29, 52) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 52);
					if (k == 3) cherry.showPlatB(27, 52);
					if (k == 4) flower.showPlatB(27, 52);
					if (k == 5) wall.showPlatB(27, 52);
					this->plant[24] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 58 && x <= 64))
				{
					if (k == 1) {
						pea.showPlatB(27, 60);
						shooterPEA.push_back(PlantsPeaShooter(27, 60));
						conOut(29, 60) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 60);
					if (k == 3) cherry.showPlatB(27, 60);
					if (k == 4) flower.showPlatB(27, 60);
					if (k == 5) wall.showPlatB(27, 60);
					this->plant[25] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 66 && x <= 72))
				{
					if (k == 1) {
						pea.showPlatB(27, 68);
						shooterPEA.push_back(PlantsPeaShooter(27, 68));
						conOut(29, 68) << pea.getNrMuscaturi();
					};
					if (k == 2) snow.showPlatB(27, 68);
					if (k == 3) cherry.showPlatB(27, 68);
					if (k == 4) flower.showPlatB(27, 68);
					if (k == 5) wall.showPlatB(27, 68);
					this->plant[26] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 74 && x <= 80))
				{
					if (k == 1) {
						pea.showPlatB(27, 76);
						shooterPEA.push_back(PlantsPeaShooter(27, 76));
						conOut(29, 76) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 76);
					if (k == 3) cherry.showPlatB(27, 76);
					if (k == 4) flower.showPlatB(27, 76);
					if (k == 5) wall.showPlatB(27, 76);
					this->plant[27] = true;
					return;
				}
				if ((y >= 25 && y <= 25) && (x >= 82 && x <= 88))
				{
					if (k == 1) {
						pea.showPlatB(27, 84);
						shooterPEA.push_back(PlantsPeaShooter(27, 84));
						conOut(29, 84) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 84);
					if (k == 3) cherry.showPlatB(27, 84);
					if (k == 4) flower.showPlatB(27, 84);
					if (k == 5) wall.showPlatB(27, 84);
					this->plant[28] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 90 && x <= 96))
				{
					if (k == 1) {
						pea.showPlatB(27, 92);
						shooterPEA.push_back(PlantsPeaShooter(27, 92));
						conOut(29, 92) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 92);
					if (k == 3) cherry.showPlatB(27, 92);
					if (k == 4) flower.showPlatB(27, 92);
					if (k == 5) wall.showPlatB(27, 92);
					this->plant[29] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 98 && x <= 104))
				{
					if (k == 1) {
						pea.showPlatB(27, 100);
						shooterPEA.push_back(PlantsPeaShooter(27, 100));
						conOut(29, 100) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 100);
					if (k == 3) cherry.showPlatB(27, 100);
					if (k == 4) flower.showPlatB(27, 100);
					if (k == 5) wall.showPlatB(27, 100);
					this->plant[30] = true;
					return;
				}
				if ((y >= 25 && y <= 29) && (x >= 106 && x <= 112))
				{
					if (k == 1) {
						pea.showPlatB(27, 108);
						shooterPEA.push_back(PlantsPeaShooter(27, 108));
						conOut(29, 108) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(27, 108);
					if (k == 3) cherry.showPlatB(27, 108);
					if (k == 4) flower.showPlatB(27, 108);
					if (k == 5) wall.showPlatB(27, 108);
					this->plant[31] = true;
					return;
				}

				if ((y >= 30 && y <= 34) && (x >= 50 && x <= 56))
				{
					if (k == 1) {
						pea.showPlatB(32, 52);
						shooterPEA.push_back(PlantsPeaShooter(32, 52));
						conOut(34, 52) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(32, 52);
					if (k == 3) cherry.showPlatB(32, 52);
					if (k == 4) flower.showPlatB(32, 52);
					if (k == 5) wall.showPlatB(32, 52);
					this->plant[32] = true;
					return;
				}
				if ((y >= 30 && y <= 34) && (x >= 58 && x <= 64))
				{
					if (k == 1) {
						pea.showPlatB(32, 60);
						shooterPEA.push_back(PlantsPeaShooter(32, 60));
						conOut(34, 60) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(32, 60);
					if (k == 3) cherry.showPlatB(32, 60);
					if (k == 4) flower.showPlatB(32, 60);
					if (k == 5) wall.showPlatB(32, 60);
					this->plant[33] = true;
					return;
				}
				if ((y >= 30 && y <= 34) && (x >= 66 && x <= 72))
				{
					if (k == 1) {
						pea.showPlatB(32, 68);
						shooterPEA.push_back(PlantsPeaShooter(32, 68));
						conOut(34, 68) << pea.getNrMuscaturi();
					};
					if (k == 2) snow.showPlatB(32, 68);
					if (k == 3) cherry.showPlatB(32, 68);
					if (k == 4) flower.showPlatB(32, 68);
					if (k == 5) wall.showPlatB(32, 68);
					this->plant[34] = true;
					return;
				}
				if ((y >= 30 && y <= 34) && (x >= 74 && x <= 80))
				{
					if (k == 1) {
						pea.showPlatB(32, 76);
						shooterPEA.push_back(PlantsPeaShooter(32, 76));
						conOut(34, 76) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(32, 76);
					if (k == 3) cherry.showPlatB(32, 76);
					if (k == 4) flower.showPlatB(32, 76);
					if (k == 5) wall.showPlatB(32, 76);
					this->plant[35] = true;
					return;
				}
				if ((y >= 30 && y <= 34) && (x >= 82 && x <= 88))
				{
					if (k == 1) {
						pea.showPlatB(32, 84);
						shooterPEA.push_back(PlantsPeaShooter(32, 84));
						conOut(34, 84) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(32, 84);
					if (k == 3) cherry.showPlatB(32, 84);
					if (k == 4) flower.showPlatB(32, 84);
					if (k == 5) wall.showPlatB(32, 84);
					this->plant[36] = true;
					return;
				}
				if ((y >= 30 && y <= 34) && (x >= 90 && x <= 96))
				{
					if (k == 1) {
						pea.showPlatB(32, 92);
						shooterPEA.push_back(PlantsPeaShooter(32, 92));
						conOut(34, 92) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(32, 92);
					if (k == 3) cherry.showPlatB(32, 92);
					if (k == 4) flower.showPlatB(32, 92);
					if (k == 5) wall.showPlatB(32, 92);
					this->plant[37] = true;
					return;
				}
				if ((y >= 30 && y <= 34) && (x >= 98 && x <= 104))
				{
					if (k == 1) {
						pea.showPlatB(32, 100);
						shooterPEA.push_back(PlantsPeaShooter(32, 100));
						conOut(34, 100) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(32, 100);
					if (k == 3) cherry.showPlatB(32, 100);
					if (k == 4) flower.showPlatB(32, 100);
					if (k == 5) wall.showPlatB(32, 100);
					this->plant[38] = true;
					return;
				}
				if ((y >= 30 && y <= 34) && (x >= 106 && x <= 112))
				{
					if (k == 1) {
						pea.showPlatB(32, 108);
						shooterPEA.push_back(PlantsPeaShooter(32, 108));
						conOut(34, 108) << pea.getNrMuscaturi();
					}
					if (k == 2) snow.showPlatB(32, 108);
					if (k == 3) cherry.showPlatB(32, 108);
					if (k == 4) flower.showPlatB(32, 108);
					if (k == 5) wall.showPlatB(32, 108);
					this->plant[39] = true;
					return;
				}
			}
		}
	}while (true);
}

void Game::checkIfZombieWasKicked()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	for (auto it1 = shooterPEA.begin(); it1 != shooterPEA.end(); it1++) {
		for (auto it2 = zs.begin(); it2 != zs.end(); it2++) {
			if (it1->returnNrOfProiectils()!=0) {
				ProiectilPEA a = it1->returnFirstProiectil();
				if (a.getRow() - 1 == it2->getRow()) {
					if ((it2->getCol() - a.getCol() < 3) && (it2->getCol() - a.getCol() > -7)) {
						it1->destroyFirstProiectil();
						int aux = a.getDamage();
						it2->modifyHealth(aux);
						int r = it2->getRow();
						int c = it2->getCol();
						conOut(r + 3, c + 1) << it2->getRezistence();

						if (it2->getRezistence() == 0) {
							zs.erase(it2);
							ground.DrawCasset(r-1,c-1);
							return;
						}
					}
				}
			}
		}
	}


}

void Game::level1()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	conOut(1, 1) << "Username:" << this->jucator.getNume();
	ground.DrawTable(1);
	conOut(2, 41) << "S: " << this->jucator.getScore();
	conOut(4, 41) << "R: " << this->jucator.getResurse();
	for (int j = 0; j < 8; j++) {
		sori[j] = FALSE;
	}

	this->numar_zombie = 5; //5 zombii pentru nivelul 1
	plant.assign(40, false); //fiecare casuta va fi false pana se pune o planta pe aceasta
	zombie.assign(40, false);//idem
	showWeapons(); //afiseaza plantele in stanga
	
	int option;
	string action;
	string aux2;
	stringstream aux(ios_base::in);
	char s[] = "Mouse event: mouse clicked";
	int x = 0, y = 0, i = 1;
	
	do {
			showSuns();
			

			action = conIn.getUserActions();
			char* p;
			p = (char*)strstr(action.c_str(), s);
			if (p) {
				
				aux.str(action);
				while (!aux.eof()) {
					
					aux >> aux2;
					if ((i == 2) && (stringstream(aux2) >> y)) {

						i++;
					}

					if ((i == 1) && (stringstream(aux2) >> x)) {

						i++;
					}

				}
				if (((y >= 2) && (y <= 4)) && ((x >= 52) && (x <= 111))) {
					catchSun(x, y);
				}
				if (((y >= 11) && (y <= 32)) && ((x >= 42) && (x <= 46))) {
					option=checkIfaPlantWasSelected(x, y);
					switch (option) {
					case 0:
						break;
					case 1:
						putPlantOnMap(1,1);
						break;
					case 2:
						putPlantOnMap(2,1);
						break;
					case 3:
						putPlantOnMap(3,1);
						break;
					case 4:
						putPlantOnMap(4,1);
						break;
					case 5:
						putPlantOnMap(5,1);
						break;
					}
				}
				
				i = 1;
				x = 0;
				y = 0;
				aux.str("");
				aux.clear();

			}
			for (auto index = shooterPEA.begin(); index != shooterPEA.end(); index++) {
				index->GenerateProiectil();
				index->Shoot();
			}
			for (auto it = zs.begin(); it != zs.end(); it++) {//muta zombie iar daca se afla langa o planta ii face sa se opreasca
				
				it->move();
				if (it->getCol() > 105 && it->getCol() <= 112) {
					zombie[23] = true;
					if (plant[22] == true) it->stopZombie();
				}
				if (it->getCol() > 97 && it->getCol() <= 104) {
					zombie[22] = true;
					if (plant[21] == true) it->stopZombie();
				}
				if (it->getCol() > 89 && it->getCol() <= 96) {
					zombie[21] = true;
					if (plant[20] == true) it->stopZombie();
				}
				if (it->getCol() > 81 && it->getCol() <= 88) {
					zombie[20] = true;
					if (plant[19] == true) it->stopZombie();
				}
				if (it->getCol() > 73 && it->getCol() <= 80) {
					zombie[19] = true;
					if (plant[18] == true) it->stopZombie();
				}
				if (it->getCol() > 65 && it->getCol() <= 72) {
					zombie[18] = true;
					if (plant[17] == true) it->stopZombie();
				}
				if (it->getCol() > 57 && it->getCol() <= 64) {
					zombie[17] = true;
					if (plant[16] == true) it->stopZombie();
				}
				if (it->getCol() > 49 && it->getCol() <= 56) {
					zombie[16] = true;
					if (plant[15] == true) it->stopZombie();
				}
			}
			showZombie(1);
			checkIfZombieWasKicked();
	} while (true);

}

void Game::level2()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	conOut(1, 1) << "Username:" << this->jucator.getNume();
	ground.DrawTable(2);
	conOut(2, 41) << "S: " << this->jucator.getScore();
	conOut(4, 41) << "R: " << this->jucator.getResurse();
	for (int j = 0; j < 8; j++) {
		sori[j] = FALSE;
	}

	this->numar_zombie = 10; 
	plant.assign(40, false); 
	zombie.assign(40, false);
	showWeapons(); 

	int option;
	string action;
	string aux2;
	stringstream aux(ios_base::in);
	char s[] = "Mouse event: mouse clicked";
	int x = 0, y = 0, i = 1;

	do {
		showSuns();


		action = conIn.getUserActions();
		char* p;
		p = (char*)strstr(action.c_str(), s);
		if (p) {

			aux.str(action);
			while (!aux.eof()) {

				aux >> aux2;
				if ((i == 2) && (stringstream(aux2) >> y)) {

					i++;
				}

				if ((i == 1) && (stringstream(aux2) >> x)) {

					i++;
				}

			}
			if (((y >= 2) && (y <= 4)) && ((x >= 52) && (x <= 111))) {
				catchSun(x, y);
			}
			if (((y >= 11) && (y <= 32)) && ((x >= 42) && (x <= 46))) {
				option = checkIfaPlantWasSelected(x, y);
				switch (option) {
				case 0:
					break;
				case 1:
					putPlantOnMap(1,2);
					break;
				case 2:
					putPlantOnMap(2,2);
					break;
				case 3:
					putPlantOnMap(3,2);
					break;
				case 4:
					putPlantOnMap(4,2);
					break;
				case 5:
					putPlantOnMap(5,2);
					break;
				}
			}

			i = 1;
			x = 0;
			y = 0;
			aux.str("");
			aux.clear();

		}
		for (auto index = shooterPEA.begin(); index != shooterPEA.end(); index++) {
			index->GenerateProiectil();
			index->Shoot();
		}
		for (auto it = zs.begin(); it != zs.end(); it++) {//muta zombie iar daca se afla langa o planta ii face sa se opreasca

			it->move();
			if (it->getCol() > 105 && it->getCol() <= 112) {
				zombie[23] = true;
				if (plant[22] == true) it->stopZombie();
			}
			if (it->getCol() > 97 && it->getCol() <= 104) {
				zombie[22] = true;
				if (plant[21] == true) it->stopZombie();
			}
			if (it->getCol() > 89 && it->getCol() <= 96) {
				zombie[21] = true;
				if (plant[20] == true) it->stopZombie();
			}
			if (it->getCol() > 81 && it->getCol() <= 88) {
				zombie[20] = true;
				if (plant[19] == true) it->stopZombie();
			}
			if (it->getCol() > 73 && it->getCol() <= 80) {
				zombie[19] = true;
				if (plant[18] == true) it->stopZombie();
			}
			if (it->getCol() > 65 && it->getCol() <= 72) {
				zombie[18] = true;
				if (plant[17] == true) it->stopZombie();
			}
			if (it->getCol() > 57 && it->getCol() <= 64) {
				zombie[17] = true;
				if (plant[16] == true) it->stopZombie();
			}
			if (it->getCol() > 49 && it->getCol() <= 56) {
				zombie[16] = true;
				if (plant[15] == true) it->stopZombie();
			}
		}
		showZombie(2);
		checkIfZombieWasKicked();
	} while (true);
}

void Game::level3()
{
	ground.DrawTable(3);
}

void Game::play()
{
	clear();
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	conOut(1, 1) << "Username:" << this->jucator.getNume();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_BLUE);
	conOut(5, 5) << "-------------";
	conOut(6, 5) << "-------------";
	conOut(7, 5) << "-------------";
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_GREEN);
	conOut(6,10) << "BACK";

	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_BLUE);
	conOut(15, 75) << "-------------";
	conOut(16, 75) << "-------------";
	conOut(17, 75) << "-------------";
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_GREEN);
	conOut(16, 77) << "LEVEL 1";

	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_BLUE);
	conOut(23, 75) << "-------------";
	conOut(24, 75) << "-------------";
	conOut(25, 75) << "-------------";
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_GREEN);
	conOut(24, 77) << "LEVEL 2";

	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_BLUE);
	conOut(31, 75) << "-------------";
	conOut(32, 75) << "-------------";
	conOut(33, 75) << "-------------";
	SetConsoleTextAttribute(h, BACKGROUND_BLUE | FOREGROUND_GREEN);
	conOut(32, 77) << "LEVEL 3";

	SetConsoleTextAttribute(h, 7);
	conOut(1, 1) << "Username:" << this->jucator.getNume();

	string action;
	string aux2;
	stringstream aux;
	int x = 0, y = 0, i = 1;
	do {
		action = conIn.getUserActions();
		char s[] = "Mouse event: mouse clicked";
		char* p;
		p = (char*)strstr(action.c_str(), s);
		if (p) {
			aux << action;
			while (!aux.eof()) {
				aux >> aux2;
				if ((i == 2) && (stringstream(aux2) >> y)) {

					i++;
				}

				if ((i == 1) && (stringstream(aux2) >> x)) {

					i++;
				}

			}

			if ((y >= 5 && y <= 7) && (x >= 5 && x <= 19))//apasare buton back
			{
				clear();
				print_first_menu();
				break;
			}
			if ((y >= 15 && y <= 17) && (x >= 75 && x <= 89)) {
				clear();
				level1();
			}
			if ((y >= 23 && y <= 25) && (x >= 75 && x <= 89)) {
				clear();
				level2();
			}
			if ((y >= 31 && y <= 33) && (x >= 75 && x <= 89)) {
				clear();
				level3();
			}
		}
	} while (true);

}


PlayersList *PlayersList::instance = nullptr;
void Game::execute()
{
	PlayersList& lista = PlayersList::getInstance();
	initial_loading();
	clear();
	getUsername();
	clear();
	print_first_menu();
	int option = 10;
	while (true) {
		option = select_option();
		switch (option) {
			
		case 1:
			play();
			break;
		case 2:
			//best();
			break;
		}
	}
}
