#pragma once
#include <windows.h>
#include <string>
/*TODO: singleton*/
namespace UserInterface
{
	struct coords
	{
		int x;
		int y;
		coords() {};
		coords  ( int x, int y) : x(x), y(y) {};
	};
	class ConsoleInput
	{
	private:
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];
		UserInterface::coords* mouseEventProc(MOUSE_EVENT_RECORD);
		std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);
		ConsoleInput();
		static ConsoleInput *instance;

	public:
		
		~ConsoleInput();

		static ConsoleInput & getInstance(void);
		UserInterface::coords* getUserActions();
	};
}


