#include "terrain.h"

void terrain::setlevel(int n)
{
	level = n;
}
int terrain::getlevel()
{
	return this->level;
}
int terrain::getx_grass()
{
	return this->x_grass;
}
int terrain::gety_grass()
{
	return this->y_grass;
}

int terrain::getx_plant()
{
	return this->x_plant;
}
int terrain::gety_plant()
{
	return this->y_plant;
}
int terrain::getx_space()
{
	return this->x_space;
}
int terrain::gety_space()
{
	return this->y_space;
}
int terrain::getx_sun()
{
	return this->x_sun;
}
int terrain::gety_sun()
{
	return this->y_sun;
}


