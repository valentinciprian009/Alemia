#pragma once
#include <string>

class Player
{

public:

	std::string nickname;
	int score;
	int max_lvl;

	Player()
	{
		nickname = "default";
		score = 0;
		max_lvl = 1;
	}

	void score_add(int points){score += points;}

	void next_lvl(){max_lvl++;}

	void set_nickname(std::string new_nick){nickname = new_nick;}

	void set_score(int score_){	score = score_;}

	std::string get_nickname() { return this->nickname;}

	int get_max_lvl(){return this->max_lvl;}

	int get_max_score(){return score;}

	friend std::ostream& operator<<(std::ostream &out, Player pl);
	friend std::istream& operator>>(std::istream &in, Player& pl);
	friend bool operator<(Player& p1, Player& p2);
};



