#pragma once
#include<iostream>
using namespace std;
class Soare
{
private:
	bool SetSun = 0;
	int whichSun;
	int ratePower = 12;

public:
	Soare() {};

	void CheckSun(int decreaser);
	bool getBool()
	{
		return SetSun;
	}
	int getSunPosition()
	{

		return whichSun;
	}
	void resetSun()
	{
		SetSun = 0;
	}
};

