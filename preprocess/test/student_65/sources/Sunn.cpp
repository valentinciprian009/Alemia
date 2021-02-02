#include "Sunn.h"

void Sunn::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->get_x(), this->get_y() + 1) << "/\\";
	conOut(this->get_x()+1, this->get_y()) << "<";
	conOut(this->get_x()+1, this->get_y() + 2) << "O";
	conOut(this->get_x()+1, this->get_y() + 4) << ">";
	conOut(this->get_x()+2, this->get_y() + 1) << "\\/";
}

void Sunn::update(std::string)
{
}

Sunn::~Sunn()
{
}
