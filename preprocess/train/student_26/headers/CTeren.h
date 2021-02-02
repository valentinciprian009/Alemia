#pragma once
#include "CEntity.h"
#include <vector>
class CTeren:
	public CEntity
{
	int level;
public:
	
	//static vector<vector<CEntity*>> matrice;
	virtual void draw();
	CTeren(int);
	int getlLevel() { return level; }
	CTeren();
	~CTeren();
};

