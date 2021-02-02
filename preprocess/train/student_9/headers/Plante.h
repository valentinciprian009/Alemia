#pragma once

class Planta {
private:
	int cost;
	int viata=100;
	int dmg=25;
public:
	Planta() {}
	Planta(int cost, int viata, int dmg) :cost(cost), viata(viata), dmg(dmg) {};
	int getcost() { return cost; };
	int getviata() { return viata; };
	int getdmg() { return dmg; };
	void setcost(int costt) { cost = costt; };
	void setviata(int viatat) { viata = viatat; };
	void setdmg(int dmgt) { dmg = dmgt; };
};

class Peashooter:public Planta {
private:
	int cost;
	int viata;
	int dmg;
public:
	Peashooter() {};
	Peashooter(int cost, int viata, int dmg) :cost(cost), viata(viata), dmg(dmg) {};
	void shotpea(char ****a);
	void setare(char ****a, int x, int y);
	int IntalnireProiectil(char ****a);
	void death(char ****a);
};

class SunFlower :public Planta {
public:
	SunFlower() :Planta(50, 100, 0) {};
	void producesun();
};
