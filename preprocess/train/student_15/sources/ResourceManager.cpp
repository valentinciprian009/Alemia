#include "ResourceManager.h"
#include "ArenaSlide.h"
#include <sstream>

using namespace Arena;

ResourceManager::ResourceManager() : ITickable(SUNPERIOD)
{
	memset(active, 0, TERENX);
}

ResourceManager* ResourceManager::instance = nullptr;
ResourceManager* ResourceManager::getInstance()
{
	if (instance == nullptr)
		instance = new ResourceManager();
	return instance;
}

void ResourceManager::addToRate(int i)
{
	rate += i;
	changePeriod(SUNPERIOD / rate);
}

void ResourceManager::click(std::string s, int& sunCount, UserInterface::ConsoleOutput conOut)
{
	if (s[0] != 'D')
		return;
	int cy, cx;
	std::istringstream in(s.substr(2));
	in >> cx >> cy;
	if (cy >= HLINE || cx <= VLINE)
		return;
	int cell = (cx - VLINE - 1) / CELLX;
	if (active[cell] == 0)
		return;
	active[cell] = 0;
	Slide::clearZone(conOut, 
		VLINE + 1 + CELLX * cell, 0, 
		VLINE + CELLX * (cell + 1), HLINE - 1
	);
	sunCount++;
}

void ResourceManager::update(UserInterface::ConsoleOutput conOut)
{
	updateTime();
	this->conOut = conOut;
}

void Arena::ResourceManager::reset(int& sunCount)
{
	sunCount = 0;
	resetTime();
}

void Arena::ResourceManager::tickAction()
{
	int sum = 0, i;
	for (i = 0; i < TERENX; i++)
		sum += active[i];
	if (sum == TERENX)
		return;
	int r = rand() % (TERENX - sum);
	i = 0;
	while (active[i] == 1)
		i++;
	while (r > 0)
	{
		while (active[i] == 1)
			i++;
		r--, i++;
	}
	while (active[i] == 1)
		i++;
	active[i] = 1;
	Slide::drawAsciiArt("sun.txt", conOut, 0, VLINE + 1 + CELLX * i);
}
