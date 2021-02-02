#pragma once
#include "Plante.h"
#include <time.h>
#include <chrono>
#include <vector>
#include <tuple>
#include "Pea.h"

using namespace std;
using namespace std::chrono;

class Peashooter :
	public Planta
{
private:
	vector < tuple<int, int, time_point<steady_clock>>> ps;

public:
	void update(vector<tuple<char, int, int>> Y, vector<Pea>& P);
	void amplasare();
	Peashooter();
	~Peashooter();
};

