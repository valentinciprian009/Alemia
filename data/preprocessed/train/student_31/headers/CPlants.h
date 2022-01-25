#pragma once
class CPlants

{
protected:
	int cost;
	int n_muscaturi;
	
	int x_coord;
	int y_coord;

public:
	static int		return_disponibil();
	static void		set_indisponibil();
	static void		set_disponibil();

	virtual void		delete_planta(int x, int y);
	virtual int			get_x_plant();
	virtual int			get_y_plant();

	virtual int 		hurt();

	void				get_coord();
	virtual void		afiseaza_planta(int x, int y);
	int					get_cost();
	CPlants();
	~CPlants();
};

