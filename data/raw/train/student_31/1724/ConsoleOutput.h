#pragma once
#include <Windows.h>
#include <fcntl.h>
#include <io.h>

#define CON_WIDTH 1280
#define CON_HEIGHT 720
#include <iostream>

namespace UserInterface {

	class ConsoleOutput
	{
	private:
		ConsoleOutput();
		static ConsoleOutput*Instance;

	public:
		static ConsoleOutput & getInstance();
		static void DestroyInstance();
		ConsoleOutput & operator() (int row, int col,int color);

		template <typename T>
		friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
		{
			std::cout << obj;
			return out;
		}
		friend ConsoleOutput &operator<< (ConsoleOutput& out, const wchar_t* text)
		{
			

			_setmode(_fileno(stdout), _O_U16TEXT);
			
			std::wcout << text;
			_setmode(_fileno(stdout), _O_TEXT);
			return out;
		}
	};
}
