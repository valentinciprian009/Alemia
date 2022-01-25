#pragma once
#include "CTeren.h"
#include <vector>
class CTeren_3:
	public CTeren
{
	int level = 3;
public:
	virtual int getlLevel() { return level; }
	void draw();
	CTeren_3();
	~CTeren_3();
};

