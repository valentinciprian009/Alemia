#include "Meniu.h"
#include <iostream>


#define Middle_ROW		20
#define Middle_COL		77

#define First_BOX_ROW  15
#define First_BOX_COL  30
using namespace std;

void Meniu::print_Main_Meniu(Player player_nickname)
{
	int Player_COL_Print_Start = Middle_COL * 2 - player_nickname.get_nickname().size()-5;
	conOut(3, Player_COL_Print_Start) << player_nickname.get_nickname();
	conOut(4, Player_COL_Print_Start) << "score:";  conOut(4, Player_COL_Print_Start+7) << player_nickname.get_max_score();
	conOut(5, Player_COL_Print_Start) << "LVL:"; conOut(5, Player_COL_Print_Start+5) << player_nickname.get_max_lvl();

	SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN | FOREGROUND_GREEN);
	conOut(3, Player_COL_Print_Start-12)	<< "----------";
	conOut(4, Player_COL_Print_Start-12)	<< "----------";
	conOut(5, Player_COL_Print_Start-12)	<< "----------";

	conOut(Middle_ROW - 10, Middle_COL - 4) << "----------";
	conOut(Middle_ROW - 9, Middle_COL - 4)	<< "----------";
	conOut(Middle_ROW - 8, Middle_COL - 4)	<< "----------";

	conOut(Middle_ROW - 6, Middle_COL - 4) << "----------";
	conOut(Middle_ROW - 5, Middle_COL - 4) << "----------";
	conOut(Middle_ROW - 4, Middle_COL - 4) << "----------";

	conOut(Middle_ROW - 2, Middle_COL - 4) << "----------";
	conOut(Middle_ROW - 1, Middle_COL - 4) << "----------";
	conOut(Middle_ROW	, Middle_COL - 4)  << "----------";

	SetConsoleTextAttribute(conOut.handle, 7);
	SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN);
	conOut(4, Player_COL_Print_Start - 10) << "CHANGE";
	conOut(Middle_ROW - 9, Middle_COL - 1) << "PLAY";
	conOut(Middle_ROW - 5, Middle_COL - 1) << "BEST";
	conOut(Middle_ROW - 1, Middle_COL - 1) << "EXIT";
	
	SetConsoleTextAttribute(conOut.handle, 7);
}

void Meniu::exit_q()
{
	conOut(Middle_ROW - 6, Middle_COL - 15) << "Are you sure you want to exit ?";

	SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN | FOREGROUND_GREEN);
	conOut(Middle_ROW - 4, Middle_COL - 15)		<< "----------";
	conOut(Middle_ROW - 3, Middle_COL - 15)		<< "----------";
	conOut(Middle_ROW - 2, Middle_COL - 15)		<< "----------";

	SetConsoleTextAttribute(conOut.handle, BACKGROUND_RED | FOREGROUND_RED);
	conOut(Middle_ROW - 4, Middle_COL + 6)		<< "----------";
	conOut(Middle_ROW - 3, Middle_COL + 6)		<< "----------";
	conOut(Middle_ROW - 2, Middle_COL + 6)		<< "----------";

	SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN);
	conOut(Middle_ROW - 3, Middle_COL - 12) << "YES";
	SetConsoleTextAttribute(conOut.handle, BACKGROUND_RED);
	conOut(Middle_ROW - 3, Middle_COL + 10) << "NO";

	SetConsoleTextAttribute(conOut.handle, 7);
}

void Meniu::print_levels(Player player_curent)
{
	SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN | FOREGROUND_GREEN);
	conOut(Middle_ROW - 1, Middle_COL - 40)	<<"----------";
	conOut(Middle_ROW, Middle_COL -40)		<<"----------";
	conOut(Middle_ROW + 1, Middle_COL - 40)	<<"----------";
	SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN);
	conOut(Middle_ROW, Middle_COL - 38) << "LVL 1";

	if(player_curent.get_max_lvl()<=1){	SetConsoleTextAttribute(conOut.handle, BACKGROUND_RED | FOREGROUND_RED);}
	else	{							SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN | FOREGROUND_GREEN);}

	conOut(Middle_ROW - 1, Middle_COL - 5)	<<"----------";
	conOut(Middle_ROW, Middle_COL - 5)		<<"----------";
	conOut(Middle_ROW + 1, Middle_COL - 5)	<<"----------";

	if (player_curent.get_max_lvl() <= 1) {	SetConsoleTextAttribute(conOut.handle, BACKGROUND_RED);}
	else {									SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN);}
	conOut(Middle_ROW, Middle_COL - 3) << "LVL 2";

	if (player_curent.get_max_lvl() <= 2) {	SetConsoleTextAttribute(conOut.handle, BACKGROUND_RED | FOREGROUND_RED);}
	else {									SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN | FOREGROUND_GREEN);}

	conOut(Middle_ROW - 1, Middle_COL + 30) << "----------";
	conOut(Middle_ROW, Middle_COL + 30)		<< "----------";
	conOut(Middle_ROW + 1, Middle_COL + 30) << "----------";

	if (player_curent.get_max_lvl() <= 2) {	SetConsoleTextAttribute(conOut.handle, BACKGROUND_RED);}
	else {									SetConsoleTextAttribute(conOut.handle, BACKGROUND_GREEN);}
	conOut(Middle_ROW, Middle_COL + 32) << "LVL 3 ";

	SetConsoleTextAttribute(conOut.handle, 119);
	conOut(	3,	3 )	<< "----------";
	conOut(	4,	3 )	<< "----------";
	conOut(	5,	3)	<< "----------";
	SetConsoleTextAttribute(conOut.handle, 112);
	conOut(4, 6) << "BACK";
	SetConsoleTextAttribute(conOut.handle, 7);
}

