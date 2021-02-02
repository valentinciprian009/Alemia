#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <string>
#include <stdio.h>

namespace UserInterface
{
	class ConsoleInput
	{
	private:
		static ConsoleInput* mpInstance;

		int x, y;

		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];
		std::string mouseEventProc(MOUSE_EVENT_RECORD);
		std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);

		ConsoleInput();
		
	public:
		static ConsoleInput& getInstance();

		void set_x(int x);
		void set_y(int y);
		int get_x();
		int get_y();

		std::string getUserActions();

		virtual ~ConsoleInput() {};

	};
}