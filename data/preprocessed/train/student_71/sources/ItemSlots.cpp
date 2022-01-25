#include "ItemSlots.h"
#include "Sunflower.h"
#include "Peashooter.h"
#include "SnowPea.h"
#include "Wallnut.h"
#include "CherryBomb.h"
#include "ConsoleOutput.h"

#define ITEMSLOT_0_ROW				11
#define ITEMSLOT_0_COL				 9

ItemSlots* ItemSlots::instance = NULL;

ItemSlots::ItemSlots()
{
	item[0] = new Sunflower;
	item[0]->draw(0);

	item[1] = new Peashooter;
	item[1]->draw(1);

	item[2] = new SnowPea;
	item[2]->draw(2);

	item[3] = new Wallnut;
	item[3]->draw(3);

	item[4] = new CherryBomb;
	item[4]->draw(4);

	displayTimers();
	displayPrices();
}

ItemSlots::~ItemSlots()
{
	delete item[0];
	delete item[1];
	delete item[2];
	delete item[3];
	delete item[4];

}

ItemSlots& ItemSlots::getInstance()
{
	if (!instance)
		instance = new ItemSlots;
	return *instance;
}

void ItemSlots::destroyInstance()
{
	delete instance;
}

void ItemSlots::displayTimers()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();

	conOut(ITEMSLOT_0_ROW, 1, 244) << item[0]->buyTimer;
	conOut(ITEMSLOT_0_ROW + 7, 1, 244) << item[1]->buyTimer;
	conOut(ITEMSLOT_0_ROW + 13, 1, 244) << item[2]->buyTimer;
	conOut(ITEMSLOT_0_ROW + 19, 1, 244) << item[3]->buyTimer;
	conOut(ITEMSLOT_0_ROW + 25, 1, 244) << item[4]->buyTimer;
}

void ItemSlots::displayPrices()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(ITEMSLOT_0_ROW + 3, ITEMSLOT_0_COL, 112) << item[0]->getPrice();
	conOut(ITEMSLOT_0_ROW + 9, ITEMSLOT_0_COL, 112) << item[1]->getPrice();
	conOut(ITEMSLOT_0_ROW + 15, ITEMSLOT_0_COL, 112) << item[2]->getPrice();
	conOut(ITEMSLOT_0_ROW + 21, ITEMSLOT_0_COL, 112) << item[3]->getPrice();
	conOut(ITEMSLOT_0_ROW + 27, ITEMSLOT_0_COL, 112) << item[4]->getPrice();
}

std::string ItemSlots::identity(int x)
{
	return item[x]->identity();
}
