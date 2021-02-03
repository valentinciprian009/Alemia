#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Evenimente
{
	string fisier;

public:

	Evenimente(string x)
	{
		fisier = x;
	}

	void write(string x)
	{
		ofstream out;
		out.open(fisier);
		out << x;
	}
};

