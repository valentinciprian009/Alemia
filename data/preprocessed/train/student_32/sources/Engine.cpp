#include "Engine.h"
Engine* Engine::instance = nullptr;


void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
}



Engine& Engine::getInstance()
{
	if (!Engine::instance)
	{
		Engine::instance = new Engine();
	}
	return *Engine::instance;
} 

string buffer_nume;
int col = 8;
int level = 1;
int level1_zombies = 10;
int level2_zombies = 15;
int level3_zombies = 20;
int sun_spawn = 4000;
int scor = 0;
vector <Sun*> sun_list;
vector <Plants*> shop;
vector <Plants*> plants_added;
vector <Plants*> shooting_plants;
vector<Projectile*> projectiles_shot; 
vector<Zombie*> spawned_zombies;
vector <int> possible_rows = { 6,10,14,18,22 };
vector<int> possible_cols = { 8,14,20,26,32,38,44,50,56 };
int money = 0;

Engine::Engine()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	Engine::start_game();
	Engine::menu();
	Field::print();
	Engine::draw_shop();
	CLog& x = CLog::getInstance();
	x.print_event("THE GAME HAS STARTED.");
	int planting = 0;
	while (true)
	{
		if (scor == 50)
			level = 2;
		if (scor == 150)
			level = 3;
		conOut(1, 1) << scor;
		conOut(2, 109) << "COINS: " << money<<"            ";
		Engine::show_sun();
		string action = conIn.getUserActions();
		Event e(action);
		Engine::take_events(e, planting);
		Engine::plant(e, planting);
		Engine::show_projectiles();
		Engine::levels();
		Engine::fight();
		


		if (action != " ")
		{
			conOut(41, 2) << action;
		}
		else
		{
			break;
		}
	}
	
}
void Engine::destroyInstance()
{
	if (Engine::instance)
	{
		delete Engine::instance;
		Engine::instance = nullptr;
	}
}

void Engine::draw_shop()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	conOut(6, 2) << "P";
	conOut(7, 2) << "15";
	shop.push_back(new Peashooter("P", 50, 15,4000, 6, 2));
	conOut(10, 2) << "F";
	conOut(11, 2) << "25";
	shop.push_back(new Sunflower("F", 10, 2, 20, 25));
	conOut(14, 2) << "C";
	conOut(15, 2) << "35";
	shop.push_back(new CherryBomb("C", 20, 14, 2, 1, 35));
	conOut(18, 2) << "W";
	conOut(19, 2) << "40";
	shop.push_back(new Wallnut("W", 100, 40, 18, 2));
	conOut(22, 2) << "$";
	conOut(23, 2) << "45";
}


void Engine::show_sun()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	if ((duration_cast<milliseconds>(end - begin).count() > sun_spawn)&&(sun_list.size()<=9))
	{
		begin = end;
		conOut(2, col) << char(178);
		sun_list.push_back(new Sun(2, col));
	}
	col = col + 6;
	if (col >= 57)
	{
		col = 8;
	}
}

void Engine::take_events(Event aux,int &planting)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	if (aux.get_event() == "clicked")
	{
		for (int i = 0; i < sun_list.size(); i++)
		{
			if ((sun_list[i]->get_row() == aux.get_row()) && (sun_list[i]->get_col() == aux.get_col()))
			{
				money = money + sun_list[i]->get_money();
				conOut(aux.get_row(), aux.get_col()) << " ";
				sun_list.erase(sun_list.begin() + i);
				break;
			}
		}

		for (int i = 0; i < shop.size(); i++)
		{
			if ((aux.get_row() == shop[i]->get_row()) && (aux.get_col() == shop[i]->get_col()))
			{
				if (money >= shop[i]->get_price())
				{
					money = money - shop[i]->get_price();
					if (shop[i]->get_name() == "W")
					{
						plants_added.push_back(new Wallnut("W", 70, 40, 0, 0));
						planting = 1;
					}
					if (shop[i]->get_name() == "P")
					{
						plants_added.push_back(new Peashooter("P", 50, 15, 4000, 0, 0));
						planting = 1;
					}
					if (shop[i]->get_name() == "F")
					{
						plants_added.push_back(new Sunflower("F", 0, 0, 20, 25));
						planting = 1;
					}
					if (shop[i]->get_name() == "C")
					{
						plants_added.push_back(new CherryBomb("C", 20, 0, 0, 1, 35));
						planting = 1;
					}

				}
			}
		}
	}
}

