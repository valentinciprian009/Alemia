#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)
#include "Projectile.h"
#include "ConsoleOutput.h"

class Pea :
	public virtual Projectile
{
public:
	Pea(int x, int y);
	~Pea();
	void print() const override;
};

#pragma warning(pop)