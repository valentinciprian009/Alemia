#include "ConsoleOutput.h"

using namespace UserInterface;

ConsoleOutput* ConsoleOutput::mpInstance=NULL;

ConsoleOutput& ConsoleOutput::getInstance()
{
	if (mpInstance == NULL)
	{
		mpInstance = new ConsoleOutput();
	}
	return *mpInstance;
}

ConsoleOutput::ConsoleOutput()
{
	// setting console width and height
	HWND console = GetConsoleWindow();
	MoveWindow(console, 0, 0, CON_WIDTH, CON_HEIGHT, TRUE);

	// hiding scrollbar
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);

	// hide blinking cursor
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(handle, &cursorInfo);
}

ConsoleOutput& UserInterface::ConsoleOutput::operator()(int row, int col)
{
	/*should check wether the row and the column values ar within the limits of the current window*/
	COORD coord;
	coord.X = col;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return *this;
}

void UserInterface::ConsoleOutput::doLoadingBar()
{
	int repeats = 13000000;
	while (repeats != 0)
	{
		static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		static auto begin = std::chrono::steady_clock::now();
		static int col = COL_FIRST_STAR_POSITION;
		static std::string printedChar = "*";

		auto end = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() > 150)
		{
			begin = end;
			conOut(ROW_TITLE + 1, col) << printedChar;
			if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
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
		repeats--;
	}
	system("cls");
}