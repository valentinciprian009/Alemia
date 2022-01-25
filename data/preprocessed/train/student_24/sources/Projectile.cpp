#include "Projectile.h"

int Projectile::getDamage() const { return this->m_Damage; }

void Projectile::hit(iBattleEntity& injured)
{
	injured.setHealth(injured.getHealth() - m_Damage);
}

Projectile::Projectile(int x, int y, int step, int dmg) : movingEntity(x, y, step), m_Damage(dmg) {}

Projectile::~Projectile() { this->colors.clear(); }