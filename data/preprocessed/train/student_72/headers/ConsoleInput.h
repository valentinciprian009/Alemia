#pragma once
#include <windows.h>
#include <string>
/*TODO: singleton*/
namespace UserInterface
{
	class ConsoleInput
	{
	private:
		DWORD cNumRead, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];
		std::string mouseEventProc(MOUSE_EVENT_RECORD);
		std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);

		static ConsoleInput *Instance;
		ConsoleInput();
	public:
		~ConsoleInput();
		DWORD  fdwMode;
		HANDLE hStdin;

		static ConsoleInput & getInstance(void);
		std::string getUserActions();
	};
}


