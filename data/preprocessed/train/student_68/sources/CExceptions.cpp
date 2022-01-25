#include "CExceptions.h"

CExceptions::CExceptions(string message, int code)
{
	this->message_ = message;
	this->code_ = code;

}

CExceptions::~CExceptions()
{

}

void CExceptions::printExceptions()
{
	cout << "ERROR!! " << this->message_ << " cu codul " << this->code_ << endl;
}
