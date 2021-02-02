#include "CPlants.h"
//#include"CPlant_Peashooter.h"
//#include"CPlant_SnowPea.h"
//#include"CPlant_Sunflower.h"
//#include"CPlant_CherryBomb.h"
//#include"CPlant_WallNut.h"

string CPlants::FilePlantationsCoord = "";

CPlants::CPlants(int cost, int LifeResistance, int shooting_frequency)
{
	this->Cost_ = cost;
	this->LifeResistance_ = LifeResistance;
	this->FilePlantationsCoord = "PlantationsCoord.txt";
	this->ShootingFrequency_ = shooting_frequency;
}

CPlants::~CPlants()
{
	CLog::getInstance().printLog("S-a apelat destrucorul explicit al clasei CPlants.\n");
}

int CPlants::GetPlantValue()
{
	return this->Cost_;
}

void CPlants::Draw(int x, int y)
{

}

bool CPlants::Attacker_or_not()
{
	return 1;
}