bool verify(int rand, int coloana)
{
	int aux = 0;
	for (int i = 0; i < possible_rows.size(); i++)
	{
		if (possible_rows[i] == rand)
		{
			aux++;
			break;
		}
	}
	for (int j = 0; j < possible_cols.size(); j++)
	{
		if (possible_cols[j] == coloana)
		{
			aux++;
			break;
		}
	}
	if (aux == 2)
		return true;
	else
	{
		return false;
	}
}

void Engine::plant(Event e, int& planting)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	if (planting == 1)
	{
		if (e.get_event() == "clicked")
		{
			if (verify(e.get_row(), e.get_col()) == true)
			{
				plants_added[plants_added.size() - 1]->set_col(e.get_col());
				plants_added[plants_added.size() - 1]->set_row(e.get_row());
				conOut(e.get_row(), e.get_col()) << plants_added[plants_added.size()-1]->get_name();
				planting = 0;
				if (plants_added[plants_added.size() - 1]->get_name() == "P")
				{
					shooting_plants.push_back(new Peashooter("P", 50, 15, 4000, 0, 0));
					shooting_plants[shooting_plants.size() - 1]->set_row(e.get_row());
					shooting_plants[shooting_plants.size() - 1]->set_col(e.get_col());
				}
				if (plants_added[plants_added.size() - 1]->get_name() == "F")
				{
					sun_spawn = sun_spawn - 100;
				}
			}
		}
	}
}

void Engine::show_projectiles()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < shooting_plants.size(); i++)
	{
		if (shooting_plants[i]->delay())
			projectiles_shot.push_back(new Projectile(shooting_plants[i]->get_row(), shooting_plants[i]->get_col(), 10,750));
	}
	for (int j = 0; j < projectiles_shot.size(); j++)
	{
		if (projectiles_shot[j]->delay())
		{
			projectiles_shot[j]->move();
		}
		if (projectiles_shot[j]->get_col() + 1 == 59)
		{
			delete projectiles_shot[j];
			projectiles_shot.erase(projectiles_shot.begin() + j);
			continue;
		}
		for (int k = 0; k < spawned_zombies.size(); k++)
		{
			if (spawned_zombies[k]->get_row() == projectiles_shot[j]->get_row())
			{
				if ((spawned_zombies[k]->get_col() == projectiles_shot[j]->get_col() + 1) || (spawned_zombies[k]->get_col() == projectiles_shot[j]->get_col() + 2))
				{
					conOut(projectiles_shot[j]->get_row(), projectiles_shot[j]->get_col()) << " ";
					spawned_zombies[k]->take_damage(projectiles_shot[j]->get_damage());
					delete projectiles_shot[j];
					projectiles_shot.erase(projectiles_shot.begin() + j);
					break;
				}
			}
		}
	}

}

