#include "ConsoleOutput.h"
#include <windows.h>

using namespace UserInterface;

ConsoleOutput* ConsoleOutput::console = NULL;

ConsoleOutput::ConsoleOutput()
{
	system("color f0");  // White background with black text
	SetConsoleTitle("POO vs Zombies - Cazamir Teodor");  // Set the title
	

	// setting console width and height and placing it on the center
	HWND desktop = GetDesktopWindow();
	RECT resolution;
	GetWindowRect(desktop, &resolution);
	HWND console = GetConsoleWindow();
	MoveWindow(
		console, resolution.right/2 - CON_WIDTH/2,
		resolution.bottom/2 - CON_HEIGHT/2,
		CON_WIDTH,
		CON_HEIGHT,
		TRUE);

	// make the window unsizeable
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	// hiding scrollbar
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);

	// hide blinking cursor
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(handle, &cursorInfo);

}

ConsoleOutput::~ConsoleOutput()
{
}

ConsoleOutput & ConsoleOutput::getInstance()
{
	if(!ConsoleOutput::console)
		console = new ConsoleOutput();
	return *console;
}

void UserInterface::ConsoleOutput::destroyInstance()
{
	delete console;
}

ConsoleOutput& UserInterface::ConsoleOutput::operator()(int row, int col, int flag)
{
	/*should check wether the row and the column values ar within the limits of the current window*/
	COORD coord;
	coord.X = col;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), flag);
	return *this;
}

ConsoleOutput& UserInterface::ConsoleOutput::operator()(int flag)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), flag);
	return *this;
}
