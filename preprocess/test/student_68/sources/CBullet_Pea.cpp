#include "CBullet_Pea.h"

int CBullet_Pea::Damage_ = 0;
int Bullet_Active2 = 0;

CBullet_Pea::~CBullet_Pea()
{
	CLog::getInstance().printLog("S-a apelat destructorul clasei CBullet_Pea \n");
}

void CBullet_Pea::Start_Bullet_Attack(int x, int y)
{
	Bullet_Active2++;
	char buff[10];
	string filename = "BulletPea_";
	filename += +_itoa(x, buff, 10);
	filename += "_";
	filename += _itoa(y, buff, 10);
	filename += "_";
	filename += _itoa(Bullet_Active2, buff, 10);
	filename += ".txt";

	const char* Filenamech = filename.c_str();

	const char* StoreBulletPeaFiles = "StoreBulletPea.txt";
	FILE* store = fopen(StoreBulletPeaFiles, "a");
	fprintf(store, "%s ", Filenamech);
	fclose(store);

	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	int b, a, nb_positions = 0, row_nb;

	FILE* fPea = fopen(Filenamech, "r");
	if (fPea)
	{
		while (fscanf(fPea, "%d %d", &a, &b) > 0)//a=x proiectil, b=y proiectil
		{
			nb_positions++;
		}
	}
	//fclose(fPea);

	if (nb_positions == 0)// in cazul in care s-a creat un folder inainte, dar nu s-a scris in el, adica proiectilul nu s-a deplasat pe acea linie:
	{
		a = x;//daca proiectilul nu a inceput inaintarea, ii atribui coordonatele de unde sa o faca
		b = y;
	}
	else
		conOut(5, 5) << "malina"; //nu cred ca imi intra vreodata DE REVENIT SI STERS DACA E CAZUL !!!!

	if (duration_cast<milliseconds>(end - begin).count() > 10 || nb_positions == 0)
	{
		begin = end;
		store = fopen(StoreBulletPeaFiles, "r");

		int x_bullet, y_bullet;

		FILE* Each_BulletPeaFile = fopen(Filenamech, "r");
		if (nb_positions != 0)
		{
			while (fscanf(Each_BulletPeaFile, "%d %d", &x_bullet, &y_bullet) > 0)
			{
				a = x_bullet;
				b = y_bullet;
				fclose(Each_BulletPeaFile);
			}
		}
		a++;
		Each_BulletPeaFile = fopen(Filenamech, "a");
		conOut(b, a) << "  ";
		a++;
		conOut(b, a) << "-";
		fprintf(Each_BulletPeaFile, "%d\t%d\n", a, b);
		fclose(Each_BulletPeaFile);

		fclose(store);
	}
}

void CBullet_Pea::Display_attack()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	int a, b, row_nb;
	const char* StoreBulletPeaFiles = "StoreBulletPea.txt";
	if (duration_cast<milliseconds>(end - begin).count() > 1000)
	{
		begin = end;
		char filebuff[100];
		FILE* store = fopen(StoreBulletPeaFiles, "r");
		while (fscanf(store, "%s", filebuff) > 0)
		{
			int x_bullet, y_bullet;
			FILE* Each_BulletPeaFile = fopen(filebuff, "r");
			int ok = 0, firstX, firstY, done = 0;
			if (!Each_BulletPeaFile)
				break;

			while (fscanf(Each_BulletPeaFile, "%d %d", &x_bullet, &y_bullet) > 0)
			{
				if (!done)
				{
					firstX = x_bullet;
					firstY = y_bullet;
					done = 1;
				}
				a = x_bullet;
				b = y_bullet;
				ok = 1;
			}
			if (ok)
			{
				fclose(Each_BulletPeaFile);
				row_nb = b / float((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00);
				char buff[100];
				int Y_Zombie = float(BEGIN_LOGIN_BOX_ROW + float(END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 * float(row_nb - 1)) + float(END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 12.00;
				string ZombieFile = _itoa(END_LOGIN_BOX_COL, buff, 10);
				ZombieFile += "_";
				ZombieFile += _itoa(Y_Zombie, buff, 10);
				ZombieFile += ".txt";
				const char* ZombieFilech = ZombieFile.c_str();
				FILE* Fzombie = fopen(ZombieFilech, "r");
				if (Fzombie)
				{
					char nameZombie[10];
					fscanf(Fzombie, "%s", nameZombie);
					int important_X;
					float y_zombie;
					while (fscanf(Fzombie, "%d\t%f\n", &important_X, &y_zombie) > 0)
					{
						if (important_X == a)//proiectilul a atins zombie ul(x zombie = x proiectil)
						{
							fclose(Fzombie);
							Fzombie = fopen(ZombieFilech, "a");
							fprintf(Fzombie, "%d\t%.2f\n", 1, 1.00);
							//fclose(Fzombie);
							//conOut(b, a) << "    ";
							fclose(Each_BulletPeaFile);
							Each_BulletPeaFile = fopen(filebuff, "w");
							fprintf(Each_BulletPeaFile, "%d %d\n", firstX, firstY);
							a = firstX;
							b = firstY;
							fclose(Each_BulletPeaFile);
						}
					}
					fclose(Fzombie);
				}

			}
			//a++;
			Each_BulletPeaFile = fopen(filebuff, "a");
			/*if (!first)
			{
				conOut(b, a + 1) << " ";
				first = 1;
			}
			else*/
			conOut(b, a) << " ";
			a++;
			conOut(b, a) << "-";
			fprintf(Each_BulletPeaFile, "%d\t%d\n", a, b);
			fclose(Each_BulletPeaFile);
		}
		fclose(store);
	}
}

