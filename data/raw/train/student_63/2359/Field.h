#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

class Field
{
	std::vector <std::string> C;	
	COORD A;
	COORD M;
	int X;
	int Y;
public:
	Field();
	Field(int x,int y);
	void print();
	void increase_x() { A.X = A.X + 10; }
	void increase_y() { A.Y = A.Y + 5; }
	void update_mij() { M.X = A.X + 4; M.Y = A.Y + 2; }
	void reset_x() { A.X = X; }
	void reset_y() { A.Y = Y; }
	void schimba(char c);
	const COORD get_mijloc() {return M;}
	~Field();
};

