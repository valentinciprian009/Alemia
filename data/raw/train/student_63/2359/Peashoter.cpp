#include "Peashoter.h"
#include <time.h>


Peashoter::Peashoter(char img1, int x1, int y1, int color1, int hp):
	Plant(img1,x1, y1, color1, hp)
{
	Fire* one = new Fire(x1 + 3, y1, '+');
	bulets.push_back(one);
}

void Peashoter::update()
{
	Draw();
	for (auto bulet : bulets) {
		bulet->print();
		bulet->sterge();
		bulet->set_bullet_pos(bulet->get_bullet_pos());
	}
	if (bulets[0]->get_bullet_pos().X == 100) {
		for (auto i = 0; i < bulets.size() - 1; i++)
			bulets[i] = bulets[i + 1];
		bulets.pop_back();
	}
	if(clock()%12==0)
	{
		Fire* one = new Fire(getX()+3, getY(), '+');
		bulets.push_back(one);
	}
}

Peashoter::~Peashoter()
{
}
