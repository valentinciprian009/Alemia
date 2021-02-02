#include "GAME.h"

GAME* GAME::instance = nullptr;

GAME& GAME::getInstance(void)
{
	if (!GAME::instance)
	{
		GAME::instance = new GAME();
	}
	return *GAME::instance;
}

void GAME::destroyInstance()
{
	if(GAME::instance)
	{
		delete GAME::instance;
		GAME::instance = NULL;
	}
}

bool GAME::sunClicked(string action, int& X, int& Y)
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
		if ((y < 7) && (y > 0) && (x > 12) && ((x % 12) != 0))
		{
			X = x / 12;
			Y = y;
			return true;
		}
	}

	return false;
}

bool GAME::clickedInGarden(string action, int level, int& X, int &Y)
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
	}
	if (level == 1)
	{
		if ((y < 25) && (y > 18) && (x > 12) && (x < 120) && ((x % 12) != 0))
		{
			X = x / 12;
			Y = y / 6;
			Y++;
			return true;
		}
	}
	if (level == 2)
	{
		if ((y < 31) && (y > 12) && (x > 12) && (x < 120) && ((x % 12) != 0))
		{
			X = x / 12;
			Y = y / 6;
			Y++;
			return true;
		}
	}
	if (level == 3)
	{
		if ((y < 37) && (y > 6) && (x > 12) && (x < 120) && ((x % 12) != 0))
		{
			X = x / 12;
			Y = y / 6;
			Y++;
			return true;
		}
	}
	return false;
}

bool GAME::searchPlantInVector(vector<Cadran*> locations, int X, int Y)
{
	if (!locations.empty())
	{
		auto it = locations.begin();
		while (it != locations.end())
		{
			if ((*it)->getLineNumber() == Y && (*it)->getColNumber() == X)
			{
				return false;
			}
			else
			{
				it++;
			}
		}
	}
	return true;
}

