#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Table.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "Main.h"
#include <fstream>
#include "Logger.h"

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define MAXCOOLDOWN 500

using namespace std::chrono;

void placeSun(int x, int y) {
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x * 5 + 1, y * 18 + 1) << "Sun";
}

void placePlant2(int x, int y) {
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x * 5 + 1, y * 18 + 1) << "Plant";
}

void generateSun(Table &table) {
	Logger &logger = Logger::getInstance();
	int sun;
	sun = rand() % 8;
	while (table.hasSun(sun)) {
		sun = rand() % 8;
	}

	logger << "Generating sun on column " + std::to_string(sun) + "\n";
	table.setSun(sun, 1);
	placeSun(0, sun + 1);
}

void eatSun(Table &table, int row, int column) {
	Logger &logger = Logger::getInstance();

	logger << "Consuming sun on column " + std::to_string(column - 1) + "\n";
	table.incrementResources();
	table.setSun(column - 1, 0);
	clearCell1(row, column);
}

int checkZombies(Table table, int row) {
	int s = 0;
	for (int i = 0; i < 9; i++) {
		s += (int)table.getCell(row, i)->noZombies();
	}

	return s;
}

int main(void)
{
	Logger &logger = Logger::getInstance();

	logger << "Start game\n";

	std::string name;
	std::cout << "Input name: ";
	std::cin >> name;

	logger << "Username: " + name + "\n";

	int level = 1, score = 0;
	std::ifstream save;
	save.open(name);
	if (save.good()) {
		logger << "Found save file, loading progress\n";
		save >> score;
		save >> level;
	}
	else {
		logger << "No save file found, starting new game\n";
	}
	save.close();

	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();

	int toPlant;

	std::vector<TableEntities::Zombie*> zombies;

	int rows_start = level * 2 - 1;
	for (int rows = rows_start; rows <= 5; rows += 2) {
		Table table;
		table.setScore(score);
		table.setLevel((rows + 1) / 2);

		logger << "Starting level " + std::to_string(table.getLevel()) + "\n";

		for (int i = 0; i < 8; i++) {
			table.setSun(i, 0);
		}

		int sun_counter = 0;

		bool plantingMode = false;

		int cooldown1 = 0;
		int cooldown2 = 0;
		int cooldown3 = 0;
		int cooldown4 = 0;
		int cooldown5 = 0;

		int zombieMoveCounter = 1500;
		int zombieGeneratorCounter = 0;
		int projectileMoveCounter = 200;

		logger << "Drawing table\n";
		for (int i = 0; i < 36; i++) {
			for (int j = 0; j < 163; j++) {
				if (i % 5 == 0) {
					conOut(i, j) << "_";
				}
				if (j % 18 == 0 && i != 0) {
					conOut(i, j) << "|";
				}
				if (!((i % 5 == 0) || (j % 18 == 0 && i != 0)) && i / 5 > rows && j / 18 > 0) {
					conOut(i, j) << "/";
				}
			}
		}

		TableEntities::Plant *p;

		conOut(1, 1) << "Score: ";
		conOut(2, 1) << "Resources: ";

		conOut(6, 1) << "Peashooter";
		conOut(7, 1) << "Cooldown: ";
		p = new TableEntities::Peashooter();
		conOut(9, 1) << "Cost " + std::to_string(p->getPrice());
		delete p;
		conOut(11, 1) << "Sunflower";
		conOut(12, 1) << "Cooldown: ";
		p = new TableEntities::Sunflower();
		conOut(14, 1) << "Cost " + std::to_string(p->getPrice());
		delete p;
		conOut(16, 1) << "Cherry Bomb";
		conOut(17, 1) << "Cooldown: ";
		p = new TableEntities::CherryBomb();
		conOut(19, 1) << "Cost " + std::to_string(p->getPrice());
		delete p;
		conOut(21, 1) << "Wallnut";
		conOut(22, 1) << "Cooldown: ";
		p = new TableEntities::Wallnut();
		conOut(24, 1) << "Cost " + std::to_string(p->getPrice());
		delete p;
		conOut(26, 1) << "Snow Pea";
		conOut(27, 1) << "Cooldown: ";
		p = new TableEntities::SnowPea();
		conOut(29, 1) << "Cost " + std::to_string(p->getPrice());
		delete p;

		int no_zombies = 0;
		int zombiesAlive = 0;
		logger << "Starting level loop\n";
		while (no_zombies < 10 * rows || zombiesAlive)
		{
			logger.incrementStamp();
			zombiesAlive = 0;
			table.processCollisions();

			zombieGeneratorCounter++;
			table.updateProjectiles();

			table.placeProjectiles();
			table.moveProjectiles(projectileMoveCounter);

			int end = table.moveZombies(zombieMoveCounter, name);

			if (end == -1) {
				return 0;
			}

			TableEntities::Zombie *z = nullptr;

			if (no_zombies == 5 * rows) {
				// spawn super
				int superRow = rand() % rows;
				logger << "Generating super zombie on row " + std::to_string(superRow) + "\n";
				z = new TableEntities::SuperZombie(superRow, 7);
				table.getCell(superRow, 7)->addZombie(z);
				zombies.push_back(z);
				no_zombies++;
				table.addLivingZombie();
			} else if (zombieGeneratorCounter % 2200 == 0) {
				int zRow = rand() % rows;
				if (checkZombies(table, zRow) < 3) {
					int type = rand() % 3;
					switch (type)
					{
					case 0:
						logger << "Generating simple zombie on row " + std::to_string(zRow) + "\n";
						z = new TableEntities::Simple(zRow, 7);
						break;
					case 1:
						logger << "Generating BucketHead zombie on row " + std::to_string(zRow) + "\n";
						z = new TableEntities::BucketHead(zRow, 7);
						break;
					case 2:
						logger << "Generating PoleVaulting zombie on row " + std::to_string(zRow) + "\n";
						z = new TableEntities::PoleVaulting(zRow, 7);
						break;
					default:
						break;
					}
					table.getCell(zRow, 7)->addZombie(z);
					zombies.push_back(z);
					no_zombies++;
					table.addLivingZombie();
				}
			}

			table.updateGuns();
			table.updateZombies();

			if (cooldown1 > 0) {
				cooldown1--;
			}
			if (cooldown2 > 0) {
				cooldown2--;
			}
			if (cooldown3 > 0) {
				cooldown3--;
			}
			if (cooldown4 > 0) {
				cooldown4--;
			}
			if (cooldown5 > 0) {
				cooldown5--;
			}
			if (!table.hasFullSuns()) {
				sun_counter++;
				if (sun_counter > 400 / table.getSunRate()) {
					generateSun(table);
					sun_counter = 0;
				}
			}

			UserInterface::Action action = conIn.getUserActions();
			if (action.action == 27) {
				logger << "Escape key pressed, ending game\n\n\n";
				std::ofstream save;
				save.open(name);
				save << table.getScore() << std::endl;
				save << table.getLevel() << std::endl;
				save.close();
				delete &logger;
				return 0;
			}
			if (action.action == 1) {
				int row = (action.row - 1) / 5;
				int column = (action.column) / 18;

				logger << "Click at (" + std::to_string(row) + ", " + std::to_string(column) + ")\n";
				
				if (row == 0 && column > 0 && table.hasSun(column - 1)) {
					eatSun(table, row, column);
				}
				else if (column == 0 && row > 0) {
					logger << "Plant selected\n";
					plantingMode = true;
					toPlant = row;
				}
				else if (column > 0 && row > 0 && row <= rows) {
					if (plantingMode) {
						switch (toPlant) {
						case 1:
							// peashooter
							p = new TableEntities::Peashooter(row - 1, column - 1);
							if (table.getResources() >= p->getPrice() && cooldown1 / 100 == 0) {
								logger << "Peashooter planted\n";
								table.setCell(row - 1, column - 1, p);
								table.pay(p->getPrice());
								cooldown1 = MAXCOOLDOWN;
							}
							break;
						case 2:
							// sunflower
							p = new TableEntities::Sunflower(row - 1, column - 1);
							if (table.getResources() >= p->getPrice() && cooldown2 / 100 == 0) {
								logger << "Sunflower planted\n";
								table.setCell(row - 1, column - 1, p);
								table.pay(p->getPrice());
								cooldown2 = MAXCOOLDOWN;
								table.incrementSunRate();
							}
							break;
						case 3:
							// cherry bomb
							p = new TableEntities::CherryBomb(row - 1, column - 1);
							if (table.getResources() >= p->getPrice() && cooldown3 / 100 == 0) {
								logger << "CherryBomb planted\n";
								table.setCell(row - 1, column - 1, p);
								table.pay(p->getPrice());
								cooldown3 = MAXCOOLDOWN;
							}
							break;
						case 4:
							// wallnut
							p = new TableEntities::Wallnut(row - 1, column - 1);
							if (table.getResources() >= p->getPrice() && cooldown4 / 100 == 0) {
								logger << "Wallnut planted\n";
								table.setCell(row - 1, column - 1, p);
								table.pay(p->getPrice());
								cooldown4 = MAXCOOLDOWN;
							}
							break;
						case 5:
							// snow pea
							p = new TableEntities::SnowPea(row - 1, column - 1);
							if (table.getResources() >= p->getPrice() && cooldown5 / 100 == 0) {
								logger << "SnowPea planted\n";
								table.setCell(row - 1, column - 1, p);
								table.pay(p->getPrice());
								cooldown5 = MAXCOOLDOWN;
							}
							break;
						default:
							break;
						}
						toPlant = 0;
						plantingMode = false;
					}
				}
			}

			conOut(1, 8) << std::to_string(table.getScore());
			std::string res;
			res += std::to_string(table.getResources());
			res += "   ";
			conOut(7, 11) << std::to_string(cooldown1 / 100);
			conOut(12, 11) << std::to_string(cooldown2 / 100);
			conOut(17, 11) << std::to_string(cooldown3 / 100);
			conOut(22, 11) << std::to_string(cooldown4 / 100);
			conOut(27, 11) << std::to_string(cooldown5 / 100);
			conOut(2, 12) << res;

			table.renderTable();

			for (int i = 0; i < rows; i++) {
				zombiesAlive += checkZombies(table, i);

				if (table.getCell(i, 0)->noZombies()) {
					logger << "Zombie got in the base, game over\n\n\n";
					std::ofstream save;
					save.open(name);
					save << table.getScore() << std::endl;
					save << table.getLevel() << std::endl;
					delete &logger;
					return 0;
				}
			}
		}

		for (int i = 0; i < 36; i++) {
			for (int j = 0; j < 163; j++) {
				conOut(i, j) << " ";
			}
		}
	}

	return 0;
}
