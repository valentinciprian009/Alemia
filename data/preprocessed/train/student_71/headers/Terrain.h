#pragma once
#include "GameObject.h"


// 32 = Green 1
// 160 = Green 2

class Terrain
{
	GameObject*** entities;
	int matrix[5][9] =
	{
		{160,32,160,32,160,32,160,32,160 },
		{32,160,32,160,32,160,32,160,32} ,
		{160,32,160,32,160,32,160,32,160 },
		{32,160,32,160,32,160,32,160,32},
		{160,32,160,32,160,32,160,32,160 }
	};
	std::string map[5][9];
	static Terrain* instance;
	Terrain();
	~Terrain();
public:
	static Terrain& getInstance();
	static void destroyInstance();

	bool place(std::string name, int x, int y);
	void redraw(int x, int y);				// Redraws the entity
	void spawnZombie();
	bool isEmpty(int x, int y);
	bool isZombie(int x, int y);
	bool isPlant(int x, int y);
	void execute();

	void destroy(int x, int y);
	void damage(int x, int y, int damage = 0, bool slowed = false);
	void move(GameObject* to_move, int blocks_to_move);
};

