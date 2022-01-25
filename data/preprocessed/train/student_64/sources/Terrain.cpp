#include "Terrain.h"
#include "ConsoleInput.h"
#include "PlantTypes.h"
#include<sstream>
#include<iomanip>

Terrain::Terrain()
{

}


Terrain::~Terrain()
{
}

void Terrain::PrintScore()
{

	UserInterface::ConsoleOutput conout = UserInterface::ConsoleOutput::getInstance();
	std::stringstream ss;
	ss << std::setw(4) << std::setfill('0') << scoreBoard.points;
	std::string s = ss.str();
	conout(3, 2) << s;
}

void Terrain::init()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

	scoreBoard.setLeftCorner(0, 0);
	scoreBoard.setEntity(Entities::Score);
	scoreBoard.PrintInteriorValue();

	for (int i = 0; i < 8; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		suns[i].setLeftCorner(0, (i + 2) * DEFAULT_SIDE_SIZE);
		suns[i].setEntity(Entities::NoEntity);
		suns[i].DoASquare();
	}

	plants[0].plant_type = PlantTypes::PeaShooter;
	plants[1].plant_type = PlantTypes::SnowPea;
	plants[2].plant_type = PlantTypes::CherryBomb;
	plants[3].plant_type = PlantTypes::Sunflower;
	plants[4].plant_type = PlantTypes::WallNut;
	for (int i = 0; i < 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

		plants[i].setLeftCorner((i + 1) * DEFAULT_SIDE_SIZE + 1, 0);
		plants[i].setEntity(Entities::Plant);
		plants[i].DoASquare();
		
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

			mainZone[i][j].setLeftCorner((i + 1) * DEFAULT_SIDE_SIZE + 1, (j + 2) * DEFAULT_SIDE_SIZE);
			mainZone[i][j].setEntity(Entities::NoEntity);
			mainZone[i][j].DoASquare();
		}
	}


	
}


