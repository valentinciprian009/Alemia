#pragma once

class Zombie {
private:
	int life, dmg;
	char nume;
public:
	Zombie() {}
	Zombie(int life, int dmg, char nume) :life(life), dmg(dmg), nume(nume) {};
	void miscare(char ****a);
	int getlife() { return life; };
	int getdmg() { return dmg; };
	char getnume() { return nume; };
	void death(char ****a);
	int mananca(char ****a);
};

class BucketZombie :public Zombie {
private:
	int life, dmg;
	char nume;
public:
	BucketZombie() {};
	BucketZombie(int life, int dmg, char nume) : life(life), dmg(dmg), nume(nume) {};
	void miscare(char ****a);
	void death(char ****a);
	int getdmg() { return dmg; };
	int getlife() { return life; };
	char getnume() { return nume; };
	int mananca(char ****a);
};