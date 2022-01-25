#pragma once
#include"CLog.h"

#define SUN_ID 0

enum TypeResource//ofera posibilitatea de a aduga mai multe resurse pe viitor
{
	SUN
};

class IResource
{
public:
	static IResource& createResource(int Value, TypeResource type);
	virtual void Display(int x, int y,int idElement, bool status_SunFlower) = 0;
	virtual int GetValue() = 0;
};

