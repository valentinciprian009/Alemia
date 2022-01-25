#pragma once
#include <windows.h>
#include <string>

namespace UserInterface
{
	class ConsoleInput
	{
	private:
		std::string			id_player;
		int					level;
		HANDLE				hStdin;
		DWORD				cNumRead;
		DWORD				fdwMode;
		DWORD				fdwSaveOldMode;
		DWORD				i;
		INPUT_RECORD		irInBuf[128];
		std::string			mouseEventProc(MOUSE_EVENT_RECORD);
		std::string			resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string			keyEventProc(KEY_EVENT_RECORD);

		static ConsoleInput *Instance;
		ConsoleInput();

	public:
		
		std::string			get_id();
		int					get_level();
		void				set_level(int x);
		std::string			getUserActions();


		static ConsoleInput & getInstance(void);
		static void DestroyInstance();
		
	};
}


