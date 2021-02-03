#include "ZombieBanal.h"



ZombieBanal::~ZombieBanal()
{
}

void ZombieBanal::pune_zombie()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	char  c = char(249);
	int poz_random;
	int v[5];
	for (int i = 0; i < 5; i++)
		v[i] = i;
	poz_random = rand() % 5;
	for(int i=0;i<5;i++)
		if(v[i]==poz_random)
			conOut(12+5*i,118) << c;//pozitia vectorului in tabela

		

}
