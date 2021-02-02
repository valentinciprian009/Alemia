#pragma once
#include <windows.h>
#include <string>
/*TODO: singleton*/
namespace UserInterface
{
	class ConsoleInput
	{
	private:
		static ConsoleInput *console;
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];
		std::string mouseEventProc(MOUSE_EVENT_RECORD);
		std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);
		ConsoleInput();
		~ConsoleInput();

	public:
		static ConsoleInput & getInstance(void);
		std::string getUserActions();

		ConsoleInput & operator() (int row, int col);

		template <typename T>
		friend ConsoleInput &operator>> (ConsoleInput &in, T obj)
		{
			std::cin>> obj;
			return in;
		}
	};
}


