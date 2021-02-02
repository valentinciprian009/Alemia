#include "Handler.h"

Handler* Handler::mpInstance = NULL;

Handler& Handler::getInstance()
{
	if (mpInstance == NULL)
	{
		mpInstance = new Handler();
	}

	return *mpInstance;
}

void Handler::color(int color) // modifica culoarea caracterelor care vor fi afisate
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void Handler::get_pos_on_console(int& x, int& y) // foloseste indicii matricei pentru a returna pozitia pe consola 
{
	x = 6 + x * 3;

	switch (y)
	{
	case 0:
		y = 16;
		break;

	case 1:
		y = 22;
		break;

	case 2:
		y = 28;
		break;

	case 3:
		y = 34;
		break;

	case 4:
		y = 40;
		break;

	case 5:
		y = 46;
		break;

	case 6:
		y = 52;
		break;

	case 7:
		y = 58;
		break;

	case 8:
		y = 64;
		break;

	}
}

void Handler::get_pos_on_matrix(int& x, int& y) // converteste indicii unei pozitii de pe consola in indici pentru matrice
{
	if (y >= 5 && y <= 7)
	{
		y = 0;
	}
	if (y >= 8 && y <= 10)
	{
		y = 1;
	}
	if (y >= 11 && y <= 13)
	{
		y = 2;
	}
	if (y >= 14 && y <= 16)
	{
		y = 3;
	}
	if (y >= 17 && y <= 19)
	{
		y = 4;
	}

	if (x >= 14 && x <= 19)
	{
		x = 0;
	}
	if (x >= 20 && x <= 25)
	{
		x = 1;
	}
	if (x >= 26 && x <= 31)
	{
		x = 2;
	}
	if (x >= 32 && x <= 37)
	{
		x = 3;
	}
	if (x >= 38 && x <= 43)
	{
		x = 4;
	}
	if (x >= 44 && x <= 49)
	{
		x = 5;
	}
	if (x >= 50 && x <= 55)
	{
		x = 6;
	}
	if (x >= 56 && x <= 61)
	{
		x = 7;
	}
	if (x >= 62 && x <= 67)
	{
		x = 8;
	}
}

void Handler::get_y_sun(int& y)
{
	y = 16 + y * 5;
}

void Handler::reverse_get_y_sun(int& y)
{
	y = (y - 16) / 5;
}

void Handler::gotoXY(int x, int y) // pozitioneaza cursorul la o anumita pozitie
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Handler::collect_sun(int x)
{
	resources += x;

	if (resources >= 1000000000)
	{
		resources = 999999999;
	}

	show_resources();
}

void Handler::show_resources() // afiseaza numarul de resurse de tip sun
{
	int verif = resources;
	int digits = 0;

	gotoXY(14, 26);
	cout << "          ";

	while (verif)
	{
		verif /= 10;
		digits++;
	}

	gotoXY(23-digits, 26);
	color(15);
	cout << resources;
}

int Handler::spend_resources(int x) // verifica daca exista suficiente resurse pentru a cumpara o planta selectata anterior
{
	if (resources >= x)
	{
		resources -= x;
		show_resources();
		return 1;
	}

	gotoXY(1, 23);
	color(4);
	cout << "Nu aveti suficiente resurse";

	Sleep(3000);

	gotoXY(1, 23);
	cout << "                           ";
	color(15);

	return 0;
}

void Handler::generate_sun(vector<vector<int>> fight_matrix, vector<vector<int>>& sun_matrix, int i, int j, int runs)
{
	int pos_sun_matrix, coord_print_y;

	if (runs % 3 == 0) // resursele de tip sun se genereaza din 3 in 3 rulari ale algoritmului
	{
		if (fight_matrix[i][j] == 2)
		{
			pos_sun_matrix = rand() % 10;

			if (sun_matrix[0][pos_sun_matrix] == 0)
			{
				sun_matrix[0][pos_sun_matrix] = 1;

				coord_print_y = pos_sun_matrix;
				get_y_sun(coord_print_y);
				gotoXY(coord_print_y, 2);
				color(14);
				cout << "*";
				color(15);
			}

			sun_matrix[1][pos_sun_matrix] += 50;
		}
	}
}

