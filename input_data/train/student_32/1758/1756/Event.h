#pragma once
#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;
class Event
{
private:
	int col;
	int row;
	string aux;
public:
	Event(string aux);
	int get_col();
	int get_row();
	string get_event();
};

