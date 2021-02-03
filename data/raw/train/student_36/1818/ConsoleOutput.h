#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define CON_WIDTH 1280
#define CON_HEIGHT 720

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>

namespace UserInterface 
{
	class ConsoleOutput
	{
	private:
		static ConsoleOutput* mpInstance;

		ConsoleOutput();
		
	public:
		static ConsoleOutput& getInstance();

		void doLoadingBar();

		virtual ~ConsoleOutput() {};

		ConsoleOutput& operator() (int row, int col);

		template <typename T>
		friend ConsoleOutput& operator<< (ConsoleOutput& out, T obj)
		{
			std::cout << obj;
			return out;
		}

	};
}