#include "LoadingSlide.h"
#include <time.h>
#include <iostream>
#include <chrono>
#include <fstream>
#include "LoginSlide.h"

using namespace std::chrono;

LoadingSlide::LoadingSlide() : Slide(false)
{
	conOut(rowTitle, colCenter) << "Loading PvZ game now...";
	Slide::drawAsciiArt("title.txt", conOut, startTitle, -1);

	for (int i = 1; i < conOut.width()-1; i++) 
	{
		conOut(0, i) << "=";
		conOut(conOut.height() - 2, i) << "=";
	}
	for (int i = 1; i < conOut.height()-2; i++)
	{
		conOut(i, 0) << "|";
		conOut(i, conOut.width() - 1) << "|";
	}
	conOut(0, 0) << "O";
	conOut(conOut.height() - 2, 0) << "O";
	conOut(0, conOut.width() - 1) << "O";
	conOut(conOut.height() - 2, conOut.width() - 1) << "O";

}

void LoadingSlide::update()
{
	static int i = 0;
	doLoadingBar();
	std::string action = conIn.getUserActions();
	if(action != "")
	{
		conOut(41, 2) << i;
		i++;
		conOut(41, 10) << action;
	}
}

void LoadingSlide::doLoadingBar()
{
	static auto begin = steady_clock::now();
	static auto start = begin;
	static int col = colCenter;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(rowTitle + 1, col) << printedChar;
		if (col >= colCenter + 4 * starDistance) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = colCenter;
		}
		else
		{
			col += starDistance;
		}
	}
	if (duration_cast<milliseconds>(end - start).count() > 2000)
		next = new LoginSlide();
}

LoadingSlide::~LoadingSlide() {}