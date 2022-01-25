#include "Container.h"
#define CHR_STANGA_SUS char(201)
#define CHR_STANGA_JOS 200
#define CHR_DREAPTA_SUS 187
#define CHR_DREAPTA_JOS 188
#define CHR_BARA_VERTICALA 186
#define CHR_BARA_ORIZONTALA 205
#define CHR_FRUIT 254

Container::Container()
{
}

Container::Container(Point &p1, Point &p2, Point &p3, Point &p4)
{
	this->corner1 = p1;
	this->corner2 = p2;
	this->corner3 = p3;
	this->corner4 = p4;

}

Container::~Container()
{
}

void Container::doMargin(UserInterface::ConsoleOutput &conOut) {
	//tre sa schimb x si y intre ele pt ca row l e y ul
	conOut(corner1.y, corner1.x) << char(CHR_STANGA_SUS);
	conOut(corner2.y, corner2.x) << char(CHR_DREAPTA_SUS);
	conOut(corner3.y, corner3.x) << char(CHR_STANGA_JOS);
	conOut(corner4.y, corner4.x) << char(CHR_DREAPTA_JOS);
	for (int horiz = corner1.x + 1; horiz < corner2.x; horiz++)
		conOut(corner1.y, horiz) << char(CHR_BARA_ORIZONTALA);
	for (int horiz = corner3.x + 1; horiz < corner4.x; horiz++)
		conOut(corner3.y, horiz) << char(CHR_BARA_ORIZONTALA);
	for (int ver = corner1.y+1; ver < corner3.y; ver++)
		conOut(ver, corner1.x) << char(CHR_BARA_VERTICALA);
	for (int ver = corner2.y+1; ver < corner4.y; ver++)
		conOut(ver, corner2.x) << char(CHR_BARA_VERTICALA);
}

Point& Container::getCorner1() {
	return corner1;
}