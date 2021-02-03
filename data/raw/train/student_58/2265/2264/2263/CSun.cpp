#include "CSun.h"



CSun::CSun(int loc) : CResursa(2, 10+loc*5)
{
	val = 10;
	this->CH = CHR_SUN;

	locatie = loc;
}


CSun::~CSun()
{
}
