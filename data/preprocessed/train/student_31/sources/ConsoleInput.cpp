#include <stdio.h>
#include <windows.h>
#include "ConsoleInput.h"
#include <string>
#include <iostream>
using namespace UserInterface;


ConsoleInput *ConsoleInput::Instance = NULL;

void ExceptionHandler(const char *s)
{
	// TODO: you should handle this
	exit(1);
}


ConsoleInput & UserInterface::ConsoleInput::getInstance(void)
{
	if(Instance==NULL)
		Instance = new ConsoleInput;
	return *Instance;
}

std::string ConsoleInput::mouseEventProc(MOUSE_EVENT_RECORD ir)
{
	std::string output = "Mouse event: ";
	switch (ir.dwEventFlags)
	{
	case MOUSE_MOVED:
		output += "mouse moved at (";
		output += std::to_string(ir.dwMousePosition.X);
		output += ", ";
		output += std::to_string(ir.dwMousePosition.Y);
		output += ")              ";
		return output;
	case BN_CLICKED:
		output += "mouse clicked at (";
		output += std::to_string(ir.dwMousePosition.X);
		output += ", ";
		output += std::to_string(ir.dwMousePosition.Y);
		output += ")              ";
		return output;
	case DOUBLE_CLICK:
		output += "mouse double clicked at (";
		output += std::to_string(ir.dwMousePosition.X);
		output += ", ";
		output += std::to_string(ir.dwMousePosition.Y);
		output += ")              ";
		return output;
	}
	return output;
}

std::string ConsoleInput::resizeEventProc(WINDOW_BUFFER_SIZE_RECORD ) { 
	
	
	return ""; 


};

std::string ConsoleInput::keyEventProc(KEY_EVENT_RECORD ir) { 
	

	std::string output;
	if (!ir.bKeyDown)
	{
		
		if (ir.wVirtualKeyCode != '\n' && ir.wVirtualKeyCode!='\b')
		{
			this->id_player += ir.uChar.AsciiChar;
			ir.bKeyDown;
		}
		if (ir.wVirtualKeyCode == '\b')
		{
			char*clear = _strdup(this->id_player.c_str());

			clear[strlen(clear)-1] = '\0';
			this->id_player = clear;
			ir.bKeyDown;
			output = this->id_player + " ";
			return output;
		}
		if (ir.wVirtualKeyCode == '\r')
		{
			output = "\r";
			return output;
		}

	}
	output = this->id_player;
	return output;

};

std::string UserInterface::ConsoleInput::get_id()
{
	return this->id_player;
}

int UserInterface::ConsoleInput::get_level()
{
	return this->level;
}

void UserInterface::ConsoleInput::set_level(int x)
{
	if(x==2 || x==1 || x==3)
		level = x;
}

std::string UserInterface::ConsoleInput::getUserActions()
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
				return keyEventProc(irInBuf[i].Event.KeyEvent);

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

void UserInterface::ConsoleInput::DestroyInstance()
{
	if (Instance != NULL)
		delete Instance;
	Instance = NULL;
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

