#pragma once
#include "CEntity.h"
#include <vector>
using namespace std;
class CSun
	:public CEntity
{
	int x_beg;
	int x_end;
	int y_beg;
	int y_end;
	int pozitie;
	
public:
	
	static vector<int> spawnPositions;
	void draw();
	int getPozitie() { return pozitie; }
	int get_x_beg() { return x_beg; }
	int get_x_end() { return x_end; }
	int get_y_beg() { return y_beg; }
	int get_y_end() { return y_end; }
	void set_y_beg();
	void set_y_end();
	void set_x_beg();
	void set_x_end();
	void setPozitie();
	void deleteSun(int numar_chenar);
	CSun(string);
	CSun();
	~CSun();
};

