#include "Player.h"
#include <fstream>

std::ostream& operator<<(std::ostream &out, Player pl)
{
		out << pl.get_nickname()	 <<"\n";
		out << pl.get_max_score()	 <<"\n";
		out << pl.get_max_lvl()		 <<"\n";
		return out;
}

std::istream& operator>>(std::istream &in, Player& pl)
{
	in >> pl.nickname;
	in >> pl.score;
	in >> pl.max_lvl;
	return in;
}

bool operator<(Player& p1, Player& p2)
{
	if (p1.score < p2.score){
		return 1;
	}
	else{
		return 0;
	}
}