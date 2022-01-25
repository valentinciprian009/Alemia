#pragma once
#define CON_WIDTH 1280
#define CON_HEIGHT 720
#include <iostream>
#include <fcntl.h>
#include <io.h>

namespace UserInterface {
	class ConsoleOutput
	{
		ConsoleOutput();
		~ConsoleOutput();
		static ConsoleOutput* console;

	public:

		static ConsoleOutput & getInstance();
		void destroyInstance();

		ConsoleOutput& operator() (int row, int col, int flag = 240);
		ConsoleOutput& operator()(int flag);

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


