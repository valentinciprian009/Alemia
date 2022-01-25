#pragma once
#include "Plant.h"
#include "Time.h"
#include <vector>
#include "Frozen_Pea.h"
#include "Pea.h"
class Snow_Pea :
	public Plant
{
private:
	Time t;

public:
	std::vector<Frozen_Pea*> proiectile;
	Snow_Pea(int x, int y, int health=150, std::string name = "Snow_Pea") :Plant(x, y, health, name) {}
	void draw()
	{
		UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
		c(this->get_x(), this->get_y()) << ">>>";
		c(this->get_x()+1, this->get_y()+1) << "|";
		for (auto it : proiectile)
			it->draw();
	}
	void update(std::string);
	~Snow_Pea();
};

