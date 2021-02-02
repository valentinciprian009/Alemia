#pragma once
#include"IResource.h"


class CResource :public IResource
{
	int Value_;
	TypeResource type_;
public:
	CResource(int Value, TypeResource type);
	virtual ~CResource();
	virtual void Display( int x, int y, int idElement, bool status_SunFlower);
	int GetValue();
};