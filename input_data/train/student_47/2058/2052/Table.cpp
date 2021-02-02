#include "Table.h"
#include "ConsoleOutput.h"

void draw(int x, int y, std::string name) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x * 5 + 1, y * 18 + 1) << name.c_str();
}

void placePeashooter(int x, int y) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x * 5 + 1, y * 18 + 1) << "Peashooter";
}

void placeZombie(int x, int y) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x * 5 + 1, y * 18 + 1) << "Zombie";
}

void clearCell1(int x, int y) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x * 5 + 1, y * 18 + 1) << "                 ";
	conOut(x * 5 + 2, y * 18 + 1) << "                 ";
	conOut(x * 5 + 3, y * 18 + 1) << "                 ";
	conOut(x * 5 + 4, y * 18 + 1) << "                 ";
}

TableEntities::Cell::Cell() {}

TableEntities::Cell::Cell(int x, int y, bool hP) {
	row = x;
	column = y;
	hasPlant = hP;
}

TableEntities::Cell::~Cell()
{
	delete projectile;
	for (int i = 0; i < zombies.size(); i++) {
		delete zombies[i];
	}
}

int TableEntities::Cell::getRow()
{
	return row;
}

int TableEntities::Cell::getColumn()
{
	return column;
}

bool TableEntities::Cell::checkPlant()
{
	return hasPlant;
}

void TableEntities::Cell::plant()
{
	hasPlant = true;
}

void TableEntities::Cell::addProjectile(Projectile * p)
{
	projectile = p;
}

TableEntities::Projectile* TableEntities::Cell::getProjectile()
{
	return projectile;
}

void TableEntities::Cell::destroyProjectile()
{
	projectile = nullptr;
}

bool TableEntities::Cell::hasProjectile()
{
	return projectile != nullptr;
}

int TableEntities::Cell::noZombies()
{
	return zombies.size();
}

TableEntities::Zombie * TableEntities::Cell::getZombie(int index)
{
	return zombies[index];
}

void TableEntities::Cell::killZombie(int index)
{
	zombies.erase(zombies.begin() + index);
}

void TableEntities::Cell::addZombie(Zombie * z)
{
	zombies.push_back(z);
}

void TableEntities::Cell::represent() {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	for (int i = 0; i < zombies.size(); i++) {
		int y = zombies[i]->getColumn() + 1;
		int x = zombies[i]->getRow() + 1;
		conOut(x * 5 + 1 + i, y * 18 + 1) << zombies[i]->getName().c_str();
	}
	if (zombies.size()) {
		return;
	}
	if (projectile != nullptr) {
		int y = projectile->getColumn() + 1;
		int x = projectile->getRow() + 1;
		conOut(x * 5 + 1, y * 18 + 1) << projectile->getName().c_str();
		return;
	}
}

int & TableEntities::Cell::getResistance()
{
	int n = 0;
	return n;
}

void TableEntities::Cell::fire(Table &table)
{
}

TableEntities::Plant::Plant() {}

TableEntities::Plant::Plant(int x, int y) : Cell(x, y) {
	hasPlant = true;
	resistance = 100;
}

TableEntities::Plant::~Plant()
{
}

void TableEntities::Plant::represent()
{
}

int & TableEntities::Plant::getResistance()
{
	return resistance;
}

void TableEntities::Plant::fire(Table &table)
{
}

void TableEntities::Plant::dealDamage(int damage)
{
	resistance -= damage;
}

bool TableEntities::Plant::isDead()
{
	return resistance <= 0;
}

int TableEntities::Plant::getPrice()
{
	return price;
}

TableEntities::Peashooter::Peashooter() {
	price = 4;
}

TableEntities::Peashooter::Peashooter(int x, int y) : Plant(x, y) {
	fireThreshold = 0;
	price = 4;
}

TableEntities::Peashooter::~Peashooter()
{
}

void TableEntities::Peashooter::represent() {
	draw(row + 1, column + 1, "Peashooter");
}

void TableEntities::Peashooter::fire(Table &table)
{
	Logger &logger = Logger::getInstance();

	if (fireThreshold % 376 == 0) {
		logger << "Peashooter on (" + std::to_string(row) + ", " + std::to_string(column) + ") fires\n";
		TableEntities::Projectile *p = new TableEntities::Projectile(row, column + 1);
		table.getCell(row, column + 1)->addProjectile(p);
	}
}

