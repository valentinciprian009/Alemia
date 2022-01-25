#pragma once
#include <string>
class Terrain
{
	
	void print_score();
	void plant_zone();
	void sun_zone();
	void print_teren1();
	void print_teren2();
	void print_teren3();
	void print_teren4();
	void print_teren5();
	int lv;
public:
	Terrain();
	
	int get_lv() { return lv; }
	Terrain(int level) :lv(level) {
		
		print_score();
		plant_zone();
		sun_zone();
	
	};
	

	void print();
	~Terrain();
};