void Engine::levels()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	if ((duration_cast<milliseconds>(end - begin).count() > 9000)&&(level1_zombies!=0))
	{
		CLog& x = CLog::getInstance();
		x.print_event("LEVEL 1 STARTED.");
		conOut(28, 28) << "LEVEL 1";
		begin = end;
		spawned_zombies.push_back(new Zombie("Z", 14, 59, 40, 5,2000));
		CLog& y = CLog::getInstance();
		y.print_event("A ZOMBIE HAS BEEN SPAWNED.");
		if ((level1_zombies % 3 == 0)&&(level1_zombies!=0))
		{
			spawned_zombies.push_back(new BucketHead("B", 14, 59, 50, 5, 2000));
			CLog& z = CLog::getInstance();
			z.print_event("A BUCKET HEAD ZOMBIE HAS BEEN SPAWNED.");
		}
		if ((level1_zombies % 2 == 0)&&(level1_zombies!=0))
		{
			spawned_zombies.push_back(new PoleVaulting("V", 14, 59, 40, 5, 1400));
			CLog& x = CLog::getInstance();
			x.print_event("A POLE VAULTING ZOMBIE HAS BEEN SPAWNED.");
		}
		if (level1_zombies == 7)
		{
			spawned_zombies.push_back(new SuperZombie("@", 14, 59, 60, 8, 1200));
			CLog& x = CLog::getInstance();
			x.print_event("A SUPERZOMBIE HAS BEEN SPAWNED.");
		}
		--level1_zombies;
		
	}
	else
	{
		if ((duration_cast<milliseconds>(end - begin).count() > 9000) &&(level2_zombies!=0)&&(level==2))
		{
			CLog& y = CLog::getInstance();
			y.print_event("LEVEL 1 ENDED.");
			CLog& z = CLog::getInstance();
			z.print_event("LEVEL 2 STARTED.");
			int coordY;
			std::random_device device;
			std::mt19937 generator{ device() };
			std::uniform_int_distribution<int> distribution(1, 3);
			int zombieLine = distribution(generator);
			if (zombieLine == 1)
				coordY = 10;
			if (zombieLine == 2)
				coordY = 14;
			if (zombieLine == 3)
				coordY = 18;
			conOut(28, 28) << "LEVEL 2";
			begin = end;
			spawned_zombies.push_back(new Zombie("Z", coordY, 59, 40, 5, 2000));
			CLog& x = CLog::getInstance();
			x.print_event("A ZOMBIE HAS BEEN SPAWNED.");
			if ((level2_zombies % 3 == 0)&&(level2_zombies!=0))
			{
				spawned_zombies.push_back(new BucketHead("B", 14, 59, 50, 5, 2000));
				CLog& x = CLog::getInstance();
				x.print_event("A BUCKET HEAD ZOMBIE HAS BEEN SPAWNED.");
			}
			if ((level2_zombies % 5 == 0)&&(level2_zombies!=0))
			{
				spawned_zombies.push_back(new PoleVaulting("V", 14, 59, 50, 5, 1400));
				CLog& p = CLog::getInstance();
				p.print_event("A POLE VAULTING ZOMBIE HAS BEEN SPAWNED.");
			}
			if (level2_zombies == 7)
			{
				spawned_zombies.push_back(new SuperZombie("@", 14, 59, 60, 8, 1200));
				CLog& x = CLog::getInstance();
				x.print_event("A SUPERZOMBIE HAS BEEN SPAWNED.");
			}

			--level2_zombies;
		}
		if ((duration_cast<milliseconds>(end - begin).count() > 9000) && (level3_zombies != 0)&&(level==3))
		{
			CLog& y = CLog::getInstance();
			y.print_event("LEVEL 2 ENDED.");
			CLog& x = CLog::getInstance();
			x.print_event("LEVEL 3 STARTED.");
			int coordY;
			std::random_device device;
			std::mt19937 generator{ device() };
			std::uniform_int_distribution<int> distribution(1, 5);
			int zombieLine = distribution(generator);
			if (zombieLine == 1)
				coordY = 6;
			if (zombieLine == 2)
				coordY = 10;
			if (zombieLine == 3)
				coordY = 14;
			if (zombieLine == 4)
				coordY = 18;
			if (zombieLine == 5)
				coordY = 22;
			conOut(28, 28) << "LEVEL 3";
				begin = end;
				spawned_zombies.push_back(new Zombie("Z", coordY, 59, 40, 5, 2000));
				CLog& z = CLog::getInstance();
				z.print_event("A ZOMBIE HAS BEEN SPAWNED.");
				if ((level3_zombies % 3 == 0)&&(level3_zombies!=0))
				{
					spawned_zombies.push_back(new BucketHead("B", 14, 59, 50, 5, 2000));
					CLog& p = CLog::getInstance();
					p.print_event("A BUCKET HEAD ZOMBIE HAS BEEN SPAWNED.");
				}
				if ((level3_zombies % 5 == 0)&&(level3_zombies!=0))
				{
					spawned_zombies.push_back(new PoleVaulting("V", 14, 59, 50, 5, 1400));
					CLog& o = CLog::getInstance();
					o.print_event("A POLE VAULTING ZOMBIE HAS BEEN SPAWNED.");
				}
				if (level2_zombies == 7)
				{
					spawned_zombies.push_back(new SuperZombie("@", 14, 59, 60, 8, 1200));
					CLog& x = CLog::getInstance();
					x.print_event("A SUPERZOMBIE HAS BEEN SPAWNED.");
				}
				--level3_zombies;
		}

	}

}

