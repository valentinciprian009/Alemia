#include "CExceptie.h"



std::string CExceptie::return_mesaj()
{
	return this->mesaj;
}

int CExceptie::return_code()
{
	return this->code;
}

CExceptie::CExceptie(int code, const char * mesaj)
{
	this->code = code;
	this->mesaj = mesaj;
}

CExceptie::CExceptie()
{
}


CExceptie::~CExceptie()
{
}
