#pragma once
#include <iostream>
#include "Slide.h"

class Button
{
protected:
	std::string text;
	int width;
	int height;
	int x, y;

protected:
	Slide* parent;

private:
	virtual void pushFunction() = 0;
public:
	Button(Slide* parent);
	void draw(UserInterface::ConsoleOutput conOut);
	void click(std::string userAction);
	~Button();
};