void Engine::fight()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < spawned_zombies.size(); i++)
	{
		int fighting = 0;
		if (spawned_zombies[i]->get_health() <= 0)
		{
			conOut(spawned_zombies[i]->get_row(), spawned_zombies[i]->get_col()) << " ";
			delete spawned_zombies[i];
			spawned_zombies.erase(spawned_zombies.begin() + i);
			CLog& x = CLog::getInstance();
			x.print_event("A ZOMBIE DIED.");
			scor = scor + 10;
			check_win();
			continue;
		}
		if (spawned_zombies[i]->get_col() == 6)
		{
			game_lost();
			CLog& x = CLog::getInstance();
			x.print_event("THE GAME IS OVER(THE USER LOST).");
		}
		for (int j = 0; j < plants_added.size(); j++)
		{
			if (spawned_zombies[i]->get_row() == plants_added[j]->get_row())
			{
				if (spawned_zombies[i]->get_col() - 1 == plants_added[j]->get_col())
				{
					if ((spawned_zombies[i]->get_name() == "V")&&(spawned_zombies[i]->get_jump()==0))
					{
						conOut(spawned_zombies[i]->get_row(), plants_added[j]->get_col() + 1) << " ";
						conOut(spawned_zombies[i]->get_row(), plants_added[j]->get_col() - 1) << "V";
						spawned_zombies[i]->set_col(plants_added[j]->get_col() - 1);
						spawned_zombies[i]->set_row(plants_added[j]->get_row());
						spawned_zombies[i]->set_jump();
					}
					if ((spawned_zombies[i]->get_name() == "@") && (spawned_zombies[i]->get_jump() == 0))
					{
						conOut(spawned_zombies[i]->get_row(), plants_added[j]->get_col() + 1) << " ";
						conOut(spawned_zombies[i]->get_row(), plants_added[j]->get_col() - 1) << "@";
						spawned_zombies[i]->set_col(plants_added[j]->get_col() - 1);
						spawned_zombies[i]->set_row(plants_added[j]->get_row());
						spawned_zombies[i]->set_jump();
					}
					if (plants_added[j]->get_name() == "C")
					{
						int ok = 0;
						for (int k = 0; k < spawned_zombies.size(); k++)
						{
							if ((spawned_zombies[k]->get_col() <= plants_added[j]->get_col() + 3) && (spawned_zombies[k]->get_col() >= plants_added[j]->get_col() - 3) && (spawned_zombies[k]->get_row() == plants_added[j]->get_row()))
							{
								spawned_zombies[k]->take_damage(20);//damage-ul setat pentru cherry bomb
								plants_added[j]->take_damage(2);
							}
							else
							{
								if ((spawned_zombies[k]->get_col() >= plants_added[j]->get_col() + 3) && (spawned_zombies[k]->get_col() <= plants_added[j]->get_col() + 9) && (spawned_zombies[k]->get_row() == plants_added[j]->get_row()))
								{
									spawned_zombies[k]->take_damage(10);//damage-ul setat pentru cherry bomb
		
								}
			
								if ((spawned_zombies[k]->get_col() <= plants_added[j]->get_col() - 3) && (spawned_zombies[k]->get_col() >= plants_added[j]->get_col() - 9) && (spawned_zombies[k]->get_row() == plants_added[j]->get_row()))
								{
									spawned_zombies[k]->take_damage(10);//damage-ul setat pentru cherry bomb
								}
								if ((spawned_zombies[k]->get_row()==plants_added[j]->get_row()-4) && (spawned_zombies[k]->get_col() >= plants_added[j]->get_col() - 9) && (spawned_zombies[k]->get_col() <= plants_added[j]->get_col()+9))
								{
									spawned_zombies[k]->take_damage(10);//damage-ul setat pentru cherry bomb
								}
								if ((spawned_zombies[k]->get_row() == plants_added[j]->get_row() +4) && (spawned_zombies[k]->get_col() >= plants_added[j]->get_col() - 9) && (spawned_zombies[k]->get_col() <= plants_added[j]->get_col() + 9))
								{
									spawned_zombies[k]->take_damage(10);//damage-ul setat pentru cherry bomb
								}
							}

						}

					}
					fighting = 1;
					static auto begin = steady_clock::now();
					auto end = steady_clock::now();

					if ((duration_cast<milliseconds>(end - begin).count() > 2500))
					{
						begin = end;
						if (plants_added[j]->get_health() <= 0)
						{
							if (plants_added[j]->get_name() == "F")
							{
								sun_spawn = sun_spawn + 100;
							}
							delete plants_added[j];
							plants_added.erase(plants_added.begin() + j);
							CLog& x = CLog::getInstance();
							x.print_event("A PLANT DIED.");
						}
						else
						{
							plants_added[j]->take_damage(spawned_zombies[i]->get_damage());
							
						}
						break;
					}
				}
			}
		}
		if ((spawned_zombies[i]->delay())&&(fighting==0))
			spawned_zombies[i]->move();
	}
}

void Engine::start_game()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	ifstream f;
	f.open("name_font.txt", ios::in);
	char* str = new char[300];
	for (int i = 15; i < 27; i++)
	{
		f.getline(str, 300);
		conOut(i, 20) << str;
	}
	_getch();
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			conOut(i, j) << " ";
		}
	}

}

