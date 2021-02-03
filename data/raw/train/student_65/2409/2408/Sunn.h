#pragma once
#include "Entity.h"
class Sunn :
	public Entity
{
private:
public:
	Sunn():Entity("Sun"){}
	Sunn(int a,int b):Entity("Sun",a,b){}
	void draw();
	void update(std::string);
	~Sunn();
};

