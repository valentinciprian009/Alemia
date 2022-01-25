#pragma once


#include <iostream>

class CExceptie
{
private:
	int code;
	std::string mesaj;

public:
	std::string			return_mesaj();
	int					return_code();

	CExceptie(int code, const char*mesaj);

	CExceptie();
	~CExceptie();
};

