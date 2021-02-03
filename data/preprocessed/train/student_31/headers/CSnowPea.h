#pragma once
#include "CPeaShooter.h"
#include "CProiectil_snow.h"
class CSnowPea: public CPeaShooter
{

protected:
	CProiectil_snow p_snow;

	static int disponoibil;
	static int timp_crestere;

public:
	virtual int get_damage();

	void		delete_planta(int x, int y);
	int			get_proiectil_speed();
	void		afiseaza_planta(int x, int y);
	void		shoot();
	void		get_proiectil_coord(int &a, int &b);
	void		reload();

	static int		return_disponibil();
	static void		set_indisponibil();
	static void		set_disponibil();

	CSnowPea(int x, int y);
	CSnowPea();
	~CSnowPea();
};

