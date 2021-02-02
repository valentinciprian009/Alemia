#include "Frozen_Pea.h"

void Frozen_Pea::draw()
{
	UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
	c(this->get_x(), this->get_y() -2) << " ";
	c(this->get_x(), this->get_y()) << "->";
}

void Frozen_Pea::update()
{
	this->set_position(this->get_x(), this->get_y() + 1);
	for (auto i : Terrain::zombie)
	{
		if (i->get_x() == this->get_x() && i->get_y() == this->get_y())
		{
			i->damaged(damage);
			health = 0;
			break;
		}
	}
}

Frozen_Pea::~Frozen_Pea()
{
	UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
	c(this->get_x(), this->get_y() - 2) << "   ";
}
