#pragma once
/*TODO: singleton*/
#define CON_WIDTH 1280
#define CON_HEIGHT 720
#include <iostream>
#include <Windows.h>
#include <map>

namespace UserInterface {
	class ConsoleOutput
	{
	private:
		HANDLE handle;

	public:
		ConsoleOutput();
		~ConsoleOutput();

		static ConsoleOutput & getInstance();
		ConsoleOutput & operator() (int x, int y);

		template <typename T>
		friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
		{
			std::cout << obj;
			return out;
		}


		void change_color(std::string);
	};
}


