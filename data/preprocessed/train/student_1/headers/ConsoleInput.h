#pragma once
#include <string>
#include"Exception.h"
#include"ConsoleEvent.h"

namespace UserInterface
{
	class ConsoleInput
	{
	private:
		static ConsoleInput* instance;
		ConsoleInput();
		virtual ~ConsoleInput();
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];
		ConsoleEvent& mouseEventProc(MOUSE_EVENT_RECORD);
		ConsoleEvent& resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		ConsoleEvent& keyEventProc(KEY_EVENT_RECORD);

	public:
		static ConsoleInput & getInstance();
		static void destroyInstance();
		ConsoleEvent& getUserActions();
		ConsoleInput& operator() (int row, int col);
	};
}