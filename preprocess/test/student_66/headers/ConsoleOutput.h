#define CON_WIDTH 1200
#define CON_HEIGHT 700
#include <iostream>
#include <windows.h>

namespace UserInterface 
{
	class ConsoleOutput
	{
	private:
		ConsoleOutput();
		static ConsoleOutput *consoleGame;

	public:
		static ConsoleOutput &getInstance();
		static void destroyInstance();
		ConsoleOutput & operator() (int row, int col);
		template <typename T>

		friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
		{
			std::cout << obj;
			return out;
		}
	};
}