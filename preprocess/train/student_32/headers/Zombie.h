#pragma once
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<chrono>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
using namespace std;
using namespace std::chrono;
class Zombie
{
protected:
	int col;
	int row;
	int health;
	int damage;
	int speed;
	string name;
	int jump;
	steady_clock::time_point last_move;

public:
	Zombie();
	Zombie(string name, int row, int col, int health, int damage, int speed);
	int get_col();
	int get_row();
	int get_health();
	int get_damage();
	int get_speed();
	string get_name();
	bool delay();
	void move();
	void take_damage(int x);
	void set_row(int x);
	void set_col(int x);
	void set_jump();
	int get_jump();
};

