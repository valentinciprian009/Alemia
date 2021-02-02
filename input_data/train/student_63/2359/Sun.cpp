#include "Sun.h"



Sun::Sun(int& inGameCurrency, char img1, int x1, int y1, int color1):
	Entity('X', x1, y1, color1),
	inGameCurrency(inGameCurrency)
{}

