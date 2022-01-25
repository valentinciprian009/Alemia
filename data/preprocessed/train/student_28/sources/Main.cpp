#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <iostream>
#include <vector>
#include "terrain.h"
#include "bullet.h"
#include "peashooter.h"
#include "sun.h"
#include "sunflower.h"
#include "RGame.h"
#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}		
	}
}
void drawpixel2(unsigned char x, unsigned char y, unsigned char Color, char character);
void drawframe(unsigned x, unsigned y, unsigned sx, unsigned sy, const char text_[]);
void drawwindow(unsigned x, unsigned y, unsigned sx, unsigned sy, unsigned char bkcol, const char text_[]);
void gotoxy(int x, int y);
void setcolor(WORD color);
void drawpixel(unsigned char x, unsigned char y, unsigned char Color);
void drawline(int x0, int y0, int x1, int y1, int color);
void drawfilledrectangle(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char bkcol);
void drawcircle(int x, int y, int a, int b, int color);
void Menu(std::string username)
{
	gotoxy(145, 1);
	std::cout << "player ";
	drawframe(155, 0, 170, 2, username.c_str());
	drawframe(75, 17, 95, 19, "START");
	drawframe(75, 21, 95, 23, "options");
	drawframe(75, 25, 95, 27, "EXIT");

}
void create_map(terrain map, int z)// z reprezinta liniile pe unde vin zombii(70)
{
	int x, y, row, width, level;
	map.setlevel(z);
	if (z == 3)
	{
		z = z + 2;
	}
	if (z == 2)
	{
		z = z + 1;
	}
	
	x = map.getx_grass();
	y = map.gety_grass();
	row = map.getx_space();
	width = map.gety_space();
	int y1;
	//grass
	for (int i = 0; i < z; i++)
	{
		y1 = y + i * width;
		drawline(x, y1, x + 63, y1, 2);
		for (int j = 0; j < 67; j += row)
		{
			drawline(x + j, y1, x + j, y1 + width, 2);
		}
		drawline(x, y1, x + 63, y1, 2);
	}
	drawline(x, y1 + width, x + 63, y1 + width, 2);
	//sun
	for (int j = 0; j < 67; j += row)
	{
		drawline(x + j, y - width, x + j, y - 1, 6);
	}
	drawline(x, y - width - 1, x + 63, y - width - 1, 6);
	drawline(x, y - 1, x + 63, y - 1, 6);
	//plants
	for (int i = 0; i < 5; i++)
	{

		y1 = y + i * width;
		drawline(x - row, y1, x - 1, y1, 9);
		drawline(x - row - 1, y1, x - row - 1, y1 + width, 9);
		drawline(x - 1, y1, x - 1, y1 + width, 9);
	}
	drawline(x - row, y1 + width, x - 1, y1 + width, 9);
}
void cls();
int count(int& i)
{
	if (i > 4)
		i = 0;
	i++;
	return i;
}
std::vector<bullet*>ammo;
std::vector<bullet*>::iterator it;
void attack(terrain map)
{
	int x = 51;
	int y = 11;
	
	/*bullet ammo1(51, 11);
	ammo.push_back(ammo1);
	bullet ammo2(52, 15);
	ammo.push_back(ammo2);
	*/
	COORD num;
	int i = 0;
	while (true)
	{
		if (ammo.size() == 0)
			break;
		//cls();
		create_map(map, 5);
		/*if (i == 3)
			if (ammo.size() < 30)
			{
				bullet ammo3(51, 21);
				ammo.push_back(ammo3);*/
				//ammo.push_back(ammo2);

			/*if (count(i) == 4)
				if (ammo.size() < 30)
				{

					ammo.push_back(ammo1);
				}*/
		for (it = ammo.begin(); it != ammo.end(); it++)
		{
			num = (*it)->getcord();
			num.X++;
			if (num.X < 115)
			{
				(*it)->sterge();
				(*it)->setcord(num.X, num.Y);
				(*it)->afiseaza();
			}
			else
			{
				(*it)->sterge();
				int pop = it - ammo.begin();

				ammo.erase(it);
				it = ammo.begin() + pop;
				//ammo.push_back(*it);
				//ammo.erase(ammo.begin() +ammo.size()-1);
				gotoxy(0, 0);
				std::cout << ammo.size();
			}
			Sleep(6);
			/*if (ammo.size() == 1)
				break;*/
		}
		if (ammo.size() == 1)
		{
			it = ammo.begin();

			if (num.X < 115)
			{
				(*it)->sterge();
				(*it)->setcord(num.X, num.Y);
				(*it)->afiseaza();
			}
			else
			{
				it = ammo.begin();
				(*it)->sterge();
				ammo.erase(ammo.begin());
			}
		}
	}
}
std::string Username()
{
	drawframe(75, 20, 95, 22, " ");
	gotoxy(80, 21);
	std::string buff;
	std::cin >> buff;
	return buff;

}
void aprox_coord(int& x, int& y)
{
	int init_x = 43, init_y = 9;// punctele cel mai din dreapta sus (al careului verde)
	int aux_x = x - init_x;
	int aux_y = y - init_y;
	aux_x = aux_x / 7;//latura pe x + 1(bordura)
	aux_y = aux_y / 4;// latura pe y +1(bordura
	x = init_x + aux_x * 7+1;// ca sa nu fie pe margine
	y = init_y + aux_y * 4+2;// +2 ca sa fie in patratica cea mai de jos din patratul negru 
}
std::string take_plant(std::pair<int, int> action, int &valid )
{
	std::string plant=" ";

	if ((action.first >= 43 && action.first <= 48) && (action.second >= 9 && action.second <= 11))
	{
		plant="soare";
		valid = 1;
			return plant;
	}
	if ((action.first >= 43 && action.first <= 48) && (action.second >= 13 && action.second <= 15))
	{
		plant = "pea";
		valid = 1;
		return plant;
	}
	if ((action.first >= 43 && action.first <= 48) && (action.second >= 17 && action.second <= 19))
	{
		plant = "frozen";
		valid = 1;
		return plant;
	}
	if ((action.first >= 43 && action.first <= 48) && (action.second >= 21 && action.second <= 23))
	{
		plant = "wall";
		valid = 1;
		return plant;
	}
	if ((action.first >= 43 && action.first <= 48) && (action.second >= 25 && action.second <= 27))
	{
		plant = "bomb";
		valid = 1;
		return plant;
	}
	return plant;
}
void put_plant(std::pair<int, int> action, std::string plant,int &valid)
{
	if ((action.first >= 51 && action.first <= 112) && (action.second >= 9 && action.second <= 27))
	{	
		if (plant == "soare")
		{
			aprox_coord(action.first, action.second);
			gotoxy(action.first, action.second);
			std::cout << "s";
			valid = 0;
		}
		if (plant == "pea")
		{
			aprox_coord(action.first, action.second);
			gotoxy(action.first, action.second);
			std::cout << "p";
			valid = 0;
		}
		if (plant == "frozen")
		{
			aprox_coord(action.first, action.second);
			gotoxy(action.first, action.second);
			std::cout << "f";
			valid = 0;
		}
		if (plant == "wall")
		{
			aprox_coord(action.first, action.second);
			gotoxy(action.first, action.second);
			std::cout << "w";
			valid = 0;
		}
		if (plant == "bomb")
		{
			aprox_coord(action.first, action.second);
			gotoxy(action.first, action.second);
			std::cout << "cb";
			valid = 0;
		}
	}
}
int option()
{
	gotoxy(80, 17);
	std::cout << "Introdu nr dificultatea(1,2,3) apoi dublu enter";
	drawframe(75, 20, 95, 22, " ");
	gotoxy(80, 21);
	int buff;
	std::cin >> buff;
	cls();
	return buff;
}
int level = 1;
int main(void)
{

	std::string player;
	player = Username();
	cls();
	
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	//std::pair<int, int> action;
	for (float i = 0; i < 50000; i += 0.01)
	{
		doLoadingBar();
	}
	cls();
	std::pair<int, int> action;
	while (true)
	{

		action = conIn.getUserActions();
		Menu(player);
		gotoxy(0, 0);
		//std::cout << action.first << " " << action.second << " ";
		if ((action.first > 75 && action.first < 95) && (action.second >= 17 && action.second <= 19))
		{
			gotoxy(0, 0);
			cls();
			RGame game(level);
			
		}
		if ((action.first > 75 && action.first < 95) && (action.second >= 21 && action.second <= 23))
		{
			gotoxy(0, 0);
			cls();
			level = option();
			Menu(player);
		}
		if ((action.first > 75 && action.first < 95) && (action.second >= 25 && action.second <= 27))
		{
			gotoxy(0, 0);
			std::cout << "s-a apasat exit " << action.first << "  " << action.second << "      ";
			break;
		}
		if (action.first == 0 && action.second == 3)
			exit(1);
		//conOut(41, 2) << action;
	}
}

	//}
	//std::vector<Plant*>plants;
	//std::vector<Plant*>::iterator it1;
	//Plant* ob = new sunflower(53, 25);
	//Plant* ob1 = new peashooter(53, 21);
	//Plant* ob2 = new peashooter(53, 17);
	//
	//plants.push_back(ob);
	//plants.push_back(ob1);
	//plants.push_back(ob2);
	//COORD num;
	//Sleep(60);
	//for (it1 = plants.begin(); it1 != plants.end(); it1++)
	//{
	//	num = (*it1)->getcord();
	//	if (num.X == 53 && num.Y == 17)
	//	{
	//		plants.erase(it1);
	//		gotoxy(1, 0);
	//		std::cout << plants.size();
	//		break;
	//	}
	//	
	//	/*if ((*it1)->getype() == 'P')
	//	ammo.push_back((*it1)->attack());*/
	//}
	//
	//attack(map);
	//plants.push_back(ob);
	//plants.push_back(ob1);
	//plants.push_back(ob2);
	//for (it1 = plants.begin(); it1 != plants.end(); it1++)
	//{
	//	if ((*it1)->getype() == 'P')
	//		ammo.push_back((*it1)->attack());
	//	//Sleep(60);
	//}
	//attack(map);
	//int valid = 0;
	//std::string test;
	////pun plante
	//std::vector <sun>light;
	//int i = 0;
	//while (i<150)
	//{
	//	i++;
	//	action = conIn.getUserActions();
	//	if(valid==0)
	//	 test = take_plant(action,valid);
	//	if(valid==1)
	//	put_plant(action, test,valid);
	//	sun wave;
	//	light.push_back(wave);
	//	Sleep(60);
	//    
	//}
	//for (auto it = light.begin(); it != light.end(); it++)
	//{
	//	(*it).sterge((*it).getcord());
	//	//int pop = it - light.begin();
	//	light.erase(it);
	//	it = light.begin();
	//	Sleep(600);
	//}
	//
	//return 0;
