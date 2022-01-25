#include "ConsoleInput.h"
using namespace UserInterface;

void ExceptionHandler(const string& s)
{
	// TODO: you should handle this
	exit(1);
}

ConsoleInput* ConsoleInput::instance = nullptr;

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

ConsoleInput& ConsoleInput::getInstance()
{
	if (!instance)
		instance = new ConsoleInput;
	return *instance;
}

void ConsoleInput::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

ConsoleEvent& ConsoleInput::mouseEventProc(MOUSE_EVENT_RECORD mi)
{
	ConsoleEvent& event = ConsoleEvent::getInstance();
	event.setType(MOUSE_EVENT);
	string info = "Mouse event: ";
	switch (mi.dwEventFlags)
	{
	case MOUSE_MOVED:
		info += "mouse moved at (";
		info += to_string(mi.dwMousePosition.X);
		info += ", ";
		info += to_string(mi.dwMousePosition.Y);
		info += ")              ";
		event.setInfo(info);
		return event;

	case DOUBLE_CLICK:
		info += "mouse double clicked at (";
		info += to_string(mi.dwMousePosition.X);
		info += ", ";
		info += to_string(mi.dwMousePosition.Y);
		info += ")              ";
		event.setInfo(info);
		return event;

	case 0:
		if (mi.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)	//simple left click
		{
			info += "mouse clicked at (";
			info += to_string(mi.dwMousePosition.X);
			info += ", ";
			info += to_string(mi.dwMousePosition.Y);
			info += ")              ";
			event.setInfo(info);
		}
		return event;
	}
	event.setInfo(info);
	return event;
}

ConsoleEvent& ConsoleInput::resizeEventProc(WINDOW_BUFFER_SIZE_RECORD)
{
	ConsoleEvent& event = ConsoleEvent::getInstance();
	event.setType(WINDOW_BUFFER_SIZE_EVENT);
	return event;
}

ConsoleEvent& ConsoleInput::keyEventProc(KEY_EVENT_RECORD ki)
{
	ConsoleEvent& event = ConsoleEvent::getInstance();
	event.setType(KEY_EVENT);
	string str;
	str.push_back(ki.uChar.AsciiChar);
	event.setInfo(str);
	return event;
}

ConsoleEvent& UserInterface::ConsoleInput::getUserActions()
{
	DWORD nr = 0;
	GetNumberOfConsoleInputEvents(hStdin, &nr);
	int x;
	ConsoleEvent& event = ConsoleEvent::getInstance();
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
				event = keyEventProc(irInBuf[i].Event.KeyEvent);
				event.setInputRecord(irInBuf[i]);
				return event;

			case MOUSE_EVENT: // mouse input 
				event = mouseEventProc(irInBuf[i].Event.MouseEvent);
				event.setInputRecord(irInBuf[i]);
				return event;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				event = resizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				event.setInputRecord(irInBuf[i]);
				return event;

			case FOCUS_EVENT:  // disregard focus events 
				event.setType(FOCUS_EVENT);
				event.setInputRecord(irInBuf[i]);
				return event;

			case MENU_EVENT:   // disregard menu events 
				event.setType(MENU_EVENT);
				event.setInputRecord(irInBuf[i]);
				return event;

			default:
				ExceptionHandler("unknown event type");
				break;
			}
		}
	}
	return event;
}

ConsoleInput& UserInterface::ConsoleInput::operator()(int row, int col)
{
	try
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(handle, &info);
		if ((col < info.dwSize.X) && (col >= 0) && (row < info.dwSize.Y) && (row >= 0))
		{
			COORD coord;
			coord.X = col;
			coord.Y = row;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}
		else
		{
			throw new Exception(3, "Cursor out of bounds!");
		}
		return *this;
	}
	catch (Exception * e)
	{
		Log::getInstance().write("ERROR: " + e->getMessage());
		delete e;
	}
}