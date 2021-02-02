#include "ConsoleOutput.h"
using namespace UserInterface;

ConsoleOutput *ConsoleOutput::Instance = nullptr;

ConsoleOutput::ConsoleOutput()
{
	SetConsoleTitle("Plants vs Zombie - Pesu Ciprian");//set console name


	// setting console width and height
	HWND desktop = GetDesktopWindow();
	RECT resolution;
	GetWindowRect(desktop, &resolution);
	HWND console = GetConsoleWindow();
	MoveWindow(
		console,
		resolution.right / 2 - CON_WIDTH / 2,
		resolution.bottom / 2 - CON_HEIGHT / 2,
		CON_WIDTH,
		CON_HEIGHT,
		TRUE
		);
	
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) &~WS_SIZEBOX &~WS_MAXIMIZEBOX);
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
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(handle, &cursorInfo);
}

ConsoleOutput::~ConsoleOutput()
{
}

ConsoleOutput & UserInterface::ConsoleOutput::getInstance(void)
{
	if (!ConsoleOutput::Instance)
	{
		ConsoleOutput::Instance = new ConsoleOutput();
	}
	return *ConsoleOutput::Instance;
}

ConsoleOutput & UserInterface::ConsoleOutput::operator()(int row, int col)
{
	/*should check wether the row and the column values ar within the limits of the current window*/
	COORD coord;
	coord.X = col;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return *this;
}
