#pragma once
#include <vector>
#include "CTeren.h"
class CTeren_1:
	public CTeren
{
	int level = 1;
public:
	virtual int getlLevel() { return level; }
	void draw();
	CTeren_1();
	~CTeren_1();
};

