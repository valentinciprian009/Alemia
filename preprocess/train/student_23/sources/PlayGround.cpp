#include "PlayGround.h"

PlayGround* PlayGround::instance = nullptr;

PlayGround& PlayGround::getInstance(void)
{
	if (!PlayGround::instance)
	{
		PlayGround::instance = new PlayGround();
	}
	return *PlayGround::instance;
}

void PlayGround::destroyInstance()
{
	if (PlayGround::instance)
	{
		delete PlayGround::instance;
		PlayGround::instance = NULL;
	}
}

void PlayGround::printFirstLevel()
{
	cout << " _______________________________________________________________________________________________________________________" << endl;
	for (int i = 1; i <= 36; i++)
	{
		for (int j = 0; j <= 120; j++)
		{
			if ((((i <= 17) && (i >= 7)) || ((i <= 36) && (i >= 25))) && ((j <= 120) && (j >= 13)))
			{
				cout << " ";
			}
			else
			{
				if ((j == 0) || (j % 12 == 0))
				{
					if ((i == 18) && (j > 12) && (j % 12 == 0))
					{
						if (j != 120)
						{
							cout << "_";
						}
					}
					else
					{
						cout << "|";
					}
				}
				else
				{
					if ((i != 0) && (i % 6 == 0))
					{
						cout << "_";
					}
					else
					{
						cout << " ";
					}
				}
			}
		}
		cout << endl;
	}
}

void PlayGround::printSecondLevel()
{
	cout << " _______________________________________________________________________________________________________________________" << endl;
	for (int i = 1; i <= 36; i++)
	{
		for (int j = 0; j <= 120; j++)
		{
			if ((((i <= 11) && (i >= 7)) || ((i <= 36) && (i >= 31))) && ((j <= 120) && (j >= 13)))
			{
				cout << " ";
			}
			else
			{
				if ((j == 0) || (j % 12 == 0))
				{
					if ((i == 12) && (j > 12) && (j % 12 == 0))
					{
						if (j != 120)
						{
							cout << "_";
						}
					}
					else
					{
						cout << "|";
					}
				}
				else
				{
					if ((i != 0) && (i % 6 == 0))
					{
						cout << "_";
					}
					else
					{
						cout << " ";
					}
				}
			}
		}
		cout << endl;
	}
}

void PlayGround::printThirdLevel()
{
	cout << " _______________________________________________________________________________________________________________________" << endl;
	for (int i = 1; i <= 36; i++)
	{
		for (int j = 0; j <= 120; j++)
		{
			if ((j == 0) || (j % 12 == 0))
			{
				cout << "|";
			}
			else
			{
				if ((i != 0) && (i % 6 == 0))
				{
					cout << "_";
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}