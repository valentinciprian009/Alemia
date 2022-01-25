#pragma once
#include "Entity.h"
#include "ConsoleInput.h"
class Zone :
	public Entity
{
private:
	Entity* caracter;
	bool filled;
	int x, y;
public:
	Zone();
	Zone(int x=0, int y=0, Entity* val = nullptr):Entity("Zone",x,y)
	{
		this->caracter = val;
		if(this->caracter)
			this->caracter->set_position(x + 2, y + 2);
		this->x = x;
		this ->y = y;
		filled = 0;
	}
	void set_free();
	void set_filled();
	bool is_full();
	void set_entity(Entity* val);
	Entity& get_entity();
	void draw();
	void update(std::string);
	bool is_clicked(std::string);
	~Zone();
};

