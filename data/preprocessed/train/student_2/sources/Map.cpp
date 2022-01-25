#include "Map.h"
#include "ConsoleOutput.h"
#include <fstream>
#include "Sunflower.h"
#include "BlankSpace.h"
#include "PeaShooter.h"
#include "Game.h"
Map* Map::instance = nullptr;

Map& Map::getInstance()
{
	if (Map::instance == nullptr)
	{
		Map::instance = new Map;
	}
	return *Map::instance;

}
void  Map::addSun(Sun* sun)
{
	for (int i = 0; i < MAX_SUN_NUM; i++)
	{
		if (sunAssets[i] == nullptr)
		{
			sunAssets[i] = sun;
			sun->setIndex(i);
			int colOffset = this->SunColumnStart + i * (sun->getAxisOffset() + 1);
			sun->draw(this->SunRowStart, colOffset);
			return;
		}
	}
}
void Map::movePea(Pea* pea)
{
	int col = pea->getDrawnAtCol() + 6;
	int line = pea->getDrawnAtLine();

	while (col <= 64)
	{
		AbstractDrawable* place = this->getClickedAsset(col, line);
		if (place == nullptr)
		{
			return;
		}
		if (place->getDrawableType() == "blank")
		{
			pea->move(line, col);
			break;
		}
		else if (place->getDrawableType() == "WalkerZombie")
		{
			pea->undraw();
			WalkerZombie* zombie = dynamic_cast<WalkerZombie*>(place);
			zombie->depleteLife(pea->getDamage());
			this->removePea(pea);
			Game::getGameInstance().addScore(50);
			break;
		}
		col += 6;
	}

}
void Map::movePeas()
{
	static int counter = 30000;
	counter--;
	if (counter == 0)
	{
		for (int i = 0; i < peas.size(); i++)
		{
			movePea(peas[i]);
		}
		counter = 30000;
	}
}

void Map::removePea(Pea* pea)
{
	for (int i = 0; i < peas.size(); i++)
	{
		if (peas[i] == pea)
		{
			peas.erase(peas.begin() + i);
			delete pea;
		}
	}
}

void Map::printPea(Pea* pea, PeaShooter* shooter)
{
	int col = shooter->getDrawnCol() + 6;
	int line = shooter->getDrawnLine() + 1;
	if (col <= 64)
	{
		AbstractDrawable* place = this->getClickedAsset(col, line);
		if (place->getDrawableType() == "blank")
		{
			pea->draw(line, col);
		}
		else
		{
			pea->setPotentialCol(col);
		}
	}
}

