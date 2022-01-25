#pragma once
#include <string>
#include <exception>

class MyException
	: public std::exception
{
private:
	std::string desc;

public:
	MyException(const char* except);
	const char* what() const override;
};

