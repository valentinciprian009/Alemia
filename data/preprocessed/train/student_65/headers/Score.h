#pragma once
#include "Entity.h"
#include "Zone.h"
class Score :
	public Entity
{
private:
	int score;
	Zone* image;
public:
	Score() :Entity("Score") { 
		score = 0;
		image = new Zone(this->get_x(), this->get_y()); 
	}
	Score(int x, int y) :Entity("Score", x, y) {
		image = new Zone(this->get_x(), this->get_y());
	}
	static Score* instance;
	static Score* get_instance(int x=0,int y=0);
	void draw();
	void update(std::string);
	~Score();
};

