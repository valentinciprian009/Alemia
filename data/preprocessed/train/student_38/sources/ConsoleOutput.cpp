#include "ConsoleOutput.h"

using namespace UserInterface;

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
	ConsoleOutput *console = new ConsoleOutput();
	return *console;
}

ConsoleOutput & UserInterface::ConsoleOutput::operator()(int x, int y)
{
	/*should check wether the row and the column values ar within the limits of the current window*/
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return *this;
}

void UserInterface::ConsoleOutput::change_color(std::string color)
{
	

	if(color == "green")
			SetConsoleTextAttribute(handle, 10);
	else if(color == "blue")
			SetConsoleTextAttribute(handle, 9);
	else if(color== "red")
			SetConsoleTextAttribute(handle, 12);
	else if(color == "yellow")
			SetConsoleTextAttribute(handle, 14);
	else if(color== "purple")
			SetConsoleTextAttribute(handle, 13);
	else if(color == "white")
			SetConsoleTextAttribute(handle, 15);
	else if(color == "darkgreen")
		SetConsoleTextAttribute(handle, 2);






}