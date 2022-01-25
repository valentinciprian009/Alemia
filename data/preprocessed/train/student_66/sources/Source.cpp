#define _CRT_SECURE_NO_WARNINGS

#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <conio.h>

#define UNICODE
#define _UNICODE
#define _GLIBCXX_USE_WCHAR_T
#define ROW_TITLE					27		
#define COL_FIRST_STAR_POSITION		69
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;
using namespace std;

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void doLoadingBar()
{
	int t1 = time(NULL), t2;
	do
	{
		static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
		static auto begin = steady_clock::now();
		static int col = COL_FIRST_STAR_POSITION;
		static std::string printedChar = "*";
		auto end = steady_clock::now();
		t2 = time(NULL);

		if (duration_cast<milliseconds>(end - begin).count() > 100)
		{	
			begin = end;
			conOut(ROW_TITLE + 1, col) << printedChar;

			if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) 
			{
				if (printedChar == "*")
				{
					printedChar = " ";
				}
				else
				{
					printedChar = "*";
				}
				col = COL_FIRST_STAR_POSITION;
			}
			else
			{
				col += COL_DISTANCE_BETWEEN_STARS;
			}
		}
	} while (t2-t1<4);
}

void doLogo()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

	wchar_t wide0[] = L"╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗";
	wchar_t wide1[] = L"╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝";
	wchar_t wide2[] = L"▌▌▌▌▌▌▌▌▌▌     ▌▌▌▌▌▌▌▌      ▌▌▌▌▌▌▌▌";
	wchar_t wide3[] = L"▌▌▌▌▌▌▌▌▌▌▌   ▌▌▌▌▌▌▌▌▌▌    ▌▌▌▌▌▌▌▌▌▌";
	wchar_t wide4[] = L"▌▌▌▌    ▌▌▌▌ ▌▌▌▌    ▌▌▌▌  ▌▌▌▌    ▌▌▌▌";
	wchar_t wide5[] = L"▌▌▌▌    ▌▌▌▌ ▌▌▌▌    ▌▌▌▌  ▌▌▌▌    ▌▌▌▌";
	wchar_t wide6[] = L"▌▌▌▌▌▌▌▌▌▌▌▌ ▌▌▌▌    ▌▌▌▌  ▌▌▌▌    ▌▌▌▌";
	wchar_t wide7[] = L"▌▌▌▌▌▌▌▌▌▌▌  ▌▌▌▌    ▌▌▌▌  ▌▌▌▌    ▌▌▌▌";
	wchar_t wide8[] = L"▌▌▌▌▌        ▌▌▌▌    ▌▌▌▌  ▌▌▌▌    ▌▌▌▌";
	wchar_t wide9[] = L"▌▌▌▌▌        ▌▌▌▌    ▌▌▌▌  ▌▌▌▌    ▌▌▌▌";
	wchar_t wide10[] = L"▌▌▌▌▌        ▌▌▌▌    ▌▌▌▌  ▌▌▌▌    ▌▌▌▌";
	wchar_t wide11[] = L"▌▌▌▌▌         ▌▌▌▌▌▌▌▌▌▌    ▌▌▌▌▌▌▌▌▌▌";

	wchar_t wide13[] = L"▌▌▌        ▌▌▌  ▌▌▌▌▌▌▌";
	wchar_t wide14[] = L" ▌▌▌      ▌▌▌   ▌▌▌";
	wchar_t wide15[] = L"  ▌▌▌    ▌▌▌    ▌▌▌▌▌▌▌";
	wchar_t wide16[] = L"   ▌▌▌  ▌▌▌         ▌▌▌";
	wchar_t wide17[] = L"    ▌▌▌▌▌▌      ▌▌▌▌▌▌▌";
                              
	wchar_t wide19[] = L"▌▌▌▌▌▌▌▌▌▌▌▌    ▌▌▌▌▌▌▌▌    ▌▌▌▌▌▌▌       ▌▌▌▌▌▌▌  ▌▌▌▌▌▌▌▌▌▌▌▌    ▌▌▌▌  ▌▌▌▌▌▌▌▌▌▌▌▌";
	wchar_t wide20[] = L" ▌▌▌▌▌▌▌▌▌▌    ▌▌▌▌▌▌▌▌▌▌   ▌▌▌▌ ▌▌▌     ▌▌▌ ▌▌▌▌  ▌▌▌▌     ▌▌▌▌         ▌▌▌▌▌▌▌▌▌▌▌▌";
	wchar_t wide21[] = L"      ▌▌▌▌    ▌▌▌▌    ▌▌▌▌  ▌▌▌▌  ▌▌▌   ▌▌▌  ▌▌▌▌  ▌▌▌▌      ▌▌▌▌  ▌▌▌▌  ▌▌▌▌";
	wchar_t wide22[] = L"     ▌▌▌▌     ▌▌▌▌    ▌▌▌▌  ▌▌▌▌   ▌▌▌ ▌▌▌   ▌▌▌▌  ▌▌▌▌     ▌▌▌▌   ▌▌▌▌  ▌▌▌▌";
	wchar_t wide23[] = L"    ▌▌▌▌      ▌▌▌▌    ▌▌▌▌  ▌▌▌▌     ▌▌▌     ▌▌▌▌  ▌▌▌▌▌▌▌▌▌▌▌▌    ▌▌▌▌  ▌▌▌▌▌▌▌▌▌▌▌▌";
	wchar_t wide24[] = L"   ▌▌▌▌       ▌▌▌▌    ▌▌▌▌  ▌▌▌▌             ▌▌▌▌  ▌▌▌▌     ▌▌▌▌   ▌▌▌▌  ▌▌▌▌▌▌▌▌▌▌▌▌";
	wchar_t wide25[] = L"  ▌▌▌▌        ▌▌▌▌    ▌▌▌▌  ▌▌▌▌             ▌▌▌▌  ▌▌▌▌      ▌▌▌▌  ▌▌▌▌  ▌▌▌▌";
	wchar_t wide26[] = L" ▌▌▌▌         ▌▌▌▌    ▌▌▌▌  ▌▌▌▌             ▌▌▌▌  ▌▌▌▌      ▌▌▌▌  ▌▌▌▌  ▌▌▌▌";
	wchar_t wide27[] = L"▌▌▌▌▌▌▌▌▌▌▌▌  ▌▌▌▌    ▌▌▌▌  ▌▌▌▌             ▌▌▌▌  ▌▌▌▌     ▌▌▌▌   ▌▌▌▌  ▌▌▌▌▌▌▌▌▌▌▌▌";
	wchar_t wide28[] = L"▌▌▌▌▌▌▌▌▌▌▌▌   ▌▌▌▌▌▌▌▌▌▌   ▌▌▌▌             ▌▌▌▌  ▌▌▌▌▌▌▌▌▌▌▌▌    ▌▌▌▌  ▌▌▌▌▌▌▌▌▌▌▌▌";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	conOut(12, 5);
	WriteConsoleW(handle, wide0, wcslen(wide0), NULL, NULL);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	conOut(14, 6);
	WriteConsoleW(handle, wide2, wcslen(wide2), NULL, NULL);
	conOut(15, 6);
	WriteConsoleW(handle, wide3, wcslen(wide3), NULL, NULL);
	conOut(16, 6);
	WriteConsoleW(handle, wide4, wcslen(wide4), NULL, NULL);
	conOut(17, 6);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(18, 6);
	WriteConsoleW(handle, wide6, wcslen(wide6), NULL, NULL);
	conOut(19, 6);
	WriteConsoleW(handle, wide7, wcslen(wide7), NULL, NULL);
	conOut(20, 6);
	WriteConsoleW(handle, wide8, wcslen(wide8), NULL, NULL);
	conOut(21, 6);
	WriteConsoleW(handle, wide9, wcslen(wide9), NULL, NULL);
	conOut(22, 6);
	WriteConsoleW(handle, wide10, wcslen(wide10), NULL, NULL);
	conOut(23, 6);
	WriteConsoleW(handle, wide11, wcslen(wide11), NULL, NULL);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	conOut(19, 46);
	WriteConsoleW(handle, wide13, wcslen(wide13), NULL, NULL);
	conOut(20, 46);
	WriteConsoleW(handle, wide14, wcslen(wide14), NULL, NULL);
	conOut(21, 46);
	WriteConsoleW(handle, wide15, wcslen(wide15), NULL, NULL);
	conOut(22, 46);
	WriteConsoleW(handle, wide16, wcslen(wide16), NULL, NULL);
	conOut(23, 46);
	WriteConsoleW(handle, wide17, wcslen(wide17), NULL, NULL);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	conOut(14, 70);
	WriteConsoleW(handle, wide19, wcslen(wide19), NULL, NULL);
	conOut(15, 70);
	WriteConsoleW(handle, wide20, wcslen(wide20), NULL, NULL);
	conOut(16, 70);
	WriteConsoleW(handle, wide21, wcslen(wide21), NULL, NULL);
	conOut(17, 70);
	WriteConsoleW(handle, wide22, wcslen(wide22), NULL, NULL);
	conOut(18, 70);
	WriteConsoleW(handle, wide23, wcslen(wide23), NULL, NULL);
	conOut(19, 70);
	WriteConsoleW(handle, wide24, wcslen(wide24), NULL, NULL);
	conOut(20, 70);
	WriteConsoleW(handle, wide25, wcslen(wide25), NULL, NULL);
	conOut(21, 70);
	WriteConsoleW(handle, wide26, wcslen(wide26), NULL, NULL);
	conOut(22, 70);
	WriteConsoleW(handle, wide27, wcslen(wide27), NULL, NULL);
	conOut(23, 70);
	WriteConsoleW(handle, wide28, wcslen(wide28), NULL, NULL);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	conOut(25, 5);
	WriteConsoleW(handle, wide1, wcslen(wide0), NULL, NULL);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void doScreenGame()
{
	int k = 0, k1 = 15;
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

	wchar_t wide4[] = L"╔════════╗";
	wchar_t wide5[] = L"║        ║";
	wchar_t wide6[] = L"╚════════╝";
	wchar_t wide7[] = L"╠════════╣";
	wchar_t wide0[] = L"╔════════╤════════╤════════╤════════╤════════╤════════╤════════╤════════╤════════╗";
	wchar_t wide1[] = L"║        │        │        │        │        │        │        │        │        ║";
	wchar_t wide2[] = L"╚════════╧════════╧════════╧════════╧════════╧════════╧════════╧════════╧════════╝";
	wchar_t wide3[] = L"╟────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────╢";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	conOut(8, 20);
	WriteConsoleW(handle, wide4, wcslen(wide4), NULL, NULL);
	conOut(9, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(10, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(11, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(12, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(13, 20);
	WriteConsoleW(handle, wide6, wcslen(wide6), NULL, NULL);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	conOut(14, 20);
	WriteConsoleW(handle, wide4, wcslen(wide4), NULL, NULL);
	conOut(15, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(16, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(17, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(18, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(19, 20);
	WriteConsoleW(handle, wide7, wcslen(wide7), NULL, NULL);
	conOut(20, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(21, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(22, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(23, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(24, 20);
	WriteConsoleW(handle, wide7, wcslen(wide7), NULL, NULL);
	conOut(25, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(26, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(27, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(28, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(29, 20);
	WriteConsoleW(handle, wide7, wcslen(wide7), NULL, NULL);
	conOut(30, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(31, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(32, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(33, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(34, 20);
	WriteConsoleW(handle, wide7, wcslen(wide7), NULL, NULL);
	conOut(35, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(36, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(37, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(38, 20);
	WriteConsoleW(handle, wide5, wcslen(wide5), NULL, NULL);
	conOut(39, 20);
	WriteConsoleW(handle, wide6, wcslen(wide6), NULL, NULL);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	conOut(8, 31);
	WriteConsoleW(handle, wide0, wcslen(wide0), NULL, NULL);
	conOut(9, 31);
	WriteConsoleW(handle, wide1, wcslen(wide1), NULL, NULL);
	conOut(10, 31);
	WriteConsoleW(handle, wide1, wcslen(wide1), NULL, NULL);
	conOut(11, 31);
	WriteConsoleW(handle, wide1, wcslen(wide1), NULL, NULL);
	conOut(12, 31);
	WriteConsoleW(handle, wide1, wcslen(wide1), NULL, NULL);
	conOut(13, 31);
	WriteConsoleW(handle, wide2, wcslen(wide2), NULL, NULL);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	conOut(14, 31);
	WriteConsoleW(handle, wide0, wcslen(wide0), NULL, NULL);
	while (k < 5)
	{
		conOut(k1, 31);
		WriteConsoleW(handle, wide1, wcslen(wide1), NULL, NULL);
		conOut(k1+1, 31);
		WriteConsoleW(handle, wide1, wcslen(wide1), NULL, NULL);
		conOut(k1+2, 31);
		WriteConsoleW(handle, wide1, wcslen(wide1), NULL, NULL);
		conOut(k1+3, 31);
		WriteConsoleW(handle, wide1, wcslen(wide1), NULL, NULL);
		conOut(k1+4, 31);
		WriteConsoleW(handle, wide3, wcslen(wide3), NULL, NULL);
		k1 = k1 + 5;
		k++;
	}
	conOut(k1-1, 31);
	WriteConsoleW(handle, wide2, wcslen(wide2), NULL, NULL);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int main(void)
{
	 static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	 static UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	
	doLogo();
	doLoadingBar();
	//ClearScreen();
	system("CLS");
	SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	doScreenGame();

	while (true)
	{
		string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(1, 1) << action;
		}
	}
}