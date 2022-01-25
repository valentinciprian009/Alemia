#include <windows.h>
#include <string>
#include <stdio.h>
#include<iostream>

namespace UserInterface
{
	class ConsoleInput
	{
	private:
		
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];

		std::string mouseEventProc(MOUSE_EVENT_RECORD);
		std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);
		ConsoleInput();
		static ConsoleInput *consoleGame;

	public:
		HANDLE hStdin;
		static ConsoleInput &getInstance();
		static void destroyInstance();
		std::string getUserActions();
	};
}