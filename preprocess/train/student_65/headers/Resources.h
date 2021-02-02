#pragma once
#include "Entity.h"
#include "Zone.h"
#include <vector>
class Resources :
	public Entity
{
private:
	std::vector<Zone*> sun_list;
public:
	Resources():Entity("Resources")
	{
		for (int i = 0; i < 5; i++)
			sun_list.push_back(new Zone(this->get_x(), this->get_y()+i*11));
	}
	Resources(int x, int y) :Entity("Resources", x, y) {
		sun_list.push_back(new Zone(this->get_x(), this->get_y()));
		sun_list.push_back(new Zone(this->get_x(), this->get_y() + 1 *11));
		sun_list.push_back(new Zone(this->get_x(), this->get_y() + 2 * 11));
		sun_list.push_back(new Zone(this->get_x(), this->get_y() + 3 * 11));
		sun_list.push_back(new Zone(this->get_x(), this->get_y() + 4 * 11));
	}
	bool is_full();
	void draw();
	void update(std::string);
	~Resources();
};