void Engine::menu()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	ifstream g;
	g.open("menu_font.txt", ios::in);
	char* str_1 = new char[300];
	for (int i = 15; i < 25; i++)
	{
		g.getline(str_1, 300);
		conOut(i, 60) << str_1;
	}
	conOut(26, 74) << "-REGISTER-";
	conOut(28, 74) << "-LOGIN-";
	conOut(30, 74) << "-RECENT SCORES-";
	while (true)
	{
		string action = conIn.getUserActions();
		Event e(action);
		if (e.get_row() == 26)
		{
			if ((e.get_col() > 73) && (e.get_col() < 85))
			{
				menu_register();
				break;
			}
		}
		if (e.get_row() == 28)
		{
			if ((e.get_col() > 73) && (e.get_col() < 81))
			{
				menu_login();
				break;
			}
		}
		if (e.get_row() == 30)
		{
			if ((e.get_col() > 73) && (e.get_col() < 90))
			{
				menu_recent_scores();
				break;
			}
		}
	}
	

	

}

void Engine::menu_register()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			conOut(i, j) << " ";
		}
	}
	conOut(20, 75) << "NAME:";
	conOut(22,75) << "PASSWORD:";
	string aux_1;
	conOut(24, 75) << "PRESS ENTER TWICE AFTER YOU INTRODUCED YOUR USERNAME...";
	cin >> buffer_nume;
	conOut(24, 75) << "                                                          ";
	
	conOut(20, 85) << buffer_nume;
	string parola,aux_2;
	conOut(24, 75) << "PRESS ENTER TWICE AFTER YOU INTRODUCED YOUR PASSWORD...";
	cin >> parola;
	conOut(24, 75) << "                                                          ";
	conOut(22, 85) << parola;
	ifstream g;
	g.open("date_login.txt", ios::in);
	while (g >> aux_1 >> aux_2)
	{
		if (aux_1 == buffer_nume)
		{
			conOut(25, 85) << "USERNAME ALREADY USED...";
			_getch();
			menu_register();
		}
	}
	g.close();
	ofstream f;
	f.open("date_login.txt", ios::app);

	f << buffer_nume << " " << parola << "\n";

	conOut(27, 75) << "PRESS ENTER TO PLAY...";
	_getch();
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			conOut(i, j) << " ";
		}
	}
}

void Engine::menu_login()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			conOut(i, j) << " ";
		}
	}
	string aux_1;
	string buffer_parola, aux_2;
	conOut(20, 75) << "USERNAME:";
	cin >> buffer_nume;
	conOut(20, 90) << buffer_nume;
	conOut(22, 75) << "PASSWORD:";
	cin >> buffer_parola;
	conOut(22, 90) << buffer_parola;
	
	int x = 0;
	ifstream f;
	f.open("date_login.txt", ios::in);
	while (f >> aux_1 >> aux_2)
	{
		
		if ((aux_1 == buffer_nume) && (aux_2 == buffer_parola))
		{
			conOut(25, 75) << "LOGIN SUCCESFUL...";
			_getch();
			for (int i = 0; i < 60; i++)
			{
				for (int j = 0; j < 400; j++)
				{
					conOut(i, j) << " ";
				}
			}
			x = 1;
			break;
		}
	}
	if (x == 0)
	{
		conOut(25, 75) << "USERNAME OR PASSWORD WRONG...";
		_getch();
		menu_login();
	}
}

void Engine::game_lost()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	ofstream f;
	f.open("users_scores.txt", ios::app);
	f << buffer_nume << " " << scor << "\n";
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			conOut(i, j) << " ";
		}
	}
	conOut(20, 75) << "GAME LOST!";
	_getch();
	exit(0);
}

void Engine::check_win()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	if (scor == 450)
	{
		for (int i = 0; i < 60; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				conOut(i, j) << " ";
			}
		}
		conOut(20, 75) << "YOU WON!";
		CLog& x = CLog::getInstance();
		x.print_event("THE GAME IS OVER(USER WON).");
		_getch();
		exit(0);
	}
}

void Engine::menu_recent_scores()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			conOut(i, j) << " ";
		}
	}
	int x = 15;
	ifstream f;
	string buffer_1, buffer_2;
	f.open("users_scores.txt", ios::in);
	while (f >> buffer_1 >> buffer_2)
	{
		conOut(x, 75) << buffer_1 << "->" << buffer_2 << "\n";
		x++;
	}
	
	conOut(x + 1, 75) << "PRESS ENTER TO GET BACK TO MENU...";
	_getch();
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			conOut(i, j) << " ";
		}
	}
	menu();
}
