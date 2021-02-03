#pragma once
#include <vector>
#include <string>
#include "ConsoleOutput.h"
#include "Logger.h"
#include <iterator>

class Table;

void clearCell1(int x, int y);

namespace TableEntities {
	class Movable
	{
	protected:
		int row, column;
		int moveThreshold;
	public:
		Movable();
		Movable(int i, int j);
		virtual ~Movable();

		virtual int getThresh() = 0;
		virtual int getRow() = 0;
		virtual int getColumn() = 0;
		virtual void represent() = 0;
		virtual std::string getName() = 0;
		virtual void move() = 0;
	};

	class Zombie : public Movable
	{
	protected:
		int life, speed;
		bool jump;
	public:
		Zombie();
		Zombie(int i, int j);
		virtual ~Zombie();

		virtual int getThresh();
		virtual int getRow();
		virtual int getColumn();
		virtual void represent();
		virtual std::string getName();
		void move();
		void resetThresh();
		void advance();

		bool isDead();
		bool canJump();
		void slow();
		void dealDamage(int damage);
		void noJumping();
		virtual int getValue();
	};

	class Projectile : public Movable
	{
		bool freeze;
	public:
		Projectile();
		Projectile(int i, int j, bool f = false);
		~Projectile();

		virtual int getThresh();
		virtual int getRow();
		virtual int getColumn();
		void represent();
		std::string getName();
		void move();
		void resetThresh();
		void advance();

		bool isFreeze();
	};

	class Cell
	{
	protected:
		int row, column;
		bool hasPlant;
		std::vector<TableEntities::Zombie*> zombies;
		TableEntities::Projectile* projectile;
	public:
		Cell();
		Cell(int x, int y, bool hP = false);
		virtual ~Cell();

		int getRow();
		int getColumn();
		bool checkPlant();
		void plant();
		void addProjectile(Projectile *p);
		Projectile* getProjectile();
		void destroyProjectile();
		bool hasProjectile();
		int noZombies();
		Zombie* getZombie(int index);
		void killZombie(int index);
		void addZombie(Zombie *z);

		virtual void represent();
		virtual int & getResistance();
		virtual void fire(Table &table);
	};

	class Plant : public Cell
	{
	protected:
		int price, resistance;
	public:
		Plant();
		Plant(int i, int j);
		virtual ~Plant();

		void represent();
		int & getResistance();
		void fire(Table &table);

		void dealDamage(int damage);
		bool isDead();
		virtual int getPrice();
	};

	class Peashooter : public Plant
	{
		int fireThreshold;
		int price = 4;
	public:
		Peashooter();
		Peashooter(int i, int j);
		~Peashooter();

		void represent();
		void fire(Table &table);
		void incFT();
		virtual int getPrice();
	};

	class Sunflower : public Plant
	{
	public:
		Sunflower();
		Sunflower(int i, int j);
		~Sunflower();

		void represent();
		void fire(Table &table);
		virtual int getPrice();
	};

	class CherryBomb : public Plant
	{
		int fireThreshold;
	public:
		CherryBomb();
		CherryBomb(int i, int j);
		~CherryBomb();

		void represent();
		void fire(Table &table);
		void incFT();
		virtual int getPrice();
	};

	class Wallnut : public Plant
	{
	public:
		Wallnut();
		Wallnut(int i, int j);
		~Wallnut();

		void represent();
		void fire(Table &table);
		virtual int getPrice();
	};

	class SnowPea : public Plant
	{
		int fireThreshold;
	public:
		SnowPea();
		SnowPea(int i, int j);
		~SnowPea();

		void represent();
		void fire(Table &table);
		void incFT();
		virtual int getPrice();
	};

	class Simple : public Zombie {
	public:
		Simple();
		Simple(int i, int j);
		~Simple();

		void represent();
		std::string getName();
		virtual int getValue();
	};

	class BucketHead : public Zombie
	{
	public:
		BucketHead();
		BucketHead(int i, int j);
		~BucketHead();

		void represent();
		std::string getName();
		virtual int getValue();
	};

	class PoleVaulting : public Zombie
	{
	public:
		PoleVaulting();
		PoleVaulting(int i, int j);
		~PoleVaulting();

		void represent();
		std::string getName();
		virtual int getValue();
	};

	class SuperZombie : public Zombie
	{
	public:
		SuperZombie();
		SuperZombie(int i, int j);
		~SuperZombie();

		void represent();
		std::string getName();
		virtual int getValue();
	};
}

class Table
{
	int level = 1;
	int sun_rate = 1;
	int resources = 0;
	int score = 0;
	int suns[8] = {};
	int zombiesAlive = 0;
	TableEntities::Cell* grid[5][9];
public:
	Table();
	~Table();

	TableEntities::Cell* getCell(int i, int j);
	void clearCell(int i, int j);
	void setSun(int i, int v);
	void incrementResources();
	int getResources();
	void pay(int v);

	void raiseScore(int v);

	int getLevel();
	void setLevel(int v);

	int getScore();
	void setScore(int v);

	void addLivingZombie();

	int getSunRate();
	void incrementSunRate();
	void decrementSunRate();

	bool hasFullSuns();
	void setCell(int i, int j, TableEntities::Plant *p);

	void hurtZombies(int row, int col, int damage);
	void renderTable();
	bool hasSun(int x);
	int moveZombies(int zombieMoveCounter, std::string name);
	void moveProjectiles(int projectileMoveCounter);
	void updateGuns();
	void updateZombies();
	void updateProjectiles();
	void placeProjectiles();
	void processCollisions();
};