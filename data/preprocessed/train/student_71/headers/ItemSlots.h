#pragma once
#include "Plant.h"

class ItemSlots
{
	Plant* item[5];
	ItemSlots();
	~ItemSlots();
	static ItemSlots* instance;
public:
	static ItemSlots& getInstance();
	static void destroyInstance();
	void displayTimers(); // display the timer
	void displayPrices();
	std::string identity(int x);

	friend class GameSession;
};

