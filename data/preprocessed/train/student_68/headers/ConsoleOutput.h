#pragma once
/*TODO: singleton*/
#define CON_WIDTH 1400
#define CON_HEIGHT 800
#include <iostream>


namespace UserInterface {
	class ConsoleOutput
	{
	public:
		ConsoleOutput();
		~ConsoleOutput();

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


