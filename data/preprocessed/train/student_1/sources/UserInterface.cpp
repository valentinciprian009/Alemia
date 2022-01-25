#include"UserInterface.h"

void UserInterface::ClearScreen()
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
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
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

void UserInterface::doLoadingBar(int RowLoading, int colFirstStarPosition, int colDistanceBetweenStars, int LoadingPeriod, ConsoleOutput& consoleOut)
{
	static auto begin = steady_clock::now();
	static int col = colFirstStarPosition;
	static string printedChar = "** ";
	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > LoadingPeriod)
	{
		begin = end;
		consoleOut(RowLoading + 1, col) << printedChar;
		if (col >= colFirstStarPosition + 20 * colDistanceBetweenStars) {
			if (printedChar == "** ")
			{
				printedChar = "   ";
			}
			else
			{
				printedChar = "** ";
			}
			col = colFirstStarPosition;
		}
		else
		{
			col += colDistanceBetweenStars;
		}
	}
}

void UserInterface::printTitle(ConsoleOutput& consoleOut)
{
	consoleOut(ROW_GAME_TITLE + 0, COLUMN_GAME_TITLE) << "@@@@@@@    @@@@@@    @@@@@@      @@@  @@@   @@@@@@      @@@@@@@@   @@@@@@   @@@@@@@@@@   @@@@@@@   @@@  @@@@@@@@   @@@@@@   ";
	consoleOut(ROW_GAME_TITLE + 1, COLUMN_GAME_TITLE) << "@@@@@@@@  @@@@@@@@  @@@@@@@@     @@@  @@@  @@@@@@@      @@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@  @@@  @@@@@@@@  @@@@@@@   ";
	consoleOut(ROW_GAME_TITLE + 2, COLUMN_GAME_TITLE) << "@@!  @@@  @@!  @@@  @@!  @@@     @@!  @@@  !@@               @@!  @@!  @@@  @@! @@! @@!  @@!  @@@  @@!  @@!       !@@       ";
	consoleOut(ROW_GAME_TITLE + 3, COLUMN_GAME_TITLE) << "!@!  @!@  !@!  @!@  !@!  @!@     !@!  @!@  !@!              !@!   !@!  @!@  !@! !@! !@!  !@   @!@  !@!  !@!       !@!       ";
	consoleOut(ROW_GAME_TITLE + 4, COLUMN_GAME_TITLE) << "@!@@!@!   @!@  !@!  @!@  !@!     @!@  !@!  !!@@!!          @!!    @!@  !@!  @!! !!@ @!@  @!@!@!@   !!@  @!!!:!    !!@@!!    ";
	consoleOut(ROW_GAME_TITLE + 5, COLUMN_GAME_TITLE) << "!!@!!!    !@!  !!!  !@!  !!!     !@!  !!!   !!@!!!        !!!     !@!  !!!  !@!   ! !@!  !!!@!!!!  !!!  !!!!!:     !!@!!!   ";
	consoleOut(ROW_GAME_TITLE + 6, COLUMN_GAME_TITLE) << "!!:       !!:  !!!  !!:  !!!     :!:  !!:       !:!      !!:      !!:  !!!  !!:     !!:  !!:  !!!  !!:  !!:            !:!  ";
	consoleOut(ROW_GAME_TITLE + 7, COLUMN_GAME_TITLE) << ":!:       :!:  !:!  :!:  !:!      ::!!:!       !:!      :!:       :!:  !:!  :!:     :!:  :!:  !:!  :!:  :!:           !:!   ";
	consoleOut(ROW_GAME_TITLE + 8, COLUMN_GAME_TITLE) << "::       ::::: ::  ::::: ::       ::::    :::: ::       :: ::::  ::::: ::  :::     ::    :: ::::   ::   :: ::::  :::: ::   ";
	consoleOut(ROW_GAME_TITLE + 9, COLUMN_GAME_TITLE) << ":         : :  :    : :  :         :      :: : :       : :: : :   : :  :    :      :    :: : ::   :    : :: ::   :: : :    ";
}

bool UserInterface::pressButton(ConsoleInput& consoleIn, ConsoleOutput& consoleOut, int row_button, int column_button, const string& buttonName)
{
	ConsoleEvent& action = consoleIn.getUserActions();
	if (action.getInfo() != "")
		consoleOut(1, 1) << action.getInfo();
	if (action.getType() == MOUSE_EVENT)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD readCoord = { column_button, row_button };
		char* buttonNameCheck = new char[buttonName.size() + 1];
		DWORD nr_chars_read;
		if (ReadConsoleOutputCharacter(handle, (LPTSTR)buttonNameCheck, buttonName.size(), readCoord, (LPDWORD)&nr_chars_read))
		{
			buttonNameCheck[nr_chars_read] = 0;
			if (string(buttonNameCheck) == buttonName)
			{
				if (action.getInputRecord().Event.MouseEvent.dwMousePosition.Y == row_button && action.getInputRecord().Event.MouseEvent.dwMousePosition.X >= column_button && action.getInputRecord().Event.MouseEvent.dwMousePosition.X <= column_button + buttonName.size())
				{
					if ((action.getInputRecord().Event.MouseEvent.dwEventFlags == 0 && action.getInputRecord().Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) || action.getInputRecord().Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)	//single left click or double click
					{
						delete[] buttonNameCheck;
						return true;
					}
					else if (action.getInputRecord().Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
					{
						consoleOut(row_button, column_button - 4) << "--> ";
						consoleOut(row_button, column_button + buttonName.size()) << " <--";
					}
				}
				else if (action.getInputRecord().Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
				{
					consoleOut(row_button, column_button - 4) << "    ";
					consoleOut(row_button, column_button + buttonName.size()) << "    ";
				}
			}
		}
		delete[] buttonNameCheck;
	}
	return false;
}

bool UserInterface::readTextInput(ConsoleInput& consoleIn, ConsoleOutput& consoleOut, int row_input, int column_input, const string& inputString, string& text)
{
	consoleOut(row_input, column_input) << inputString;
	ConsoleEvent& action = consoleIn(row_input, column_input + inputString.size()).getUserActions();
	if (action.getType() == KEY_EVENT && action.getInputRecord().Event.KeyEvent.bKeyDown)
	{
		if (action.getInputRecord().Event.KeyEvent.wVirtualKeyCode != '\n' && action.getInputRecord().Event.KeyEvent.wVirtualKeyCode != '\r' && action.getInputRecord().Event.KeyEvent.wVirtualKeyCode != '\b')
		{
			text += action.getInputRecord().Event.KeyEvent.uChar.AsciiChar;
			consoleOut(row_input, column_input + inputString.size()) << text;
			!action.getInputRecord().Event.KeyEvent.bKeyDown;
		}
		else if (action.getInputRecord().Event.KeyEvent.wVirtualKeyCode == '\b')
		{
			text.pop_back();
			consoleOut(row_input, column_input + inputString.size()) << text << " ";
			!action.getInputRecord().Event.KeyEvent.bKeyDown;
		}
		else if (action.getInputRecord().Event.KeyEvent.wVirtualKeyCode == '\r')
		{
			consoleOut(row_input, column_input + inputString.size()) << text;
			ConsoleEvent::destroyInstance();
			return false;
		}
	}
	ConsoleEvent::destroyInstance();
	return true;
}