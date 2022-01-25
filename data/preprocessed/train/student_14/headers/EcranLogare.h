#pragma once
#include<iostream>
class EcranLogare
{

private:

	static EcranLogare* instance;

	EcranLogare() {};
	EcranLogare(const EcranLogare&) {};
	~EcranLogare() {};

	std::string username;
	std::string password;

public:

	static EcranLogare* getInstance();
	static void DestroyInstance();


	void DisplayTitleScreen();


	void getLogs();


};

