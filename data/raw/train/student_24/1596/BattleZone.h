#pragma once
#include "ContainerRectangle.h"
#include "iDrawable.h"
#include "iZombie.h"
#include <vector>

class BattleZone
	:public iDrawable
{
protected:
	int nrLanes;
	int nrPlants;
	int nrZombies;

	const int nrCols = 9;
	std::vector<std::vector<ContainerRectangle<iBattleEntity*>*>> battleArea;


	void printUpZone(int color) const;
	void printMiddle(int color) const;
	void printDownZone(int color) const;
	void printOneLane(int color) const;
	
public:
	void clearLvl();
	ContainerRectangle<iBattleEntity*>* getRectangle(int x, int y);
	void printInterior() const;
	BattleZone(int lanes);
	~BattleZone() {};
	void print() const override;
	void triggerActions();
	ContainerRectangle<iBattleEntity*>* getNextRectangle(int x, int y);
	ContainerRectangle<iBattleEntity*>* getPrevRectangle(int x, int y);
	ContainerRectangle<iBattleEntity*>* getUpRectangle(int x, int y);
	ContainerRectangle<iBattleEntity*>* getDownRectangle(int x, int y);
	ContainerRectangle<iBattleEntity*>* getLastRectangle(int lane);
	void eraseDead() const;
	int getNrPlants() const;
	int getNrZombies() const;
	void setNrPlants(int plants);
	void setNrZombies(int zombies);
	bool checkLane(int lane) const;
	int getNrLanes() const;

};

