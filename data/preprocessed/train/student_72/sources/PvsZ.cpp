#include "PvsZ.h"
#include <fstream>
#include <algorithm>

#define Middle_ROW					20
#define Middle_COL					77
#define ROW_START_PvZ				10
#define ROW_TITLE					30		
#define COL_START_PvZ				37
#define COL_FIRST_STAR_POSITION		65
#define COL_DISTANCE_BETWEEN_STARS	5
#define NICKNAME_MAX_SIZE			15


/////////////////////////////////////////////////////// PRINT THE LOADING STAGE//////////////////////////////////////////////////////////////////////////////////////////////// 

using namespace std::chrono;

bool PvsZ::check_click_box(mouse_input inp, int x1, int x2, int y1, int y2)
{
	if ((inp.x >= x1) && (inp.x <= x2))	{
		if ((inp.y >= y1) && (inp.y <= y2)){
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}

void PvsZ::save_curent_player()
{
	std::vector<Player>::iterator it = Players.begin();
	bool gasit = false;
	for (it ; it != Players.end(); it++){
		if (it->get_nickname() == this->Curent_Player.get_nickname()){
			gasit = true;
			break;
		}
	}

	if (gasit == true){
		if (it->get_max_score() < this->Curent_Player.get_max_score()){
			it->set_score(Curent_Player.get_max_score());
		}
		
		while (it->get_max_lvl() < this->Curent_Player.get_max_lvl()){
			it->next_lvl();
		}
	}
	else{
		this->Players.push_back(Curent_Player);
	}

	std::vector<Player>::iterator it1 = Players.begin();
	for (it1; it1 != Players.end(); it1++) {
		for (int i=0; i != Players.size(); i++) {
			if ((*it1) < Players[i]==0)
			{
				Player aux = (*it1);
				(*it1) = Players[i];
				Players[i] = aux;
			}
		}
	}
}

void PvsZ::save_file()
{
	ofstream out("Players.txt");

	std::vector<Player>::iterator it = Players.begin();
	for (it; it != Players.end(); it++){
		out << (*it);
	}
}

void PvsZ::load_save_file()
{
	ifstream in("Players.txt");

	Player aux;
	while (in){
		in >> aux;
		if (aux.get_nickname() != "default"){
			Players.push_back(aux);
		}
		aux.nickname = "default";
	}
}

void PvsZ::clear()
{
	ifstream in("Players.txt");
	this->Players.clear();
	save_curent_player();
}

void PvsZ::print_Loading()
{
	load_save_file();
	SetConsoleTextAttribute(conOut.handle, FOREGROUND_GREEN);
	conOut(ROW_START_PvZ - 6, COL_START_PvZ) << "PPPPPPPPPPPPPPPPP                                           ZZZZZZZZZZZZZZZZZZZ";
	conOut(ROW_START_PvZ - 5, COL_START_PvZ) << "P::::::::::::::::P                                          Z:::::::::::::::::Z";
	conOut(ROW_START_PvZ - 4, COL_START_PvZ) << "P::::::PPPPPP:::::P                                         Z:::::::::::::::::Z";
	conOut(ROW_START_PvZ - 3, COL_START_PvZ) << "PP:::::P     P:::::P                                        Z:::ZZZZZZZZ:::::Z ";
	conOut(ROW_START_PvZ - 2, COL_START_PvZ) << "  P::::P     P:::::Pvvvvvvv           vvvvvvv  ssssssssss   ZZZZZ     Z:::::Z  ";
	conOut(ROW_START_PvZ - 1, COL_START_PvZ) << "  P::::P     P:::::P v:::::v         v:::::v ss::::::::::s          Z:::::Z    ";
	conOut(ROW_START_PvZ + 0, COL_START_PvZ) << "  P::::PPPPPP:::::P   v:::::v       v:::::vss:::::::::::::s        Z:::::Z     ";
	conOut(ROW_START_PvZ + 1, COL_START_PvZ) << "  P:::::::::::::PP     v:::::v     v:::::v s::::::ssss:::::s      Z:::::Z      ";
	conOut(ROW_START_PvZ + 2, COL_START_PvZ) << "  P::::PPPPPPPPP        v:::::v   v:::::v   s:::::s  ssssss      Z:::::Z       ";
	conOut(ROW_START_PvZ + 3, COL_START_PvZ) << "  P::::P                 v:::::v v:::::v      s::::::s          Z:::::Z        ";
	conOut(ROW_START_PvZ + 4, COL_START_PvZ) << "  P::::P                  v:::::v:::::v          s::::::s      Z:::::Z";
	conOut(ROW_START_PvZ + 5, COL_START_PvZ) << "  P::::P                   v:::::::::v     ssssss   s:::::s ZZZ:::::Z     ZZZZZ";
	conOut(ROW_START_PvZ + 6, COL_START_PvZ) << "PP::::::PP                  v:::::::v      s:::::ssss::::::sZ::::::ZZZZZZZZ:::Z";
	conOut(ROW_START_PvZ + 7, COL_START_PvZ) << "P::::::::P                   v:::::v       s::::::::::::::s Z:::::::::::::::::Z";
	conOut(ROW_START_PvZ + 8, COL_START_PvZ) << "P::::::::P                    v:::v         s:::::::::::ss  Z:::::::::::::::::Z";
	conOut(ROW_START_PvZ + 9, COL_START_PvZ) << "PPPPPPPPPP                     vvv           sssssssssss    ZZZZZZZZZZZZZZZZZZZ";

	SetConsoleTextAttribute(conOut.handle, 7);
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";

	static auto begin = std::chrono::steady_clock::now();
	static auto end = std::chrono::steady_clock::now();
	while (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() < 3)	{	
			end = std::chrono::steady_clock::now();
			doLoadingBar();
			std::string action = conIn.getUserActions();
			if (action != ""){
				conOut(41, 2) << action;
			}
	}
	system("cls");
	conIn.fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

}

void PvsZ::doLoadingBar()
{
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 50){
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*"){
				printedChar = " ";
			}
			else{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
}

void PvsZ::lvl(int nr)
{
	system("CLS");
	SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	Sun_Spawn_Area Sun_Line(30, 10);
	Plant_choosing_area P_C_A(13, 18);
	

	arena LVL(30, 18, nr);

	LVL.print_arena();

	
	mouse_input* inp = new mouse_input(0, 0);
	while (TRUE)
	{
		inp = new mouse_input(0, 0);
		string input = conIn.getUserActions();
		if (strstr(input.c_str(), "CLICKED") != 0) {
			inp = new mouse_input(input);
		}

		Sun_Line.run(*inp, LVL.Sunflower_nr, LVL.score);
		P_C_A.run(*inp, Sun_Line.resources);

		if (LVL.run(*inp, P_C_A.picked) == 0) {}
		else if (LVL.run(*inp, P_C_A.picked) == 1) {
			system("CLS");
			SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			meniu.print_win_lose(true);
			inp = new mouse_input;
			if (Curent_Player.max_lvl == nr) {
				Curent_Player.max_lvl = nr + 1;
			}
			if (Curent_Player.score < LVL.score) {
				Curent_Player.score = LVL.score;
			}
			system("CLS");
			SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			break;
		}

		else if (LVL.run(*inp, P_C_A.picked) == -1) { 
		system("CLS");
		SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		meniu.print_win_lose(false);
		inp = new mouse_input;
		system("CLS");
		SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		break;
		}
	}

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PvsZ::run()
{
	save_curent_player();
	meniu.print_Main_Meniu(Curent_Player);
	
	save_file();

	while (true){
		mouse_input* inp=new mouse_input;

		if (check_click_box(*inp, Middle_COL - 4, Middle_COL + 5, Middle_ROW - 10, Middle_ROW - 8) == true){	//////////////// PLAY //////////////////////
			system("cls");
			SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			meniu.print_levels(Curent_Player);
			while (true){
				mouse_input* inp1 = new mouse_input;
				
				if (check_click_box(*inp1, Middle_COL - 40, Middle_COL - 30, Middle_ROW - 1, Middle_ROW  +1) == true){		//////////////// PLAY-> LVL1 //////////////////////
					lvl(1);
					run();
					break;
				}						
					
				else if (check_click_box(*inp1, Middle_COL - 5, Middle_COL + 5, Middle_ROW - 1, Middle_ROW + 1) == true){		//////////////// PLAY-> LVL2 ///////////////////////
					if (Curent_Player.get_max_lvl() >= 2){		
						lvl(2);
						run();
						break;
					}
				}

				else if (check_click_box(*inp1, Middle_COL + 30, Middle_COL + 40, Middle_ROW - 1, Middle_ROW + 1) == true){		//////////////// PLAY-> LVL3 ///////////////////////
					if (Curent_Player.get_max_lvl() >= 3) {	
						lvl(3);
						run();
						break;
					}
				}
				
				else if (check_click_box(*inp1, 3, 13, 3, 6) == true){			//////////////// BACK //////////////////////
					system("cls");
					SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
						run();
						break;
				}	
			}
			break;
		}
			
		if (check_click_box(*inp, Middle_COL - 4, Middle_COL + 5, Middle_ROW - 6, Middle_ROW-4) == true){	//////////////// BEST //////////////////////		
			system("cls");
			SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			meniu.print_best(Players);

			while (true)
			{
				mouse_input* inp = new mouse_input;
				if (check_click_box(*inp, 3, 13, 3, 6) == true) {																								//////////////// BACK //////////////////////
					system("cls");
					SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
					run();
					break;
				}

				if (check_click_box(*inp, ((2 * Middle_COL) - 13), ((2 * Middle_COL) - 2), ((2 * Middle_ROW) - 5), ((2 * Middle_ROW) - 3)) == true) {			//////////////// CLEAR //////////////////////
					system("cls");
					SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
					clear();
					SetConsoleTextAttribute(conOut.handle, 7);
					meniu.print_best(Players);
					SetConsoleTextAttribute(conOut.handle, 7);
				}
			}
			break;
		}

		if (check_click_box(*inp, Middle_COL - 4, Middle_COL + 5, Middle_ROW - 2, Middle_ROW) == true){		//////////////// EXIT //////////////////////
			system("cls");
			SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			meniu.exit_q();

			while (true){
				delete inp;
				mouse_input* inp = new mouse_input;

				if (check_click_box(*inp, Middle_COL - 15, Middle_COL - 5, Middle_ROW - 4, Middle_ROW - 2) == true){	//////////////// EXIT-> YES //////////////////////
					break;
				}

				if (check_click_box(*inp, Middle_COL + 6, Middle_COL + 16, Middle_ROW - 4, Middle_ROW - 2) == true){	//////////////// EXIT-> NO//////////////////////
					system("cls");
					SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
					run();
					break;
				}	
			}	
			break;
		}			

		int Player_COL_Print_Start = Middle_COL * 2 - Curent_Player.get_nickname().size()-5;
		if (check_click_box(*inp, Player_COL_Print_Start - 12, Player_COL_Print_Start - 2, 3, 5)==true){ ////////////// CHANGE /////////////////////
			system("cls");
			SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			read_player();
			run();
			break;
		}
	}
}

void PvsZ::read_player()
{
	conOut(Middle_ROW ,Middle_COL - 20) << "Please enter player nickname:";
	std::string player_nickname="";
	
	key_input *inp=new key_input;
	int write_begin = Middle_COL + 10;
	int nickname_size = 0;
	while (inp->key[1] != '\r')
	{		
			nickname_size++;
			if (nickname_size == NICKNAME_MAX_SIZE)
			{
				conOut(Middle_ROW+2, Middle_COL - 25) << "Max number of character for nickname reached";

				nickname_size = 0;
				write_begin = Middle_COL + 10;
				conOut(Middle_ROW, write_begin) << "                ";
				write_begin = Middle_COL + 10;

				conOut(Middle_ROW, write_begin);
				player_nickname = "";
				key_input* inp1 = new key_input;
				inp->key = inp1->key;
			}
			if (inp->key[1] == 8)
			{
				nickname_size--;
				write_begin--;
				conOut(Middle_ROW, write_begin) << " ";
				player_nickname = player_nickname.substr(0, player_nickname.size()-1);
				key_input* inp1 = new key_input;
				inp->key = inp1->key;
			}
			else
			{
				player_nickname = player_nickname + inp->key[1];
				inp->key[1];
				conOut(Middle_ROW, write_begin) << inp->key[1];
				write_begin++;

				key_input* inp1 = new key_input;
				inp->key = inp1->key;
			}
	}
	Curent_Player.set_nickname(player_nickname);
	Curent_Player.score = 0;
	Curent_Player.max_lvl = 1;

	std::vector<Player>::iterator it = Players.begin();
	bool gasit = false;
	for (it; it != Players.end(); it++)
	{
		if (it->get_nickname() == this->Curent_Player.get_nickname()) {
			gasit = true;
			break;
		}
	}

	if (gasit == true)
	{
		Curent_Player.score = (*it).score;
		Curent_Player.max_lvl = (*it).max_lvl;
	}

	SetConsoleTextAttribute(conOut.handle, 7);
	system("cls");
	SetConsoleMode(conIn.hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

PvsZ::PvsZ(){}

PvsZ::~PvsZ(){}
