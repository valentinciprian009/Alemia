#include "movingEntity.h"

movingEntity::movingEntity(int x, int y, int step) : Entity(x, y), m_Step(step) {}

movingEntity::~movingEntity() { this->colors.clear(); }

int movingEntity::getStep() const { return this->m_Step; }

void movingEntity::move() { this->coordY += m_Step; }