#pragma once
#include<iostream>
using namespace std;
class Zombie 
{
private:
	int X1;
	int Y1;
	bool alive = 0;
	bool fresh = 0;
	int health;
	


public:
	string lastPos;
	Zombie()  { 
		health = 100;
		lastPos = "/ "; };

	void setCor(int a, int b)
	{
		X1 = a;
		Y1 = b;
	}



	int getX1()
	{
		return X1;
	}

	int getY1()
	{
		return Y1;
	}

	void setAlive()
	{
		alive = 1;
	}
	void setFresh()
	{
		fresh = 1;
	}

	void getKilled()
	{
		alive = 0;
	}

	bool getAlive()
	{
		return alive;
	}
	bool getFresh()
	{
		return fresh;
	}

	void lowerY1()
	{
		Y1--;
	}

    void setValues(int x, int y)
	{
		health = x;
		
	}

	

	 void lowerHP()
	{
		health -= 50;
	}

	 int getHP()
	{
		return health;
	}


	~Zombie() {};

};

