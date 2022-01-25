#include "Shop.h"

Shop* Shop::instance = nullptr;

Shop& Shop::getInstancee(void)
{
	if (!Shop::instance)
	{
		Shop::instance = new Shop();
	}
	return *Shop::instance;
}

void Shop::gestroyInstance()
{
	if (Shop::instance)
	{
		delete Shop::instance;
		Shop::instance = NULL;
	}
}

void Shop::displayShop()
{
	FrozenPea frozen(100, 70, 0, 0);
	PeaShooter pea(100, 50, 1, 7);
	WallNut wallnut(100, 40, 1, 13);
	SunFlower sunflower(100, 60, 0, 0);
	CherryBomb cherrybomb(100, 80, 0, 0);

	pea.printInShop(6, 1);
	frozen.printInShop(13, 1);
	wallnut.printInShop(19, 1);
	sunflower.printInShop(25, 1);
	cherrybomb.printInShop(31, 1);
}

bool Shop::PeeShooterClicked(string action)
{
	stringstream ss;
	ss << action;

	string temp;
	int found;
	int x = -1;
	int y = -1;

	if (action.find("CLICKED") != std::string::npos)
	{
		while (!ss.eof())
		{
			ss >> temp;
			if (stringstream(temp) >> found)
			{
				if (x == -1)
				{
					x = stoi(temp);
				}
				else
				{
					if (y == -1)
					{
						y = stoi(temp);
					}
				}
			}
			temp = "";
		}
		if ((y < 13) && (y > 6) && (x > 0) && (x < 13))
		{
			return true;
		}
	}
	return false;
}

bool Shop::frozenPeaClicked(string action)
{
	stringstream ss;
	ss << action;

	string temp;
	int found;
	int x = -1;
	int y = -1;

	if (action.find("CLICKED") != std::string::npos)
	{
		while (!ss.eof())
		{
			ss >> temp;
			if (stringstream(temp) >> found)
			{
				if (x == -1)
				{
					x = stoi(temp);
				}
				else
				{
					if (y == -1)
					{
						y = stoi(temp);
					}
				}
			}
			temp = "";
		}
		if ((y < 19) && (y > 12) && (x > 0) && (x < 13))
		{
			return true;
		}
	}
	return false;
}

bool Shop::WallNutClicked(string action)
{
	stringstream ss;
	ss << action;

	string temp;
	int found;
	int x = -1;
	int y = -1;

	if (action.find("CLICKED") != std::string::npos)
	{
		while (!ss.eof())
		{
			ss >> temp;
			if (stringstream(temp) >> found)
			{
				if (x == -1)
				{
					x = stoi(temp);
				}
				else
				{
					if (y == -1)
					{
						y = stoi(temp);
					}
				}
			}
			temp = "";
		}
		if ((y < 25) && (y > 18) && (x > 0) && (x < 13))
		{
			return true;
		}
	}
	return false;
}

bool Shop::SunFlowerClicked(string action)
{
	stringstream ss;
	ss << action;

	string temp;
	int found;
	int x = -1;
	int y = -1;

	if (action.find("CLICKED") != std::string::npos)
	{
		while (!ss.eof())
		{
			ss >> temp;
			if (stringstream(temp) >> found)
			{
				if (x == -1)
				{
					x = stoi(temp);
				}
				else
				{
					if (y == -1)
					{
						y = stoi(temp);
					}
				}
			}
			temp = "";
		}
		if ((y < 31) && (y > 24) && (x > 0) && (x < 13))
		{
			return true;
		}
	}
	return false;
}

bool Shop::CherryBombClicked(string action)
{
	stringstream ss;
	ss << action;

	string temp;
	int found;
	int x = -1;
	int y = -1;

	if (action.find("CLICKED") != std::string::npos)
	{
		while (!ss.eof())
		{
			ss >> temp;
			if (stringstream(temp) >> found)
			{
				if (x == -1)
				{
					x = stoi(temp);
				}
				else
				{
					if (y == -1)
					{
						y = stoi(temp);
					}
				}
			}
			temp = "";
		}
		if ((y < 37) && (y > 30) && (x > 0) && (x < 13))
		{
			return true;
		}
	}
	return false;
}