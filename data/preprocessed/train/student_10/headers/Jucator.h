#pragma once
class Jucator
{
	int scor;
	int bani;
	int rata_soare;
	Jucator() :bani(2000),rata_soare(5000),scor(0){};
	static Jucator*instanta;
public:
	void adauga_bani(int suma) { bani += suma; };
	void scade_bani(int suma) { bani -= suma; };
	int get_bani() { return bani; };
	int get_scor() { return scor; };
	int get_rata_soare() { return rata_soare; };
	void scada_rata() { rata_soare -= rata_soare / 10; };
	void adauga_scor() { scor++; };
	static Jucator& get_instance();
	~Jucator();
};

