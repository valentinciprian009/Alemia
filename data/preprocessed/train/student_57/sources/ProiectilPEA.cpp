#include "ProiectilPEA.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"




int ProiectilPEA::getViteza()
{
	return this->viteza;
}

int ProiectilPEA::getDamage()
{
	return this->damage;
}

int ProiectilPEA::getRow()
{
	return this->y;
}

int ProiectilPEA::getCol()
{
	return this->x;
}

void ProiectilPEA::drawProiectil(int row, int col)
{

	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0xAA);
	conOut(row, col+1) << "-";
	

	SetConsoleTextAttribute(h, 7);
	conOut(row , col) << " ";
	
}

ProiectilPEA::ProiectilPEA(const ProiectilPEA& a)
{
	this->damage = a.damage;
	this->x = a.x;
	this->y = a.y;
}

void ProiectilPEA::move() {
	drawProiectil(this->y,this->x);
	this->x += 1;
	//function check zombie

}

