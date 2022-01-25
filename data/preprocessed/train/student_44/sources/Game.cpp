#include "Game.h"


void Game::doLoadingBar()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = std::chrono::steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() > 150)
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

void clear() 
{
	for (int i = 250; i >0; --i) {
		std::cout << endl;
	}
}

Game::Point* Game::getXY(string aux)
{
	char *p,*q;
	char *s = new char[aux.size()];
	strcpy(s, aux.c_str());
	int x, y;

	p = strtok(s, " ()");
	q = strtok(NULL, " ()");
	while (p)
	{
		if (p[0] == '(')
		{
			x = stoi(q);
		}
		if(q[0]==')')
			y = stoi(p);

		p = strtok(NULL, " ,");
		q = strtok(NULL, " ,");
	}
	Game::Point *point = new Game::Point(x, y);
	return point;

	delete[] s;
}

void Game::printBar()
{
	auto begin = std::chrono::steady_clock::now();
	auto end = std::chrono::steady_clock::now();
	while (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() < 2)
	{
		end = std::chrono::steady_clock::now();
		doLoadingBar();
	}
	clear();
}

void Game::printLevels()
{
	conOut(ROW_TITLE - 5, COL_FIRST_STAR_POSITION - 5) << name;
	conOut(ROW_TITLE - 3, COL_FIRST_STAR_POSITION - 14) << "Are you afraid?! Select a level!";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION - 30) << "Level 1 \t\t\t Level 2 \t\t\tLevel 3\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

char Game::getMyString(string mys)
{
	
		char *s = new char(mys.size() + 1);
		strcpy(s, mys.c_str());

		char *p = strtok(s, " (\n");
		p = strtok(NULL," (\n");

		char c = char(atoi(p));

		return c;
		delete[]s;
}

void Game::logInBar()
{
	conOut(21, COL_FIRST_STAR_POSITION - 5);
	cout << "username:";
	conOut(22, COL_FIRST_STAR_POSITION);
	cout << "      ------------";
	//cautare in useri
	char aux = ' ';
	int xx = 82;
	int i = 0;
	char nume[10];
	while (true)
	{
		std::string action = conIn.getUserActions();

		if (strstr(action.c_str(), "key ") != 0)
		{
			//implementare backspace
			char aux;
			aux = getMyString(action);
			if (aux == '\b')
			{
				xx--;
				conOut(21, xx) << ' ';
				strcpy(nume + i - 1, nume + i);

			}
			if (aux != '\r' and aux != '\b') {
				conOut(21, xx) << aux;
				nume[i] = aux;
				i++;
				xx += 1;
			}
			if (aux == '\r')
				break;
		}

	}
	nume[i] = '\n';

	Jucator *player = new Jucator(nume);
	jucatori.push_back(player);
}

void Game::youWin()
{
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << " Y O U   W I N ";
}

void Game::gameOver()
{	
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << " G A M E   O V E R ";

}

