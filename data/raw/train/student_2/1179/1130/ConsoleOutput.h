#pragma once
/*TODO: singleton*/
#define CON_WIDTH 1280
#define CON_HEIGHT 720
#include <iostream>
#include <windows.h>
class ConsoleOutput
{
private:
	CONSOLE_CURSOR_INFO  cursorInfo;
	HANDLE handle;
	static ConsoleOutput* instance;
	int consoleColor;
	ConsoleOutput();
	ConsoleOutput(ConsoleOutput&);
	~ConsoleOutput();
public:


	void setCursorVisibility(bool);

	static ConsoleOutput & getInstance();
	ConsoleOutput & operator() (int row, int col);

	template <typename T>
	friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
	{
		std::cout << obj << std::flush;
		return out;
	}
	void setOutputColor(int color);
	void clearScreen();
	int getCurrentColor();
	void resetConsoleColor();
};



