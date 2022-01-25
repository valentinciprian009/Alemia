#pragma once
/*TODO: singleton*/
#define CON_WIDTH 1280
#define CON_HEIGHT 720
#include <iostream>

namespace UserInterface {
	class ConsoleOutput
	{
	private:
		ConsoleOutput();
		~ConsoleOutput();

		static ConsoleOutput* instance;
	public:

		static ConsoleOutput& getInstance();
		ConsoleOutput& operator() (int row, int col);

		template <typename T>
		friend ConsoleOutput& operator<< (ConsoleOutput& out, T obj)
		{
			std::cout << obj;
			return out;
		}
	};
}