void GAME::generateWave(vector<Zombie*>& zombies, int level)
{
	int zombieNr;
	int superZNr;

	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<int> distribution(1, 3);
	if (level == 1)
	{
		int it = 0;
		superZNr = distribution(generator);
		superZNr--;
		while (it < 3)
		{
			if (superZNr == it)
			{
				zombies.push_back(new SuperZombie(120, 18, 133));
			}
			else
			{
				zombieNr = distribution(generator);
				if (zombieNr == 1)
				{
					zombies.push_back(new SimpleZombie(100, 18, 133));
				}
				else
				{
					if (zombieNr == 2)
					{
						zombies.push_back(new BucketHeadZ(100, 18, 133));
					}
					else
					{
						if (zombieNr == 3)
						{
							zombies.push_back(new PoleVaultingZ(100, 18, 133));
						}
					}
				}
			}
			it++;
		}
	}
	if (level == 2)
	{
		superZNr = distribution(generator);
		superZNr--;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((superZNr == j) && (superZNr == i))
				{
					if (i == 0)
					{
						zombies.push_back(new SuperZombie(120, 12, 133));
					}
					else
					{
						if (i == 1)
						{
							zombies.push_back(new SuperZombie(120, 18, 133));
						}
						else
						{
							if (i == 2)
							{
								zombies.push_back(new SuperZombie(120, 24, 133));
							}
						}
					}
				}
				else
				{
					zombieNr = distribution(generator);
					if (zombieNr == 1)
					{
						if (i == 0)
						{
							zombies.push_back(new SimpleZombie(100, 12, 133));
						}
						else
						{
							if (i == 1)
							{
								zombies.push_back(new SimpleZombie(100, 18, 133));
							}
							else
							{
								if (i == 2)
								{
									zombies.push_back(new SimpleZombie(100, 24, 133));
								}
							}
						}
					}
					else
					{
						if (zombieNr == 2)
						{
							if (i == 0)
							{
								zombies.push_back(new BucketHeadZ(100, 12, 133));
							}
							else
							{
								if (i == 1)
								{
									zombies.push_back(new BucketHeadZ(100, 18, 133));
								}
								else
								{
									if (i == 2)
									{
										zombies.push_back(new BucketHeadZ(100, 24, 133));
									}
								}
							}
						}
						else
						{
							if (zombieNr == 3)
							{
								if (i == 0)
								{
									zombies.push_back(new PoleVaultingZ(100, 12, 133));
								}
								else
								{
									if (i == 1)
									{
										zombies.push_back(new PoleVaultingZ(100, 18, 133));
									}
									else
									{
										if (i == 2)
										{
											zombies.push_back(new PoleVaultingZ(100, 24, 133));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (level == 3)
	{
		superZNr = distribution(generator);
		superZNr--;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((superZNr == j) && (superZNr == i))
				{
					if (i == 0)
					{
						zombies.push_back(new SuperZombie(120, 6, 133));
					}
					else
					{
						if (i == 1)
						{
							zombies.push_back(new SuperZombie(120, 12, 133));
						}
						else
						{
							if (i == 2)
							{
								zombies.push_back(new SuperZombie(120, 18, 133));
							}
							else
							{
								if (i == 3)
								{
									zombies.push_back(new SuperZombie(120, 24, 133));
								}
								else
								{
									if (i == 4)
									{
										zombies.push_back(new SuperZombie(120, 30, 133));
									}
								}
							}
						}
					}
				}
				else
				{
					zombieNr = distribution(generator);
					if (zombieNr == 1)
					{
						if (i == 0)
						{
							zombies.push_back(new SimpleZombie(100, 6, 133));
						}
						else
						{
							if (i == 1)
							{
								zombies.push_back(new SimpleZombie(100, 12, 133));
							}
							else
							{
								if (i == 2)
								{
									zombies.push_back(new SimpleZombie(100, 18, 133));
								}
								else
								{
									if (i == 3)
									{
										zombies.push_back(new SimpleZombie(100, 24, 133));
									}
									else
									{
										if (i == 4)
										{
											zombies.push_back(new SimpleZombie(100, 30, 133));
										}
									}
								}
							}
						}
					}
					else
					{
						if (zombieNr == 2)
						{
							if (i == 0)
							{
								zombies.push_back(new BucketHeadZ(100, 6, 133));
							}
							else
							{
								if (i == 1)
								{
									zombies.push_back(new BucketHeadZ(100, 12, 133));
								}
								else
								{
									if (i == 2)
									{
										zombies.push_back(new BucketHeadZ(100, 18, 133));
									}
									else
									{
										if (i == 3)
										{
											zombies.push_back(new BucketHeadZ(100, 24, 133));
										}
										else
										{
											if (i == 4)
											{
												zombies.push_back(new BucketHeadZ(100, 30, 133));
											}
										}
									}
								}
							}
						}
						else
						{
							if (zombieNr == 3)
							{
								if (i == 0)
								{
									zombies.push_back(new PoleVaultingZ(100, 6, 133));
								}
								else
								{
									if (i == 1)
									{
										zombies.push_back(new PoleVaultingZ(100, 12, 133));
									}
									else
									{
										if (i == 2)
										{
											zombies.push_back(new PoleVaultingZ(100, 18, 133));
										}
										else
										{
											if (i == 3)
											{
												zombies.push_back(new PoleVaultingZ(100, 24, 133));
											}
											else
											{
												if (i == 4)
												{
													zombies.push_back(new PoleVaultingZ(100, 30, 133));
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void GAME::printFirstWave(vector<Zombie*>& zombies, int level)
{
	if (level == 1)
	{
		zombies[0]->print();
	}
	if (level == 2)
	{
		zombies[0]->print();
		zombies[3]->print();
		zombies[6]->print();
	}
	if (level == 3)
	{
		zombies[0]->print();
		zombies[4]->print();
		zombies[8]->print();
		zombies[12]->print();
		zombies[16]->print();
	}
}

void GAME::printSecondWave(vector<Zombie*>& zombies, int level)
{
	if (level == 1)
	{
		zombies[1]->print();
	}
	if (level == 2)
	{
		zombies[1]->print();
		zombies[4]->print();
		zombies[7]->print();
	}
	if (level == 3)
	{
		zombies[1]->print();
		zombies[5]->print();
		zombies[9]->print();
		zombies[13]->print();
		zombies[17]->print();
	}
}

void GAME::printThirdWave(vector<Zombie*>& zombies, int level)
{
	if (level == 1)
	{
		zombies[2]->print();
	}
	if (level == 2)
	{
		zombies[2]->print();
		zombies[5]->print();
		zombies[8]->print();
	}
	if (level == 3)
	{
		zombies[1]->print();
		zombies[6]->print();
		zombies[10]->print();
		zombies[14]->print();
		zombies[18]->print();
	}
}

void GAME::printForthWave(vector<Zombie*>& zombies, int level)
{
	if (level == 3)
	{
		zombies[3]->print();
		zombies[7]->print();
		zombies[11]->print();
		zombies[15]->print();
		zombies[19]->print();
	}
}

void GAME::startGame()
{
	bool LOST = true;

	UserInterface::ConsoleOutput& conOutt = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput& conInn = UserInterface::ConsoleInput::getInstance();
	std::string action = " ";

	Log& log = Log::getInstance();

	vector<Sun*> suns;
	vector<Cadran*> peaShooterLocations;
	vector<Cadran*> frozenPeaLocations;
	vector<Cadran*> wallNutLocations;
	vector<Cadran*> SunFlowerLocations;
	vector<Cadran*> CherryBombLocations;

	vector<Zombie*> allZombies;
	vector<bool> okWave(5, false);

	vector<Proiectile*> proiectil;
	vector<Proiectile*> frozens;

	int X, Y, Z;
	bool ok;
	int sunTime = 9000;

	Player& player = Player::getInstance();
	player.setBudget(60);

	FrozenPea frozenPea(100, 70, 0, 0);
	PeaShooter peaShooter(100, 50, 0, 0);
	WallNut wallNut(120, 40, 0, 0);
	SunFlower sunflower(100, 60, 0, 0);
	CherryBomb cherrybomb(120, 80, 0, 0);

	PlayGround& garden = PlayGround::getInstance();
	Shop& shop = Shop::getInstancee();

	shop.setpeeSClicked(false);
	shop.setFrozenClicked(false);
	shop.setWallNutClicked(false);
	shop.setSunFlowerClicked(false);
	shop.setCherryBombClicked(false);

	if (player.getLevel() == 1)
	{
		garden.printFirstLevel();
	}
	if (player.getLevel() == 2)
	{
		garden.printSecondLevel();
	}
	if (player.getLevel() == 3)
	{
		garden.printThirdLevel();
	}

	shop.displayShop();
	conOutt(2, 3);
	cout << "SCORE:";
	conOutt(3, 5);
	cout << player.getScore() << "   ";
	conOutt(2, 145);
	cout << "Wellcome to " << player.getName() << "'s house : ) ";
	conOutt(3, 150);
	cout << "Your budget is -> " << player.getBudget();

	auto begin = steady_clock::now();

	generateWave(allZombies, player.getLevel());
	printFirstWave(allZombies, player.getLevel());

	while (LOST)
	{
		X = 0; Y = 0;
		auto end = steady_clock::now();
		if (duration_cast<milliseconds>(end - begin).count() > sunTime)
		{   
			suns.push_back(new Sun);
			begin = end;
		}

		action = conInn.getUserActions();
		if (action != "")
		{
			conOutt(46, 1) << action;
			if (sunClicked(action, X, Y))
			{
				for (auto it = suns.begin(); it != suns.end(); it++)
				{
					Z = (*it)->getY();
					Z = Z - 1;
					if ((Z / 12) == X)
					{
						delete (*it);
						player.setBudget(player.getBudget() + 50);
						conOutt(3, 150);
						cout << "Your budget is -> " << player.getBudget() << "   ";
						log.addEvent("You'we clicked the SUN.");
					}
				}
			}
			else
			{
				conOutt(80, 1) << "         ";
			}
			if (shop.PeeShooterClicked(action))
			{
				if (player.getBudget() >= 50)
				{
					conOutt(11, 130);
					cout << "You clicked the pea shooter. Make your move!";
					log.addEvent("You'we clicked the PeaShooter.");
					shop.setpeeSClicked(true);
					shop.setFrozenClicked(false);
					shop.setWallNutClicked(false);
					shop.setSunFlowerClicked(false);
					shop.setCherryBombClicked(false);
				}
				else
				{
					conOutt(11, 130);
					cout << "You need MORE money to buy this!";
					shop.setpeeSClicked(false);
				}
				if (!peaShooter.testTime(2500))
				{
					conOutt(11, 130);
					cout << "You CAN'T BUY this plant! It hasn't grown yet!";
					shop.setpeeSClicked(false);
				}
			}
			else
			{
				if (shop.frozenPeaClicked(action))
				{
					if (player.getBudget() >= 70)
					{
						conOutt(11, 130);
						cout << "You clicked the Frozen Pea. Make your move!";
						shop.setFrozenClicked(true);
						log.addEvent("You'we clicked the Frozen Pea.");
					}
					else
					{
						conOutt(11, 130);
						cout << "You need MORE money to buy this!";
						shop.setFrozenClicked(false);
					}
					if (!frozenPea.testTime(2000))
					{
						conOutt(11, 130);
						cout << "You CAN'T BUY this plant! It hasn't grown yet!";
						shop.setFrozenClicked(false);
						shop.setpeeSClicked(false);
						shop.setWallNutClicked(false);
						shop.setSunFlowerClicked(false);
						shop.setCherryBombClicked(false);
					}
				}
				else
				{
					if (shop.WallNutClicked(action))
					{
						if (player.getBudget() >= 40)
						{
							conOutt(11, 130);
							cout << "You clicked the WallNut. Make your move!";
							log.addEvent("You'we clicked the WallNut.");
							shop.setWallNutClicked(true);
							shop.setpeeSClicked(false);
							shop.setFrozenClicked(false);
							shop.setSunFlowerClicked(false);
							shop.setCherryBombClicked(false);
						}
						else
						{
							conOutt(11, 130);
							cout << "You need MORE money to buy this!";
							shop.setWallNutClicked(false);
						}
						if (!wallNut.testTime(2000))
						{
							conOutt(11, 130);
							cout << "You CAN'T BUY this plant! It hasn't grown yet!";
							shop.setWallNutClicked(false);
						}
					}
					else
					{
						if (shop.SunFlowerClicked(action))
						{
							if (player.getBudget() >= 60)
							{
								conOutt(11, 130);
								cout << "You clicked the SunFlower. Make your move!";
								log.addEvent("You'we clicked the SunFlower.");
								shop.setSunFlowerClicked(true);
								shop.setpeeSClicked(false);
								shop.setFrozenClicked(false);
								shop.setWallNutClicked(false);
								shop.setCherryBombClicked(false);
							}
							else
							{
								conOutt(11, 130);
								cout << "You need MORE money to buy this!";
								shop.setSunFlowerClicked(false);
							}
							if (!sunflower.testTime(6000))
							{
								conOutt(11, 130);
								cout << "You CAN'T BUY this plant! It hasn't grown yet!";
								shop.setSunFlowerClicked(false);
							}
						}
						else
						{
							if (shop.CherryBombClicked(action))
							{
								if (player.getBudget() >= 80)
								{
									conOutt(11, 130);
									cout << "You clicked the CherryBomb. Make your move!";
									log.addEvent("You'we clicked the CherryBomb.");
									shop.setCherryBombClicked(true);
									shop.setpeeSClicked(false);
									shop.setFrozenClicked(false);
									shop.setWallNutClicked(false);
									shop.setSunFlowerClicked(false);
								}
								else
								{
									conOutt(11, 130);
									cout << "You need MORE money to buy this!";
									shop.setCherryBombClicked(false);
								}
								if (!cherrybomb.testTime(11000))
								{
									conOutt(11, 130);
									cout << "You CAN'T BUY this plant! It hasn't grown yet!";
									shop.setCherryBombClicked(false);
								}
							}
							else
							{
								conOutt(11, 130);
								cout << "                                                          ";
							}
						}
					}
				}
			}
			if (clickedInGarden(action, player.getLevel(), X, Y) && shop.getpeeSClicked())
			{
				ok = true;
				if (searchPlantInVector(peaShooterLocations, X, Y) && searchPlantInVector(frozenPeaLocations, X, Y) && searchPlantInVector(wallNutLocations, X, Y) && searchPlantInVector(SunFlowerLocations, X, Y) && searchPlantInVector(CherryBombLocations, X, Y))
				{
					ok = true;
				}
				else
				{
					conOutt(11, 130);
					cout << "You ALREADY have a plant here!";
					shop.setpeeSClicked(false);
					ok = false;
				}
				if (ok)
				{
					peaShooter.printInCadran(Y, X);
					peaShooterLocations.push_back(new Cadran(X, Y));
					X = X * 12;
					X++;
					Y--;
					Y = Y * 6;
					proiectil.push_back(new Proiectile(233, Y + 4, X + 6));
					proiectil.back()->printTheProiectile(5);
					player.setBudget(player.getBudget() - 50);
					conOutt(3, 150);
					cout << "Your budget is -> " << player.getBudget() << "   ";
					shop.setpeeSClicked(false);
					log.addEvent("You'we planted a PeaShooter.");
				}
			}
			else
			{
				if (clickedInGarden(action, player.getLevel(), X, Y) && shop.getWallNutClicked())
				{
					ok = true;
					if (searchPlantInVector(peaShooterLocations, X, Y) && searchPlantInVector(frozenPeaLocations, X, Y) && searchPlantInVector(wallNutLocations, X, Y) && searchPlantInVector(SunFlowerLocations, X, Y) && searchPlantInVector(CherryBombLocations, X, Y))
					{
						ok = true;
					}
					else
					{
						conOutt(11, 130);
						cout << "You ALREADY have a plant here!";
						shop.setWallNutClicked(false);
						ok = false;
					}
					if (ok)
					{
						wallNut.printInCadran(Y, X);
						wallNutLocations.push_back(new Cadran(X, Y));
						log.addEvent("You'we planted a WallNut.");
						player.setBudget(player.getBudget() - 40);
						conOutt(3, 150);
						cout << "Your budget is -> " << player.getBudget() << "   ";
						shop.setWallNutClicked(false);
					}
				}
				else
				{
					if (clickedInGarden(action, player.getLevel(), X, Y) && shop.getFrozenClicked())
					{
						ok = true;
						if (searchPlantInVector(peaShooterLocations, X, Y) && searchPlantInVector(frozenPeaLocations, X, Y) && searchPlantInVector(wallNutLocations, X, Y) && searchPlantInVector(SunFlowerLocations, X, Y) && searchPlantInVector(CherryBombLocations, X, Y))
						{
							ok = true;
						}
						else
						{
							conOutt(11, 130);
							cout << "You ALREADY have a plant here!";
							shop.setFrozenClicked(false);
							ok = false;
						}
						if (ok)
						{
							frozenPea.printInCadran(Y, X);
							frozenPeaLocations.push_back(new Cadran(X, Y));
							X = X * 12;
							X++;
							Y--;
							Y = Y * 6;
							frozens.push_back(new Proiectile(42, Y + 4, X + 6));
							frozens.back()->printTheProiectile(1);
							player.setBudget(player.getBudget() - 70);
							conOutt(3, 150);
							cout << "Your budget is -> " << player.getBudget() << "   ";
							shop.setFrozenClicked(false);
							log.addEvent("You'we planted a FrozenPea.");
						}
					}
					else
					{
						if (clickedInGarden(action, player.getLevel(), X, Y) && shop.getSunFlowerClicked())
						{
							ok = true;
							if (searchPlantInVector(peaShooterLocations, X, Y) && searchPlantInVector(frozenPeaLocations, X, Y) && searchPlantInVector(wallNutLocations, X, Y) && searchPlantInVector(SunFlowerLocations, X, Y) && searchPlantInVector(CherryBombLocations, X, Y))
							{
								ok = true;
							}
							else
							{
								conOutt(11, 130);
								cout << "You ALREADY have a plant here!";
								shop.setSunFlowerClicked(false);
								ok = false;
							}
							if (ok)
							{
								sunflower.printInCadran(Y, X);
								sunTime -= 80;
								SunFlowerLocations.push_back(new Cadran(X, Y));
								player.setBudget(player.getBudget() - 60);
								conOutt(3, 150);
								cout << "Your budget is -> " << player.getBudget() << "   ";
								shop.setSunFlowerClicked(false);
								log.addEvent("You'we planted a SunFlower.");
							}
						}
						else
						{
							if (clickedInGarden(action, player.getLevel(), X, Y) && shop.getCherryBombClicked())
							{
								ok = true;
								if (searchPlantInVector(peaShooterLocations, X, Y) && searchPlantInVector(frozenPeaLocations, X, Y) && searchPlantInVector(wallNutLocations, X, Y) && searchPlantInVector(SunFlowerLocations, X, Y) && searchPlantInVector(CherryBombLocations, X, Y))
								{
									ok = true;
								}
								else
								{
									conOutt(11, 130);
									cout << "You ALREADY have a plant here!";
									shop.setCherryBombClicked(false);
									ok = false;
								}
								if (ok)
								{
									cherrybomb.printInCadran(Y, X);
									CherryBombLocations.push_back(new Cadran(X, Y));
									player.setBudget(player.getBudget() - 80);
									conOutt(3, 150);
									cout << "Your budget is -> " << player.getBudget() << "   ";
									shop.setCherryBombClicked(false);
									log.addEvent("You'we planted a CherryBomb.");
								}
							}
							else
							{
								conOutt(12, 130);
								cout << "                                                    ";
							}
						}
					}
				}
			}
			for (auto it = proiectil.begin(); it != proiectil.end(); it++)
			{
				if ((*it)->testTime(900) && (*it)->getY() < 129)
				{
					(*it)->moveProiectile(5);
				}
			}
			for (auto it = frozens.begin(); it != frozens.end(); it++)
			{
				if ((*it)->testTime(1000) && (*it)->getY() < 129)
				{
					(*it)->moveProiectile(1);
				}
			}
			for (auto it = peaShooterLocations.begin(); it != peaShooterLocations.end(); it++)
			{
				if ((*it)->testTime(4000))
				{
					Y = (*it)->getLineNumber();
					X = (*it)->getColNumber();
					X = X * 12;
					X++;
					Y--;
					Y = Y * 6;
					proiectil.push_back(new Proiectile(233, Y + 4, X + 6));
					proiectil.back()->printTheProiectile(5);
				}
			}
			for (auto it = frozenPeaLocations.begin(); it != frozenPeaLocations.end(); it++)
			{
				if ((*it)->testTime(4000))
				{
					Y = (*it)->getLineNumber();
					X = (*it)->getColNumber();
					X = X * 12;
					X++;
					Y--;
					Y = Y * 6;
					frozens.push_back(new Proiectile(42, Y + 4, X + 6));
					frozens.back()->printTheProiectile(1);
				}
			}
				
			if (player.getLevel() == 1 && okWave[0] == false)
			{
				if (allZombies[0]->testTime(6000))
				{
					if (allZombies[0]->gety() > 13)
					{
						allZombies[0]->move();
					}
					else
					{
						allZombies[0]->spaceIt();
						LOST = false;
					}
				}
				for (auto it = proiectil.begin(); it != proiectil.end(); it++)
				{
					if ((*it)->getY() == (allZombies[0]->gety() - 2))
					{
						if (allZombies[0]->getLife() > 0)
						{
							allZombies[0]->getDamaged(20);
							player.setScore(player.getScore() + 20);
							conOutt(3, 5);
							cout << player.getScore() << "   ";
							(*it)->setY(200);
							(*it)->setX(40);
						}
						else
						{
							allZombies[0]->spaceIt();
							log.addEvent("You'we killed a zombie.");
							okWave[0] = true;
						}
					}
				}
				for (auto it = frozens.begin(); it != frozens.end(); it++)
				{
					if ((*it)->getY() == (allZombies[0]->gety() - 2))
					{
						if (allZombies[0]->getLife() > 0)
						{
							allZombies[0]->getDamaged(20);
							player.setScore(player.getScore() + 20);
							conOutt(3, 5);
							cout << player.getScore() << "   ";
							(*it)->setY(200);
							(*it)->setX(40);
						}
						else
						{
							allZombies[0]->spaceIt();
							log.addEvent("You'we killed a zombie.");
							okWave[0] = true;
						}
					}
				}
			}
			/*if (player.getLevel() == 1 && okWave[0] == true && okWave[1] == false)
			{
				if (allZombies[0]->testTime(6000))
				{
					if (allZombies[0]->gety() > 13)
					{
						allZombies[0]->move();
					}
					else
					{
						allZombies[0]->spaceIt();
						LOST = false;
					}
				}
				for (auto it = proiectil.begin(); it != proiectil.end(); it++)
				{
					if ((*it)->getY() == (allZombies[0]->gety() - 2))
					{
						if (allZombies[0]->getLife() > 0)
						{
							allZombies[0]->getDamaged(20);
						}
						else
						{
							allZombies[0]->spaceIt();
							okWave[0] = true;
						}
					}
				}
			}*/
			log.printLogInFolder();
		}
	}
	
}