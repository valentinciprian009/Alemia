#include "BattleEntity.h"

BattleEntity::BattleEntity(int x, int y, int health) : Entity(x, y), m_Health(health) {}

BattleEntity::~BattleEntity() { this->colors.clear(); }

int BattleEntity::getHealth() const { return this->m_Health; }

void BattleEntity::setHealth(const int& newHealth) { this->m_Health = newHealth; }
