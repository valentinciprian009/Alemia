#include "sunflower.h"
#include <iostream>
sunflower::sunflower(int x,int y )
{
    setype('S');
	Plant::setcord(x, y);
    afiseaza(Plant::getcord());
}
sunflower::sunflower()
{
    ;
}
sun* sunflower::makesunflower(int x, int y)
{
    COORD num = Plant::getcord();
    num.X++;
    num.X++;
    sun* ammo = new sun();


    return ammo;
}
void sunflower::afiseaza(COORD pos)
{
	COORD num = pos;
    Plant::gotoxy(num.X, num.Y);
	aprox_cooord(num.X, num.Y);
	drawpixel9(num.X + 1, num.Y, 6);
	drawpixel9(num.X + 2, num.Y, 6);
	drawpixel9(num.X + 3, num.Y, 6);
	drawpixel9(num.X + 3, num.Y + 1, 6);
	drawpixel9(num.X + 2, num.Y + 1, 2);
	drawpixel9(num.X + 1, num.Y + 1, 6);
	drawpixel9(num.X + 2, num.Y + 2, 2);

}