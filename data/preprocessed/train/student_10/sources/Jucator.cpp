#include "Jucator.h"



Jucator* Jucator::instanta = nullptr;

Jucator& Jucator::get_instance()
{
	if (!instanta)
	{
		instanta = new Jucator();
	}
	return *instanta;
}

Jucator::~Jucator()
{
}
