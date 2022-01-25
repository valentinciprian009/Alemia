#pragma once
#include <windows.h>
#include <string>
/*TODO: singleton*/
namespace UserInterface
{
	struct mouse_event
	{
		bool Mevent;
		int x;
		int y;
		mouse_event  (bool event, int x, int y) :Mevent(event), x(x), y(y) {};
	};
	class ConsoleInput
	{
	private:
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];
		UserInterface::mouse_event* mouseEventProc(MOUSE_EVENT_RECORD);
		std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);
		ConsoleInput();
		static ConsoleInput *instance;

	public:
		
		~ConsoleInput();

		static ConsoleInput & getInstance(void);
		UserInterface::mouse_event* getUserActions();
	};
}