void Map::printFlowersSidebar()
{
	ConsoleOutput& CO = ConsoleOutput::getInstance();

	std::ifstream plant;
	plant.open("sunflower.txt");
	CO.setOutputColor(14);

	std::string buffer;

	int lineOffset = 0;
	while (std::getline(plant, buffer))
	{
		CO(this->sidebarStartRow + lineOffset, this->sidebarStartCol) << buffer;
		lineOffset++;
	}

	plant.close();

	CO.setOutputColor(10);
	plant.open("peashooter.txt");

	while (std::getline(plant, buffer))
	{
		CO(this->sidebarStartRow + lineOffset, this->sidebarStartCol) << buffer;
		lineOffset++;
	}

	plant.close();
	CO.resetConsoleColor();
}
void Map::addDrawable(AbstractDrawable* drawable)
{
	if (drawable->getDrawableType() == "Sun")
	{
		addSun((Sun*)drawable);
	}
}
int Map::getSunCount()
{
	return sunAssets.size();
}
AbstractDrawable* Map::getClickedAsset(int col, int line)
{
	//verificam daca am dat click pe un soare;
	int sunLen = 2;
	if ((line >= this->SunRowStart) && (line <= this->SunRowStart + sunLen))
	{
		for (int i = 0; i < sunAssets.size(); i++)
		{
			if (sunAssets[i] != nullptr)
			{
				int leftCol = this->SunColumnStart + i * (sunAssets[i]->getAxisOffset() + 1);
				int rightCol = leftCol + 2;
				if (col >= leftCol && col <= rightCol)
				{
					return sunAssets[i];
				}
			}
		}
	}

	//verificam daca am dat click pe o planta din sidebar

	if ((line >= this->sidebarStartRow) && ((col >= sidebarStartCol && (col <= sidebarStartCol + 2))))
	{
		int g = line - this->sidebarStartRow;

		int selectedPlantNum = g / 3;

		switch (selectedPlantNum)
		{
		case 0:
		{
			return new Sunflower(20, 15);
			break;
		}
		case 1:
		{
			return new PeaShooter(20, 20, 5);
			break;
		}
		default:
			break;
		}

	}

	//Verificam daca am dat click pe o planta

	for (int i = 0; i < this->flowers.size(); i++)
	{
		AbstractDrawable* plant = dynamic_cast<AbstractDrawable*>(this->flowers[i]);

		int drawnCol = plant->getDrawnCol();
		int drawnLine = plant->getDrawnLine();
		if (((col - drawnCol <= 2) && (col - drawnCol >= 0)) && ((line - drawnLine <= 2) && (line - drawnLine >= 0)))
		{
			return plant;
		}
	}

	//Verificam daca am dat peste un zombie

	for (int i = 0; i < ZombieAssets.size(); i++)
	{
		WalkerZombie* zombie = ZombieAssets[i];
		if (zombie == nullptr)
		{
			continue;
		}
		int drawnCol = zombie->getDrawnCol();
		int drawnLine = zombie->getDrawnLine();

		if (((col - drawnCol <= 2) && (col - drawnCol >= 0)) && ((line - drawnLine <= 2) && (line - drawnLine >= 0)))
		{
			return zombie;
		}

	}
	//verificam daca am dat click pe o zona de plantare libera 
	if ((col < 64))
	{
		int pressedCol = col - 13;
		int pressedRow = line - 7;

		bool isBlankSpaceCol = (((pressedCol % 3) / 2 % 2) == 0);
		bool isBlankSpaceRow = ((pressedRow % 3) / 2 % 2 == 0);
		if (isBlankSpaceCol && isBlankSpaceRow)
		{
			int centerRow;
			int centerCol;

			if (line % 3 == 0)
			{
				centerRow = line - 1;
			}
			else if (line % 3 == 1)
			{
				centerRow = line + 1;
			}
			else
			{
				centerRow = line;
			}

			if (col % 3 == 0)
			{
				centerCol = col - 1;
			}
			else if (col % 3 == 1)
			{
				centerCol = col + 1;
			}
			else
			{
				centerCol = col;
			}

			return new BlankSpace(centerRow, centerCol);
		}
	}

	return nullptr;
}
void Map::printScore(int score)
{
	ConsoleOutput& CO = ConsoleOutput::getInstance();
	CO(1, 1) << "        ";
	CO(1, 1) << "Scor:" << score;
}
void Map::printSori(int sori)
{
	ConsoleOutput& CO = ConsoleOutput::getInstance();
	CO(0, 1) << "        ";
	CO(0, 1) << "Sori:" << sori;
}
void Map::removeSun(int index)
{
	Sun* sun = sunAssets[index];
	sun->undraw();

	sunAssets[index] = nullptr;
	delete sun;
}
void Map::addZombie(WalkerZombie* WZ)
{
	for (int i = 0; i < MAX_ZOMBIE_NUM; i++)
	{
		if (ZombieAssets[i] == nullptr)
		{
			ZombieAssets[i] = WZ;
			WZ->setIndex(i);
			int colOffset = this->ZombieColumnStart;
			int rowOffset = this->ZombieRowStart + i * (3 + WZ->getAxisOffset());
			WZ->draw(rowOffset, colOffset);
			return;
		}
	}
}
void Map::plantFlower(BlankSpace* space, GenericFLower* flower)
{
	int centerLin = space->getCenterLin();
	int centerCol = space->getCenterCol();
	AbstractDrawable* drawable = nullptr;
	this->flowers.push_back(flower);

	if (flower->getFilename() == "sunflower.txt")
	{
		drawable = dynamic_cast<AbstractDrawable*>(static_cast<Sunflower*>(flower));
	}
	else if (flower->getFilename() == "peashooter.txt")
	{
		drawable = dynamic_cast<AbstractDrawable*>(static_cast<PeaShooter*>(flower));
	}
	drawable->draw(centerLin - 1, centerCol - 1);
}
void Map::runFlowersEffects()
{
	for (int i = 0; i < flowers.size(); i++)
	{
		flowers[i]->action();
	}
	this->movePeas();
}

void Map::removeZombie(WalkerZombie* WZ)
{
	for (int i = 0; i < this->ZombieAssets.size(); i++)
	{
		if (this->ZombieAssets[i] == WZ)
		{
			WZ->undraw();
			this->ZombieAssets[i] = nullptr;
		}
	}
}

void Map::addPea(Pea* pea)
{
	this->peas.push_back(pea);
	int indexShooter = pea->getShooterIndex();
	for (int i = 0; i < flowers.size(); i++)
	{
		int index = flowers[i]->getIndex();
		if (index == indexShooter)
		{
			printPea(pea, dynamic_cast<PeaShooter*>(flowers[i]));
		}
	}
}
bool Map::hasPlant(GenericFLower* flower)
{
	for (int i = 0; i < flowers.size(); i++)
	{
		if (flowers[i] == flower)
		{
			return true;
		}
	}
	return false;
}
Map::Map()
{
	for (int i = 0; i < MAX_SUN_NUM; i++)
	{
		sunAssets.push_back(nullptr);
	}
	for (int i = 0; i < MAX_ZOMBIE_NUM; i++)
	{
		ZombieAssets.push_back(nullptr);
	}
}
Map::~Map()
{

}