#pragma once
#include "Entity.h"
class Plant :
 public Entity
{
private:
	int health;
public:
	Plant();
	Plant(int x=0, int y =0,int healt=0,std::string name="Plant") :Entity(name,x,y),health(healt){}
	virtual void draw();
	virtual void update(std::string) ;
	~Plant();
};

