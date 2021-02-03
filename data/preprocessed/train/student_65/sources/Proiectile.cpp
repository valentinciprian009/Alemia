#include "Proiectile.h"

void Proiectile::draw()
{
}

void Proiectile::update()
{
	this->set_position(this->get_x(), this->get_y() + 1);
}
