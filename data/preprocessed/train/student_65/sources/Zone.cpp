#include "Zone.h"

Zone::Zone()
{
	this->caracter = nullptr;
	filled = 0;
}

void Zone::set_free()
{
	filled = 0;
	delete caracter;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = x + 1; i < this->x + 5; i++)
		for (int j = y + 1; j <this-> y + 8; j++)
			conOut(i, j) << " ";
}

void Zone::set_filled()
{
	filled = true;
}

bool Zone::is_full()
{
	return filled;
}

void Zone::set_entity(Entity* val)
{
	if(filled)
		delete caracter;
	this->caracter = val;
	this->caracter->set_position(this->get_x() + 2, this->get_y() + 3);
	filled = 1;
}

Entity& Zone::get_entity()
{
	// TODO: insert return statement here
	return *this->caracter;
}

void Zone::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 10; i++)
	{
		conOut(this->get_x(),this->get_y() + i) << "-";
		conOut(this->get_x()+6, this->get_y() + i) << "-";
	}
	for (int i = 1; i < 6; i++)
	{
		conOut(this->get_x()+i, this->get_y()) << "|";
		conOut(this->get_x() + i, this->get_y() + 9) << "|";
	}
	if (this->filled)
		caracter->draw();
}

void Zone::update(std::string action)
{
	if(filled)
		caracter->update(action);
}
bool Zone::is_clicked(std::string action)
{
	if (action.find("double clicked") != std::string::npos)
	{
		std::string x, y;
		for (int i = action.find("(") + 1; i < action.find(","); i++)
			x += action[i];
		for (int i = action.find(",") + 1; i < action.find(")"); i++)
			y += action[i];
		int m_x, m_y;
		m_y = stoi(x);
		m_x = stoi(y);
		if (m_x > this->x&& m_x <= this->x + 6 && m_y >= this->y && m_y <= this->y + 10)
			return true;
	}
	return false;
}

Zone::~Zone()
{
	delete caracter;
}
