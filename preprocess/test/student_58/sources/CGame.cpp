#include "CGame.h"
#include "Manager.h"

bool CGame::lose = false;

void CGame::checkResources()
{
	if (TimeLastResources >= level->RataResource)
	{
		//cream sun
		srand(time(NULL));
		int nr = 0;

		for (int i = 1; i < 12; i++)
			if (locAvailable[i] == true)
				nr++;

		if (nr != 0)
		{
			while (true)
			{
				int p = rand() % 11 + 1;
				if (locAvailable[p] == true)
				{
					resurse.push_back(new CSun(p));
					printCH(resurse[resurse.size() - 1]->y, resurse[resurse.size() - 1]->x, resurse[resurse.size() - 1]->CH);
					locAvailable[p] = false;
					break;
				}
			}
		}

		TimeLastResources = 0;
	}
	else
	{
		TimeLastResources++;
	}
}

void CGame::checkZombies()
{
	static int TimeLastZombie = 0;
	if (TimeLastZombie < level->RataZombie)
		TimeLastZombie++;
	else
	{
		TimeLastZombie = 0;
		if (nrZombies < level->getNrZombie())
		{
			nrZombies++;
			srand(time(NULL));
			int r = rand() % 2 + 1;
			CZombie *z = nullptr;

			int nrrow = 1;
			if (this->level->getLevel() == LEVEL1)
				nrrow = 1;
			else if (this->level->getLevel() == LEVEL2)
				nrrow = 3;
			else
				nrrow = 5;
			srand(time(NULL));
			int row = rand() % nrrow + 1;
			row = (row - 1) * 5 + 6;
			int col = 65;
			bool b = true;
			while (b)
			{
				b = false;
				for (auto z : zombie)
					if (z->x == col && z->y == row)
					{
						col -= 5;
						b = true;
						break;
					}
			}

			switch (r)
			{
			case 1:
				z = new CZombie(row, col);
				Log::logare("Aparitie Zombie.");
				break;
			case 2:
				z = new CBucketHead(row, col);
				Log::logare("Aparitie Bucket Head.");
				break;
			}
			printCH(z->y, z->x, z->CH);
			zombie.push_back(z);
		}
	}

}

void CGame::checkProjectiles()
{
	for (auto p : plante)
	{
		auto pr = p->impusca();
		if (pr != nullptr)
		{
			proiectile.push_back(pr);
			printCH(pr->y, pr->x, pr->CH);
			Log::logare("Aparitie Proiectil Pea.");
		}
	}
}

void CGame::checkColisions()
{
	vector<CProiectil*> desterspr;
	vector<CZombie*> desterszb;
	for (auto pr : proiectile)
	{
		for (auto z : zombie)
		{
			if (pr->y == z->y && pr->x == z->x - 1)
			{
				desterspr.push_back(pr);
				z->lowerHP(pr->getDamage());
				if (z->getHP() == 0)
				{
					desterszb.push_back(z);
					printCH(z->y, z->x, ' ');
					player->setScor(player->getScor() + 10);
					displayScore();
				}
				else
				{
					printCH(z->y, z->x, z->CH);
				}
				printCH(pr->y, pr->x, ' ');
			}
		}
	}
	for (auto s : desterspr)
	{
		auto it = find(proiectile.begin(), proiectile.end(), s);
		if (it != proiectile.end())
			proiectile.erase(it);
		else
			throw Exception("Stergerea din proiectile nu a putut fi realizata.");
		Log::logare("Un proiectil a fost distrus.");
	}
	for (auto s : desterszb)
	{
		auto it = find(zombie.begin(), zombie.end(), s);
		if (it != zombie.end())
			zombie.erase(it);
		else
			throw Exception("Stergerea din zombie nu a putut fi realizata.");
		Log::logare("Un zombie a fost distrus.");
	}
	vector<CPlanta*> desterspl;
	for (auto p : plante)
	{
		for (auto z : zombie)
		{
			if (z->y == p->y && z->x == p->x + 1)
			{
				z->setStop(true);
				p->lowerHP(z->getDamage());
				if (p->getHP() == 0)
				{
					desterspl.push_back(p);
					z->setStop(false);
					printCH(p->y, p->x, ' ');
				}
			}
		}
	}
	for (auto p : desterspl)
	{
		auto it = find(plante.begin(), plante.end(), p);
		if (it != plante.end())
			plante.erase(it);
		else
			throw Exception("Stergerea din plante nu a putut fi realizata.");
		Log::logare("O planta a fost distrusa.");
	}
}

