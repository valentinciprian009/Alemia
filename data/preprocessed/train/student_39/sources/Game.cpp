//
// Created by null on 1/9/2020.
//

#include "Game.h"
#include "../plant/Plant.h"
#include "../zombie/Zombie.h"
#include "../projectile/Projectile.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include "GameConfig.h"


Game::Game(UserInterface::ConsoleInput* input, UserInterface::ConsoleOutput* output, int level, std::string username)
	: input(input),
	output(output),
	userName(username) {
	(*output)(1, 1) << "Resources:";

	terrain = new Terrain(output, 5, 14, 5, 9, CELL_ROWS, CELL_COLS);
	drawObjects.push_back(terrain);

	sunRes = new SunRes(output, 2, 14, 9, CELL_COLS);
	sunRes->draw();
	drawObjects.push_back(sunRes);
	plantResSelector = new PlantResSelector(output, 8, 1, CELL_ROWS + 1);
	plantResSelector->draw();
	int score = loadScore(username);
	(*output)(0, 0) << "username: " << username << " score: " << score;
}

Game::~Game() {
	for (auto d : drawObjects) {
		delete d;
	}
	delete terrain;
}

void Game::draw() {
	update();
	(*output)(0, 30) << plantResSelector->getSelectedPlantString();
	for (int i = 0; i < drawObjects.size(); i++) {
		auto d = drawObjects[i];
		d->draw();
	}

	(*output)(2, 5) << "    ";
	(*output)(2, 5) << money;

	for (int i = 0; i < 5; i++) {
		(*output)(8 + i * 7, 152) << "   ";
	}
}

Plant* Game::getPlantOnPosition(int row, int column) {
	for (int i = 0; i < plants.size(); i++) {
		auto p = plants[i];
		int col_diff = column - p->column_offset;
		if (row == p->row_offset && col_diff > 0 && col_diff < p->getWidth() + 2)
			return p;
	}
	return nullptr;
}

void Game::onEvent(Event event, int row, int col, void* data) {
	switch (event) {
	case SPAWN_NEW_PROJECTILE: {
		auto* p = (Projectile*)data;
		projectiles.push_back(p);
		drawObjects.push_back(p);
		break;
	}
	case Event::MOUSE_CLICK: {
		// sori
		money += sunRes->getMoneyFromResource(row, col);
		// select plant
		plantResSelector->selectPlantAt(row, col);

		// plant the plant
		int row_offset = terrain->getClickedCellRowOffset(row);
		int col_offset = terrain->getClickedCellColumnOffset(col);
		if (row_offset != -1 && col_offset != -1) {
			if (!isPlantInCell(row_offset, col_offset)) {
				Plant* p = plantResSelector->getSelectedPlant(this, row_offset + 3, col_offset + 1, &money);
				if (p != nullptr) {
					plants.push_back(p);
					drawObjects.push_back(p);
				}
			}
		}
		break;
	}
	}
}

Zombie* Game::getZombieOnPosition(int row, int column) {
	for (auto z : zombies) {
		int col_diff = column - z->column_offset;
		if (row == z->row_offset && col_diff >= 0)
			return z;
	}
	return nullptr;
}

void Game::update() {
	time++;
	spawnZombies();
	for (auto i = zombies.begin(); i != zombies.end();) {
		auto z = (*i);
		Plant* p = getPlantOnPosition(z->row_offset, z->column_offset);
		if (p != nullptr) {
			p->getBitten(z->bitePlant(5));
		}
		else {
			z->advance();
		}
		if (z->getHealth() <= 0 || z->column_offset < terrain->column_offset + 4) {
			z->clean();
			i = zombies.erase(i);
			drawObjects.erase(std::remove(drawObjects.begin(), drawObjects.end(), z), drawObjects.end());
		}
		else {
			i++;
		}
	}

	for (auto i = plants.begin(); i != plants.end();) {
		auto p = (*i);
		if (p->getHealth() <= 0) {
			p->clean();
			i = plants.erase(i);
			drawObjects.erase(std::remove(drawObjects.begin(), drawObjects.end(), p), drawObjects.end());
		}
		else {
			i++;
		}
	}

	for (auto i = projectiles.begin(); i != projectiles.end();) {
		if ((*i)->column_offset > 150) {
			(*i)->clean();
			i = projectiles.erase(i);
		}
		auto p = (*i);
		auto z = getZombieOnPosition(p->row_offset, p->column_offset);
		if (z != nullptr) {
			z->damage(p->getHealthDamage(), p->getSpeedDamage());
			i = projectiles.erase(i);
			drawObjects.erase(std::remove(drawObjects.begin(), drawObjects.end(), p), drawObjects.end());
		}
		else {
			p->advance();
			i++;
		}
	}
}

void Game::spawnZombies() {
	if ((firstZombie && time % 100 == 0) || (!firstZombie && time % 300 == 0)) {
		// time to spwan a zombie
		int type = (int)(2 * (float)rand() / RAND_MAX);
		int r = (int)(4 * (float)rand() / RAND_MAX);
		int col = terrain->column_offset + terrain->getWidth() - 6;
		int row = terrain->row_offset + (CELL_ROWS + 1) * r + 1;
		ZombieType tt[] = {
				ZOMBIE,
				BUCKET_HEAD,
				POLE_VAULTING,
		};
		int row_offset = terrain->getClickedCellRowOffset(row);
		int col_offset = terrain->getClickedCellColumnOffset(col);
		auto zombie = Zombie::create(output, row_offset + 3, col_offset + 6, tt[type]);
		zombies.push_back(zombie);
		drawObjects.push_back(zombie);
		firstZombie = true;
	}
}

bool Game::isPlantInCell(int rowOffset, int collOffset) {
	for (Plant* p : plants) {
		int rowDiff = p->row_offset - rowOffset;
		int colDiff = p->column_offset - collOffset;
		if (rowDiff >= 0 && rowDiff < CELL_ROWS && colDiff >= 0 && colDiff < CELL_COLS)
			return true;
	}
	return false;
}


int Game::loadScore(std::string& username) {
	std::string SCORE_FILE = "scores.txt";
	std::ifstream file(SCORE_FILE);
	std::string readUserName;
	int score = 0;
	if (!file.is_open()) {
		std::ofstream out(SCORE_FILE);
		out << "toto 250\nbla 670\nteo 476\nprof 567\n";
		out.close();
		file = std::ifstream(SCORE_FILE);
	}
	if (file.is_open()) {
		std::string line;
		while (getline(file, line)) {
			// using printf() in all tests for consistency
			std::istringstream s(line);
			s >> readUserName >> score;
			if (readUserName == username) {
				break;
			}

		}
		file.close();
	}
	else {
		(*output)(0, 30) << "Couldn't open file";
	}
	return score;
}