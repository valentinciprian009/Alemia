#pragma once
#include "CZombie.h"
class CPoleVaulting:public CZombie
{
protected:
	static int speed;
	int leap;

public:
	
	int				move();
	 void			reset_leap();
	void			print_zombie(int x, int y);
	static  int		return_speed();
	 int			return_leap();

	CPoleVaulting();
	~CPoleVaulting();
};

