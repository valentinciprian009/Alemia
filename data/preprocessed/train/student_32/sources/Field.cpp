#include "Field.h"

void Field::print()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	for (int j = 0; j < 28; j=j+4)
	{
		for (int i = 0; i < 60; i = i + 6)
		{
			conOut(j, i) << "_____ ";
		}
	}
	
	
	for (int aux_1 = 1; aux_1 < 25; aux_1++)
	{
		conOut(aux_1, 5) << "|";
	}
	
	for (int aux_2 = 11; aux_2 < 60; aux_2 = aux_2 + 6)
	{
		for (int aux_3 = 1; aux_3 < 25; aux_3++)
		{
			conOut(aux_3, aux_2) << "|";
		}
	}
}
