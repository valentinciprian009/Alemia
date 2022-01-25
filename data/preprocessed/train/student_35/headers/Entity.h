#pragma once
#include<Windows.h>
#include <time.h>
#include <chrono>
#include<iostream>
#include"ConsoleOutput.h"
using namespace std;
class Entity
{
protected:
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int cx;
	int cy;
	string icon;
public:
	Entity() {}
	Entity(int x, int y, string img) :cx(x), cy(y), icon(img) {}
	~Entity() {

	}
	virtual void print_icon() { conOut(cx, cy) << icon; conOut(cx, cy + 2) << " "; }
	virtual void set_coord(int x, int y) {
		cx = x;
		cy = y;
	}
	void set_all(int x, int y, string icn) {
		cx = x;
		cy = y;
		icon = icn;
	}
	virtual void move() {
		cy = cy - 1;
		Sleep(100);
	}
	virtual int getx() { return cx; }
	virtual int gety() { return cy; }

};

