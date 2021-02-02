#include <iostream>

using namespace std;

class iPlants
{
	string type;
	int health;
	
public:
	iPlants(string t, int h) : type(t), health(h) {};

	string get_type();
	int get_health();
	
	
};