void TableEntities::Peashooter::incFT()
{
	fireThreshold++;
}

int TableEntities::Peashooter::getPrice()
{
	return price;
}

TableEntities::Sunflower::Sunflower() {
	price = 2;
}

TableEntities::Sunflower::Sunflower(int x, int y) : Plant(x, y) {
	price = 2;
}

TableEntities::Sunflower::~Sunflower()
{
}

void TableEntities::Sunflower::represent() {
	draw(row + 1, column + 1, "Sunflower");
}

void TableEntities::Sunflower::fire(Table &table)
{
}

int TableEntities::Sunflower::getPrice()
{
	return price;
}

TableEntities::CherryBomb::CherryBomb() {
	price = 4;
}

TableEntities::CherryBomb::CherryBomb(int x, int y) : Plant(x, y) {
	hasPlant = false;
	fireThreshold = 1;
	price = 4;
}

TableEntities::CherryBomb::~CherryBomb()
{
}

void TableEntities::CherryBomb::represent() {
	draw(row + 1, column + 1, "CherryBomb");
}

void Table::hurtZombies(int row, int col, int damage) {
	if (row >= 0 && col >= 0 && row <= 4 && col <= 7 && grid[row][col]->noZombies() != 0) {
		for (int i = 0; i < grid[row][col]->noZombies(); i++) {
			grid[row][col]->getZombie(i)->dealDamage(damage);
		}
	}
}

void TableEntities::CherryBomb::fire(Table &table)
{
	Logger &logger = Logger::getInstance();

	if (fireThreshold % 75 == 0) {
		logger << "CherryBomb on (" + std::to_string(row) + ", " + std::to_string(column) + ") fires\n";
		table.hurtZombies(row, column, 200);

		table.hurtZombies(row - 1, column - 1, 50);
		table.hurtZombies(row, column - 1, 50);
		table.hurtZombies(row + 1, column - 1, 50);

		table.hurtZombies(row - 1, column, 50);
		table.hurtZombies(row + 1, column, 50);

		table.hurtZombies(row - 1, column + 1, 50);
		table.hurtZombies(row, column + 1, 50);
		table.hurtZombies(row + 1, column + 1, 50);

		table.clearCell(row, column);
		clearCell1(row + 1, column + 1);
	}
}

void TableEntities::CherryBomb::incFT()
{
	fireThreshold++;
}

int TableEntities::CherryBomb::getPrice()
{
	return price;
}

TableEntities::Wallnut::Wallnut() {
	price = 3;
}

TableEntities::Wallnut::Wallnut(int x, int y) : Plant(x, y) {
	price = 3;
}

TableEntities::Wallnut::~Wallnut()
{
}

void TableEntities::Wallnut::represent() {
	draw(row + 1, column + 1, "Wallnut");
}

void TableEntities::Wallnut::fire(Table &table)
{
}

int TableEntities::Wallnut::getPrice()
{
	return price;
}

TableEntities::SnowPea::SnowPea() {
	price = 5;
}

TableEntities::SnowPea::SnowPea(int x, int y) : Plant(x, y) {
	fireThreshold = 0;
	price = 5;
}

TableEntities::SnowPea::~SnowPea()
{
}

void TableEntities::SnowPea::represent() {
	draw(row + 1, column + 1, "SnowPea");
}

void TableEntities::SnowPea::fire(Table &table)
{
	Logger &logger = Logger::getInstance();

	if (fireThreshold % 376 == 0) {
		logger << "SnowPea on (" + std::to_string(row) + ", " + std::to_string(column) + ") fires\n";
		TableEntities::Projectile *p = new TableEntities::Projectile(row, column + 1, true);
		table.getCell(row, column + 1)->addProjectile(p);
	}
}

void TableEntities::SnowPea::incFT()
{
	fireThreshold++;
}

int TableEntities::SnowPea::getPrice()
{
	return price;
}

TableEntities::Zombie::Zombie() {}

TableEntities::Zombie::Zombie(int x, int y) {
	column = y;
	row = x;
	life = 100;
	speed = 1;
	moveThreshold = 0;
	jump = false;
}

