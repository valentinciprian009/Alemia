#pragma once
#include <string>
class Menu 
{
	char *x;
	char *y;
public:
	Menu();
	void print();
	void coordonate(std::string);
	char *get_x() {
		return x;
	}
	char *get_y() {
		return y;
	}
	~Menu();
};

