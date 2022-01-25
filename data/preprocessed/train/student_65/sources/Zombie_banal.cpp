#include "Zombie_banal.h"

void Zombie_banal::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->get_x(), this->get_y() + 1) << " ";
	conOut(this->get_x() + 1, this->get_y() + 1) << "  ";
	conOut(this->get_x() + 2, this->get_y() + 1) << " ";
	conOut(this->get_x(), this->get_y()) << "Q";
	conOut(this->get_x() + 1, this->get_y()) << ">]";
	conOut(this->get_x() + 2, this->get_y()) << "|";

}

void Zombie_banal::update(std::string)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	t.update();
	if (t.durata() > 0.5f)
	{
		draw();
		this->set_position(this->get_x(), this->get_y() -1);
		t.set_time();
		t.update();
	}
}

Zombie_banal::~Zombie_banal()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->get_x(), this->get_y() -1) << "  ";
	conOut(this->get_x() + 1, this->get_y() -1) << "   ";
	conOut(this->get_x() + 2, this->get_y() -1) << "  ";
}
