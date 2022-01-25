#include "PlantsPeaShooter.h"

ProiectilPEA PlantsPeaShooter::returnFirstProiectil()
{
	return pea.front();
}

int PlantsPeaShooter::returnNrOfProiectils()
{
	return pea.size();
}

void PlantsPeaShooter::destroyFirstProiectil()
{
	pea.pop_front();//PROBLEM*********************************

}

void PlantsPeaShooter::decrementLife()
{
	this->nr_muscaturi--;
}

void PlantsPeaShooter::Shoot()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	ProiectilPEA* p = new ProiectilPEA();
	int viteza =p->getViteza();
	
	delete p;
	end = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() > viteza*500)
	{

		begin = std::chrono::steady_clock::now();
		
		for (auto it = pea.begin(); it != pea.end(); it++) {
			it->move();
			
		}
		
	}
}

void PlantsPeaShooter::GenerateProiectil()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();


	end_generare = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::seconds>(end_generare - begin_generare).count() > 15)
	{

		begin_generare = std::chrono::steady_clock::now();
		this->pea.push_back(ProiectilPEA(this->Row, this->Col + 4));
		for (auto it = pea.begin(); it != pea.end(); it++) {
			it->drawProiectil(this->Row, this->Col + 3);
		}
	}
}

void PlantsPeaShooter::showPlat(int row,int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x22);
	conOut(row, col) << "---";
	conOut(row + 1, col) << "---";

	SetConsoleTextAttribute(h, 7);
	conOut(row + 3, col) << this->cost;
}

void PlantsPeaShooter::showPlatB(int row, int col)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x22);
	conOut(row, col) << "---";
	conOut(row + 1, col) << "---";

	SetConsoleTextAttribute(h, 7);
}

int PlantsPeaShooter::getCost()
{
	return this->cost;
}

int PlantsPeaShooter::getNrMuscaturi()
{
	return this->nr_muscaturi;
}

int PlantsPeaShooter::getRegenerare()
{
	return this->regenerare;
}
