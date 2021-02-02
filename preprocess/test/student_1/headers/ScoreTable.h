#pragma once
#include"Entity.h"
#include"Scoreboard.h"

class ScoreTable : public Entity, public ScoreBoard
{
private:
	string username;
public:
	ScoreTable() : Entity(), ScoreBoard(), username() { ; }
	ScoreTable(int row_ul, int col_ul) : Entity(row_ul, col_ul), ScoreBoard(), username() { ; }
	ScoreTable(int row_ul, int col_ul, int lvl, int scr, int sunQty, const string& usernm) : Entity(row_ul, col_ul), ScoreBoard(lvl, scr, sunQty), username(usernm) { ; }
	void setUsername(const string& usernm) { username = usernm; }
	void updateInfo(int sc, int sunQty);
	void updateSunQuantity(int sunQty);
	void print();
};