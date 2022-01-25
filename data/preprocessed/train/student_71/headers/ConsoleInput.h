#pragma once
#include <windows.h>
#include <string>
/*TODO: singleton*/
namespace UserInterface
{
	class ConsoleInput
	{
	private:
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];

		std::string mouseEventProc(MOUSE_EVENT_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);

		ConsoleInput();
		~ConsoleInput();
		static ConsoleInput* console;
	
	public:

		static ConsoleInput & getInstance();
		static void destroyInstance();

		std::string getUserActions();
	};
}

