#include "bucketM.h"
bucketM::bucketM()
{
	;
}

 bucketM::bucketM(int x,int y)
{	
	int viata;
	viata = getLife();
	viata += 3;
	setLife(viata);
	viata = getValue();
	setValue(viata * 10);
	setcord(x, y);
	afiseaza(getcord());
}
void bucketM::afiseaza(COORD num)
{
	for (int j = 0; j < 3; j++)
	{
		gotoxy(num.X, num.Y + j);
		std::cout << 'B';
	}
}