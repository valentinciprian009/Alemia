#include "Peashooter.h"
#include "ConsoleOutput.h"
#include "Pea.h"
#include <chrono>
#include <thread>
using namespace std::chrono;

Peashooter::Peashooter()
{
}


void Peashooter::draw(int x, int y)
{
	Pea pea;
	
	
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << char(239);
	conOut(x + 1, y) << char(219) << char(198);
	conOut(x + 2, y) << char(207);
	
	
	}

void Peashooter::shoot(int x, int y, Pea pea)
{
	
	
		int x1 = x;
		int y1 = y;


		while (true) {
			static auto begin = steady_clock::now();
			auto end = steady_clock::now();
			if (duration_cast<milliseconds>(end - begin).count() > 1000)
			{
				begin = end;

				pea.draw(x1, y1);
				y1 += 5;


			}

		
	}
}






Peashooter::~Peashooter()
{
}
