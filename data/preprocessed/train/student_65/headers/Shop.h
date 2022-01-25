#pragma once
#include "Entity.h"
#include "Zone.h"
#include "vector"
#include "Cherry_Bomb.h"
#include "Peashooter.h"
#include"Sunflower.h"
#include "Snow_Pea.h"
#include "Wall_nut.h"
class Shop :
	public Entity
{
private:
	std::vector<Zone*> shop_list;
	static Entity* buyed;
public:
	Shop():Entity("Shop")
	{
		for (int i = 0; i < 5; i++)
			shop_list.push_back(new Zone(this->get_x()+i*7,this->get_y()));
	}
	Shop(int x=0,int y=0):Entity("Shop",x,y)
	{
		buyed = nullptr;
		shop_list.push_back(new Zone(this->get_x(), this->get_y()));
		shop_list[0]->set_entity(new Peashooter(shop_list[0]->get_x()+1, shop_list[0]->get_y()+5));
		shop_list.push_back(new Zone(this->get_x() + 1 * 6, this->get_y()));
		shop_list[1]->set_entity(new Snow_Pea(shop_list[1]->get_x()+1, shop_list[1]->get_y()+1));
		shop_list.push_back(new Zone(this->get_x() + 2 * 6, this->get_y()));
		shop_list[2]->set_entity(new Wall_nut(shop_list[2]->get_x()+1, shop_list[2]->get_y()+1));
		shop_list.push_back(new Zone(this->get_x() + 3 * 6, this->get_y()));
		shop_list[3]->set_entity(new Cherry_Bomb(shop_list[3]->get_x()+1, shop_list[3]->get_y()+1));
		shop_list.push_back(new Zone(this->get_x() + 4 * 6, this->get_y()));
		shop_list[4]->set_entity(new Sunflower(shop_list[4]->get_x()+1, shop_list[4]->get_y()+5));
	}
	void draw();
	void update(std::string);
	static Entity* buy();
	~Shop();
};

