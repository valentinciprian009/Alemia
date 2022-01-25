#include "CProiectil.h"


void CProiectil::goProiectil(BattleField* f,int col, int row)
{

	Jurnal *act = Jurnal::getInstance();
	act->writeJurnal("proiectil coming");

		this->draw(col, row);
		col = col + 10;

}

CProiectil::~CProiectil()
{
}
