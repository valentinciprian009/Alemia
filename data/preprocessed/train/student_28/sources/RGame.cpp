#include "RGame.h"
using namespace std;
RGame::RGame()
{
	;
}
RGame::RGame(int level)
{
    UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	pair<int, int> action = conIn.getUserActions();
	int valid = 0;
	COORD pos;
	string plant_type="";
	
	create_map(map,level);
	int checkpoint=0;
	
	srand(time(NULL));
	while (true)
	{
		if (timp % 40 == 0)
		{//111 ,9
			Monster* zbuf;
			int n = rand() % level + 1;
			if (n == 1)
			{
				zbuf = new Monster(111, 9);
				monsters.push_back(zbuf);
			}
			if (n == 2)
			{
				zbuf = new Monster(111, 13);
				monsters.push_back(zbuf);
			}
			if (n == 3)
			{
				zbuf = new Monster(111, 17);
				monsters.push_back(zbuf);
			}
			if (n == 4)
			{
				zbuf = new Monster(111, 21);
				monsters.push_back(zbuf);
			}
			if (n == 5)
			{
				zbuf = new Monster(111, 25);
				monsters.push_back(zbuf);
			}
		}
		if (timp % 100 == 0)
		{//111 ,9
			Monster* zbuf;
			int n = rand() % level + 1;
			if (n == 1)
			{
				zbuf = new bucketM(111, 9);
				monsters.push_back(zbuf);
			}
			if (n == 2)
			{
				zbuf = new Monster(111, 13);
				monsters.push_back(zbuf);
			}
			if (n == 3)
			{
				zbuf = new Monster(111, 17);
				monsters.push_back(zbuf);
			}
			if (n == 4)
			{
				zbuf = new Monster(111, 21);
				monsters.push_back(zbuf);
			}
			if (n == 5)
			{
				zbuf = new Monster(111, 25);
				monsters.push_back(zbuf);
			}
		}
		create_map(map, level);
		checkpoint = 0;
		action = conIn.getUserActions();
		timp++;
		
		if (valid == 0 && action.first != 0 && action.second != 0 && checkpoint == 0)
		{
			plant_type = take_plant(action, valid);
			checkpoint = 1;
		}
		if (valid == 1 && plant_type!=" " && action.first != 0 && action.second != 0 && checkpoint == 0)
		{
			Plant* trying = put_plant(action, plant_type, valid);
			pos = trying->getcord();
			if(pos.X>49 && pos.Y>5)
			plants.push_back(trying);
			checkpoint = 1;
		}
		if(timp%20==0)
		for (auto it1 = plants.begin(); it1 != plants.end(); it1++)
		{
			if ((*it1)->getype() == 'P')
				ammo.push_back((*it1)->attack());
			if ((*it1)->getype() == 'S')
			{
				
				light.push_back(new sun());
			}
		}
		move_damage_zombie();
		take_light(action);
		//Sleep(150);
    }
	
}
//void RGame:: Menu(std::string username)
//{
//	gotoxy(145, 1);
//	std::cout << "player ";
//	drawframe(155, 0, 170, 2, username.c_str());
//	drawframe(75, 17, 95, 19, "START");
//	drawframe(75, 21, 95, 23, "HALL OF FAME");
//	drawframe(75, 25, 95, 27, "EXIT");
//
//};
void RGame::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}
void RGame::drawpixel2(unsigned char x, unsigned char y, unsigned char Color, char character) {
	setcolor(Color);
	gotoxy(x, y); printf("%c", character);
}
void RGame::setcolor(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}
void RGame::drawpixel(unsigned char x, unsigned char y, unsigned char Color) {
	setcolor(Color);
	gotoxy(x, y); printf("Û");
}
void RGame::drawline(int x0, int y0, int x1, int y1, int color) {
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
void RGame::drawfilledrectangle(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char bkcol) {
	int x, y;
	setcolor(bkcol);                       //Set to color bkcol

	for (y = y1; y < y2; y++) {                    //Fill second Region Loop
		for (x = x1; x < x2; x++) {              //Fill first region Loop
			gotoxy(x, y); drawpixel(x, y, bkcol);      //Draw Solid space
		}
	}
}
void RGame::drawframe(unsigned x, unsigned y, unsigned sx, unsigned sy) {
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
		gotoxy(x+j, 4);
		cout <<"     ";
		gotoxy(x + j, 4);
		cout  << money;
		//if (strlen(text_) < 7)
		//{
		//	gotoxy(x + j - 1, y + 1); printf(text_);
		//} //put Title
		/*else { gotoxy(x + j / 2, y + 1); printf(text_); }*/

	}
}
//void RGame::drawwindow(unsigned x, unsigned y, unsigned sx, unsigned sy, unsigned char bkcol, const char text_[]) {
//	drawfilledrectangle(x, y, sx, sy, bkcol);
//	drawframe(x, y, sx, sy, text_);
//}
void RGame::drawcircle(int x, int y, int a, int b, int color) {
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
void RGame::cls()
{
	gotoxy(0, 0);
	for (int j = 0; j < 100; j++)
		std::cout << std::string(100, ' ');
	gotoxy(0, 0);
}
void RGame::aprox_coord(int& x, int& y)
{
	int init_x = 43, init_y = 9;// punctele cel mai din dreapta sus (al careului verde)
	int aux_x = x - init_x;
	int aux_y = y - init_y;
	aux_x = aux_x / 7;//latura pe x + 1(bordura)
	aux_y = aux_y / 4;// latura pe y +1(bordura
	x = init_x + aux_x * 7 + 1;// ca sa nu fie pe margine
	y = init_y + aux_y * 4 + 2;// +2 ca sa fie in patratica cea mai de jos din patratul negru 
}
int  RGame::count(int& i)
{
	if (i > 4)
		i = 0;
	i++;
	return i;
}
std::string RGame::take_plant(std::pair<int, int> action, int& valid)
{
	std::string plant = " ";

	if ((action.first >= 43 && action.first <= 48) && (action.second >= 9 && action.second <= 11))
		if (money >= 50)
	{		
		money -= 50;
		plant = "soare";
		valid = 1;
		return plant;
	}
	if ((action.first >= 43 && action.first <= 48) && (action.second >= 13 && action.second <= 15))
		if (money >= 100)
	{
		money -= 100;
		plant = "pea";
		valid = 1;
		return plant;
	}
	if ((action.first >= 43 && action.first <= 48) && (action.second >= 17 && action.second <= 19))
		if (money >= 150)
	{
		money -= 150;
		plant = "frozen";
		valid = 1;
		return plant;
	}
	if ((action.first >= 43 && action.first <= 48) && (action.second >= 21 && action.second <= 23))
		if (money >= 75)
	{
		money -= 75;
		plant = "wall";
		valid = 1;
		return plant;
	}
	if ((action.first >= 43 && action.first <= 48) && (action.second >= 25 && action.second <= 27))
		if (money >= 225)
	{
		money -= 225;
		plant = "bomb";
		valid = 1;
		return plant;
	}
	return plant;
}
void RGame::create_map(terrain map, int z)// z reprezinta liniile pe unde vin zombii(70)
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
		if (i == 0)
		{
			gotoxy(44, 10);
			cout << "sunfl";
		}
		if (i == 1)
		{
			gotoxy(44, 14);
			cout << "pea";
		}
		if (i == 2)
		{
			gotoxy(44, 18);
			cout << "fropea";

		}
		if (i == 3)
		{
			gotoxy(44, 22);
			cout << "wall";
		}
		if (i == 4)
		{
			gotoxy(44, 26);
			cout << "????";

		}
		y1 = y + i * width;
		drawline(x - row, y1, x - 1, y1, 9);
		drawline(x - row - 1, y1, x - row - 1, y1 + width, 9);
		drawline(x - 1, y1, x - 1, y1 + width, 9);
	}
	drawline(x - row, y1 + width, x - 1, y1 + width, 9);
	gotoxy(121, 2);
	cout << "Money";
	drawframe(115, 3, 130, 6);
}
Plant* RGame::put_plant(std::pair<int, int> action, std::string plant, int& valid)
{
	if ((action.first >= 51 && action.first <= 112) && (action.second >= 9 && action.second <= 27))
	{
		if (plant == "soare")
		{
			valid = 0;
			return new sunflower(action.first,action.second);
			
		}
		if (plant == "pea")
		{
			
			valid = 0;
				aprox_coord(action.first, action.second);
			gotoxy(action.first, action.second);

			return new peashooter(action.first, action.second);
		
			
		}
		if (plant == "frozen")
		{
	
			valid = 0;
				aprox_coord(action.first, action.second);
				gotoxy(action.first, action.second);
				
				return new frozenshooter(action.first, action.second);
			
		}
		if (plant == "wall")
		{
			valid = 0;
			
				aprox_coord(action.first, action.second);
				gotoxy(action.first, action.second);
				return new potato(action.first, action.second);
		
			
		}
		if (plant == "bomb")
		{
			
			valid = 0;
				aprox_coord(action.first, action.second);
				gotoxy(action.first, action.second);
				std::cout << "cb";
			
			
		}
	}
	return new Plant;
}
void RGame::move_damage_zombie()
{
	COORD num, num_z;
	bool size = 0;
	bool sters_ammo = false;
	for (auto it = ammo.begin(); it != ammo.end(); it++)
	{
		num = (*it)->getcord();
		num.X++;
		for (auto it1 = monsters.begin(); it1 != monsters.end(); it1++)
		{
			num_z = (*it1)->getcord();
			if (num_z.X == num.X && num_z.Y == num.Y - 2)
			{
				bool slow = (*it)->getslow();
				(*it1)->setLife(2);
				sters_ammo = true;
				if ((*it1)->getLife() <= 0)
				{
					(*it1)->sterge((*it1)->getcord());

					score += 50;
					monsters.erase(it1);

				}
				break;
			}
		}
		if (sters_ammo == true)
		{
			(*it)->sterge();
			ammo.erase(it);
			sters_ammo = true;
			break;
		}

	}

	for (auto it = ammo.begin(); it != ammo.end(); it++)
	{
		num = (*it)->getcord();
		num.X++;
		if (num.X < 114)
		{
			(*it)->setcord(num.X, num.Y);
			(*it)->sterge();
			(*it)->afiseaza();
		}
		else
		{
			(*it)->sterge();

			ammo.erase(it);
			break;
		}
	}
	bool miscare = true;
if(timp%10==0)
	for (auto it1 = monsters.begin(); it1 != monsters.end(); it1++)
	{
		miscare = true;
		sters_ammo = false;
		num_z = (*it1)->getcord();
	
				for (auto it2 = plants.begin(); it2 != plants.end(); it2++)
				{
					num = (*it2)->getcord();
					if (num_z.X - 4 == num.X && num_z.Y == num.Y-2)
					{
						miscare = false;
						(*it2)->setLife(2);
						if ((*it2)->getLife() <= 0)
						{
							(*it2)->sterge((*it2)->getcord());

							score += 50;
							plants.erase(it2);
							break;
						}

					}
				}
				if (miscare == true)
				{
					(*it1)->sterge((*it1)->getcord());
					num_z.X = num_z.X - 1;
					(*it1)->setcord(num_z.X, num_z.Y);
					(*it1)->afiseaza((*it1)->getcord());
				}
				if (num_z.X < 51)
					exit(0);
	}
		
	
}
void RGame::take_light(std::pair<int, int> action)
{
	COORD pos;
	aprox_coord(action.first, action.second);
	action.second -=2;
	if ((action.first >= 51 && action.first <= 56) && (action.second >= 4 && action.second <= 6))
	{
		for (auto it = light.begin(); it != light.end(); it++)
		{
			pos = (*it)->getcord();
			if (pos.X == 52 && pos.Y == 4)
			{
				money += 25;
				(*it)->sterge(pos);
				light.erase(it);
				break;
			}

		}
	}
	if ((action.first >= 58 && action.first <= 63) && (action.second >= 4 && action.second <= 6))
	{
		for (auto it = light.begin(); it != light.end(); it++)
		{
			
			pos = (*it)->getcord();
			if (pos.X == 59 && pos.Y == 4)
			{
				money += 25;
				(*it)->sterge(pos);
				light.erase(it);
				break;
			}

		}
	}
	if ((action.first >= 65 && action.first <= 70) && (action.second >= 4 && action.second <= 6))
	{
		for (auto it = light.begin(); it != light.end(); it++)
		{
			pos = (*it)->getcord();
			if (pos.X == 66 && pos.Y == 4)
			{
				money += 25;
				(*it)->sterge(pos);
				light.erase(it);
				break;
			}

		}
	}
	if ((action.first >= 72 && action.first <= 77) && (action.second >= 4 && action.second <= 6))
	{
		for (auto it = light.begin(); it != light.end(); it++)
		{
			
			pos = (*it)->getcord();
			if (pos.X == 73 && pos.Y == 4)
			{
				money += 25;
				(*it)->sterge(pos);
				light.erase(it);
				break;
			}

		}
	}
	if ((action.first >= 79 && action.first <= 84) && (action.second >= 4 && action.second <= 6))
	{
		for (auto it = light.begin(); it != light.end(); it++)
		{
			
			pos = (*it)->getcord();
			if (pos.X == 80 && pos.Y == 4)
			{
				money += 25;
				(*it)->sterge(pos);
				light.erase(it);
				break;
			}

		}
	}
	if ((action.first >= 86 && action.first <= 91) && (action.second >= 4 && action.second <= 6))
	{
		for (auto it = light.begin(); it != light.end(); it++)
		{
			money += 25;
			pos = (*it)->getcord();
			if (pos.X == 87 && pos.Y == 4)
			{
				money += 25;
				(*it)->sterge(pos);
				light.erase(it);
				break;
			}

		}
	}
	if ((action.first >= 93 && action.first <= 98) && (action.second >= 4 && action.second <= 6))
	{
		for (auto it = light.begin(); it != light.end(); it++)
		{
			pos = (*it)->getcord();
			if (pos.X == 94 && pos.Y == 4)
			{
				money += 25;
				(*it)->sterge(pos);
				light.erase(it);
				break;
			}

		}
	}
	if ((action.first >= 100 && action.first <= 105) && (action.second >= 4 && action.second <= 6))
	{
		for (auto it = light.begin(); it != light.end(); it++)
		{
			pos = (*it)->getcord();
			if (pos.X == 101 && pos.Y == 4)
			{
				money += 25;
				(*it)->sterge(pos);
				light.erase(it);
				break;
			}

		}
	}
	if ((action.first >= 107 && action.first <= 112) && (action.second >= 4 && action.second <= 6))
	{
		for (auto it = light.begin(); it != light.end(); it++)
		{
			pos = (*it)->getcord();
			if (pos.X == 108 && pos.Y == 4)
			{
				money += 25;
				(*it)->sterge(pos);
				light.erase(it);
				break;
			}

		}
	}
	
	
}