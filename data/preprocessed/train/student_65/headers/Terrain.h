#pragma once
#include "Entity.h"
#include "Zone.h"
#include <vector>
#include "Zombie.h"
#include "Time.h"
class Terrain :
	public Entity
{
private:
	 std::vector<std::vector<Zone*>> matrice;
	
	Time t;
public:
	static std::vector<Zombie*>zombie;
	Terrain():Entity("Terrain")
	{
		for (int i = 0; i < 5; i++)
		{
			std::vector<Zone*> aux;
			for (int j = 0; j < 8; j++)
				aux.push_back(new Zone(this->get_x() + i * 6, this->get_y() +j * 11));
			matrice.push_back(aux);
		}
	}
	Terrain(int x,int y) :Entity("Terrain",x,y)
	{
		for (int i = 0; i < 5; i++)
		{
			std::vector<Zone*> aux;
			for (int j = 0; j < 8; j++)
				aux.push_back(new Zone(this->get_x() + i * 6, this->get_y() + j * 11));
			matrice.push_back(aux);
		}
	}
	void draw();
	void update(std::string);
	void create_zombie(std::string);
	void check_collide();
	~Terrain();
};

