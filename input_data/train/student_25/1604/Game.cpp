#include "Game.h"
void draw_boxes()
{
	Box box1(3, 0, 9, 2);
	box1.Draw();
	Box box2(0, 3, 2, 12);
	box2.Draw();
	Box box3(3, 3, 9, 12);
	box3.Draw();
	Box box4(0, 0, 2, 2);
	box4.Draw();
	Box box5(0, 13, 2, 17);
	box5.Draw();
}


Game* Game::instance = nullptr;


Game& Game::getInstance()
{
	if (!instance)
	{
		instance = new Game;
		return *instance;
	}
	else
		return *instance;
}

void Game::draw_shop()
{
	conOut(4, 1) << 'S';
	conOut(5, 1) << 'P';
	conOut(6, 1) << 'B';
	conOut(7, 1) << 'F';
	conOut(8, 1) << 'N';
}

void Game::print_money()
{
	conOut(1, 14) << "   ";
	conOut(1, 14) << player->get_money();
}

void Game::deal_action(UserInterface::mouse_event eveniment, char &symbol)
{
	if (!eveniment.Mevent)
	{
		if(eveniment.x<12&&eveniment.x>3&&eveniment.y>3&&eveniment.y<9)
		switch (symbol)
		{
		case 'S':
			if (player->get_money() >= 100) {
				flowers.push_back(std::move(new SunFlower(eveniment.x, eveniment.y)));
				symbol = '\0';
				player->substract_sun(100);
				player->add_sunplants();
			}
			break;
		case 'B':
			if (player->get_money() >= 150) {
				flowers.push_back(std::move(new CherryBomb(eveniment.x, eveniment.y)));
				symbol = '\0';
				player->substract_sun(150);
			}
			break;
		case 'N':
			if (player->get_money() >= 75) {
				flowers.push_back(std::move(new WallNut(eveniment.x, eveniment.y)));
				symbol = '\0';
				player->substract_sun(75);
			}
			break;
		case 'F':
			if (player->get_money() >= 150) {
				flowers.push_back(std::move(new SnowPea(eveniment.x, eveniment.y)));
				symbol = '\0';
				player->substract_sun(150);
			}
			break;
		case 'P':
			if (player->get_money() >= 100) {
				flowers.push_back(std::move(new PeaShooter(eveniment.x, eveniment.y)));
				symbol = '\0';
				player->substract_sun(100);
			}
			break;
		default:
			break;
		}
		if (eveniment.y == 1)
		{
			if (suns[eveniment.x - 4])
			{
				suns[eveniment.x - 4] = false;
				player->add_sun();
			}
		}
	
		if (eveniment.x == 1)
		{
			switch (eveniment.y)
			{
			case 4:
				symbol = 'S';
				break;
			case 5:
				symbol = 'P';
				break;
			case 6:
				symbol = 'B';
				break;
			case 7:
				symbol = 'F';
				break;
			case 8:
				symbol = 'N';
				break;
			}
		}
	}

}

void Game::display_enitites()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = ' ';
		}
	}
	for (auto x : flowers)
	{
		board[x->get_y()-4][x->get_x()-4] = x->get_icon();
	}

	for (auto x : zombies)
	{
		board[x->get_y()-4][x->get_x()-4] = x->get_icon();
	}

	for (auto x : bullets)
	{
		board[x->get_y()-4][x->get_x()-4] = x->get_icon();
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
			conOut(i + 4, j + 4) << board[i][j];
	}
}

void Game :: check_sing_in(string nume, string parola, ifstream &f)
{
	ofstream p("log.txt", ios_base::app);
	bool found=false;
	while (!f.eof())
	{
		string name, pass;
		f >> name >> pass;
		if (name == nume)
		{
			clear_screen();
			conOut(5,5)<< nume << " deja exista in sistem.\n";
			p << nume << " deja exista in sistem.\n";
			logged_in = false;
			found = true;
			break;
		}
	}
	if (!found)
		logged_in = true;
}

void Game::sing_in_screen()
{
	clear_screen();
	conOut(5, 5) << "Please enter your name and press enter twice\n";
	cin >> player_name;
	clear_screen();
	conOut(5, 5) << "Please enter your password and press enter twice\n";
	cin >> player_password;
	ifstream f("name_pass.txt");
	check_sing_in(player_name, player_password, f);
	if (logged_in)
	{
		ofstream p("name_pass.txt", ios_base::app);
		p << player_name << " " << player_password << endl;
	}
}