void CGame::checkWin()
{
	if (zombie.size() == 0 && nrZombies == level->getNrZombie())
	{
		system("cls");
		cout << "Nivel incheiat cu succes!\nScor: " << player->getScor() << "\n";
		if (player->getLvl()->getLevel() == LEVEL3)
		{
			Log::logare("S-a ajuns la nivelul 3. Jocul se incheie.");
			cout << "Jocul s-a terminat!\n";
			system("pause");
		}
		else
		{
			system("pause");
			Log::logare("Trecere la nivelul urmator.");
			player->setLevel(player->getLvl()->getLevel() + 2);
			Manager::getInstance().updateUser(player->getName(), player->getScor(), player->getLvl()->getLevel() + 1);
		}
	}
}

CGame::CGame(Utilizator * player)
{
	for (int i = 0; i < 12; i++)
	{
		locAvailable.push_back(true);
	}
	this->player = player;
	TimeLastResources = 0;
	nrZombies = 0;
	plantaCurenta = -1;
}

void CGame::init()
{
	Log::logare("Initializare nivel.");
	NrResurseDisponibile = 200;
	level = player->getLvl();
}


void CGame::displayObjects()
{
	for (auto z : zombie)
	{
		int r = z->y;
		int c = z->x;
		if (z->move())
		{
			printCH(r, c, ' ');
			if (z->x < 14)
			{
				lose = true;
				break;
			}
			printCH(z->y, z->x, z->CH);
		}
	}
	vector<CProiectil*> iesite;
	for (auto p : proiectile)
	{
		int r = p->y;
		int c = p->x;
		if (p->move())
		{
			bool existaPlanta = false;
			for (auto p : plante)
			{
				if (p->x == c && p->y == r)
				{
					printCH(r, c, p->CH);
					existaPlanta = true;
					break;
				}
			}
			if (!existaPlanta)
				printCH(r, c, ' ');
			if (p->x > 65)
			{
				iesite.push_back(p);
			}
			else
				printCH(p->y, p->x, p->CH);
		}
	}
	for (auto desters : iesite)
	{
		proiectile.erase(find(proiectile.begin(), proiectile.end(), desters));
	}
}

void CGame::displayResources()
{
	UserInterface::ConsoleOutput::getInstance()(30, 3) << "Resurse: " << this->NrResurseDisponibile << "   ";
}

void CGame::displayScore()
{
	UserInterface::ConsoleOutput::getInstance()(32, 3) << "Scor: " << player->getScor() << "  ";
}

void CGame::printCH(int row, int col, char ch)
{
	UserInterface::ConsoleOutput::getInstance()(row, col) << ch;

}

void CGame::play()
{
	level->initializeaza_scena();
	level->afiseaza_scena();
	Log::logare("Afisare scena.");

	UserInterface::ConsoleInput::destroyInstance();
	UserInterface::ConsoleOutput::getInstance()(31, 3) << "User: " << player->getName();

	displayResources();
	displayScore();
	auto nivelcurent = player->getLvl()->getLevel();
	while (!lose && nivelcurent == player->getLvl()->getLevel())
	{
		Sleep(500);
		resetPlante();
		checkMouse();
		checkZombies();
		//mutam zombie si proiectilele
		//verificam aparitia sun
		//verificam daca planta trebuie sa traga=aparitia de proiectile
		//functie de verificare click: double-click-apasa pe soare+colecteaza//ia o planta
		//verificam pozitiile: zombie=planta, proiectil=zombie, zombie=casa
		checkProjectiles();
		checkColisions();
		checkResources();
		displayObjects();
		checkWin();
	}
	system("cls");
	if (lose)
	{
		cout << "Game over!\n";
		system("pause");
	}
}

void CGame::resetPlante()
{
	if (CPeaShooter::timpUltimaAparitie > 0)
		CPeaShooter::timpUltimaAparitie--;
	if (CSunFlower::timpUltimaAparitie > 0)
		CSunFlower::timpUltimaAparitie--;
}

