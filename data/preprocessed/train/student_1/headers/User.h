#pragma once
#include<fstream>
#include"Scoreboard.h"

class User
{
private:
	string username;
	int maxLevel;
	ScoreBoard score;
public:
	User() : username(), maxLevel(), score() { ; }
	User(const string& username);
	User(const string& usernm, const string& pass, int maxlvl, const ScoreBoard& scr) : username(usernm), maxLevel(maxlvl), score(scr) { ; }
	User(const User& u) : username(u.username), maxLevel(u.maxLevel), score(u.score) { ; }
	User(const string& UserFilename, const string& SaveLocation);
	const string& getUsername() const { return username; }
	const int getMaxLevel() const { return maxLevel; }
	ScoreBoard getScoreBoard() const { return score; }
	void refreshSuns() { score.setSunQuantity(100); }
	void nextLevel(int highScore) { maxLevel++; score.setScore(highScore); refreshSuns(); }
	void setScore(int highScore) { score.setScore(highScore); }
	User& operator=(const User& other);
};