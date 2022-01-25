#include "Shop.h"
Entity* Shop::buyed = nullptr;
void Shop::draw()
{
	for (auto it : shop_list)
		it->draw();
}

void Shop::update(std::string action)
{
	for(auto it:shop_list)
		if (it->is_clicked(action))
		{
			buyed = new Entity(it->get_entity());
		}
}

Entity* Shop::buy()
{
	return buyed;
}

Shop::~Shop()
{
}
