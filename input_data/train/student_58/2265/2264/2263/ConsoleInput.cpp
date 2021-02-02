#include <stdio.h>
#include <windows.h>
#include "ConsoleInput.h"
#include"ConsoleOutput.h"
#include"Log.h"
#include <string>
#include<iostream>

using namespace UserInterface;

void ExceptionHandler(const char *s)
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

ConsoleInput& UserInterface::ConsoleInput::getInstance(void)
{
	if (instance == nullptr)
		instance = new ConsoleInput();
	return *instance;
}

string UserInterface::ConsoleInput::getMouse()
{
	DWORD nr = 0;
	GetNumberOfConsoleInputEvents(hStdin, &nr);
	if (nr)
	{
		if (!ReadConsoleInput(
			hStdin,
			irInBuf,
			1280,
			&cNumRead))
			ExceptionHandler("ReadConsoleInput");

		for (i = 0; i < cNumRead; i++)
		{
			if (irInBuf[i].EventType== MOUSE_EVENT)
			{
				auto mouse = irInBuf[i].Event.MouseEvent;
				if (mouse.dwEventFlags == DOUBLE_CLICK)
				{
					std::string output;
					output += to_string(mouse.dwMousePosition.Y);
					output += " ";
					output += to_string(mouse.dwMousePosition.X);
					return output;
				}
					
			}
		}
	}
	return "";
}
void ConsoleInput::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

string ConsoleInput::mouseEventProc(MOUSE_EVENT_RECORD ir)
{
	string output = "";
	switch (ir.dwEventFlags)
	{
	case MOUSE_MOVED:
		break;

	case DOUBLE_CLICK:
		output += to_string(ir.dwMousePosition.X);
		output += " ";
		output += to_string(ir.dwMousePosition.Y);
		return output;
	}
	return output;
}
string ConsoleInput::resizeEventProc(WINDOW_BUFFER_SIZE_RECORD) { return ""; };
string ConsoleInput::keyEventProc(KEY_EVENT_RECORD ker)
{
	string output = "OK";
	return output;
};


string UserInterface::ConsoleInput::getUserActions()
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
			{   Log::logare("Afisare fereastra logare.");
				system("CLS");
				Logare log;
				log.DisplayResourceNAMessageBox();

				return keyEventProc(irInBuf[i].Event.KeyEvent);
			}

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