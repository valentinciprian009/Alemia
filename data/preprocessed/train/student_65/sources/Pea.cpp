#include "Pea.h"
#include "Terrain.h"
void Pea::draw()
{
	UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
	c(this->get_x(), this->get_y()-1) << " ";
	c(this->get_x(), this->get_y()) << "O";
}

void Pea::update()
{
	this->set_position(this->get_x(), this->get_y()+1);
	for (auto i : Terrain::zombie)
	{
		if (i->get_x() - 1 == this->get_x() && i->get_y() == this->get_y())
		{
			i->damaged(damage);
			health = 0;
			break;
		}
	}
}

Pea::~Pea()
{
	UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
	c(this->get_x(), this->get_y() - 1) << "  ";
	 
}
