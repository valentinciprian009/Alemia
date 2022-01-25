#include "CLevel3.h"

CLevel3::CLevel3()
{
	CLog::getInstance().printLog("S-a apelat constructorul clasei CLevel3.\n");
	this->level_ = 3;
	this->Nb_Zombies_ = 1;
	this->lives_ = 1;
}

CLevel3::~CLevel3()
{
	CLog::getInstance().printLog("S-a apelat destrucorul explicit al clasei CLevel3.\n");
}

void CLevel3::DrawLand()
{
	MY_UTILS::DrawBox();
	char printedChar = 205;
	MY_UTILS::SetColor(10);
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (float i = float(BEGIN_LOGIN_BOX_ROW + float(END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00); i <= END_LOGIN_BOX_ROW-1 ; i = i + float((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00))
	{
		for (int k = BEGIN_LOGIN_BOX_COL + 1; k <= END_LOGIN_BOX_COL ; k++)
			conOut(i, k) << printedChar;
	}
	for (float i = float(BEGIN_LOGIN_BOX_ROW + float(END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00); i <= END_LOGIN_BOX_ROW; i++)
		conOut(i, END_LOGIN_BOX_COL) << " ";
	char printedChar2 = 186;
	MY_UTILS::SetColor(14);
	for (float i = float(BEGIN_LOGIN_BOX_COL + float(END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10.00); i <= float(END_LOGIN_BOX_COL - float(END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10.00); i = i + float((END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10.00))
	{
		for (int j = 0; j < 4; j++)
		{
			conOut(BEGIN_LOGIN_BOX_ROW + j + 1, i) << printedChar2;
			if (i == float(BEGIN_LOGIN_BOX_COL + float(END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10.00))
				for (int k = BEGIN_LOGIN_BOX_ROW + 1; k <= END_LOGIN_BOX_ROW - 1; k++)
					conOut(k, i) << printedChar2;
		}
	}
	
	MY_UTILS::SetColor(12);
	conOut(BEGIN_LOGIN_BOX_ROW + 1, BEGIN_LOGIN_BOX_COL + 2) << "SCOREBOARD";
	FILE* fin = fopen("PlantsInfo.txt", "w");
	fprintf(fin, "PLANT\t\tX\tY\tCOST\tRESISTANCE\tShooting frequency\n");

	conOut((BEGIN_LOGIN_BOX_ROW + (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 + 3), BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 20 - 4) << char(225);//peashooter
	int y = BEGIN_LOGIN_BOX_ROW + (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 + 3;
	int x = BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 20 - 4;
	fprintf(fin, "%s\t%d\t%d\t%d\t  %d\t\t%d\n", "PeaShooter", x, y, 10, 4, 10);//10=feecventa de tragere

	conOut((BEGIN_LOGIN_BOX_ROW + 2 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 + 3), BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 20 - 4) << char(228);
	y = BEGIN_LOGIN_BOX_ROW + 2 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 + 3;
	fprintf(fin, "%s\t%d\t%d\t%d\t  %d\t\t%d\n", "SunFlower", x, y, 10, 3, 0);

	conOut((BEGIN_LOGIN_BOX_ROW + 3 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 + 3), BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 20 - 4) << char(224);
	y = BEGIN_LOGIN_BOX_ROW + 3 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 + 3;
	fprintf(fin, "%s\t%d\t%d\t%d\t  %d\t\t%d\n", "CherryBomb", x, y, 150, 5, 0);

	conOut((BEGIN_LOGIN_BOX_ROW + 4 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 + 3), BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 20 - 4) << char(229);
	y = BEGIN_LOGIN_BOX_ROW + 4 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 + 3;
	fprintf(fin, "%s\t\t%d\t%d\t%d\t  %d\t\t%d\n", "WallNut", x, y, 200, 10, 0);

	conOut((BEGIN_LOGIN_BOX_ROW + 5 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 + 3), BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 20 - 4) << char(227);
	y = BEGIN_LOGIN_BOX_ROW + 5 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 + 3;
	fprintf(fin, "%s\t\t%d\t%d\t%d\t  %d\t\t%d\n", "SnowPea", x, y, 10, 6, 0);

	fclose(fin);
}
