#pragma once
#include <string>
class Entity_interface
{
public:
	virtual void draw() = 0;
	virtual void update(std::string) = 0;
};

