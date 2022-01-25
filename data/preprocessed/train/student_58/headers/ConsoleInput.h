#pragma once
#include <windows.h>
#include <string>
#include"Logare.h"
using namespace std;


namespace UserInterface
{
	class ConsoleInput
	{
	private:
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[1280];
		string mouseEventProc(MOUSE_EVENT_RECORD);
		string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		string keyEventProc(KEY_EVENT_RECORD);

		ConsoleInput();
		~ConsoleInput();

		static ConsoleInput *instance;
	public:

		static ConsoleInput& getInstance(void);

		string getMouse();

		string getUserActions();
		static void destroyInstance();
	};
}
