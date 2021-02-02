#pragma once
#include "CPlants.h"
class CChery:public CPlants
{
private:
	static int disponoibil;
	static int timp_crestere;
public:

	void afiseaza_planta(int x, int y);
	void delete_planta(int x, int y);

	static int		return_disponibil();
	static void		set_indisponibil();
	static void		set_disponibil();
	CChery();
	CChery(int x, int y);
	~CChery();
};

