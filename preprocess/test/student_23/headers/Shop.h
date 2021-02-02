#pragma once
#include "Plant.h"
#include "PeaShooter.h"
#include "GAME.h"

class Shop
{
private:
	Shop() {};
	~Shop() {};
	Shop(const Shop&) {};
	static Shop* instance;
	bool peeSClicked;
	bool frozenClicked;
	bool wallNutClicked;
	bool sunFlowerClicked;
	bool cherryBombClicked;
public:
	static Shop& getInstancee(void);
	static void gestroyInstance();
	void displayShop();
	bool PeeShooterClicked(string action);
	void setpeeSClicked(bool val) { this->peeSClicked = val; };
	bool getpeeSClicked() { return this->peeSClicked; };
	bool frozenPeaClicked(string action);
	void setFrozenClicked(bool val) { this->frozenClicked = val; };
	bool getFrozenClicked() { return this->frozenClicked; };
	bool WallNutClicked(string action);
	void setWallNutClicked(bool val) { this->wallNutClicked = val; };
	bool getWallNutClicked() { return this->wallNutClicked; };
	bool SunFlowerClicked(string action);
	void setSunFlowerClicked(bool val) { this->sunFlowerClicked = val; };
	bool getSunFlowerClicked() { return this->sunFlowerClicked; };
	bool CherryBombClicked(string action);
	void setCherryBombClicked(bool val) { this->cherryBombClicked = val; };
	bool getCherryBombClicked() { return this->cherryBombClicked; };
};