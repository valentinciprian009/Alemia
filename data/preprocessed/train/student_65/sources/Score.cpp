#include "Score.h"
Score* Score::instance = nullptr;
Score* Score::get_instance(int x,int y)
{	
	if (!instance)
		instance = new Score(x, y);
	return instance;
}

void Score::draw()
{
	image->draw();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->get_x() + 3, this->get_y() + 2) << "Score";
	conOut(this->get_x() + 4, this->get_y() + 4) << score;
}

void Score::update(std::string score)
{
	int punct;
	if(score!="")
		if (score[0]>=48&&score[0]<=57)
		{
			punct = stoi(score);
			this->score += punct;
		}
}

Score::~Score()
{
}
