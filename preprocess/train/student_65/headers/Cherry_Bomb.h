#pragma once
#include "Plant.h"
class Cherry_Bomb :
	public Plant
{
public:
	Cherry_Bomb(int x, int y, int health=10, std::string name = "Cherry_Bomb") :Plant(x, y, health, name) {}
	void draw()
	{
		UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();	
		c(this->get_x(), this->get_y()) << "{ }";
		c(this->get_x()+1, this->get_y()+1) << "|";
	}
	void update(std::string);
	~Cherry_Bomb();
};

