#pragma once
#include <windows.h>
#include <string>
#include<iostream>
using namespace std;

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
		std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);

	public:
		ConsoleInput();
		~ConsoleInput();

		static ConsoleInput& getInstance(void);
		std::string getUserActions();
		ConsoleInput & operator()(int row, int col);

		template<typename Z>
		friend string operator>>(ConsoleInput& in, Z obj)
		{
			std::cin >> obj;
			return obj;
		}
	};
}
