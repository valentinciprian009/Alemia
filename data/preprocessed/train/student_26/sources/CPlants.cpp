#include "CPlants.h"
using namespace std;
void SetColor1(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}
void CPlants::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	SetColor1(10);
	conOut(8,0) << "PEASHOOTER\n100";
	SetColor1(6);
	conOut(13,0) << "SUNFLOWER\n50";
	SetColor1(4);
	conOut(18,0) << "CHERRY BOMB\n150";
	SetColor1(8);
	conOut(23,0) << "WALL-NUT\n50";
	SetColor1(1);
	conOut(28,0) << "SNOW PEA\n175";
	SetColor1(7);
}

void CPlants::deletepos()
{
	
}

CPlants::CPlants()
{
}


CPlants::~CPlants()
{
}
