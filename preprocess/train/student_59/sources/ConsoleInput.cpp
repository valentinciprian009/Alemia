#include <stdio.h>
#include <windows.h>
#include "ConsoleInput.h"
#include <string>
#include <tuple>

using namespace UserInterface;

void ExceptionHandler(const char *s)
{
	// TODO: you should handle this
	exit(1);
}

ConsoleInput::ConsoleInput()
{
	// Get the standard input handle. 
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ExceptionHandler("GetStdHandle");

	// Save the current input mode, to be restored on exit. 
	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ExceptionHandler("GetConsoleMode");

	// Disable 'Quick Edit Mode' option.
	fdwMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fdwMode))
		ExceptionHandler("SetConsoleMode");

	// Enable the window and mouse input events.
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ExceptionHandler("SetConsoleMode");
}

ConsoleInput::~ConsoleInput()
{
}

ConsoleInput & UserInterface::ConsoleInput::getInstance(void)
{
	// TODO: singleton logics
	ConsoleInput *console = new ConsoleInput();
	return *console;
}

std::tuple<int, COORD> ConsoleInput::mouseEventProc(MOUSE_EVENT_RECORD ir)
{
	return std::make_tuple(ir.dwEventFlags, ir.dwMousePosition);
}
std::string ConsoleInput::resizeEventProc(WINDOW_BUFFER_SIZE_RECORD) { return ""; };
std::string ConsoleInput::keyEventProc(KEY_EVENT_RECORD) { return ""; };

std::tuple<int, COORD> UserInterface::ConsoleInput::getUserActions()
{
	DWORD nr = 0;
	GetNumberOfConsoleInputEvents(hStdin, &nr);
	if (nr)
	{
		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			ExceptionHandler("ReadConsoleInput");

		if (irInBuf[0].EventType == MOUSE_EVENT)
			return mouseEventProc(irInBuf[0].Event.MouseEvent);

		else
		{
			COORD c;
			std::make_tuple(-1, c);
		}
	}
}