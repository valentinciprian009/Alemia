#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include "Monster.h"
#include <chrono>
#include <iostream>
#include <vector>
#include "terrain.h"
#include "bullet.h"
#include "peashooter.h"
#include "frozenshooter.h"
#include "Plant.h"
#include "sunflower.h"
#include "sun.h"
#include "potato.h"
#include "bucketM.h"
#include <conio.h>
class RGame
{public:
	int money=50;
	int timp=0;
	int level;
	int score = 0;
	terrain map;
	std::vector <Plant*> plants;
	std::vector <sun*>light;
	std::vector <Monster*> monsters;
	std::vector <bullet*> ammo;
	std::string username;
	void Menu(std::string username);
	RGame(int level);
	RGame();
	void drawpixel2(unsigned char x, unsigned char y, unsigned char Color, char character);
	void drawframe(unsigned x, unsigned y, unsigned sx, unsigned sy);
	void drawwindow(unsigned x, unsigned y, unsigned sx, unsigned sy, unsigned char bkcol, const char text_[]);
	void gotoxy(int x, int y);
	void setcolor(WORD color);
	void drawpixel(unsigned char x, unsigned char y, unsigned char Color);
	void drawline(int x0, int y0, int x1, int y1, int color);
	void drawfilledrectangle(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char bkcol);
	void drawcircle(int x, int y, int a, int b, int color);
	void cls();
	int count(int& i);
	void aprox_coord(int& x, int& y);
	void create_map(terrain map, int z);
	std::string take_plant(std::pair<int, int> action, int& valid);
	Plant* put_plant(std::pair<int, int> action, std::string plant, int& valid);
	void move_damage_zombie();
	void take_light(std::pair<int, int> action);
};