void Meniu::print_best(std::vector<Player> players)
{
	SetConsoleTextAttribute(conOut.handle, FOREGROUND_GREEN);
	
	conOut(6, Middle_COL - 54) << "_/        _/_/_/_/    _/_/    _/_/_/    _/_/_/_/  _/_/_/    _/_/_/      _/_/      _/_/    _/_/_/    _/_/_/ ";
	conOut(7, Middle_COL - 54) << "_/        _/        _/    _/  _/    _/  _/        _/    _/  _/    _/  _/    _/  _/    _/  _/    _/  _/    _/";
	conOut(8, Middle_COL - 54) << "_/        _/_/_/    _/_/_/_/  _/    _/  _/_/_/    _/_/_/    _/_/_/    _/    _/  _/_/_/_/  _/_/_/    _/    _/";
	conOut(9, Middle_COL - 54) << "_/        _/        _/    _/  _/    _/  _/        _/    _/  _/    _/  _/    _/  _/    _/  _/    _/  _/    _/ ";
	conOut(10, Middle_COL - 54)<< "_/_/_/_/  _/_/_/_/  _/    _/  _/_/_/    _/_/_/_/  _/    _/  _/_/_/      _/_/    _/    _/  _/    _/  _/_/_/   ";

	SetConsoleTextAttribute(conOut.handle, 119);
	conOut(3, 3) << "----------";
	conOut(4, 3) << "----------";
	conOut(5, 3) << "----------";
	SetConsoleTextAttribute(conOut.handle, 112);
	conOut(4, 6) << "BACK";

	SetConsoleTextAttribute(conOut.handle, BACKGROUND_RED|FOREGROUND_RED);
	conOut(Middle_ROW + Middle_ROW -3, Middle_COL+ Middle_COL -13)		<< "-----------";
	conOut(Middle_ROW + Middle_ROW -4, Middle_COL + Middle_COL -13)		<< "-----------";
	conOut(Middle_ROW + Middle_ROW -5, Middle_COL + Middle_COL -13)		<< "-----------";
	SetConsoleTextAttribute(conOut.handle, BACKGROUND_RED);
	conOut(Middle_ROW + Middle_ROW - 4, Middle_COL + Middle_COL - 10) << "CLEAR";

	SetConsoleTextAttribute(conOut.handle, 7);

	std::vector<Player>::iterator it = players.begin();

	int i=0;
	int x = First_BOX_COL;
	int y = First_BOX_ROW;
	for (it; it != players.end(); it++){
		i++;
		conOut(y, x) << i;
		printf(":\t");
		printf("%s" , players[i - 1].nickname.c_str());
		printf("\t");
		printf("%d", players[i - 1].score);
		y += 2;
		if (i % 10==0){
			x = x + First_BOX_COL;
			y = First_BOX_ROW;
		}
	}

	SetConsoleTextAttribute(conOut.handle, 102);
	conOut(First_BOX_ROW, First_BOX_COL - 2) << " ";

	if (players.size() > +2) {
		SetConsoleTextAttribute(conOut.handle, 119);
		conOut(First_BOX_ROW + 2, First_BOX_COL - 2) << " ";
	}
	if (players.size() > +3) {
		SetConsoleTextAttribute(conOut.handle, 68);
		conOut(First_BOX_ROW + 4, First_BOX_COL - 2) << " ";
	}
	SetConsoleTextAttribute(conOut.handle, 7);
}

void Meniu::print_win_lose(bool win)
{
	if (win == true) {
		SetConsoleTextAttribute(conOut.handle, FOREGROUND_GREEN);
		conOut(9, Middle_COL - 12) <<  " _     _  ___   __    _ ";
		conOut(10, Middle_COL - 12) <<  "| | _ | ||   | |  |  | | ";
		conOut(11, Middle_COL - 12) <<  "| || || ||   | |   |_| |";
		conOut(12, Middle_COL - 12) <<  "|       ||   | |       |";
		conOut(13, Middle_COL - 12) <<  "|       ||   | |  _    |";
		conOut(14, Middle_COL - 12) <<  "|   _   ||   | | | |   |";
		conOut(15, Middle_COL - 12) << "|__| |__||___| |_|  |__|";
		SetConsoleTextAttribute(conOut.handle, 7);
	}
	else {
		SetConsoleTextAttribute(conOut.handle, FOREGROUND_RED);
		conOut(9, Middle_COL - 19) <<  "  ___      _______  _______  _______ ";
		conOut(10, Middle_COL - 19) << " |   |    |       ||       ||       |";
		conOut(11, Middle_COL - 19) << " |   |    |   _   ||  _____||    ___|";
		conOut(12, Middle_COL - 19) << " |   |    |  | |  || |_____ |   |___ ";
		conOut(13, Middle_COL - 19) << " |   |___ |  |_|  ||_____  ||    ___|";
		conOut(14, Middle_COL - 19) << " |       ||       | _____| ||   |___ ";
		conOut(15, Middle_COL - 19) << " |_______||_______||_______||_______|";
		SetConsoleTextAttribute(conOut.handle, 7);
	}
}

Meniu::Meniu(){}

Meniu::~Meniu(){}