#pragma once
#pragma warning(push)
#pragma warning(disable : 4250)

#include <Windows.h>
#include"ConsoleOutput.h"
#include "Resource.h"

class Sun :
	public virtual Resource
{
public:
	Sun(int x, int y, int val);
	void print() const override;
	~Sun() override;
};

#pragma warning(pop)