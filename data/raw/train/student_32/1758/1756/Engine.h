#pragma once
#include<iostream>
#include<stdio.h>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
#include <conio.h>
#include<windows.h>
#include<time.h>
#include<chrono>
#include"Field.h"
#include"Sun.h"
#include"Event.h"
#include<vector>
#include"Wallnut.h"
#include"Peashooter.h"
#include"Projectile.h"
#include"Zombie.h"
#include"Sunflower.h"
#include"CherryBomb.h"
#include"BucketHead.h"
#include"PoleVaulting.h"
#include"CLog.h"
#include"SuperZombie.h"
#include<fstream>
#include<random>
using namespace std;
using namespace std::chrono;
#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;
class Engine
{
private:
	Engine();
	static Engine* instance;
	~Engine() {};
	Engine(const Engine&);

public:
	static Engine& getInstance();
	static void destroyInstance();
	static void draw_shop();
	static void show_sun();
	static void take_events(Event aux,int &planting);
	static void plant(Event e, int& planting);
	static void show_projectiles();
	static void levels();
	static void fight();
	static void start_game();
	static void menu();
	static void menu_register();
	static void menu_login();
	static void game_lost();
	static void check_win();
	static void menu_recent_scores();
};

