#pragma once
#include<iostream>
#include"Exception.h"
using namespace std;

class ScoreBoard
{
protected:
	int level, score, sunQuantity;

public:
	ScoreBoard() : level(), score(), sunQuantity() { ; }
	ScoreBoard(const ScoreBoard& scboard) : level(scboard.level), score(scboard.score), sunQuantity(scboard.sunQuantity) { ; }
	ScoreBoard(int lvl, int scr, int sunQty) : level(lvl), score(scr), sunQuantity(sunQty) { ; }
	const int getLevel() const { return level; }
	const int getScore() const { return score; }
	const int getSunQuantity() const { return sunQuantity; }
	virtual void setLevel(int lvl) { level = lvl; }
	virtual void setScore(int scr) { score = scr; }
	virtual void setSunQuantity(int sunQty) { sunQuantity = sunQty; }
	virtual void updateInfo(int sc, int sunQty) { score = sc; sunQuantity = sunQty; }
	virtual void updateSunQuantity(int sunQty) { sunQuantity = sunQty; }
	virtual void nextLevel() { level++; }
	ScoreBoard& operator=(const ScoreBoard& other);
};