void Handler::set_action(UserInterface::ConsoleInput conIn, int& action, int &ok, int number_zombies_killed)
{
	// se verifica daca utilizatorul a selectat o planta. In caz afirmativ se verifica daca exista suficiente resurse pentru acea planta,
	//   iar daca exista, se va scadea numarul de resurse pe care-l necesita planta si se va marca in variabila action numarul plantei

	if (conIn.get_x() >= 1 && conIn.get_x() <= 8)
	{
		if (conIn.get_y() >= 5 && conIn.get_y() <= 7) // Peashooter
		{
			if (spend_resources(100))
			{
				action = 1;
				ok = 1;
			}
			else
			{
				action = 0;
			}
		}

		if (conIn.get_y() >= 8 && conIn.get_y() <= 10) //Sunflower
		{
			if (spend_resources(50))
			{
				action = 2;
				ok = 1;
			}
			else
			{
				action = 0;
			}
		}

		if (conIn.get_y() >= 11 && conIn.get_y() <= 13) //Cherry_Bomb
		{
			if (number_zombies_killed != -1) // daca variabila are valoarea -1 inseamna ca jocul este intre runde si nu se
			{								 //    poate folosi Cherry_Bomb-ul
				if (spend_resources(150))
				{
					action = 3;
					ok = 1;
				}
				else
				{
					action = 0;
				}
			}
			else
			{
				gotoXY(1, 23);
				color(4);
				cout << "Nu se poate folosi Cherry_Bomb-ul in acest moment al jocului";

				Sleep(3000);

				gotoXY(1, 23);
				cout << "                                                            ";
				color(15);

				action = 0;
			}
		}

		if (conIn.get_y() >= 14 && conIn.get_y() <= 16) // Wall-nut
		{
			if (spend_resources(50))
			{
				action = 4;
				ok = 1;
			}
			else
			{
				action = 0;
			}
		}

		if (conIn.get_y() >= 17 && conIn.get_y() <= 19) // Snow_Pea
		{
			if (spend_resources(175))
			{
				action = 5;
				ok = 1;
			}
			else
			{
				action = 0;
			}
		}
	}
}

