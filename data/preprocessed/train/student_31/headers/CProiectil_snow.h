#pragma once
#include "CProiectil.h"
class CProiectil_snow: public CProiectil
{
	int speed_invers_zombie;
	static int speed;

public:
	int			get_damage();
	void		reload();
	void		print_proiectil();
	static int		    get_speed();
	CProiectil_snow(int x, int y);
	CProiectil_snow();
	~CProiectil_snow();
};

