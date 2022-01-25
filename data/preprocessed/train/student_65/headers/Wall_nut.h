#pragma once
#include "Plant.h"
class Wall_nut :
	public Plant
{
public:
	Wall_nut(int x, int y, int health = 200, std::string name = "Wall_nut") :Plant(x, y, health, name) {}
	void draw()
	{
		UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
		c(this->get_x(), this->get_y()) << "[ ]";
		c(this->get_x() + 1, this->get_y()+1) << "|";
	}
	void update(std::string);
	~Wall_nut();
};

