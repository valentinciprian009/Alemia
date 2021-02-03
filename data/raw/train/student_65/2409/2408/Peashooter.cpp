#include "Peashooter.h"
#include "Time.h"
#include <vector>
#include "Terrain.h"

void Peashooter::draw()
{
	UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
	c(this->get_x(), this->get_y()) << ">";
	c(this->get_x()+1, this->get_y()) << "|";
	if(proiectile.size()>0)
	for (auto it : proiectile)
		it->draw();
}

void Peashooter::update(std::string)
{
	t.update();
	if(t.durata()>10)
	{
		proiectile.push_back(new Pea(this->get_x(), this->get_y() + 2));
		t.set_time();
		t.update();
	}
	for (auto it : proiectile)
	{
		if (it->get_y() == 102 || it->get_health() == 0)
		{
			proiectile.erase(proiectile.begin());
			delete it;
			break;
		}
		it->update();
		
	}
}

Peashooter::~Peashooter()
{
	UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
	c(this->get_x(), this->get_y()-1) << "  ";
	c(this->get_x() + 1, this->get_y()-1) << " ";
}

