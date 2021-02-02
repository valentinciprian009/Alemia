#include "CUser.h"
#include"CLevel1.h"
#include"CLevel2.h"
#include"CLevel3.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
FILE* CUser::fAccounts_ = nullptr;

CUser::CUser(string username, string password)
{
	fAccounts_ = fopen("Utilizatori.txt", "a");
	this->UserName_ = username;
	this->Password_ = password;
	this->status_ = 1;
	CLog::getInstance().printLog("S-a apelat constructorul explicit al clasei CUser\n");
}

CUser::~CUser()
{
	fclose(fAccounts_);
	//fclose(User_); icnhis in passnextLevel
	CLog::getInstance().printLog("S-a apelat destrucorul explicit al clasei CUser.\n");
}

void CUser::SignIn(string username, string password)
{
	const char* userchr = username.c_str();
	const char* passchr = password.c_str();
	fprintf(fAccounts_, "USERNAME: %s\nPASSWORD: %s\n", userchr, passchr);
	string userfile = username + ".txt";
	const char* userFileCh = userfile.c_str();
	User_ = fopen(userFileCh, "w");
	fprintf(User_, "USERNAME: %s\nPASSWORD: %s\nLEVEL: %d", userchr, passchr, 1);
	this->level_ = 1;
	this->status_ = 1;
	CLog::getInstance().printLog("Autentificarea utilizataorului a fost realizata cu succes!\n");
}

int CUser::LogIn(string username, string password)
{
	string userFile = username + ".txt";
	const char* userFilech = userFile.c_str();
	FILE* fin = fopen(userFilech, "r");
	char pass[1024];
	if (!fin)//daca nu exista fisiserul creat
	{
		return 0;
	}
	else
	{
		fscanf(fin, "%s", pass);
		while (strcmp(pass, "PASSWORD:") != 0)
		{
			fscanf(fin, "%s", pass);
		}
	}
	fscanf(fin, "%s", pass);
	if (strcmp(pass, password.c_str()) != 0)
	{
		return 0;
	}
	fscanf(fin, "%s", pass);
	int level;
	fscanf(fin, "%d", &level);
	CLog::getInstance().printLog("Utilizator logat cu succes!\n"); 
	return level;
}

void CUser::LogOut(string username)
{
	this->status_ = 0;
}

void CUser::PassNextLevel()
{
	this->level_++;
	fclose(User_);
	string userfile = this->UserName_ + ".txt";
	const char* userFileCh = userfile.c_str();
	User_ = fopen(userFileCh, "w");
	fprintf(User_, "USERNAME: %s\nPASSWORD: %s\nLEVEL: %d", this->UserName_.c_str(), this->Password_.c_str(), this->level_);
	fclose(User_);
	FILE* fin = fopen("PlantationsCoord.txt", "w");
	fclose(fin);
	fin = fopen("StoreBulletFrozenPea.txt", "r");
	char FileName[1024];
	while (fscanf(fin, "%s", FileName) > 0)
	{
		FILE* BulletFile = fopen(FileName, "w");
		fclose(BulletFile);
	}
	fclose(fin);
	fin = fopen("StoreBulletFrozenPea.txt", "w");
	fclose(fin);

	string ZombieCoord = "ZombieCoord.txt";
	const char* ZombieCoordCh = ZombieCoord.c_str();
	FILE* ZCoord = fopen(ZombieCoordCh, "r");
	while (fscanf(ZCoord, "%s", FileName) > 0)
	{
		FILE* ZombieFile = fopen(FileName, "w");
		fclose(ZombieFile);
	}
	fclose(ZCoord);
	ZCoord = fopen(ZombieCoordCh, "w");
	fclose(ZCoord);
}

void CUser::pickResource(IResource&resource)
{
	this->totalValue_ += resource.GetValue();
}

bool CUser::Plant(CPlants& plant)
{
	if (plant.GetPlantValue() > this->totalValue_)
		return false;
	else
		this->totalValue_ -= plant.GetPlantValue();
	return 1;
}

void CUser::EndGame()
{
	string Filename = "SunCoord.txt";
	const char* Filenamch;
	Filenamch = Filename.c_str();
	FILE* fin = fopen(Filenamch, "w");
	fclose(fin);
	Filename = "ZombieCoord.txt";
	Filenamch - Filename.c_str();
	fin = fopen(Filenamch, "r");
	char buff[500];
	while(fscanf(fin, "%s", buff) > 0)
	{
		FILE* f2 = fopen(buff, "w");
		fclose(f2);
	}
	fclose(fin);
	fin = fopen(Filenamch, "w");
	fclose(fin);
	Filename = "StoreBulletFrozenPea.txt";
	Filenamch = Filename.c_str();
	fin = fopen(Filenamch, "w");
	fclose(fin);
	fin = fopen("StorBulletPea.txt", "w");
	fclose(fin);
	fin = fopen("PlantationsCoord.txt", "w");
	fclose(fin);
}





int CUser::GetTotalValue()
{
	return this->totalValue_;
}


IUser& IUser::CreateUser(string username, string password)
{
	return *new CUser(username, password);
}

