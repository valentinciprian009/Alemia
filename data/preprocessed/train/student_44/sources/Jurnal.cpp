#include "Jurnal.h"

Jurnal* Jurnal::instanta = NULL;

Jurnal::Jurnal()
{
}

Jurnal::~Jurnal()
{
}

Jurnal * Jurnal::getInstance()
{
	if (instanta == NULL)
		instanta = new Jurnal();

	return instanta;
}

void Jurnal::destroyInstance()
{
	if (instanta != NULL)
		delete instanta;
	instanta = NULL;

}

void Jurnal::writeJurnal(string action)
{
	ofstream afisare("Jurnal.log", std::ios::app);

	afisare << action << endl;

}