TableEntities::Zombie::~Zombie()
{
}

int TableEntities::Zombie::getThresh()
{
	return moveThreshold;
}

int TableEntities::Zombie::getRow()
{
	return row;
}

int TableEntities::Zombie::getColumn()
{
	return column;
}

void TableEntities::Zombie::represent() {
}

std::string TableEntities::Zombie::getName()
{
	return std::string();
}

void TableEntities::Zombie::move() {
	column--;
}

bool TableEntities::Zombie::isDead()
{
	return life <= 0;
}

bool TableEntities::Zombie::canJump()
{
	return jump;
}

void TableEntities::Zombie::slow()
{
	if (speed > 1) {
		speed /= 2;
	}
}

void TableEntities::Zombie::dealDamage(int damage)
{
	life -= damage;
}

void TableEntities::Zombie::noJumping()
{
	jump = false;
}

void TableEntities::Zombie::resetThresh()
{
	moveThreshold = 0;
}

void TableEntities::Zombie::advance()
{
	moveThreshold += speed;
}

int TableEntities::Zombie::getValue()
{
	return 0;
}

TableEntities::Simple::Simple()
{
}

TableEntities::Simple::Simple(int i, int j) : Zombie(i, j)
{
	life = 100;
	speed = 2;
	moveThreshold = 0;
}

TableEntities::Simple::~Simple()
{
}

void TableEntities::Simple::represent() {
	draw(row + 1, column + 1, "¬(^-^¬)");
}

std::string TableEntities::Simple::getName()
{
	return "¬(^-^¬)";
}

int TableEntities::Simple::getValue()
{
	return 100;
}

TableEntities::BucketHead::BucketHead()
{
}

TableEntities::BucketHead::BucketHead(int i, int j) : Zombie(i, j)
{
	life = 200;
	speed = 2;
	moveThreshold = 0;
}

TableEntities::BucketHead::~BucketHead()
{
}

void TableEntities::BucketHead::represent() {
	draw(row + 1, column + 1, "BucketHead");
}

std::string TableEntities::BucketHead::getName()
{
	return "BucketHead";
}

int TableEntities::BucketHead::getValue()
{
	return 200;
}

TableEntities::PoleVaulting::PoleVaulting()
{
}

TableEntities::PoleVaulting::PoleVaulting(int i, int j) : Zombie(i, j)
{
	life = 100;
	speed = 4;
	moveThreshold = 0;
	jump = true;
}

TableEntities::PoleVaulting::~PoleVaulting()
{
}

void TableEntities::PoleVaulting::represent() {
	draw(row + 1, column + 1, "PoleVaulting");
}

std::string TableEntities::PoleVaulting::getName()
{
	return "PoleVaulting";
}

int TableEntities::PoleVaulting::getValue()
{
	return 300;
}

TableEntities::SuperZombie::SuperZombie()
{
}

TableEntities::SuperZombie::SuperZombie(int i, int j) : Zombie(i, j)
{
	life = 200;
	speed = 4;
	moveThreshold = 0;
}

TableEntities::SuperZombie::~SuperZombie()
{
}

void TableEntities::SuperZombie::represent() {
	draw(row + 1, column + 1, "SuperZombie");
}

std::string TableEntities::SuperZombie::getName()
{
	return "SuperZombie";
}

int TableEntities::SuperZombie::getValue()
{
	return 500;
}

Table::Table() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			grid[i][j] = new TableEntities::Cell(i, j);
		}
	}
}

Table::~Table()
{
}

TableEntities::Cell * Table::getCell(int i, int j)
{
	return grid[i][j];
}

void Table::clearCell(int row, int column)
{
	grid[row][column] = new TableEntities::Cell(row, column);
}

void Table::setSun(int i, int v)
{
	suns[i] = v;
}

void Table::incrementResources()
{
	resources++;
}

int Table::getResources()
{
	return resources;
}

void Table::pay(int v)
{
	resources -= v;
}

int Table::getScore()
{
	return score;
}

void Table::setScore(int v)
{
	score = v;
}

void Table::raiseScore(int v)
{
	score += v;
}

int Table::getLevel()
{
	return level;
}

void Table::setLevel(int v)
{
	level = v;
}

