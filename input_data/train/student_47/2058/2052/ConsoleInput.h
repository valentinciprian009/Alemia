#pragma once
#include <windows.h>
#include <string>
namespace UserInterface
{
	class Action
	{
	public:
		int action = -1;
		int row, column;

		Action();
		Action(int act, int x, int y);
	};

	class ConsoleInput
	{
	private:
		ConsoleInput();
		static ConsoleInput *instance;
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];
		UserInterface::Action mouseEventProc(MOUSE_EVENT_RECORD);
		UserInterface::Action resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		UserInterface::Action keyEventProc(KEY_EVENT_RECORD);

	public:
		~ConsoleInput();

		static ConsoleInput & getInstance(void);
		UserInterface::Action getUserActions();
	};
}


