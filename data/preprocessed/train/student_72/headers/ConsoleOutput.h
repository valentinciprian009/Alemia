#pragma once
/*TODO: singleton*/
#define CON_WIDTH 1280
#define CON_HEIGHT 720
#include <iostream>
#include <windows.h>

namespace UserInterface {
	class ConsoleOutput
	{
	private:
		static ConsoleOutput *Instance;
		ConsoleOutput();
		
	public:
		~ConsoleOutput();
		static ConsoleOutput & getInstance();
		ConsoleOutput & operator() (int row, int col);
		HANDLE handle;

		template <typename T>
		friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
		{
			std::cout << obj;
			return out;
		}
	};
}


