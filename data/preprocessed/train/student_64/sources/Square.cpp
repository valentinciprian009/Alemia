#include "Square.h"
#include "ConsoleOutput.h"


Square::Square() : sideSize(DEFAULT_SIDE_SIZE)
{
}


Square::~Square()
{
}

void Square::DoASquare()
{
	int a = leftCorner.get_x();
	int b = leftCorner.get_y();

	for (int i = 0; i < sideSize; i++)
	{
		UserInterface::ConsoleOutput::getInstance()(a, b+i) << char(196);
		UserInterface::ConsoleOutput::getInstance()(a+i, b + sideSize) << char(179);
		UserInterface::ConsoleOutput::getInstance()(a + sideSize, b+i) << char(196);
		UserInterface::ConsoleOutput::getInstance()(a+i, b) << char(179);
	}
	ChangeInteriorValue();
}

void Square::ChangeInteriorValue()
{
	int a = leftCorner.get_x();
	int b = leftCorner.get_y();
	UserInterface::ConsoleOutput printer = UserInterface::ConsoleOutput::getInstance();
	switch (currentEntity) {
	case Entities::Plant:
		switch (plant_type)
		{
			case PlantTypes::PeaShooter:
				printer(a + DEFAULT_SIDE_SIZE / 2, b + DEFAULT_SIDE_SIZE / 2) << "PS";
				break;
			case PlantTypes::Sunflower:
				printer(a + DEFAULT_SIDE_SIZE / 2, b + DEFAULT_SIDE_SIZE / 2) << "SF";
				break;
			case PlantTypes::CherryBomb:
				printer(a + DEFAULT_SIDE_SIZE / 2, b + DEFAULT_SIDE_SIZE / 2) << "CB";
				break;
			case PlantTypes::SnowPea:
				printer(a + DEFAULT_SIDE_SIZE / 2, b + DEFAULT_SIDE_SIZE / 2) << "SP";
				break;
			case PlantTypes::WallNut:
				printer(a + DEFAULT_SIDE_SIZE / 2, b + DEFAULT_SIDE_SIZE / 2) << "WN";
				break;
		}
		break;
	case Entities::NoEntity:
		printer(a + DEFAULT_SIDE_SIZE / 2, b + DEFAULT_SIDE_SIZE / 2) << " ";
		break;
	case Entities::Sun:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printer(a + DEFAULT_SIDE_SIZE / 2, b + DEFAULT_SIDE_SIZE / 2) << "*";
		break;
	case Entities::Zombie:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printer(a + DEFAULT_SIDE_SIZE / 2, b + DEFAULT_SIDE_SIZE / 2) << "ZB";
		break;
	}
}

void Square::PrintInteriorValue(int value)
{
	int a = leftCorner.get_x();
	int b = leftCorner.get_y();
	UserInterface::ConsoleOutput printer = UserInterface::ConsoleOutput::getInstance();
	printer(a + DEFAULT_SIDE_SIZE / 2, b + DEFAULT_SIDE_SIZE / 2) << value;
}