#include "CZombieBucketHead.h"



CZombieBucketHead::~CZombieBucketHead()
{
	CLog::getInstance().printLog("S-a apelat destructorul clasei CZombieBucketHead \n");
}

void CZombieBucketHead::Display(string type_Zombie, int x, float y, CLevel& level)
{
	

	const char* typeZ = type_Zombie.c_str();
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();

	char buffX[4], buffY[4];
	int nr;
	string HealthZombieFile = "Health";
	HealthZombieFile += _itoa(x, buffX, 10);
	HealthZombieFile += "_";
	HealthZombieFile += _itoa(y, buffY, 10);
	HealthZombieFile += ".txt";
	const char* HealthZombieFileCh = HealthZombieFile.c_str();
	FILE* health = fopen(HealthZombieFileCh, "r");
	if (!health)
	{
		health = fopen(HealthZombieFileCh, "w");
		fprintf(health, "%d ", 40); //HEALTH SUPER ZOMBIE=20. DACA SE DORESTE SCHIMBARE, SE VA MODIFICA SI AICI !!
	}
	else
	{
		int index = 0;
		while (fscanf(health, "%d", &nr) > 0)
			index++;
		if (index == 1 && nr != 40)
		{
			fclose(health);
			health = fopen(HealthZombieFileCh, "w");
			fprintf(health, "%d ", 40);
		}
	}
	fclose(health);

	
	int a, XbeforeShot = 0;
	float b, YbeforeShot = 0;
	char typeZombie[10];
	string Filename = _itoa(x, buffX, 10);
	Filename += "_";
	Filename += _itoa(y, buffY, 10);
	string Filename2 = Filename;
	Filename += ".txt";
	int disponibleLineNewZombie = 0;//linie goala, fara zombie
	int nb_positions = 0;
	const char* Filenamech = Filename.c_str();
	FILE* fZombie = fopen(Filenamech, "r");

	int existent = 0;
	char buff[1024];
	string ZombieCoord = "ZombieCoord.txt";
	const char* ZombieCoordCh = ZombieCoord.c_str();
	FILE* ZCoord = fopen(ZombieCoordCh, "r");
	if (ZCoord)
	{
		/*if (fscanf(ZCoord, "%s", buff) > 0)
		{
			fclose(ZCoord);
			ZCoord = fopen(ZombieCoordCh, "a");
			fprintf(ZCoord, "%s ", Filenamech);
			fclose(ZCoord);
			ZCoord = fopen(ZombieCoordCh, "r");*/
		while (fscanf(ZCoord, "%s", buff) > 0)
		{
			if (strcmp(buff, Filenamech) == 0)
			{
				existent = 1;
				break;
			}

		}
		fclose(ZCoord);
		////}
		//else
		//{
		//	ZCoord = fopen(ZombieCoordCh, "a");
		//	fprintf(ZCoord, "%s ", Filenamech);
		//	fclose(ZCoord);
		//}
	}
	else
	{
		ZCoord = fopen(ZombieCoordCh, "a");
		fprintf(ZCoord, "%s ", Filenamech);
		fclose(ZCoord);
	}

	if (existent == 0)
	{
		//fclose(ZCoord);
		ZCoord = fopen(ZombieCoordCh, "a");
		fprintf(ZCoord, "%s ", Filenamech);
		fclose(ZCoord);
	}

	string FileAttack = Filename2 + "FrozenPeaAttack";
	FileAttack += ".txt";
	const char* FileAttackCh = FileAttack.c_str();
	int much = 9990; //health
	if (fZombie)
	{

		fscanf(fZombie, "%s", typeZombie);
		

		while (fscanf(fZombie, "%d %f", &a, &b) > 0)
		{
			
			if (strcmp(typeZombie, typeZ) != 0)
			{

				fclose(fZombie);
				return;
			}//muta ca la zpv
			nb_positions++;
			int a2;
			float b2;
			a2 = a;
			b2 = b;
			if (a - 1 == BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10 || a == 0 || a == 1)// || a=0 : lovit de un frozenpea, a=1 lovit de un pea
			{
				if (a == 0)
				{
					health = fopen(HealthZombieFileCh, "r");
					while (fscanf(health, "%d", &much) > 0)
					{

					}
					if (much != 0)
					{
						fclose(health);
						health = fopen(HealthZombieFileCh, "a");
						much -= CBullet_FrozenPea::Damge_;
						fprintf(health, "%d ", much);
						fclose(health);

						FILE* SnowPAttack = fopen(FileAttackCh, "w");
						fprintf(SnowPAttack, "%d", 1);
						fclose(SnowPAttack);
					}
				}
				else
					if (a == 1)
					{
						health = fopen(HealthZombieFileCh, "r");

						while (fscanf(health, "%d", &much) > 0)
						{

						}
						if (much != 0)
						{
							fclose(health);
							health = fopen(HealthZombieFileCh, "a");
							much -= CBullet_Pea::Damage_;
							fprintf(health, "%d ", much);

						}
						fclose(health);
					}
				if (much <= 0 || a - 1 == BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10)
				{

					if (a - 1 == BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10)
						level.lives_--;
					fclose(fZombie);
					fZombie = fopen(Filenamech, "r");
					int last_x, last_xx;
					float last_y, last_yy;
					char name[10];
					fscanf(fZombie, "%s", name);
					while (fscanf(fZombie, "%d %f", &last_x, &last_y) > 0)
					{
						if (last_x != 0 && last_x!=1)
						{
							last_xx = last_x;
							last_yy = last_y;
						}

					}
					fclose(fZombie);
					disponibleLineNewZombie = 1;
					conOut(last_yy, last_xx) << "     ";
					fZombie = fopen(Filenamech, "w");
					fclose(fZombie);
					health = fopen(HealthZombieFileCh, "w");
					fprintf(health, "%d ", 40);
					fclose(health);

					FILE* SnowPAttack = fopen(FileAttackCh, "w");
					fclose(SnowPAttack);  
					level.Nb_Zombies_--;
					return;
				}
				else
				{
					if (a == 0 || a == 1)
					{
						fZombie = fopen(Filenamech, "w");
						fprintf(fZombie, "%s\n", "ZBH");
						fprintf(fZombie, "%d\t%.2f\n", XbeforeShot, YbeforeShot);
						a = XbeforeShot;
						b = YbeforeShot;
						fclose(fZombie);
					}
				}
			}
			XbeforeShot = a2;
			YbeforeShot = b2;
		}

		fclose(fZombie);
	}
	if (disponibleLineNewZombie == 1 || nb_positions == 0)// in cazul in care s-a creat un folder inainte, dar nu s-a scris in el, adica zombie nu s-a deplasat pe acea linie:
	{
		a = x;//daca linia mea este goala, o sa reiau procedura din capatul din dreapta al terenului
		b = y;
	}
	else
	{
		if (strcmp(typeZombie, "ZBH") != 0)
			return;
	}
	int status = 0, time_move = 1000;

	FILE* SnowPAttack = fopen(FileAttackCh, "r");
	if (SnowPAttack)
	{
		if(fscanf(SnowPAttack, "%d", &status)>0)
		time_move = 10000;
		fclose(SnowPAttack);
	}

	if (duration_cast<milliseconds>(end - begin).count() > time_move)
	{
		fZombie = fopen(Filenamech, "a");
		begin = end;
		conOut(b, a) << "   ";
		a--;
		conOut(b, a) << "ZBH";
		if (disponibleLineNewZombie == 1 || nb_positions == 0)
			fprintf(fZombie, "%s\n", "ZBH");
		fprintf(fZombie, "%d\t%.2f\n", a, b);
		fclose(fZombie);
	}

	
}
