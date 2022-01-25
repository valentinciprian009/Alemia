#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)
#include "Projectile.h"
#include "ConsoleOutput.h"

class FrozenPea :
	public virtual Projectile
{
public:
	FrozenPea(int x, int y);
	~FrozenPea();
	void print() const override;
};

#pragma warning(pop)