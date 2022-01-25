#pragma once
class CZombie
{
protected:
	int health;

	int speed;

	int x_coordz;
	int y_coordz;
	int free;

public:
	void				set_free();
	void				reset_free();
	int					return_free();
	void				stay();
	void				go();
	virtual void		print_zombie(int x, int y);
	void				delete_zobie(int x, int y);
	int					minus_life(int val_minus);
	int					get_health();
	int					get_speed();

	int x_z();
	int y_z();


	virtual int			move();
	CZombie();
	~CZombie();
};

