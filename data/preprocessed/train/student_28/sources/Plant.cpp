#include "Plant.h"
#include <iostream>
Plant::Plant()
{
	setcord(0, 0);
}
void Plant::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}
void Plant::setCost(int value)
{
	cost = value;
}
void Plant::setLife(int viata)
{
	life = life-viata;
}
void Plant::setRate(int time)
{
	rate = time;
}
void Plant::setslow()
{
	slow = true;
}
int Plant::getCost()
{
	return cost;
}
int Plant::getLife()
{
	return life;
}
bool Plant::getSlow()
{
	return slow;
}
double Plant::getRate()
{
	return rate;
}
COORD Plant::getcord()
{
	return pos;
}
void Plant::setcord(int x, int y)
{
	pos.X = x;
	pos.Y = y;
}
bullet* Plant::attack()
{

	return new bullet(0, 0);
}
void Plant::setype(char diff)
{
	type = diff;
}
char Plant::getype()
{
	return type;
}
void Plant::setcreated(int buff)
{
	created = buff;

}
int Plant::getcreated()
{
	return created;
}
void Plant::sterge(COORD num)
{
	aprox_cooord(num.X, num.Y);
	for (int j = 0; j < 3; j++)
	{
		gotoxy(num.X, num.Y + j);
		for (int i = 1; i < 6; i++)
			std::cout << " ";
	}
} 
void Plant::aprox_cooord(short& x, short& y)
{
	int init_x = 43, init_y = 9;// punctele cel mai din dreapta sus 
	int aux_x = x - init_x;
	int aux_y = y - init_y;
	aux_x = aux_x / 7;//latura pe x + 1(bordura)
	aux_y = aux_y / 4;// latura pe y +1(bordura
	x = init_x + aux_x * 7 + 1;// ca sa nu fie pe margine
	y = init_y + aux_y * 4;// 
}
void Plant::afiseaza(COORD pos)
{
	;


}
void Plant::drawpixel9(unsigned char x, unsigned char y, unsigned char Color)
{
	setcolor9(Color);
	gotoxy(x, y); std::cout<<"Û";
}
void Plant::setcolor9(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}