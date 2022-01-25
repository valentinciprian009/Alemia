#include "Resource.h"

Resource::Resource(int x, int y, int val) : Entity(x, y), m_Value(val) {}

int Resource::getValue() const
{
	return m_Value;
}

Resource::~Resource()
{
	this->colors.clear();
}