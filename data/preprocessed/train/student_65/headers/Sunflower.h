#pragma once
#include "Plant.h"
class Sunflower :
	public Plant
{
public:
	Sunflower(int x, int y, int health = 70, std::string name = "Sunflower") :Plant(x, y, health, name) {}
	void draw()
	{
		UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
		c(this->get_x(), this->get_y()) << "+";
		c(this->get_x() + 1, this->get_y()) << "|";
	}
	void update(std::string);
	~Sunflower();
};

