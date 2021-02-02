#pragma once
#include <windows.h>
#include <string>

namespace UserInterface
{
	class ConsoleInput
	{
	private:
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];
		std::string mouseEventProc(MOUSE_EVENT_RECORD);
		std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);
		static ConsoleInput* instance;

		ConsoleInput();
		~ConsoleInput() {};

	public:
		static ConsoleInput& getInstance(void);
		static void destroyInstance();
		std::string getUserActions();
	};
}