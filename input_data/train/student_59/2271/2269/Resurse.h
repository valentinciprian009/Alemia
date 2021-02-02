#pragma once
#include<iostream>
#include<string>
using namespace std;

class Resurse
{
private:
	char forma = '*';
	int lovitura = 10;

public:
	virtual void amplasare() {};
	Resurse();
	~Resurse();
};