void Table::addLivingZombie()
{
	zombiesAlive++;
}

int Table::getSunRate()
{
	return sun_rate;
}

void Table::incrementSunRate()
{
	sun_rate++;
}

void Table::decrementSunRate()
{
	sun_rate--;
}

bool Table::hasFullSuns()
{
	return std::find(std::begin(suns), std::end(suns), 0) == std::end(suns);
}

void Table::setCell(int i, int j, TableEntities::Plant *p)
{
	grid[i][j] = p;
}

void Table::renderTable() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			grid[i][j]->represent();
		}
	}
}

bool Table::hasSun(int x) {
	return suns[x] == 1;
}

int Table::moveZombies(int zombieMoveCounter, std::string name)
{
	Logger &logger = Logger::getInstance();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < grid[i][j]->noZombies(); k++) {
				TableEntities::Zombie *z = grid[i][j]->getZombie(k);
				int zThres = z->getThresh();
				if (zombieMoveCounter == zThres && j > 0) {
					logger << "Moving zombie from (" + std::to_string(i) + ", " + std::to_string(j);
					if (!grid[i][j - 1]->checkPlant()) {
						grid[i][j]->killZombie(k);

						z->move();
						grid[i][j - 1]->addZombie(z);
						clearCell1(i + 1, j + 1);
						logger << ") to (" + std::to_string(i) + ", " + std::to_string(j - 1) + ")\n";
					}
					if (grid[i][j - 1]->checkPlant() && z->canJump() && j != 1) {
						z->noJumping();
						grid[i][j]->killZombie(k);

						z->move();
						z->move();
						grid[i][j - 2]->addZombie(z);
						clearCell1(i + 1, j + 1);
						logger << ") to (" + std::to_string(i) + ", " + std::to_string(j - 2) + ")\n";
					}
					if (grid[i][j - 1]->checkPlant() && z->canJump() && j == 1) {
						// game over
						logger << "PoleVaulting jumped in the base, game over\n\n\n";
						std::ofstream save;
						save.open(name);
						save << getScore() << std::endl;
						save << getLevel() << std::endl;
						save.close();
						delete &logger;
						return -1;
					}
					if (grid[i][j - 1]->checkPlant() && !z->canJump()) {
						// attack plant
						logger << "Zombie from (" + std::to_string(i) + ", " + std::to_string(j) + 
							") attacks plant on (" + std::to_string(i) + ", " + std::to_string(j - 1) + ")\n";
						TableEntities::Cell *p = grid[i][j - 1];
						TableEntities::Plant *pp = static_cast<TableEntities::Plant*>(p);
						if (!pp->isDead()) {
							pp->dealDamage(50);
						}
						else {
							logger << "Plant on (" + std::to_string(i) + ", " + std::to_string(j - 1) + ") dies\n";
							TableEntities::Sunflower *sunflower = dynamic_cast<TableEntities::Sunflower*>(pp);
							if (sunflower != nullptr) {
								// if sunflower died
								sun_rate--;
							}
							grid[i][j - 1] = new TableEntities::Cell(i, j - 1);
							clearCell1(i + 1,j);
						}
					}
					z->resetThresh();
				}
			}
		}
	}

	return 0;
}

void Table::moveProjectiles(int projectileMoveCounter)
{
	// iterate through the table and move projectiles when it is their time
	Logger &logger = Logger::getInstance();
	for (int i = 4; i >= 0; i--) {
		for (int j = 8; j >= 0; j--) {
			TableEntities::Projectile *z = grid[i][j]->getProjectile();
			if (z != nullptr) {
				int zThres = z->getThresh();
				if (j < 7 && projectileMoveCounter == zThres) {
					logger << "Projectile on (" + std::to_string(i) + ", " + std::to_string(j) + ") advances\n";
					grid[i][j]->destroyProjectile();

					z->move();
					grid[i][j + 1]->addProjectile(z);
					clearCell1(i + 1, j + 1);
					z->resetThresh();
				}
				if (j == 7 && projectileMoveCounter == zThres) {
					// destroy projectile
					grid[i][j]->destroyProjectile();
					clearCell1(i + 1, j + 1);
				}
			}
		}
	}
}

