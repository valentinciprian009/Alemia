#pragma once
#include <string>
#include <iostream>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Player.h"
#include <chrono>
#include <time.h>
#include <vector>
using namespace std;
using namespace std::chrono;


struct point
{
	int x;
	int y;
	point() {};
	point(int x, int y) :x(x), y(y) {};
};

class Entity
{
protected:
	int health;
	point location;
	char icon;
public:
	int get_x() { return location.x; };
	int get_y() { return location.y; };
	virtual void update(vector<Entity*>&flowers,vector <Entity*>&zombies, vector <Entity*>&bullets,Player &player) = 0;
	virtual void set_eater(Entity *zombie) {};
	int get_health() { return health; };
	Entity();
	Entity(int x, int y,char icon,int health) :location(x, y),icon(icon),health(health) {};
	void take_damage(int damage) { health -= damage; };
	char get_icon() { return icon; };
	virtual ~Entity();
	void die(vector<Entity*> &those);
	virtual void get_slowed() {};
};

class Plant :public Entity
{
protected:
	int cost;
	Entity* zombie;

public:
	Plant(int x, int y, int cost, char icon,int health) :Entity(x, y, icon,health), cost(cost) {};
	void set_eater(Entity *zombie) { zombie = zombie; };
	virtual ~Plant() {};
	virtual void update(vector<Entity*>&flowers, vector<Entity*>&zombies, vector <Entity*>&bullets, Player &player);
};

class Zombie :public Entity
{
protected: 
	bool stopped;
	bool eating;
	int damage;
	int move_frequency;
	Entity* plant_attacked;
	steady_clock::time_point time;
	int points;
	
	void move();
	void check(vector <Entity*> flowers,  vector <Entity*>zombies);
	void eat();
	

public:
	Zombie(int x, int y, int move_frequency,char icon,int health,int points) :points(points),Entity(x, y,icon,health),move_frequency(move_frequency),time(steady_clock::now()),damage(34) {};
	virtual void update(vector<Entity*>&flowers, vector<Entity*>&zombies, vector <Entity*>&bullets, Player &player);
	void take_damage(int damage) { health -= damage; };
	void get_slowed() { move_frequency *= 2; };
	virtual ~Zombie() {};
};

class BasicZombie :public Zombie
{
public:
	BasicZombie(int x, int y) :Zombie(x, y, 2000, 'z',100,1) {};
};

class BucketHeadZombie :public Zombie
{
public:
	BucketHeadZombie(int x, int y) :Zombie(x, y, 2000, 'Z', 400, 3) {};
};

class  SunFlower :public Plant
{
public:
	SunFlower(int x, int y) :Plant(x, y, 50, 'S',100) {};
};


class  CherryBomb :public Plant
{
public:
	CherryBomb(int x, int y) :Plant(x, y, 150, 'B',2000) {};
	void update(vector<Entity*>&flowers, vector <Entity*>&zombies, vector <Entity*>&bullets, Player &player) {};
};


class  WallNut :public Plant
{
public:
	WallNut(int x, int y) :Plant(x, y, 100, 'N',1000) {};
	void update(vector<Entity*>&flowers, vector <Entity*>&zombies, vector <Entity*>&bullets, Player &player) {};
};

class ShootingPlant :public Plant
{
protected:
	steady_clock::time_point timp;
	int frequency;
	void shoot(bool freeze,vector<Entity*>&bullets);
public:
	ShootingPlant(int x, int y, int cost, char icon, int life) :Plant(x, y, cost, icon, life),frequency(2000) {};
	void update(vector<Entity*>&flowers, vector <Entity*>&zombies, vector <Entity*>&bullets, Player &player) {};
};


class  SnowPea :public ShootingPlant
{
	
public:
	SnowPea(int x, int y) :ShootingPlant(x, y, 150, 'F',100) {};
	void update(vector<Entity*>&flowers, vector <Entity*>&zombies, vector <Entity*>&bullets, Player &player) ;
};


class  PeaShooter :public ShootingPlant
{

public:
	PeaShooter(int x, int y) :ShootingPlant(x, y, 100, 'P',100) {};
	void update(vector<Entity*>&flowers, vector <Entity*>&zombies,  vector <Entity*>&bullets, Player &player);
};


class Bullet :public Entity
{
	int frequency;
	steady_clock::time_point timp;
	bool freezing;
	int damage;
	void move();
public:
	Bullet(int x, int y, bool freezing, char icon) :Entity(x, y, icon, 1), damage(34), frequency(500), timp(steady_clock::now()) {};
	void update(vector<Entity*>&flowers,  vector <Entity*>&zombies, vector <Entity*>&bullets, Player &player);
};