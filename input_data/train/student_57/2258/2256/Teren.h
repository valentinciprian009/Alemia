#pragma once
class Teren
{
private:
	const int lungime=9;
	int latime;
public:
	Teren():latime(0) {};
	Teren(int l) :latime(l) {};
	~Teren() {};
	void DrawScoreboard();
	void DrawCasset(int row,int col);
	void DrawSunZone();
	void DrawPlantsZone();
	
	void DrawTable(int i);
};