//}
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}
void drawpixel2(unsigned char x, unsigned char y, unsigned char Color, char character) {
	setcolor(Color);
	gotoxy(x, y); printf("%c", character);
}
void setcolor(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}
void drawpixel(unsigned char x, unsigned char y, unsigned char Color) {
	setcolor(Color);
	gotoxy(x, y); printf("Û");
}
void drawline(int x0, int y0, int x1, int y1, int color) {
	int pix = color;
	int dy = y1 - y0;
	int dx = x1 - x0;
	int stepx, stepy;

	if (dy < 0) { dy = -dy;  stepy = -1; }
	else { stepy = 1; }
	if (dx < 0) { dx = -dx;  stepx = -1; }
	else { stepx = 1; }
	dy <<= 1;                                                  // dy is now 2*dy
	dx <<= 1;                                                  // dx is now 2*dx

	drawpixel(x0, y0, pix);
	if (dx > dy) {
		int fraction = dy - (dx >> 1);                         // same as 2*dy - dx
		while (x0 != x1) {
			if (fraction >= 0) {
				y0 += stepy;
				fraction -= dx;                                // same as fraction -= 2*dx
			}
			x0 += stepx;
			fraction += dy;                                    // same as fraction -= 2*dy
			drawpixel(x0, y0, pix);
		}
	}
	else {
		int fraction = dx - (dy >> 1);
		while (y0 != y1) {
			if (fraction >= 0) {
				x0 += stepx;
				fraction -= dy;
			}
			y0 += stepy;
			fraction += dx;
			drawpixel(x0, y0, pix);
		}
	}
}
void drawfilledrectangle(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char bkcol) {
	int x, y;
	setcolor(bkcol);                       //Set to color bkcol

	for (y = y1; y < y2; y++) {                    //Fill second Region Loop
		for (x = x1; x < x2; x++) {              //Fill first region Loop
			gotoxy(x, y); drawpixel(x, y, bkcol);      //Draw Solid space
		}
	}
}
void drawframe(unsigned x, unsigned y, unsigned sx, unsigned sy, const char text_[]) {
	unsigned i, j, m; {

		m = (sx - x);                       //differential
		j = m / 2;                          //adjust
		j = j - 1;                          //more adjustment
		gotoxy(x, y); printf("É");       //Top left corner of drawframe
		gotoxy(sx, y); printf("»");      //Top right corner of drawframe
		gotoxy(x, sy); printf("È");      //Bottom left corner of drawframe
		gotoxy(sx, sy); printf("¼");     //Bottom right corner of drawframe

		for (i = x + 1; i < sx; i++) {
			gotoxy(i, y); printf("Í");     // Top horizontol line
			gotoxy(i, sy); printf("Í");    // Bottom Horizontal line
		}

		for (i = y + 1; i < sy; i++) {
			gotoxy(x, i); printf("º");     //Left Vertical line
			gotoxy(sx, i); printf("º");    //Right Vertical Line
		}
		if (strlen(text_) < 7)
		{
			gotoxy(x + j - 1, y + 1); printf(text_);
		} //put Title
		else { gotoxy(x + j / 2, y + 1); printf(text_); }

	}
}
void drawwindow(unsigned x, unsigned y, unsigned sx, unsigned sy, unsigned char bkcol, const char text_[]) {
	drawfilledrectangle(x, y, sx, sy, bkcol);
	drawframe(x, y, sx, sy, text_);
}
void drawcircle(int x, int y, int a, int b, int color) {
	int wx, wy;
	int thresh;
	int asq = a * a;
	int bsq = b * b;
	int xa, ya;

	drawpixel(x, y + b, color);
	drawpixel(x, y - b, color);

	wx = 0;
	wy = b;
	xa = 0;
	ya = asq * 2 * b;
	thresh = asq / 4 - asq * b;

	for (;;) {
		thresh += xa + bsq;

		if (thresh >= 0) {
			ya -= asq * 2;
			thresh -= ya;
			wy--;
		}

		xa += bsq * 2;
		wx++;

		if (xa >= ya)
			break;


		drawpixel(x + wx, y - wy, color);
		drawpixel(x - wx, y - wy, color);
		drawpixel(x + wx, y + wy, color);
		drawpixel(x - wx, y + wy, color);
	}

	drawpixel(x + a, y, color);
	drawpixel(x - a, y, color);

	wx = a;
	wy = 0;
	xa = bsq * 2 * a;

	ya = 0;
	thresh = bsq / 4 - bsq * a;

	for (;;) {
		thresh += ya + asq;

		if (thresh >= 0) {
			xa -= bsq * 2;
			thresh = thresh - xa;
			wx--;
		}

		ya += asq * 2;
		wy++;

		if (ya > xa)
			break;

		drawpixel(x + wx, y - wy, color);
		drawpixel(x - wx, y - wy, color);
		drawpixel(x + wx, y + wy, color);
		drawpixel(x - wx, y + wy, color);
	}
}
void cls()
{
	gotoxy(0, 0);
	for (int j = 0; j < 100; j++)
		std::cout << std::string(100, ' ');
	gotoxy(0, 0);
}