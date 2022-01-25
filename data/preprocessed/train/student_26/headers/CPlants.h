#pragma once
#include "CEntity.h"
using namespace std;
class CPlants :
	public CEntity
{
	
public:
	int hp;
	int price;
	string name;
	void draw();
	virtual void deletepos();
	CPlants();
	~CPlants();
};

