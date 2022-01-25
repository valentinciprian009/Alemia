#include "MY_UTILS.h"
int MY_UTILS::id_ = 0;

MY_UTILS::MY_UTILS()
{

}

MY_UTILS::~MY_UTILS()
{
	
}

int MY_UTILS::GenerateId()
{
	id_++;
	return id_;
}

void MY_UTILS::SetColor(int Value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Value);
}

void MY_UTILS::ClearScreen()
{

	int n;
	for (n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");

}

void MY_UTILS::DrawBox()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	MY_UTILS::SetColor(15);
	char printedChar = 176;
	for (int i = BEGIN_LOGIN_BOX_COL; i <= END_LOGIN_BOX_COL; i++)
	{
		conOut(BEGIN_LOGIN_BOX_ROW, i) << printedChar;
	}

	for (int i = BEGIN_LOGIN_BOX_COL; i <= END_LOGIN_BOX_COL; i++)
	{
		conOut(END_LOGIN_BOX_ROW, i) << printedChar;
	}
	for (int j = BEGIN_LOGIN_BOX_ROW + 1; j <= END_LOGIN_BOX_ROW; j++)
	{
		conOut(j, BEGIN_LOGIN_BOX_COL) << printedChar;
	}
	for (int j = BEGIN_LOGIN_BOX_ROW + 1; j <= END_LOGIN_BOX_ROW; j++)
	{
		conOut(j, END_LOGIN_BOX_COL) << printedChar;
	}
}

int MY_UTILS::RandomSelectElementDisplay()
{
	int n = rand() % 4;
	return n;
}

int  MY_UTILS::RandomCoord_x()
{
	int s = rand() % (9 - 2 + 1) + 2;
	int sel = BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10*s+9;
	return sel;
}

float MY_UTILS::RandomCoord_Y()
{
	int th = rand() % (6 - 1) + 1;

	float chosen = float(BEGIN_LOGIN_BOX_ROW + float(END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 * float(th))+ float(END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 12.00;

	return chosen;
}

int MY_UTILS::RandomCoord_Y_level2()
{
	int th = rand() % (4 - 1) + 1;

	float chosen = float(BEGIN_LOGIN_BOX_ROW + float(END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 * float(th)) + float(END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 12.00;

	return chosen;
}
