#pragma once
#include "CPlants.h"
class CWall_nut:public CPlants
{
private:
	static int disponoibil;
	static int timp_crestere;
public:


	void		afiseaza_planta(int x, int y);
	void		delete_planta(int x, int y);

	static int		return_disponibil();
	static void		set_indisponibil();
	static void		set_disponibil();
	CWall_nut(int x, int y);
	CWall_nut();
	~CWall_nut();
};

