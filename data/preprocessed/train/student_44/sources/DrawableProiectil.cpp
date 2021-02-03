#include "DrawableProiectil.h"



DrawableProiectil::DrawableProiectil()
{
}

void DrawableProiectil::draw(int row, int col)
{
	conOut(row, col) << "o";
}


DrawableProiectil::~DrawableProiectil()
{
}
