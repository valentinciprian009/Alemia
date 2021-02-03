#include "ConsoleHandler.h"
#include <windows.h>

ConsoleHandler& ConsoleHandler::getInstance()
{
	_instanceCount++;
	if (_instance == nullptr)
	{
		_instance = new ConsoleHandler;
	}
	return *_instance;
}
void ConsoleHandler::releaseInstance()
{
	_instanceCount--;
	if (_instanceCount == 0 && _instance != nullptr)
	{
		delete _instance;
		_instance = nullptr;
	}
	return;
}

ConsoleHandler::ConsoleHandler()
{
	Init();
}
ConsoleHandler::~ConsoleHandler() {}
ConsoleHandler& ConsoleHandler::operator()(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return *this;
}

void ConsoleHandler::Init()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 12;
	cfi.dwFontSize.Y = 24;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	if (!SetCurrentConsoleFontEx(handle, false, &cfi));

	HWND console = GetConsoleWindow();
	MoveWindow(console, 0, 0, W_WIDTH, W_HEIGHT, TRUE);

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);

	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &cursorInfo);
}

void ConsoleHandler::setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

ConsoleHandler* ConsoleHandler::_instance = nullptr;
int ConsoleHandler::_instanceCount = 0;