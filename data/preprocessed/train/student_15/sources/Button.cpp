#include "Button.h"
#include "Slide.h"
#include <sstream>

Button::Button(Slide* pr) : parent(pr)
{
}

void Button::draw(UserInterface::ConsoleOutput conOut)
{
	Slide::drawBox(conOut, x, y, width, height);
	int mx = x + 1 + (width - text.size()) / 2;
	int my = y + 1 + height / 2;
	if (text[0] != 8)
		conOut(my, mx) << text;
	else
		conOut(my, mx) << "<";
}

void Button::click(std::string userAction)
{
	std::istringstream in(userAction);
	int mx, my; char a;
	in >> a >> mx >> my;
	if (a != 'D')
		return;
	if (mx >= x && mx <= x + width && my >= y && my <= y + height)
		pushFunction();
	
}


Button::~Button()
{
}
