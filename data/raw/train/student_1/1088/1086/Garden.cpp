#include"Garden.h"

Garden::Garden(int row_ul, int col_ul, int nr_rows, int nr_cols, float time_int) : Entity(row_ul, col_ul), ground(row_ul + 9, col_ul + 15, nr_rows, nr_cols), spawnGround(row_ul + 9, col_ul), scoreTable(row_ul, col_ul), sunGround(row_ul + 1, col_ul + 15, nr_cols, time_int), plantList()
{
	plantSpawn[0] = new Peashooter;
	plantSpawn[1] = new Sunflower;
	plantSpawn[2] = new CherryBomb;
	plantSpawn[3] = new WallNut;
	plantSpawn[4] = new SnowPea;
}

Garden::Garden(int row_ul, int col_ul, int nr_rows, int nr_cols, float time_int, int lvl, int scr, int sunQty, const string& usernm) : Entity(row_ul, col_ul), ground(row_ul + 9, col_ul + 15, nr_rows, nr_cols), spawnGround(row_ul + 9, col_ul), scoreTable(row_ul, col_ul - 10, lvl, scr, sunQty, usernm), sunGround(row_ul + 1, col_ul + 15, nr_cols, time_int), plantList()
{
	plantSpawn[0] = new Peashooter;
	plantSpawn[1] = new Sunflower;
	plantSpawn[2] = new CherryBomb;
	plantSpawn[3] = new WallNut;
	plantSpawn[4] = new SnowPea;
}

Garden::~Garden()
{
	for (int i = 0; i < 5; i++)
		delete plantSpawn[i];
	for (auto& plant : plantList)
		if (plant)
		{
			delete plant;
			plant = nullptr;
		}
}

void Garden::takeSun()
{
	int suns = scoreTable.getSunQuantity();
	scoreTable.updateSunQuantity(suns + sunGround.takeSun());
}

void Garden::print()
{
	int row, col;
	ground.print();
	spawnGround.print();
	scoreTable.print();
	sunGround.print();
	takeSun();
	for (auto& plant : plantList)
	{
		if (plant)
		{
			switch (plant->getType())
			{
			case 1:
				((Peashooter*)plant)->ability();
				break;

			case 5:
				((SnowPea*)plant)->ability();
				break;

			default:
				break;
			}
		}
	}
	consoleOut(2, 2) << "Sun Appearance Interval in seconds: " << sunGround.getTimeInterval() << "              ";
	for (int i = 0; i < 5; i++)
	{
		consoleOut(spawnGround.getRowUpperLeft() + 6 * i + 2, spawnGround.getColUpperLeft() - 10) << "Cost: " << plantSpawn[i]->getCost();
		consoleOut(spawnGround.getRowUpperLeft() + 6 * i + 3, spawnGround.getColUpperLeft() - 14) << "Cooldown: " << "  ";
		consoleOut(spawnGround.getRowUpperLeft() + 6 * i + 3, spawnGround.getColUpperLeft() - 14) << "Cooldown: " << (plantSpawn[i])->printCooldown(canPlant[i], lastPlantedTime[i]);
	}
}

bool Garden::plantFlower(int& type, int& row, int& col)
{
	spawnGround.selectPlant();
	int plantSelected = spawnGround.getSelectedPlant();
	if (plantSelected && (plantSpawn[plantSelected - 1]->getCost() <= scoreTable.getSunQuantity()) && plantSpawn[plantSelected - 1]->canPlantFlower(canPlant[plantSelected - 1], lastPlantedTime[plantSelected - 1]))
	{
		if (ground.plantFlower(plantSelected, row, col))
		{
			type = plantSelected;
			int suns = scoreTable.getSunQuantity();
			suns -= (plantSpawn[plantSelected - 1]->getCost());
			scoreTable.updateSunQuantity(suns);
			switch (plantSelected)
			{
			case 1:
				Plant * p1;
				p1 = new Peashooter(getGround()[row][col].getRowUpperLeft() + 2, getGround()[row][col].getColUpperLeft() + 5);
				p1->setCoords(row, col);
				plantList.push_back(p1);
				p1->plant(canPlant[0], lastPlantedTime[0]);
				break;

			case 2:
				Plant * p2;
				p2 = new Sunflower(getGround()[row][col].getRowUpperLeft() + 2, getGround()[row][col].getColUpperLeft() + 5);
				p2->setCoords(row, col);
				plantList.push_back(p2);
				p2->plant(canPlant[1], lastPlantedTime[1]);
				((Sunflower*)plantSpawn[plantSelected - 1])->ability(sunGround);
				break;

			case 3:
				Plant * p3;
				p3 = new CherryBomb(getGround()[row][col].getRowUpperLeft() + 2, getGround()[row][col].getColUpperLeft() + 5);
				p3->setCoords(row, col);
				plantList.push_back(p3);
				p3->plant(canPlant[2], lastPlantedTime[2]);
				((CherryBomb*)plantSpawn[plantSelected - 1])->ability();
				break;

			case 4:
				Plant * p4;
				p4 = new WallNut(getGround()[row][col].getRowUpperLeft() + 2, getGround()[row][col].getColUpperLeft() + 4);
				p4->setCoords(row, col);
				plantList.push_back(p4);
				p4->plant(canPlant[3], lastPlantedTime[3]);
				break;

			case 5:
				Plant * p5;
				p5 = new SnowPea(getGround()[row][col].getRowUpperLeft() + 2, getGround()[row][col].getColUpperLeft() + 5);
				p5->setCoords(row, col);
				plantList.push_back(p5);
				p5->plant(canPlant[4], lastPlantedTime[4]);
				break;

			default:
				break;
			}
			return true;
		}
	}
	return false;
}