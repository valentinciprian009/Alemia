#pragma once
#include "CPlants.h"
class CSunflower:public CPlants
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
	CSunflower();
	CSunflower(int x, int y);
	~CSunflower();
};