void Game::drawScene(int n,int m,int level)
{
	Jurnal *act = Jurnal::getInstance();
	act->writeJurnal("draw scene");
	DrawRectangle Score;
	DrawTriangle Plant;
	DrawCircle Sun;
	DrawRectangle Field;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	Score.draw_score(ROW_SCORE, COL_SCORE);
	//draw scene lvl1 lvl2 lvl3
	if (level == 1)
	{
		Jurnal *act = Jurnal::getInstance();
		act->writeJurnal("draw scene lvl1");
		int y = ROW_Plant;
		for (int i = 0; i < 5; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			Plant.draw(y, COL_Plant);
			y = y + 6;
		}

		int x = COL_FIRST_SUN;

		for (int i = 0; i < 8; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			Sun.draw(ROW_SCORE, x);
			x = x + COL_DISTANCE_BETWEEN_SUNS;
		}
		
		int a = ROW_FIELD + 3 + 12;
		int b = COL_FIRST_FIELD;
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				Field.draw(a, b);
				b = b + COL_DISTANCE_BETWEEN_FIELDS;
			}
			a = a + 18;
			b = COL_FIRST_FIELD;
		}
	}
	else if (level == 2)
	{
		DrawRectangle Score;
		DrawTriangle Plant;
		DrawCircle Sun;
		DrawRectangle Field;

		Jurnal *act = Jurnal::getInstance();
		act->writeJurnal("draw scene lvl2");

		int y = ROW_Plant;
		for (int i = 0; i < 5; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			Plant.draw(y, COL_Plant);
			y = y + 6;
		}

		int x = COL_FIRST_SUN;

		for (int i = 0; i < 8; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			Sun.draw(ROW_SCORE, x);
			x = x + COL_DISTANCE_BETWEEN_SUNS;
		}

		int a = ROW_FIELD + 3;
		int b = COL_FIRST_FIELD;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				Field.draw(a, b);
				b = b + COL_DISTANCE_BETWEEN_FIELDS;
			}
			a = a + 6;
			b = COL_FIRST_FIELD;
		}
	}
	else
	{
		DrawRectangle Score;
		DrawTriangle Plant;
		DrawCircle Sun;
		DrawRectangle Field;

		Jurnal *act = Jurnal::getInstance();
		act->writeJurnal("draw scene lvl3");

		int y = ROW_Plant;
		for (int i = 0; i < 5; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			Plant.draw(y, COL_Plant);
			y = y + 6;
		}

		int x = COL_FIRST_SUN;

		for (int i = 0; i < 8; i++)
		{
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			Sun.draw(ROW_SCORE, x);
			x = x + COL_DISTANCE_BETWEEN_SUNS;

		}

		int a = ROW_FIELD + 3;
		int b = COL_FIRST_FIELD;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				Field.draw(a, b);
				b = b + COL_DISTANCE_BETWEEN_FIELDS;
				
			}
			a = a + 6;
			b = COL_FIRST_FIELD;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Game::init_menu()
{ 
	Jurnal *act = Jurnal::getInstance();
	act->writeJurnal("Initializare meniu");

	printBar();
	logInBar();
	clear();
	act->writeJurnal("logare");
	printLevels();

	int xx = 22;
	string aux;
	int i = 0;

	while (true)
	{		
		std::string action = conIn.getUserActions();
		if (strstr(action.c_str(), "double ") != 0)
		{
			aux = action;
			Game::Point *point = getXY(aux);
			int x = point->getX();
			int y = point->getY();
			clear();
			if ((x >= 44 and x <= 51) and (y <= 20 and y >= 19))
			{
				drawScene(2, 9, 1);
				
				init_game(2, 9);
				Jurnal *act = Jurnal::getInstance();
				act->writeJurnal("Initializare lvl1");
			}
			if ((x >= 72 and x <= 80) and (y <= 20 and y >= 19))
			{
				Jurnal *act = Jurnal::getInstance();
				act->writeJurnal("Initializare lvl2");
				drawScene(4, 9, 2);
				init_game(4, 9);
				
			}
			if ((x >= 103 and x <= 110) and (y <= 20 and y >= 19))
			{
				Jurnal *act = Jurnal::getInstance();
				act->writeJurnal("Initializare lvl2");
				drawScene(6, 9, 3);
				init_game(6, 9);
			}
		}
		if (action != "")
		{
			conOut(1, 2) << action;
		}
	}
}

void gettingSun()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	static auto begin = std::chrono::steady_clock::now();
	static int col = COL_FIRST_SUN;
	int row = 5;
	
	DrawableSun sunrise;
	auto end = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() > 2)
	{
		int v1 = rand() % 9;
		begin = end;

		if(v1==0)
			sunrise.draw(row,col);
		if(v1==1)
			sunrise.draw(row, col+ 10);
		if (v1 == 2)
			sunrise.draw(row, col+ 20);
		if (v1 == 3)
			sunrise.draw(row, col+30);
		if (v1 == 4)
			sunrise.draw(row, col + 40);
		if (v1 == 5)
			sunrise.draw(row, col + 50);
		if (v1 == 6)
			sunrise.draw(row, col + 60);
		if (v1 == 7)
			sunrise.draw(row, col + 70);
	}
}

