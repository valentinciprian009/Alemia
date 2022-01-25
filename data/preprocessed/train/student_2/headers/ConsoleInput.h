#pragma once
#include <windows.h>
#include <string>
/*TODO: singleton*/

class ConsoleInput
{
private:
	static ConsoleInput* instance;
private:

	HANDLE hStdin;
	DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
	INPUT_RECORD irInBuf[128];
	std::string mouseEventProc(MOUSE_EVENT_RECORD);
	std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
	std::string keyEventProc(char key);

public:
	ConsoleInput();
	~ConsoleInput();

	static ConsoleInput & getInstance(void);
	std::string getUserActions();

	void setGameInput(bool isGameInput);

};


