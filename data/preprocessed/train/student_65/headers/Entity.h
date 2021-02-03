#pragma once
#include "Entity_interface.h"
#include "ConsoleOutput.h"
#include <string>
class Entity :
	public Entity_interface
{
private:
	std::string name;
	int x, y;
public:
	Entity();
	Entity(std::string nume,int a=0,int b=0) :name(nume),x(a),y(b){}
	Entity(const Entity& ent);
	virtual void draw();
	virtual void update(std::string);
	void set_position(int, int);
	int get_x();
	std::string get_name();
	int	 get_y();
	virtual ~Entity();
};