void Handler::set_pos_and_coord(int conIn_x, int conIn_y, int& position_in_vector, int& coord_on_x) // se calculeaza pozitia in vector si
{																									//    coordonata in consola
	if (conIn_x >= 14 && conIn_x <= 67)
	{
		if (conIn_x >= 14 && conIn_x <= 19)
		{
			position_in_vector = 0;
			coord_on_x = 16;
		}
		else
		{
			if (conIn_x >= 20 && conIn_x <= 25)
			{
				position_in_vector = 1;
				coord_on_x = 22;
			}
			else
			{
				if (conIn_x >= 26 && conIn_x <= 31)
				{
					position_in_vector = 2;
					coord_on_x = 28;
				}
				else
				{
					if (conIn_x >= 32 && conIn_x <= 37)
					{
						position_in_vector = 3;
						coord_on_x = 34;
					}
					else
					{
						if (conIn_x >= 38 && conIn_x <= 43)
						{
							position_in_vector = 4;
							coord_on_x = 40;
						}
						else
						{
							if (conIn_x >= 44 && conIn_x <= 49)
							{
								position_in_vector = 5;
								coord_on_x = 46;
							}
							else
							{
								if (conIn_x >= 50 && conIn_x <= 55)
								{
									position_in_vector = 6;
									coord_on_x = 52;
								}
								else
								{
									if (conIn_x >= 56 && conIn_x <= 61)
									{
										position_in_vector = 7;
										coord_on_x = 58;
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

void Handler::choose_vector(vector<Entities*>& Line, int action, int position_in_vector, int coord_on_x, int coord_on_y)
{
	// se alege vectorul in care se va memora instanta obiectului ales anterior

	Plants* New_Plant;

	switch (action)
	{
	case 1:
		New_Plant = new Peashooter();
		Line[position_in_vector] = New_Plant;
		break;

	case 2:
		New_Plant = new Sunflower();
		Line[position_in_vector] = New_Plant;
		break;

	case 3:
		New_Plant = new Cherry_Bomb();
		Line[position_in_vector] = New_Plant;
		break;

	case 4:
		New_Plant = new Wall_nut();
		Line[position_in_vector] = New_Plant;
		break;

	default:
		New_Plant = new Snow_Pea();
		Line[position_in_vector] = New_Plant;
		break;

	}

	Line[position_in_vector]->print_on_terrain(coord_on_x, coord_on_y);
}

void Handler::set_object_in_vector_and_in_fight_matrix(int conIn_x, int conIn_y, vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, int action, int position_in_vector, int coord_on_x)
{
	if (conIn_y >= 5 && conIn_y <= 7) //prima linie
	{
		choose_vector(Lines[0], action, position_in_vector, coord_on_x, 6);
		fight_matrix[0][position_in_vector] = action;
	}
	else
	{
		if (conIn_y >= 8 && conIn_y <= 10) //a doua linie
		{
			choose_vector(Lines[1], action, position_in_vector, coord_on_x, 9);
			fight_matrix[1][position_in_vector] = action;
		}
		else
		{
			if (conIn_y >= 11 && conIn_y <= 13) //a treia linie
			{
				choose_vector(Lines[2], action, position_in_vector, coord_on_x, 12);
				fight_matrix[2][position_in_vector] = action;
			}
			else

			{
				if (conIn_y >= 14 && conIn_y <= 16) //a patra linie
				{
					choose_vector(Lines[3], action, position_in_vector, coord_on_x, 15);
					fight_matrix[3][position_in_vector] = action;
				}
				else
				{
					if (conIn_y >= 17 && conIn_y <= 19) //a cincea linie
					{
						choose_vector(Lines[4], action, position_in_vector, coord_on_x, 18);
						fight_matrix[4][position_in_vector] = action;
					}
				}
			}
		}
	}

	action = 0;
}

// se calculeaza damageul pe care ar trebui sa-l aiba fiecare proiectil. In cazul in care ar trebui sa fie doua sau mai multe proiectile
//    pe aceeasi zona, se va aduna damage-ul si se va afisa doar un proiectil
void Handler::set_projectiles(vector<vector<int>> fight_matrix, vector<vector<int>>& projectile_matrix)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (fight_matrix[i][j] == 1 || fight_matrix[i][j] == 5)
			{
				if (fight_matrix[i][j] == 1) // pune Pea
				{
					projectile_matrix[i][j] += 2;
				}
				if (fight_matrix[i][j] == 5) // pune Frozen_Pea
				{
					projectile_matrix[i][j] += 2;

					if (projectile_matrix[i][j] % 2 == 0)
					{
						projectile_matrix[i][j] += 1;
					}
				}
			}
		}
	}
}

// sterge proiectilele din consola la finalul fiecarei runde
void Handler::remove_projectiles_from_the_screen(vector<vector<int>> fight_matrix)
{
	int coord_print_x, coord_print_y;

	for (auto j = 0; j <= 8; j++)
	{
		for (auto i = 0; i <= 4; i++)
		{
			if (fight_matrix[i][j] == 0)
			{
				coord_print_x = i;
				coord_print_y = j;
				get_pos_on_console(coord_print_x, coord_print_y);
				gotoXY(coord_print_y, coord_print_x);
				cout << "  ";
			}
		}
	}
}

void Handler::check_if_any_button_is_pressed(UserInterface::ConsoleInput conIn, int& start_next_round, int round)
{
	if (conIn.get_y() >= 29 && conIn.get_y() <= 31)
	{
		if (conIn.get_x() >= 1 && conIn.get_x() <= 15) // butonul Exit
		{
			COORD coord = { 1, 30 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			start_next_round = 3;
		}
		else // butonul Next Round
		{
			if (conIn.get_x() >= 20 && conIn.get_x() <= 34)
			{
				start_next_round = 1;
				conIn.set_x(0); // pentru ca ar ramane coordonatele de la ultimul dublu click care ar face sa inceapa
				conIn.set_y(0); //    urmatoarea runda imediat.

				gotoXY(1, 21);
				color(15);
				cout << "                                                                                        ";
				gotoXY(1, 21);
				cout << "Runda: " << round << ". ";
			}
		}
	}
}

void Handler::collect_resources(UserInterface::ConsoleInput conIn, vector<vector<int>>& sun_matrix)
{
	int coord_print_y;

	if (conIn.get_y() >= 1 && conIn.get_y() <= 3)
	{
		coord_print_y = conIn.get_x();
		reverse_get_y_sun(coord_print_y);

		if (sun_matrix[0][coord_print_y] == 1)
		{
			gotoXY(conIn.get_x() - 1, 2);
			cout << "   ";

			collect_sun(sun_matrix[1][coord_print_y]);
			sun_matrix[0][coord_print_y] = 0;
			sun_matrix[1][coord_print_y] = 0;
		}
	}
}

void Handler::generate_Zombie(vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, int round, int row, int number_zombies, int& nr_PV_Zombies_Created, int& number_zombies_created)
{
	int Zombie_type, coord_print_x, coord_print_y;

	Zombie* Zombie;

	coord_print_x = row;
	coord_print_y = 8;
	get_pos_on_console(coord_print_x, coord_print_y);

	if (fight_matrix[row][8] == 0)
	{
		if (number_zombies - number_zombies_created <= 2 * round)
		{
			Zombie_type = rand() % 2;

			if (Zombie_type == 0 && nr_PV_Zombies_Created)
			{
				fight_matrix[row][8] = 12;
				Zombie = new PoleVaulting_Zombie();
				Lines[row][8] = Zombie;
				Lines[row][8]->print_on_terrain(coord_print_y, coord_print_x);

				nr_PV_Zombies_Created--;
			}
			else
			{
				fight_matrix[row][8] = 11;
				Zombie = new BucketHead_Zombie();
				Lines[row][8] = Zombie;
				Lines[row][8]->print_on_terrain(coord_print_y, coord_print_x);
			}
		}
		else
		{
			fight_matrix[row][8] = 10;
			Zombie = new Normal_Zombie();
			Lines[row][8] = Zombie;
			Lines[row][8]->print_on_terrain(coord_print_y, coord_print_x);
		}

		number_zombies_created++;
	}
}

void Handler::spawn_Zombies(vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, int& number_zombies_created, int number_zombies, int& nr_PV_Zombies_Created, int round)
{
	int row;

	if (number_zombies_created != number_zombies) // se spawn-eaza Zombie pe linii
	{
		if (round >= 5)
		{
			row = rand() % 5;

			generate_Zombie(Lines, fight_matrix, round, row, number_zombies, nr_PV_Zombies_Created, number_zombies_created);
		}
		else
		{
			if (round >= 3)
			{
				row = rand() % 3 + 1;

				generate_Zombie(Lines, fight_matrix, round, row, number_zombies, nr_PV_Zombies_Created, number_zombies_created);
			}
			else
			{
				if (round >= 1)
				{
					if (fight_matrix[2][8] == 0)
					{
						fight_matrix[2][8] = 10;

						Zombie* Zombie = new Normal_Zombie();

						Lines[2][8] = Zombie;
						Lines[2][8]->print_on_terrain(64, 12);

						number_zombies_created++;
					}
				}
			}
		}
	}
}

void Handler::verif_if_Zombie_is_killed(vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, int& number_zombies_killed, int i, int j, int j_for_Lines)
{
	int coord_print_x, coord_print_y;

	Menu& M = Menu::getInstance();

	if (Lines[i][j_for_Lines]->get_hp() <= 0) // se verifica daca Zombie-ul mai are hp
	{                                         //    in caz contrar, acesta moare, fiind sters din matrici
		number_zombies_killed++;

		coord_print_x = i;
		coord_print_y = j;
		get_pos_on_console(coord_print_x, coord_print_y);
		gotoXY(coord_print_y, coord_print_x);
		cout << "  ";

		M.set_score(Lines[i][j_for_Lines]->get_points());
		color(15);
		M.show_score();

		delete Lines[i][j_for_Lines];
		Lines[i][j_for_Lines] = 0;
		fight_matrix[i][j] = 0;
	}
}

void Handler::move_Zombies(int i, vector<vector<int>>& fight_matrix, vector<vector<int>>& projectile_matrix, vector<vector<Entities*>>& Lines, vector<vector<int>>& sun_matrix, int& number_zombies_killed, int runs)
{
	int coord_print_x, coord_print_y;

	for (auto j = 0; j <= 7; j++) // verifica daca Zombii se pot deplasa
	{
		if (fight_matrix[i][j + 1] >= 10) // pe urmatoarea pozitie este un Zombie
		{
			// daca nu e nimic pus pe pozitia curenta se muta Zombie-ul 
			if (fight_matrix[i][j] == 0) // aici nu este pus nimic
			{
				if (projectile_matrix[i][j] != 0) // se verifica daca exista proiectile, iar in caz 
				{								  //    afirmativ Zombie-ul va lua damage-ul corespunzator
					if (projectile_matrix[i][j] % 2 == 0)
					{
						projectile_matrix[i][j] /= 2;
					}

					if (Lines[i][j + 1] != 0)
					{
						Lines[i][j + 1]->take_damage(projectile_matrix[i][j]);
						projectile_matrix[i][j] = 0;

						verif_if_Zombie_is_killed(Lines, fight_matrix, number_zombies_killed, i, j, j + 1);
					}
				}

				fight_matrix[i][j] = fight_matrix[i][j + 1]; // in cazul in care Zombie-ul nu moare,
				fight_matrix[i][j + 1] = 0;                  //    acesta va inainta

				coord_print_x = i;
				coord_print_y = j + 1;
				get_pos_on_console(coord_print_x, coord_print_y);
				gotoXY(coord_print_y, coord_print_x);
				cout << "  ";

				if (Lines[i][j + 1] != 0)
				{
					Lines[i][j] = move(Lines[i][j + 1]);
					Lines[i][j + 1] = 0;

					coord_print_x = i;
					coord_print_y = j;
					get_pos_on_console(coord_print_x, coord_print_y);
					gotoXY(coord_print_y, coord_print_x);
					Lines[i][j]->print_on_terrain(coord_print_y, coord_print_x);
				}
			}
			else // in cazul in care este o planta pe pozitia respectiva, aceasta va lua damage
			{
				if (Lines[i][j] != 0)
				{
					// verifica daca Zombiul este de tipul PoleVaulting si daca a sarit vreodata
					if (Lines[i][j + 1]!=0 && Lines[i][j + 1]->get_jump() == 1)
					{
						if (fight_matrix[i][j - 1] == 0) // verifica daca Zombie-ul are un spatiu gol pe care sa aterizeze; in cazul
						{								 //    in care nu este nimic pe pozitia din spatele plantei, se muta Zombie-ul
							fight_matrix[i][j - 1] = fight_matrix[i][j + 1];
							fight_matrix[i][j + 1] = 0;

							Lines[i][j - 1] = move(Lines[i][j + 1]);

							coord_print_x = i;
							coord_print_y = j - 1;
							get_pos_on_console(coord_print_x, coord_print_y);
							Lines[i][j - 1]->print_on_terrain(coord_print_y, coord_print_x);

							Lines[i][j + 1] = 0;
						}

						Lines[i][j - 1]->change_jump();
					}
					else
					{
						Lines[i][j]->take_damage();

						if (Lines[i][j]->get_hp() <= 0) // se verifica daca planta mai are hp; in caz
						{								//    contrar, aceasta se va sterge
							coord_print_x = i;
							coord_print_y = j;
							get_pos_on_console(coord_print_x, coord_print_y);
							gotoXY(coord_print_y, coord_print_x);
							cout << "  ";

							delete Lines[i][j];
							Lines[i][j] = 0;
							fight_matrix[i][j] = 0;
						}
					}
				}
			}
		}

		// se genereaza resurse de tip sun
		generate_sun(fight_matrix, sun_matrix, i, j, runs);
	}
}

void Handler::cherrybomb_explode(vector<vector<int>>& fight_matrix, vector<vector<Entities*>>& Lines, int x, int y, int& number_zombies_killed)
{
	int damage;

	get_pos_on_matrix(x, y);

	Cherry_Bomb* CB = new Cherry_Bomb();

	for (int i = y - 1; i <= y + 1; i++)
		for (int j = x - 1; j <= x + 1; j++)
		{
			if (i >= 0 && i <= 4 && j >= 0 && j <= 8)
			{
				if (fight_matrix[i][j] >= 10)
				{
					if (i == y && j == x)
					{
						damage = CB->give_damage();
					}
					else
					{
						damage = CB->give_damage() / 2;
					}

					Lines[i][j]->take_damage(damage);
					verif_if_Zombie_is_killed(Lines, fight_matrix, number_zombies_killed, i, j, j);
				}
			}
		}
}

void Handler::set_plants(UserInterface::ConsoleInput& conIn, vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, int& action, int& ok_set_action, int& ok_set_plants, int& number_zombies_killed)
{
	int x, y, position_in_vector, coord_on_x;

	if (action == 0) // nu s-a selectat nicio planta
	{
		if (ok_set_action == 0)
		{
			if (conIn.get_x() >= 1 && conIn.get_x() <= 8)
			{
				set_action(conIn, action, ok_set_action, number_zombies_killed); // returneaza prin variabila action valoarea asociata plantei alese   
			}

			if (action == 0)
			{
				conIn.set_x(0);
				conIn.set_y(0);
			}
		}
	}
	else // s-a selectat o planta 
	{
		if (ok_set_action == 1)
		{
			if (conIn.get_x() >= 62 && conIn.get_x() <= 67) // aceasta notificare apare cand se vrea punerea
			{                                               //    unei plante pe ultima coloana
				gotoXY(1, 23);
				color(4);
				cout << "Nu se pot pune plante pe ultima coloana";

				Sleep(3000);

				gotoXY(1, 23);
				cout << "                                       ";
				color(15);

				ok_set_plants = 1;
				conIn.set_x(0);
				conIn.set_y(0);
			}
			else
			{
				if (conIn.get_x() >= 14 && conIn.get_x() <= 61)
				{
					x = conIn.get_x();
					y = conIn.get_y();

					// returneaza pozitia in vector si coordonata pe x
					set_pos_and_coord(x, y, position_in_vector, coord_on_x);

					if (action != 3) // daca planta aleasa nu e Cherry_Bomb
					{
						// seteaza planta in matrici
						set_object_in_vector_and_in_fight_matrix(x, y, Lines, fight_matrix, action, position_in_vector, coord_on_x);
					}
					else // planta e Cherry_Bomb
					{
						cherrybomb_explode(fight_matrix, Lines, x, y, number_zombies_killed);
					}
					
					ok_set_action = 0;

					action = 0;

					conIn.set_x(0);
					conIn.set_y(0);
				}
			}
		}
	}
}

void Handler::move_projectiles(vector<vector<int>>& projectile_matrix, vector<vector<int>>& fight_matrix, vector<vector<Entities*>>& Lines, int i, int& number_zombies_killed)
{
	int coord_print_x, coord_print_y;

	Pea& P = Pea::getInstance();

	for (auto j = 8; j >= 1; j--)
	{
		if (projectile_matrix[i][j - 1] != 0)
		{
			// afiseaza proiectilele pe ecran in cazul in care nu exista nici un alt entitie afisat
			if (fight_matrix[i][j] == 0)
			{
				coord_print_x = i;
				coord_print_y = j;
				get_pos_on_console(coord_print_x, coord_print_y);

				P.print_on_terrain(coord_print_y, coord_print_x);
			}
			else // daca nu se poate afisa pe ecran un proiectil, se verifica daca exista un 
			{	 //    Zombie pe acea pozitie; in caz afirmativ, acesta va lua damage.
				if (fight_matrix[i][j] >= 10)
				{
					if (projectile_matrix[i][j - 1] % 2 == 0)
					{
						projectile_matrix[i][j - 1] /= 2;
					}

					if (Lines[i][j] != 0 && projectile_matrix[i][j - 1] != 0)
					{
						Lines[i][j]->take_damage(projectile_matrix[i][j - 1]);
						projectile_matrix[i][j - 1] = 0;

						verif_if_Zombie_is_killed(Lines, fight_matrix, number_zombies_killed, i, j, j);
					}
				}
			}

			// se muta proiectilele in memorie
			projectile_matrix[i][j] = projectile_matrix[i][j - 1];
			projectile_matrix[i][j - 1] = 0;
		}
	}
}

void Handler::verif_game_lost(vector<vector<int>> fight_matrix, int& ok, int& round)
{
	for (int i = 0; i <= 4; i++) // se verifica daca exista vreun Zombie pe prima coloana a terenului;
	{							 //    in caz afirmativ, jocul este pierdut.
		if (fight_matrix[i][0] >= 10)
		{
			gotoXY(1, 23);
			color(4);
			cout << "Joc pierdut!";

			ok = 0;
			round--;

			break;
		}
	}
}

void Handler::start_battle(vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, vector<vector<int>>& projectile_matrix, vector<vector<int>>& sun_matrix, int& round, int& ok)
{
	int ok_set_plants, action = 0, ok_set_action = 0, runs = 0, number_zombies_killed = 0, number_zombies_created = 0;
	int number_zombies = 3 * round;
	int nr_PV_Zombies_Created = round;

	ok = 1;
	
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	while (number_zombies_killed != number_zombies && ok == 1)
	{
		runs++;

	start2:

		std::string v = conIn.getUserActions();

		// se colecteaza resursele
		collect_resources(conIn, sun_matrix);

		// se pun plante pe teren
		ok_set_plants = 0;
		set_plants(conIn, Lines, fight_matrix, action, ok_set_action, ok_set_plants, number_zombies_killed);

		if (ok_set_plants == 1)
		{
			goto start2;
		}

		// pune toate proiectilele in matricea projectile_matrix si calculeaza damage-urile pe fiecare pozitie
		set_projectiles(fight_matrix, projectile_matrix);

		spawn_Zombies(Lines, fight_matrix, number_zombies_created, number_zombies, nr_PV_Zombies_Created, round);

		for (auto i = 0; i <= 4; i++)
		{
			move_Zombies(i, fight_matrix, projectile_matrix, Lines, sun_matrix, number_zombies_killed, runs);

			move_projectiles(projectile_matrix, fight_matrix, Lines, i, number_zombies_killed);

			Sleep(50);
		}

		remove_projectiles_from_the_screen(fight_matrix); // elimina proiectilele de pe ecran

		verif_game_lost(fight_matrix, ok, round);
	}

	round++;
}

// delimiteaza mapa mai bine. Delimitarile dispar atunci cand incepe cate o runda
void Handler::show_boundaries(int x)
{
	short i, j;
	string boundary;

	COORD coord;

	if (x == 1)
		boundary = "|";
	else
		boundary = " ";

	color(8);

	for (i = 5; i <= 17; i = i + 3)
	{
		for (j = 20; j <= 62; j = j + 6)
		{
			coord = { j, i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << boundary;

			coord = { j, i + 1 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << boundary;
		}
	}

	color(15);
}

// incepe o runda noua
void Handler::start_game(UserInterface::ConsoleInput& conIn, vector<vector<Entities*>>& Lines, vector<vector<int>>& fight_matrix, vector<vector<int>>& projectile_matrix, vector<vector<int>>& sun_matrix, int& start_next_round, int& action, int &ok_set_action, int& round, int& ok_set_plants, int& ok)
{
	if (start_next_round == 0) // se colecteaza resursele si se aleg plantele care se pun pe mapa
	{
		show_boundaries(1); // delimiteaza zonele

		// se colecteaza resursele
		collect_resources(conIn, sun_matrix);

		int number_zombies_killed = -1; // pentru ca jocul se afla intre runde si nu exista Zombie care sa fie omorati

		// se pun plante pe teren
		ok_set_plants = 0;
		set_plants(conIn, Lines, fight_matrix, action, ok_set_action, ok_set_plants, number_zombies_killed);
	}
	else // incepe batalia
	{
		show_boundaries(0); // elimina delimitarea zonelor

		start_battle(Lines, fight_matrix, projectile_matrix, sun_matrix, round, ok);

		start_next_round = 0;
		conIn.set_x(0); // pentru a nu incepe urmatoarea runda automat dupa ce se termina runda actuala
		conIn.set_y(0);
	}
}

void Handler::game()
{
	int ok_set_plants, ok, action = 0, start_next_round = 0, runs = 0, ok_set_action = 0, round = 1;

	vector<vector<Entities*>> Lines(5, vector<Entities*>(9));
	vector<vector<int>> fight_matrix(5, vector<int>(9));
	vector<vector<int>> projectile_matrix(5, vector<int>(9));
	vector<vector<int>> sun_matrix(2, vector<int>(15));

	srand(time(NULL));

	Menu& M = Menu::getInstance();

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading game...";
	conOut.doLoadingBar();

	Terrain& T = Terrain::getInstance();
	T.print_on_terrain(0, 0);

	show_resources();

	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	while (true)
	{
	start1:

		std::string v = conIn.getUserActions();
		if (v != "") // momentul in care se pun plantele; jocul este intre runde
		{
			gotoXY(1, 21);
			color(15);
			cout << "Runda: " << round << ". ";
			cout << "Sunteti intre runde. Aveti acum posibilitatea de a pune noi plante pe teren.";

			check_if_any_button_is_pressed(conIn, start_next_round, round); // verifica daca s-a apasat butonul Exit sau Next Round
			if (start_next_round == 3)
			{
				break;
			}

			start_game(conIn, Lines, fight_matrix, projectile_matrix, sun_matrix, start_next_round, action, ok_set_action, round, ok_set_plants, ok);

			if (ok_set_plants == 1)
			{
				goto start1;
			}

			if (ok == 0)
			{
				break;
			}
		}
	}

	color(15);
	gotoXY(1, 33);
	cout << "Ati iesit din joc" << endl;

	M.save_infos(round);
}