#include "Box.h"



Box::Box()
{
}

void Box::Draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(upper_point.x, upper_point.y) << (char)CHR_STANGA_SUS;
	conOut(lower_point.x, upper_point.y) << (char)CHR_STANGA_JOS;
	conOut(upper_point.x, lower_point.y) << (char)CHR_DREAPTA_SUS;
	conOut(lower_point.x, lower_point.y) << (char)CHR_DREAPTA_JOS;
	for (int i = upper_point.x + 1; i < lower_point.x; i++)
	{
		conOut(i, upper_point.y) << (char)CHR_BARA_VERTICALA;
		conOut(i, lower_point.y) << (char)CHR_BARA_VERTICALA;
	}
	for (int i = upper_point.y + 1; i < lower_point.y; i++)
	{
		conOut(upper_point.x, i) << (char)CHR_BARA_ORIZONTALA;
		conOut(lower_point.x, i) << (char)CHR_BARA_ORIZONTALA;
	}
}


Box::~Box()
{
}
