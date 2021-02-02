#include "ConsoleOutput.h"
#include <windows.h>
#include <string>

ConsoleOutput* ConsoleOutput::instance = nullptr;

ConsoleOutput::ConsoleOutput()
{
	// setting console width and height
	HWND console = GetConsoleWindow();
	MoveWindow(console, 0, 0, CON_WIDTH, CON_HEIGHT, TRUE);

	// hiding scrollbar
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);

	// hide blinking cursor
	GetConsoleCursorInfo(handle, &(this->cursorInfo));
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(handle, &cursorInfo);
	SetConsoleTextAttribute(handle, 15);

}

ConsoleOutput::~ConsoleOutput()
{
	SetConsoleTextAttribute(handle, 15);
}

void ConsoleOutput::setCursorVisibility(bool isShown)
{
	this->cursorInfo.bVisible = isShown;
	SetConsoleCursorInfo(handle, &cursorInfo);
}

ConsoleOutput& ConsoleOutput::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ConsoleOutput();
	}
	return *instance;
}

ConsoleOutput& ConsoleOutput::operator()(int row, int col)
{
	/*should check wether the row and the column values ar within the limits of the current window*/
	COORD coord;
	coord.X = col;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return *this;
}

void ConsoleOutput::setOutputColor(int color)
{
	SetConsoleTextAttribute(handle, color);
	this->consoleColor = color;
}

void ConsoleOutput::clearScreen()
{
	this->operator()(0, 0);
	std::cout << std::string(100, '\n');
	this->operator()(0, 0);
}

int ConsoleOutput::getCurrentColor()
{
	return this->consoleColor;
}

void ConsoleOutput::resetConsoleColor()
{
	setOutputColor(15);
}
