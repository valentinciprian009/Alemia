#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "entity.h"
class Plante:
	public entity
{
protected:
	int cost;
	int nr_max_muscaturi;
public:
	virtual void pune_planta() = 0;
	Plante();
	~Plante();
};

