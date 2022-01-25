#include "MyException.h"

MyException::MyException(const char* except) : desc(except)
{
}

const char* MyException::what() const
{
	return desc.c_str();
}
