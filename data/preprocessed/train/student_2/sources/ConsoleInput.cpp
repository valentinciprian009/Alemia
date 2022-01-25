#include <stdio.h>
#include <windows.h>
#include "ConsoleInput.h"
#include <string>

ConsoleInput* ConsoleInput::instance = nullptr;

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

ConsoleInput & ConsoleInput::getInstance(void)
{
	if (instance == nullptr)
	{
		ConsoleInput::instance = new ConsoleInput();
	}
	return *instance;
}

std::string ConsoleInput::mouseEventProc(MOUSE_EVENT_RECORD ir)
{
	std::string output = "";
	switch (ir.dwEventFlags)
	{
	case MOUSE_MOVED:
		output += "moved(";
		output += std::to_string(ir.dwMousePosition.X);
		output += ",";
		output += std::to_string(ir.dwMousePosition.Y);
		output += ")";
		return output;

	case DOUBLE_CLICK:
		output += "dc(";
		output += std::to_string(ir.dwMousePosition.X);
		output += ",";
		output += std::to_string(ir.dwMousePosition.Y);
		output += ")";
		return output;
	}
	return output;
}
std::string ConsoleInput::resizeEventProc(WINDOW_BUFFER_SIZE_RECORD) { return ""; };
std::string ConsoleInput::keyEventProc(char key) { return std::string() + key; };

std::string ConsoleInput::getUserActions()
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

		// Dispatch the events to the appropriate handler. 
		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				return keyEventProc(irInBuf[i].Event.KeyEvent.uChar.AsciiChar);

			case MOUSE_EVENT: // mouse input 
				return mouseEventProc(irInBuf[i].Event.MouseEvent);

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				return resizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);

			case FOCUS_EVENT:  // disregard focus events 
				return "";

			case MENU_EVENT:   // disregard menu events 
				return "";

			default:
				ExceptionHandler("unknown event type");
				break;
			}
		}
	}

	return "";
}

void ConsoleInput::setGameInput(bool isGameInput)
{
	if (isGameInput)
	{
		// Disable 'Quick Edit Mode' option.
		fdwMode = ENABLE_EXTENDED_FLAGS;
		if (!SetConsoleMode(hStdin, fdwMode))
			ExceptionHandler("SetConsoleMode");

		// Enable the window and mouse input events.
		fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
		if (!SetConsoleMode(hStdin, fdwMode))
			ExceptionHandler("SetConsoleMode");
	}
	else
	{
		SetConsoleMode(hStdin, fdwSaveOldMode);
	}
}