void Table::updateGuns()
{
	// iterate through the table and increment counters of gun plants
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			TableEntities::Cell *p = grid[i][j];
			TableEntities::Peashooter *pp = dynamic_cast<TableEntities::Peashooter*>(p);
			if (pp != nullptr) {
				pp->incFT();
			}
			else {
				TableEntities::SnowPea *pp = dynamic_cast<TableEntities::SnowPea*>(p);
				if (pp != nullptr) {
					pp->incFT();
				}
				else {
					TableEntities::CherryBomb *pp = dynamic_cast<TableEntities::CherryBomb*>(p);
					if (pp != nullptr) {
						pp->incFT();
					}
				}
			}
		}
	}
}

void Table::updateZombies()
{
	// iterate through the table and increment counters of zombies
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < grid[i][j]->noZombies(); k++) {
				if (grid[i][j]->getZombie(k)->isDead()) {
					grid[i][j]->killZombie(k);
					if (!grid[i][j]->checkPlant()) {
						clearCell1(i + 1, j + 1);
						grid[i][j]->represent();
					}
					zombiesAlive--;
					continue;
				}

				TableEntities::Zombie *z = grid[i][j]->getZombie(k);
				z->advance();
			}
		}
	}
}

void Table::updateProjectiles()
{
	// iterate through the table and increment counters of projectiles
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			TableEntities::Projectile *z = grid[i][j]->getProjectile();
			if (z != nullptr) {
				z->advance();
			}
		}
	}
}

void Table::placeProjectiles()
{
	// iterate through the table and place projectiles in front of plants when their time to shoot comes
	Logger &logger = Logger::getInstance();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			TableEntities::Cell *p = grid[i][j];
			TableEntities::CherryBomb *pp = dynamic_cast<TableEntities::CherryBomb*>(p);
			if (grid[i][j]->checkPlant() || pp != nullptr) {
				grid[i][j]->fire(*this);
			}
		}
	}
}

void Table::processCollisions()
{
	// iterate through the table and check if projectiles are on the same cell as zombies (hit)
	Logger &logger = Logger::getInstance();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (grid[i][j]->hasProjectile() && grid[i][j]->noZombies() != 0) {
				logger << "Projectile hit on (" + std::to_string(i) + ", " + std::to_string(j) + ")\n";
				//destroy projectile and deal damage
				if (grid[i][j]->getProjectile()->isFreeze()) {
					// if freeze projectile
					grid[i][j]->getZombie(0)->slow();
				}
				grid[i][j]->destroyProjectile();
				grid[i][j]->getZombie(0)->dealDamage(50);
				if (grid[i][j]->getZombie(0)->isDead()) {
					score += grid[i][j]->getZombie(0)->getValue();
					logger << "First zombie on (" + std::to_string(i) + ", " + std::to_string(j) + ") dies\n";
					grid[i][j]->killZombie(0);
					zombiesAlive--;
				}
			}
		}
	}
}

TableEntities::Projectile::Projectile()
{
}

TableEntities::Projectile::Projectile(int i, int j, bool f) : Movable(i, j)
{
	freeze = f;
	moveThreshold = 0;
}

TableEntities::Projectile::~Projectile()
{
}

void TableEntities::Projectile::represent()
{
	if (freeze) {
		draw(row + 1, column + 1, "Projectile");
	}
	else {
		draw(row + 1, column + 1, "FProjectile");
	}
}

int TableEntities::Projectile::getThresh()
{
	return moveThreshold;
}

int TableEntities::Projectile::getRow()
{
	return row;
}

int TableEntities::Projectile::getColumn()
{
	return column;
}

std::string TableEntities::Projectile::getName()
{
	if (freeze) {
		return "FProjectile";
	}
	else {
		return "Projectile";
	}
}

void TableEntities::Projectile::move() {
	column++;
}

void TableEntities::Projectile::resetThresh()
{
	moveThreshold = 0;
}

void TableEntities::Projectile::advance()
{
	moveThreshold++;
}

bool TableEntities::Projectile::isFreeze()
{
	return freeze;
}

TableEntities::Movable::Movable()
{
}

TableEntities::Movable::Movable(int i, int j)
{
	row = i;
	column = j;
	moveThreshold = 0;
}

TableEntities::Movable::~Movable()
{
}
