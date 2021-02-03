#pragma once
#include <iostream>
#include <string>
#include "Menu.h"
#include "Pick_and_plant.h"
#include <vector>
using namespace std;
class Sun 
{
	
	
public:
	Sun();

	void _random();
	void _delete_after();
	void draw(int x,int y);
	void remove_sun(int x, int y);
	
	~Sun();
};

