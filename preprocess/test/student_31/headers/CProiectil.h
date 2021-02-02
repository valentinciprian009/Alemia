#pragma once
class CProiectil
{
protected:

	int x_plant;

    int x;
	int y;
	static int speed;
	int damage;

public:
	virtual int			get_damage();
	int					get_x();
	int					get_y();
	virtual void		reload();
	virtual void		print_proiectil();
	void				set_coord(int x, int y);
	static  int			get_speed();

	CProiectil();
	~CProiectil();
};

