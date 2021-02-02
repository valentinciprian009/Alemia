#include "CPlayer.h"



void CPlayer::setNume(string nume)
{
	this->nume = nume;
}

void CPlayer::setParola(string pw)
{
	this->parola = pw;
}

string CPlayer::getNume()
{
	return this->nume;
}

string CPlayer::getParola()
{
	return this->parola;
}

CPlayer::CPlayer()
{
	this->maxLevel = 1;
}


CPlayer::~CPlayer()
{
}
