#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Jurnal
{
private:
	Jurnal();
	~Jurnal();

	static Jurnal* instanta;

public:
	static Jurnal* getInstance();
	static void destroyInstance();

	void writeJurnal(string action);
};

