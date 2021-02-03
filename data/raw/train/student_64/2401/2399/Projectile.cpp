#include "Projectile.h"
#include "Terrain.h"
#include "Entities.h"
#include <chrono>

using namespace std::chrono;


Projectiles::Projectiles()
{
	
}


Projectiles::~Projectiles()
{
}

void Projectiles::Move(std::chrono::system_clock::time_point& begin, std::chrono::system_clock::time_point& begin1)
{
	UserInterface::ConsoleOutput conout = UserInterface::ConsoleOutput::getInstance();

	auto end = std::chrono::system_clock::now();
	if (std::chrono::duration_cast<seconds>(end - begin).count() > 3)
	{
		begin = end;
		this->vector_proiectile.push_back(this->x);
	}

	auto end1 = std::chrono::system_clock::now();
	if (std::chrono::duration_cast<milliseconds>(end1 - begin1).count() > 250)
	{
		begin1 = end1;
		for (auto it = this->vector_proiectile.begin(); it != this->vector_proiectile.end(); it++)
		{
			if (*it >= 53)
			{
				conout(this->y + 3, *it + 6) << "   ";
				this->vector_proiectile.erase(it);
				break;
			}
			else
			{
				(*it)++;
				conout(this->y + 3, *it + 6) << "  @";
			}

		}
	}
}
