#include "Zombie.h"

#include "BattleField.h"

Zombie::Zombie()
{
	name = "Zombie";
	Tip_Zombie type = SIMPLE_ZOMBIE;
}


void Zombie::actionare(BattleField * f)
{
	Field *field = f->getField(y, x - 10);
	if (f->getField(y, x - 10)->getCharacter().getType() == PROIECTIL)
	{
		this->life = this->life - 10;
	}

}

Zombie::~Zombie()
{
}
