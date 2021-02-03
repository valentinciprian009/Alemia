#include "CZombie.h"
#include "CTeren.h"
#include <time.h>
#include <fstream>


void CZombie::deletePos()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->y, this->x) << "  ";
	conOut(this->y+1,this->x)<<" ";
}

void CZombie::updatePos()
{

	int oldX = this->x;
	int oldY = this->y;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	this->y -= this->speed;
	conOut(oldX, oldY) << ' ';
	conOut(oldX, oldY+1) << ' ';
	conOut(this->x, this->y) << nume;

	if (this->y <= 15)
	{

		std::ofstream log;
		log.open("log.log", std::fstream::app);
		log << "Utilizatorul a pierdut levelul\n";
		log.close();
		conOut(35, 17) << "AI PIERDUT LEVELUL !\n";
		system("pause");
		exit(1);
	}
}
CZombie::CZombie()
{

}



CZombie::~CZombie()
{
}