int Game::ZombieComing(int lvl,BattleField &b,int v1)
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	static auto begin = std::chrono::steady_clock::now();
	static int col = COL_FIRST_FIELD+70;
	int row;

	if (lvl == 1) {
		row = 23;
	}

	Jurnal *act = Jurnal::getInstance();
	act->writeJurnal("zombie coming");

	DrawableZombie zombie;
	Field *f = b.getField( col,row+1);
	
	Character *p = NULL;
	
	auto end = std::chrono::steady_clock::now();

	 // pt zombie..ce tip sa vina 
	if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() > 4)
	{

		begin = end;

		if (v1 == 0)
		{
			zombie.draw(row, col); // tip simplu
			p = new Zombie();

		}
		else if (v1 == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			zombie.draw(row, col);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			p = new BucketHead_Zombie();
		

		}
		else if (v1 == 2) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			zombie.draw(row, col);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			p = new PoleVaulting_Zombie();
			
		}
		else if (v1 == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			zombie.draw(row, col);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			p = new Super_Zombie();
			
		}
		
		int x, y;

		p->setY(row);
		p->setX(col);
		
		f->addCharacter(*p);

			y = p->getY();
			x = p->getX();
	
		Sleep(500);
		
		zombie.delete_draw(p->getY(), p->getX());
		col = col - 10;
		delete p;
		if (col == 60)
		{
			return 1;
		}

		p = new Character();
		p->setX(col);
		p->setY(y);
		f->addCharacter(*p);

		return 0;
	}
}