void CGame::checkMouse()
{
	string str = UserInterface::ConsoleInput::getInstance().getMouse();

	if (str != "")
	{
		UserInterface::ConsoleOutput::getInstance()(35, 15) << str;
		int row = stoi(str.substr(0, str.find_first_of(' ')));
		int col = stoi(str.substr(str.find_first_of(' ') + 1));

		if (row == 2)
		{
			for (int j = 1; j <= 11; j++)
			{
				if (col >= 10 + j * 5 - 1 && col <= 10 + j * 5 + 1)
				{
					if (locAvailable[j] == false)
					{
						int k;
						for (k = 0;k < resurse.size();k++)
						{
							if (resurse[k]->x == 10 + j * 5)
								break;
						}
						if (k != resurse.size())
						{
							Log::logare("Colectare Resursa de tip Sun.");
							locAvailable[j] = true;
							addResurse(resurse[k]->getVal());
							displayResources();
							printCH(resurse[k]->y, resurse[k]->x, ' ');
							resurse.erase(std::find(resurse.begin(), resurse.end(), resurse[k]));
						}
					}
				}
			}
		}

		if (col == 4)
		{
			switch (row)
			{
			case 6:
				if (NrResurseDisponibile >= CPeaShooter::cost && CPeaShooter::timpUltimaAparitie == 0)
					plantaCurenta = 1;
				break;
			case 11:
				if (NrResurseDisponibile >= CSunFlower::cost &&CSunFlower::timpUltimaAparitie == 0)
					plantaCurenta = 2;
				break;
			default:
				break;
			}
			if (plantaCurenta != -1)
			{
				string nume = "";
				if (plantaCurenta == 1)
					nume = "Pea Shooter";
				else
					nume = "Sun Flower";
				UserInterface::ConsoleOutput::getInstance()(35, 50) << "Planta curenta: " << nume << "   ";
				Log::logare("Planta curenta este " + nume);
			}
		}


		int nrrow = 1;
		if (this->level->getLevel() == LEVEL1)
			nrrow = 1;
		else if (this->level->getLevel() == LEVEL2)
			nrrow = 3;
		else
			nrrow = 5;
		for (int r = 1; r <= nrrow; r++)
		{
			if (row == (r - 1) * 5 + 6 || row == (r - 1) * 5 + 5 || row == (r - 1) * 5 + 7)
				for (int c = 14; c <= 66; c += 5)
				{
					if (col == c || col == c - 1 || col == c + 1)
					{
						UserInterface::ConsoleOutput::getInstance()(37, 25) << r << " " << (c - 14) / 5 + 1 << " ";
						bool free = true;
						for (auto z : zombie)
						{
							if (z->x == c && z->y == (r - 1) * 5 + 6)
							{
								free = false;
								break;
							}
						}
						for (auto p : plante)
						{
							if (p->x == c && p->y == (r - 1) * 5 + 6)
							{
								free = false;
								break;
							}
						}
						CPlanta* p = nullptr;
						if (free)
						{
							switch (plantaCurenta)
							{
							case 1:
								p = new CPeaShooter((r - 1) * 5 + 6, c);
								plante.push_back(p);
								NrResurseDisponibile -= CPeaShooter::cost;
								Log::logare("Aparitie Pea Shooter.");
								CPeaShooter::timpUltimaAparitie = 10;
								break;
							case 2:
								p = new CSunFlower((r - 1) * 5 + 6, c);
								plante.push_back(p);
								NrResurseDisponibile -= CSunFlower::cost;
								CSunFlower::timpUltimaAparitie = 10;
								Log::logare("Aparitie Sun Flower.");
								if (level->RataResource > 0)
									this->level->RataResource--;
								break;
							default:
								break;
							}
						}
						if (p != nullptr)
						{
							printCH(p->y, p->x, p->CH);
							plantaCurenta = -1;
							displayResources();
							UserInterface::ConsoleOutput::getInstance()(35, 50) << "Planta curenta:                ";
						}
					}
				}

		}
	}
}

Utilizator * CGame::getPlayer()
{
	return player;
}


CGame::~CGame()
{
}
