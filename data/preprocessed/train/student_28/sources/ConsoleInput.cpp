#include <stdio.h>
#include <windows.h>
#include "ConsoleInput.h"
#include <string>

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

std::pair<int, int> ConsoleInput::mouseEventProc(MOUSE_EVENT_RECORD ir)
{
	std::pair<int, int> output ;
	output.first = 0;
	output.second = 0;
	switch (ir.dwEventFlags)
	{
	case 0x0000:
		output.first = ir.dwMousePosition.X;
		output.second = ir.dwMousePosition.Y;
		return output;
	case MOUSE_MOVED:
		//output.first = ir.dwMousePosition.X;
		//output.second = ir.dwMousePosition.Y;
		return output;

	case DOUBLE_CLICK:
		/*output.first = ir.dwMousePosition.X;
		output.second = ir.dwMousePosition.Y;*/
		return output;
		;
	}
	return output;
}
std::string ConsoleInput::resizeEventProc(WINDOW_BUFFER_SIZE_RECORD) { return ""; };
std::string ConsoleInput::keyEventProc(KEY_EVENT_RECORD) { return ""; };

std::pair<int, int> UserInterface::ConsoleInput::getUserActions()
{std::pair<int, int> output;
output.first = 0;
output.second = 0;
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
			//	return keyEventProc(irInBuf[i].Event.KeyEvent);

			case MOUSE_EVENT: // mouse input 
				return mouseEventProc(irInBuf[i].Event.MouseEvent);

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				//return resizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);

			case FOCUS_EVENT:  // disregard focus events 
				return output;

			case MENU_EVENT:   // disregard menu events 
				return output;

			default:
				ExceptionHandler("unknown event type");
				break;
			}
		}
	}
	return output;
}