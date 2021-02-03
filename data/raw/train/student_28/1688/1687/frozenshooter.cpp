#include "frozenshooter.h"
frozenshooter::frozenshooter(int x, int y)
{
	Plant::setslow();
	Plant::setcord(x, y);
}
frozenshooter::frozenshooter()
{
	;
}