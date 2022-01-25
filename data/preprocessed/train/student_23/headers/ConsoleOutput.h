#pragma once
#define CON_WIDTH 1500
#define CON_HEIGHT 800
#include <iostream>

namespace UserInterface
{
	class ConsoleOutput
	{
	public:
		static ConsoleOutput& getInstance();
		static void destroyInstance();
		ConsoleOutput& operator() (int row, int col);

		template <typename T>
		friend ConsoleOutput& operator<< (ConsoleOutput& out, T obj)
		{
			std::cout << obj;
			return out;
		}
	private:
		static ConsoleOutput* instance;
		ConsoleOutput();
		ConsoleOutput(const ConsoleOutput&) {};
		~ConsoleOutput() {};
	};
}