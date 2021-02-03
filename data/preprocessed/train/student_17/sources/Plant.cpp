#include "Plant.h"
#include <chrono>

using namespace std::chrono;

void Peashooter::Print(Point &pt) {
	pea.builtAround = builtAround; //pozitia initiala a proiectilului
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(pt.gety(), pt.getx()) << "P";
	conOut(pt.gety()+1, pt.getx()) << "S";
}

void Peashooter::Delete(Point &pt) {
	//Point p(0, 0);
	//builtAround = p;
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(pt.gety(), pt.getx()) << " ";
	conOut(pt.gety() + 1, pt.getx()) << " ";
}

void Peashooter::Draw(SegmentedContainer &c3) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int x = c3.getCorner1().getx() + int(15 / 2);
	int y = c3.getCorner1().gety() + 0*5 + int(5 / 2); //in primul cadran e peashooter
	conOut(y, x-1)<< "PS";
	conOut(y + 1, x-1) << this->cost;
}

void SunFlower::Print(Point &pt) {
	builtAround = pt;
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(pt.gety(), pt.getx()) << "S";
	conOut(pt.gety() + 1, pt.getx()) << "F";
}

void SunFlower::Delete(Point &pt) {
	//Point p(0, 0);
	//builtAround = p;
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(pt.gety(), pt.getx()) << " ";
	conOut(pt.gety() + 1, pt.getx()) << " ";
}

void SunFlower::Draw(SegmentedContainer &c3) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int x = c3.getCorner1().getx() + int(15 / 2);
	int y = c3.getCorner1().gety() + 1*5 + int(5 / 2); //in al doilea e sunflower
	conOut(y, x-1) << "SF";
	conOut(y + 1, x-1) << this->cost;
}