#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
class Log
{
	std::string username;
	FILE* f;
public:
	Log();
	void user();
	void get_user_action(std::string string);
	void exit();
	~Log();
};

