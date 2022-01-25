#include"CResource_Sun.h"
#include"CLevel1.h"
#include"CLevel2.h"
#include"CLevel3.h"

#include"IUser.h"

#include"CPlant_Peashooter.h"
#include"CPlant_SnowPea.h"
#include"CPlant_Sunflower.h"
#include"CPlant_CherryBomb.h"
#include"CPlant_WallNut.h"

#include"CZombie_Banal.h"
#include"CZombie_PoleVaulting.h"
#include"CZombie_Super.h"
#include"CZombieBucketHead.h"

#include"CBullet_Pea.h"
#include"CBullet_FrozenPea.h"

#include <time.h>
#include <chrono>
#include<conio.h>
#include<thread>
#include<stdlib.h>
#include<iostream>

using namespace std::chrono;

int AttackStartedSnowPea = 0;
int AttackStartedPea = 0;



int main(void)
{
	try {
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();


		MY_UTILS::DrawBox();
		MY_UTILS::SetColor(11);


		conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) - 5, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) << "Buna! Pregateste-te pentru Plants VS Zombie!";
		conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) - 4, ((END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) + 2) << "Esti pregatit? Raspundeti cu DA sau NU";
		string str, answer;
		answer = conIn >> str;
		conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) + 2, ((END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) + 20) << answer;

		if (answer == "NU")
		{
			conOut(40, 0) << "La revedere!";
			throw CExceptions("STOP GAME!", STOP_GAME);
		}

		seconds time(1);
		this_thread::sleep_for(time);
		for (int i = (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + 20; i < (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + 22; i++)
			conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) + 2, i) << " ";

		for (int i = (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2; i < (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("Buna!Pregateste-te pentru Plants VS Zombie!") + 1; i++)//sterg
			conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) - 5, i) << " ";
		conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) - 4, ((END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) + 2) << "Utilizator nou? Raspundeti cu DA sau NU";
		answer = conIn >> str;
		conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) + 2, ((END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) + 20) << answer;
		this_thread::sleep_for(time);

		for (int i = (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + 20; i < (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + 22; i++)
			conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) + 2, i) << " ";
		if (answer == "DA")
			conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) - 4, ((END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) + 2) << "Minunat! Introduceti datele de autentificare";
		else
			conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) - 4, ((END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) + 2) << "Super! Introduceti datele de logare";

		string username, password;
		conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) + 5, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) << "USERNAME: ";
		username = conIn >> str;
		conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) + 5, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("USERNAME: ") + 1) << username;
		conOut((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2 + 7, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) << "PASSWORD: ";
		password = conIn >> str;
		for (int i = (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("PASSWORD: "); i <= ((END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("PASSWORD: ") + password.size() - 1); i++)
			conOut((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2 + 7, i) << "*";
		this_thread::sleep_for(time);
		int levelfromFile;
		CLevel* level = new CLevel;
		int LogOk = 0, SignIn = 0;
		IUser& User = IUser::CreateUser(username, password);
		if (answer == "DA")
		{
			User.SignIn(username, password);
			CLevel1* level1 = new CLevel1;  
			level = level1;
			level->level_ = 1;
		}
		else
		{
			if (User.LogIn(username, password))
			{
				levelfromFile = User.LogIn(username, password);
				switch (levelfromFile)
				{
				case 1:
				{
					CLevel1* level1 = new CLevel1;
					level = level1;
					break;
				}
				case 2:
				{
					CLevel2* level2 = new CLevel2;
					level = level2;
					break;
				}
				case 3:
				{
					CLevel3* level3 = new CLevel3;
					level = level3;
					break;
				}
				}
			}
			else
			{
				MY_UTILS::SetColor(12);
				int tryNo = 2;
				while (tryNo > 0 && (User.LogIn(username, password)) == 0)
				{
					conOut((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2 + 9, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) << "INCORRECT PASSWORD OR USERNAME! ";
					this_thread::sleep_for(time);
					conOut((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2 + 10, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) << tryNo << " MORE TRY: ";
					tryNo--;
					for (int i = (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("USERNAME: "); i < (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("USERNAME: ") + username.size() + 1; i++)
						conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) + 5, i) << " ";
					for (int i = (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("PASSWORD: "); i <= ((END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("PASSWORD: ") + password.size()); i++)
						conOut((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2 + 7, i) << " ";
					username = conIn >> str;
					conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) + 5, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("USERNAME: ") + 1) << username;
					this_thread::sleep_for(time);

					password = conIn >> str;
					conOut((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2 + 7, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("PASSWORD: ")) << password;

					this_thread::sleep_for(time);
					for (int i = (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("  MORE TRY: "); i < (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + strlen("  MORE TRY: ") + password.size(); i++)
						conOut((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2 + 8, i) << " ";
				}
				if (tryNo == 0 && !(User.LogIn(username, password)))
				{
					conOut((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2 + 14, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2 + 8) << "WRONG. WE'RE SORRY :( GOOD BYE!";
					seconds time2(3);
					this_thread::sleep_for(time2);
					throw CExceptions("LOGARE ESUATA!", INEXISTENT_USER);
				}
				else
				{
					levelfromFile = User.LogIn(username, password);
					switch (levelfromFile)
					{
					case 1:
					{
						CLevel1* level1 = new CLevel1;
						level = level1;
						level->level_ = 1;
						break;
					}
					case 2:
					{
						CLevel2* level2 = new CLevel2;
						level = level2;
						level->level_ = 2;
						break;
					}
					case 3:
					{
						CLevel3* level3 = new CLevel3;
						level = level3;
						level->level_ = 3;
						break;
					}
					}
				}
			}
		}
		


		MY_UTILS::ClearScreen();
		level->DrawLand();

		CBullet* Bullet = new CBullet;
		IResource& sun = IResource::createResource(10, SUN);
		FILE* fSun = fopen("SunCoord.txt", "w");
		fprintf(fSun, "X\t%Y\n");
		fclose(fSun);
		int index;

		CZombie* zombie = new CZombie();
		CZombie_Banal* banal = new CZombie_Banal(20, 10);//health, speed
		CZombieBucketHead* Bucket = new CZombieBucketHead(100, 10);
		CZombie_PoleVaulting* PoleVaulting = new CZombie_PoleVaulting(40, 10);
		CZombie_Super* Super = new CZombie_Super(100, 10);

		CBullet_FrozenPea* frozenPea = new CBullet_FrozenPea(20);
		CBullet_Pea* Pea = new CBullet_Pea(10);

		while (level->lives_ != 0)
		{
			conOut(BEGIN_LOGIN_BOX_ROW + 3, BEGIN_LOGIN_BOX_COL + 5) << User.GetTotalValue();
			if (level->Nb_Zombies_ == 0)
			{
				switch (level->level_)
				{
				case 1:
				{
					CLevel2* level2_ = new CLevel2;
					level = level2_;
					MY_UTILS::ClearScreen();
					level->DrawLand();
					User.PassNextLevel();
					break;
				}
				case 2:
				{
					CLevel3* level3_ = new CLevel3;
					level = level3_;
					MY_UTILS::ClearScreen();
					level->DrawLand();
					User.PassNextLevel();
					break;

				}
				default:
				{
					MY_UTILS::SetColor(12);
					MY_UTILS::ClearScreen();
					conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) - 5, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) << "Congratulations, winner!";
					User.EndGame();
					if (Bullet)
						delete Bullet;
					delete level;
					delete& User;
					delete& sun;
					_getch();
					return 0;
				}

				}
			}
			int ID = MY_UTILS::RandomSelectElementDisplay();
			int x = MY_UTILS::RandomCoord_x();
			MY_UTILS::SetColor(14);
			bool status_SunFlower = CPlant_Sunflower::status_;
			sun.Display(BEGIN_LOGIN_BOX_ROW + 2, x, ID, status_SunFlower);
			string type_Zombie;

			if (AttackStartedPea)
			{
				Bullet = Pea;
				Bullet->Display_attack();
			}
			if (AttackStartedSnowPea)
			{
				Bullet = frozenPea;
				Bullet->Display_attack();
			}

			int IDZombie = MY_UTILS::RandomSelectElementDisplay();
			switch (IDZombie)
			{
			case 0:
			{

				zombie = banal;
				type_Zombie = "ZB";
				break;
			}
			case 1:
			{

				zombie = Bucket;
				type_Zombie = "ZBH";
				break;
			}
			case 2:
			{

				zombie = PoleVaulting;
				type_Zombie = "ZPV";
				break;
			}
			case 3:
			{

				zombie = Super;
				type_Zombie = "ZS";
				break;
			}
			default:
				break;
			}
			int Y_Zombie;
			if (level->level_ == 1)
				Y_Zombie = float((BEGIN_LOGIN_BOX_ROW + float(END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6.00 * 3) + (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 12.00);
			else
				if (level->level_ == 2)
					Y_Zombie = MY_UTILS::RandomCoord_Y_level2();
				else
					Y_Zombie = MY_UTILS::RandomCoord_Y();
			MY_UTILS::SetColor(2);
			zombie->Display(type_Zombie, zombie->GetPos_x(), Y_Zombie, *level);

			std::string action = conIn.getUserActions();

			if (action != "")
			{
				int X = 0, Y;
				if (action.size() > 39)
				{
					conOut(45, 2) << action;

					const char* word = action.c_str();
					for (int i = 29; i < action.length(); i++)
					{
						int index = 0;
						const char* wordfinalatoi = "\0";
						char* word2atoi = new char[4];
						while (word[i] >= 48 && word[i] <= 57)
						{
							word2atoi[index] = word[i];
							i++;
							index++;
						}

						if (X == 0 && index != 0)
						{
							wordfinalatoi = word2atoi;
							X = atoi(wordfinalatoi);
							wordfinalatoi = "\0";
							delete word2atoi;
						}
						else
							if (index != 0)
							{
								wordfinalatoi = word2atoi;
								Y = atoi(wordfinalatoi);
								break;
							}
					}
					int checker = 0;
					fSun = fopen("SunCoord.txt", "r");
					int xx, yy;
					char s1[500], s2[500];
					fscanf(fSun, "%s\t%s", &s1, &s2);
					while (fscanf(fSun, "%d\t%d\n", &xx, &yy) > 0)
					{
						if (xx == X && yy == Y)
						{
							conOut(BEGIN_LOGIN_BOX_ROW + 2, xx) << " ";
							User.pickResource(sun);
							checker = 1;
							break;
						}
						conOut(BEGIN_LOGIN_BOX_ROW + 3, BEGIN_LOGIN_BOX_COL + 5) << User.GetTotalValue();
					}
					fclose(fSun);
					fSun = fopen("SunCoord.txt", "a");
					if (checker == 0)
					{
						FILE* fPlants = fopen("PlantsInfo.txt", "r");
						char buff[1024];
						const char* PlantType;
						int cost, resistance, freq;
						fgets(buff, 1024, fPlants);
						while (fscanf(fPlants, "%s %d %d %d %d %d", buff, &xx, &yy, &cost, &resistance, &freq) > 0)
						{
							int ok = 0;
							if (xx == X && yy == Y) //daca s-a dat dublu clik pe o resursa, urmeaza sa o si asez
							{
								ok = 1;
								CPlants* Plant = new CPlants(cost, resistance, freq);
								PlantType = buff;
								if (strcmp(PlantType, "CherryBomb") == 0)
								{
									CPlant_CherryBomb* cherry = new CPlant_CherryBomb(cost, resistance, freq);
									Plant = cherry;
								}
								else
									if (strcmp(PlantType, "SunFlower") == 0)
									{
										CPlant_Sunflower* Sun = new CPlant_Sunflower(cost, resistance, freq);
										Plant = Sun;
									}
									else
										if (strcmp(PlantType, "SnowPea") == 0)
										{
											CPlant_SnowPea* SnowPea = new CPlant_SnowPea(cost, resistance, freq);
											Plant = SnowPea;
										}
										else
											if (strcmp(PlantType, "WallNut") == 0)
											{
												CPlant_WallNut* wallNut = new CPlant_WallNut(cost, resistance, freq);
												Plant = wallNut;
											}
											else
											{
												CPlant_Peashooter* peaShooter = new CPlant_Peashooter(cost, resistance, freq);
												Plant = peaShooter;
											}

								if (ok)
								{
									action = "";
									while (action.size() < 39)//pana cand se alege locul in care sa se planteze planta prin dublu click
									{
										action = conIn.getUserActions();
									}
									int X2put, Y2put, pass = 0;; //coordonatele care imi indica pozitia pe care o sa asez planta
									if (action.size() > 39 && action.size() < 65)//selectez cele 2 coordonate din mesajul transmis pe ecran
									{
										conOut(45, 2) << action;
										const char* word2 = action.c_str();
										for (int i = 37; i < action.length(); i++)
										{

											index = 0;
											const char* wordfinalatoi2 = "\0";
											char* word2atoi2 = new char[4];
											while (word2[i] >= 48 && word2[i] <= 57)
											{

												word2atoi2[index] = word2[i];
												i++;
												index++;
											}

											if (pass == 0 && index != 0)
											{

												wordfinalatoi2 = word2atoi2;
												X2put = atoi(wordfinalatoi2);
												wordfinalatoi2 = "\0";
												pass++;

											}
											else
												if (index != 0)
												{
													wordfinalatoi2 = word2atoi2;
													Y2put = atoi(wordfinalatoi2);

												}
										}
									}
									if (level->level_ == 1 && (X2put<BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10 + 1 || X2put>END_LOGIN_BOX_COL || Y2put<BEGIN_LOGIN_BOX_ROW + 3 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6 || Y2put>BEGIN_LOGIN_BOX_ROW + 4 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6))
									{
										conOut(45, 2) << "THIS LAND IS NOT YOURS!                                          ";
										break;
									}
									else
										if (level->level_ == 2 && (X2put<BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10 + 1 || X2put>END_LOGIN_BOX_COL || Y2put < BEGIN_LOGIN_BOX_ROW + (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6 || Y2put>BEGIN_LOGIN_BOX_ROW + 4 * (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6))
										{
											conOut(45, 2) << "THIS LAND IS NOT YOURS!                                          ";
											break;

										}
										else
											if (level->level_ == 3 && (X2put<BEGIN_LOGIN_BOX_COL + (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 10 + 1 || X2put>END_LOGIN_BOX_COL || Y2put < BEGIN_LOGIN_BOX_ROW + (END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 6 || Y2put>END_LOGIN_BOX_ROW))
											{
												conOut(45, 2) << "THIS LAND IS NOT YOURS!                                          ";
												break;
											}
									if (User.Plant(*Plant))//verifica daca am suficienti bani
									{
										Plant->Draw(X2put, Y2put);
										if (Plant->Attacker_or_not())
										{

											if (strcmp(PlantType, "SnowPea") == 0)
											{
												//CBullet_FrozenPea* frozenPea = new CBullet_FrozenPea(20);//damage=10
												Bullet = frozenPea;
												Bullet->Start_Bullet_Attack(X2put, Y2put);
												AttackStartedSnowPea = 1;
											}
											else
												if (strcmp(PlantType, "PeaShooter") == 0)
												{

													Bullet = Pea;
													Bullet->Start_Bullet_Attack(X2put, Y2put);
													AttackStartedPea = 1;
												}

										}
									}
									else
										conOut(45, 2) << "You don't have enough money for this plant!!!                    ";


									break;//daca s-au gasit coordonatele plantei, ies; nu are rost sa mai citesc din fisierul cu coordonate
								}

							}
						}

					}
				}
				else {
					if (action.size() < 39 && action.size() > 31)
					{
						MY_UTILS::SetColor(11);
						conOut(45, 2) << action;
						conOut(45, 39) << "                  ";
					}
				}
			}
		}

		if (level->lives_ == 0)
		{
			MY_UTILS::ClearScreen();
			conOut(((END_LOGIN_BOX_ROW - BEGIN_LOGIN_BOX_ROW) / 2) - 5, (END_LOGIN_BOX_COL - BEGIN_LOGIN_BOX_COL) / 2) << "GAME OVER!";
		}

		if (Bullet)
			delete Bullet;
		delete level;
		delete& User;
		delete& sun;
	}
	catch(IExceptions&e)
	{
		e.printExceptions();
	}
	_getch();
}