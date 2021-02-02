#pragma once
#define NOMINMAX
#include <iostream>
#include <windows.h>
#include"Exception.h"
using namespace std;
#define CON_WIDTH 1600
#define CON_HEIGHT 900

namespace UserInterface 
{
	class ConsoleOutput
	{
	private:
		static ConsoleOutput* instance;
		ConsoleOutput();
		virtual ~ConsoleOutput();

	public:
		static ConsoleOutput & getInstance();
		static void destroyInstance();
		ConsoleOutput & operator() (int row, int col);
		template <typename T>
		friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
		{
			cout << obj;
			return out;
		}
	};
}