void Game::check_log_in(string nume, string parola,ifstream &f)
{
	ofstream p("log.txt", ios_base::app);
	bool found = false;
	while (!f.eof())
	{
		string name, pass;
		f >> name >> pass;
		if (name == nume)
		{
			if (pass == parola)
			{
				logged_in = true;
				p << player_name << " logged in successfully.\n";
			}
			else
			{
				p << player_name << " introduced a wrong password";
				logged_in = false;
				clear_screen();
				conOut(5, 5) << "Wrong password!\n" ;
			}
		
			found = true;
			break;
		}
	}
	if (!found)
	{
		p << player_name << " not registered.\n";
		logged_in = false;
	}
}

void Game::log_in_screen()
{
	clear_screen();
	conOut(5, 5) << "Please enter your name and press enter twice\n";
	cin >> player_name;
	clear_screen();
	conOut(5, 5) << "Please enter your password and press enter twice\n";
	cin >> player_password;
	ifstream f("name_pass.txt");
	check_log_in(player_name, player_password,f);

}

void Game::first_interface()
{
	
	conOut(5, 5) << "Type \"c\" if you want to continue an old save and press enter twice";
	conOut(6, 5) << "Type \"n\" if you want to start a new game and press enter twice\n";
	ofstream f("log.txt", ios::app);
	string buff;
	cin>> buff;
	if (buff == "c")
	{
		new_game = false;
		log_in_screen();
	
	}
	else
	{
		if (buff == "n")
		{
			new_game = true;
			sing_in_screen();

		}
		else
		{
			logged_in = false;
			f << "Falied to choose an option.\n";
		}
	}

}

void Game::won()
{
	finished = true;
	system("CLS");
	conOut(5, 5) << "Congratulations! You won!";
}

void Game::lost()
{
	finished = true;
	system("CLS");
	conOut(5, 5) << "Sorry! You lost.";
}

void Game::check_game_end()
{
	if (player->get_score() == 10)
		won();

	for (auto i : zombies)
	{
		if (i->get_x() <= 3)
		{
			lost();
			return;
		}
	
	}
}

void Game::play()
{

	static auto begin = steady_clock::now();
	draw_boxes();
	draw_shop();
	display_enitites();
	print_money();
	add_suns();
	print_suns();
	add_zombies();
	static char entitySelected;
	update_entities();
	display_score();
	check_game_end();

	UserInterface::mouse_event* mouseEvent = conIn.getUserActions();
	if (mouseEvent)
	{
		if (!mouseEvent->Mevent)
		{
			deal_action(*mouseEvent, entitySelected);
		}
	}
}

void Game::print_suns()
{
	for (int i = 0; i < 8; i++)
	{
		if (suns[i])
		{
			conOut(1, 4 + i) << '$';
		}
		else
		{
			conOut(1, 4 + i) << ' ';
		}
	}
}

void Game::add_zombies()
{
	auto now = steady_clock::now();
	
	if ((duration_cast<milliseconds>(now - timp_basic).count()) > (10000 - 1000 * player->get_score()))
	{
		timp_basic = now;
		zombies.push_back(std::move(new BasicZombie(11,rand()%5+4)));
	}
	if ((duration_cast<milliseconds>(now - timp_bucket).count()) > (20000 - 1000 * player->get_score()))
	{
		timp_bucket = now;
		zombies.push_back(std::move(new BucketHeadZombie(11, rand() % 5 + 4)));
	}
}

void Game::add_suns()
{
	int val = player->check_player();
	if (val != -1)
	{
		suns[val] = true;
	}
}

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

void Game::clear_screen()
{
	for (int i = 0; i < 30; i++)
	{
		conOut(i, 0) << "                                                                                                ";
	}
}

void Game::init()
{
	player = &(Player::get_instance());
	first_interface();
	if (!logged_in) finished = true;
	for (int i = 0; i < 8; i++)
	{
		suns[i] = true;
	}
	clear_screen();
	cout << flush;
}

void Game::display_score()
{
	conOut(1, 1) << player->get_score();
}

void Game::update_entities()
{
	for (auto i : flowers)
	{
		i->update(flowers,zombies,bullets,*player);
	}
	for (auto i :zombies)
	{
		i->update(flowers, zombies,bullets,*player);
	}
	for (auto i : bullets)
	{
		i->update(flowers, zombies,bullets,*player);
	}
}


Game::~Game()
{
}
