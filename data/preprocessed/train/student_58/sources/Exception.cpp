#include "Exception.h"



Exception::Exception(string exception)
{
	string mesaj ="WARNING !"+ exception;
	Log::logare(mesaj);
}

Exception::~Exception()
{
}
