#include "CResource_Sun.h"
//FILE* CResource_Sun::fSun_ = nullptr;


CResource_Sun::~CResource_Sun()
{
	
	fclose(fSun);
	CLog::getInstance().printLog("S-a apelat destructorul clasei CResource_Sun \n");
}

void CResource_Sun::Display(int y, int x, int id_element, bool status_SunFlower)
{
	fSun = fopen("SunCoord.txt", "a");
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	int max_time;
	if (status_SunFlower)
		max_time = 1500;
	else
		max_time = 10000;
	if (duration_cast<milliseconds>(end - begin).count() > max_time)
	{
		fprintf(fSun, "%d\t%d\n", x,y);
		begin = end;
		char characterPrinted = 176;
		conOut(y, x) << characterPrinted;
		
	}
	fclose(fSun);
}

