#pragma once
#include "Plant.h"
#include "Pea.h"
#include <vector>
#include "Time.h"
//#include "Terrain.h"
class Peashooter :
	public Plant
{
private:

	Time t;
public:
	std::vector<Pea*> proiectile;
	Peashooter(int x,int y, int health=50,std::string name="Peashooter"):Plant(x,y,health,name){
	}
	
	void draw();
	void update(std::string);
	~Peashooter();
};

