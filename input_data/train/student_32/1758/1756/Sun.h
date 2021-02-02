#pragma once
#include<iostream>
using namespace std;
class Sun
{
private:
	int col;
	int row;
	int earning;

public:
	Sun(int x,int y);
	int get_col();
	int get_row();
	int get_money();
};

