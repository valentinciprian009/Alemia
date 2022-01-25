#pragma once
#include <iostream>
#include <string>
#include"Log.h"
using namespace std;

class Exception
{
private:
	int code;
	string message;
public:
	Exception() : code(0), message("UNKNOWN ERROR!\n") { ; }
	Exception(int c, const string& msg) :code(c), message(msg) { ; }
	Exception(const Exception& ex) :code(ex.code), message(ex.message) { ; }
	string& getFormattedMessage() const
	{
		string formattedMesage = " ERROR (code = " + to_string(code) + "): " + message + "\n";
		Log::getInstance().write(formattedMesage);
		return formattedMesage;
	}
	const int getCode() const { return code; }
	const string& getMessage() const { return message; }
};