void Game::go_lvl3()
{
	Jurnal *act = Jurnal::getInstance();
	act->writeJurnal("draw scene lvl3");
}
void Game::go_lvl2()
{
	Jurnal *act = Jurnal::getInstance();
	act->writeJurnal("draw scene lvl2");
}
void Game::go_lvl1()
{
	static auto begin = std::chrono::steady_clock::now();

	Jurnal *act = Jurnal::getInstance();
	act->writeJurnal("lvl1");

	string aux;
	int resurse = 0;

	int col = 50;
	int row = 12;

	BattleField *loc = new BattleField(n, m);
	loc_de_joaca = *loc;

	DrawablePlant plants;
	plants.draw(row, col);

	auto end = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() < 10)
	{
		begin = end;
		zombie_mort:
		int v1 = rand() % 4;
		while (true)
		{
		xax:
			gettingSun();
			verify(&loc_de_joaca, n - 1, m);
			
			int x = ZombieComing(1, *loc,v1);
			if (x == 1)
			{
				clear();
				gameOver();
				break;
			}
			if (x == 2)
			{
				goto zombie_mort;
				//daca a murit zombie
			}
			std::string action = conIn.getUserActions();
			if (strstr(action.c_str(), "double ") != 0)
			{
				aux = action;
				Game::Point *point = getXY(aux);
				int x = point->getX();
				int y = point->getY();

				if ((x % 10 == 0) and (y >= 5 and y < 6))
				{
					//colectare SUN
					DrawableSun s;
					s.getSun(y, x);
					resurse += 30;
					conOut(6, 50);
					cout << resurse;
				}
				else
					if (x == 51 and (y >= 12 and y <= 36))
					{
						//adaugare planta
						Character *newCh = NULL;
						Jurnal *act = Jurnal::getInstance();
						act->writeJurnal("cumpar planta");

						std::string action1;
						switch (y)
						{
						case  12:
						{
							newCh = new Peashooter();
						//	CProiectil *p = new CProiectil();
							if (resurse - (*(Peashooter*)newCh).getPrice() < 0)
							{
								conOut(6, 50);
								cout << "!!";
								goto xax;
							}
							resurse = resurse - (*(Peashooter*)newCh).getPrice();
							conOut(6, 50);
							cout << resurse;
						//	p->goProiectil(&loc_de_joaca);
							break;
						}
						case 18:
						{
							newCh = new Sunflower();
							if (resurse - (*(Sunflower*)newCh).getPrice() < 0)
							{
								conOut(6, 50);
								cout << "!!";
								goto xax;
							}
							resurse -= (*(Sunflower*)newCh).getPrice();
							conOut(6, 50);
							cout << resurse;
							break;
						}
						case 24:
						{
							newCh = new Cherry_Bomb();
							if (resurse - (*(Cherry_Bomb*)newCh).getPrice() < 0)
							{
								conOut(6, 50);
								cout << "!!";
								goto xax;
							}
							resurse -= (*(Cherry_Bomb*)newCh).getPrice();
							conOut(6, 50);
							cout << resurse;
							break;
						}
						case 30:
						{
							newCh = new Wall_nut();
							if (resurse - (*(Wall_nut*)newCh).getPrice() < 0)
							{
								conOut(6, 50);
								cout << "!!";
								goto xax;
							}
							resurse -= (*(Wall_nut*)newCh).getPrice();
							conOut(6, 50);
							cout << resurse;
							break;
						}
						case 36:
						{
							newCh = new Snow_Pea();
							if (resurse - (*(Snow_Pea*)newCh).getPrice() < 0)
							{
								conOut(6, 50);
								cout << "!!";
								goto xax;
							}
							resurse -= (*(Snow_Pea*)newCh).getPrice();
							conOut(6, 50);
							cout << resurse;
							break;
						}

						}
						// new Plant depinde de zona unde am dat click si adaugam
						while (1)
						{

							UserInterface::ConsoleInput &conIn1 = UserInterface::ConsoleInput::getInstance();
							action1 = conIn1.getUserActions();
							if (strstr(action1.c_str(), "double ") != 0)
							{
								Jurnal *act = Jurnal::getInstance();
								act->writeJurnal("planta cumparata si plasata");
								//zona unde inseram
								string aux1 = action1;
								Game::Point *point1 = getXY(aux1);
								int x1 = point1->getX();
								int y1 = point1->getY();

								Field *f = loc_de_joaca.getField(x1, y1);
								newCh->setX(x1);
								newCh->setY(y1);
								f->addCharacter(*newCh);
								newCh->draw(x1, y1);

								if (newCh->getType() == PEASHOOTER)

								{
									Character *p = new CProiectil();
									p->setX(x1 + 10);
									p->setY(y1);
									static auto begin = std::chrono::steady_clock::now();
									static int col = newCh->getX() + 10;

									int row;

									Field *fi = loc_de_joaca.getField(x1+10, y1);

									DrawableProiectil proiectil;
									proiectil.draw(p->getY(),p->getX());
								
										auto end = std::chrono::steady_clock::now();
										if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() > 4)
										{
											begin = end;

											fi->addCharacter(*p);
											int aX = p->getX(), aY = p->getY();

											Sleep(30);
											proiectil.deleteDraw(aX, aY);
											aX = aX + 10;
											delete p;
											p = new Character();
										
											p->setX(aX);
											p->setY(aY);

									}
			
								
								}

								goto xax;//revenim
							}
							if (action != "")
							{
								conOut(1, 2) << action;
								conOut(4, 39) << "Score-> ";
								conOut(6, 40) << " Res-> ";
							}
						}
					}
			}
			if (action != "")
			{
				conOut(1, 2) << action;
				conOut(4, 39) << "Score-> ";
				conOut(6, 40) << " Res-> ";
			}
		}
	}

else
	{
	clear();
	gameOver();
 }
}

void Game::init_game(int n, int m)
{
	this->n = n;
	this->m = m;

	switch (n)
	{
	case 2:
		go_lvl1();
		break;

	case 4:
		go_lvl2();
		break;

	case 6:
		go_lvl3();
		break;
	}


}

void Game::verify(BattleField *f,int n,int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			f->returnLoc()[i][j]->getCharacter().actionare(f);
		}
	}
}


void Game::print()
{
}

Game::~Game()
{
}
