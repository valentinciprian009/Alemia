#pragma once
#include "CProiectil.h"
#include "CPlants.h"
class CPeaShooter: public CPlants
{
protected:
	CProiectil p;

	static int disponoibil;
	static int timp_crestere;


public:

	
	virtual void		delete_planta(int x, int y);

	virtual void		afiseaza_planta(int x, int y);
	virtual void		shoot();
	virtual int		    get_proiectil_speed();
	virtual void		get_proiectil_coord(int &a, int &b);
	virtual int			get_damage();
	virtual void		reload();
   
	static int		return_disponibil();
	static void		set_indisponibil();
	static void		set_disponibil();

	CPeaShooter();
	CPeaShooter(int x, int y);
	~CPeaShooter();
};

