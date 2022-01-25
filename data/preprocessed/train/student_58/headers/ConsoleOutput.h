#pragma once
#define CON_WIDTH 1280
#define CON_HEIGHT 720
#include <iostream>

using namespace std;

namespace UserInterface
{
	class ConsoleOutput
	{
	private:
		ConsoleOutput();
		static ConsoleOutput *instance;
		~ConsoleOutput();
	public:
	
		static ConsoleOutput& getInstance();
		ConsoleOutput & operator() (int row, int col);

		template <typename T>
		friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
		{
			std::cout << obj;
			return out;
		}

		static void destroyInstance();
	};
}



