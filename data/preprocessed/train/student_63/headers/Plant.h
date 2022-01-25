#pragma once
#include "Lifeform.h"
class Plant :
	public Lifeform
{ 
public:
	Plant(char img1, int x1, int y1, int color1, int hp);
	void update()override;

	~Plant();
};

