#pragma once
#include "CTeren.h"
#include <vector>
class CTeren_2:
	public CTeren
{
	int level = 2;
public:
	virtual int getlLevel() { return level; }
	void draw();
	CTeren_2();
	~CTeren_2();
};

