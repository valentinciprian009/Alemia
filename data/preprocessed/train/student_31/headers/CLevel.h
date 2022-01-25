#pragma once
#include "CPlants.h"
#include "CPeaShooter.h"
#include "CSunflower.h"
#include "CSnowPea.h";
#include "CChery.h"
#include "CWall_nut.h"

#include "CZombie.h"
#include "BucketHeadZZ.h"
#include "CPoleVaulting.h"

#include <deque>
#include <iostream>

class CLevel
{
protected:

	std::deque <CPeaShooter>  pea_shooter;
	std::deque <CSnowPea> snow_pea_shooter;
	std::deque <CSunflower> sunflowers;
	std::deque <CChery> cherys;
	std::deque <CWall_nut> nuts;
	std::deque <CZombie> zombs;
	std::deque <BucketHeadZZ> bzombs;
	std::deque <CPoleVaulting> pzombs;


	int start_time_zombs;
	int n_zombs;
	int n_buckets;
	int n_vaulting;

	int			scor_jucator;
	int			sun[9];
	int x_origins;
	int y_origins;

	int teren[5][9];
	int n_lines;
	int n_colums;

public:
	virtual int 	planteaza(int &a, int &b);
	void			select_plant(int x, int y);
	int				apartine_interval_planta(int x, int y);

	int				generate_rand();
	void			generate_sun(int x);
	void			colect_sun(int x, int y);

	void			kill_zombs();
	void			kill_plants();
	int 			move_zombs();
	int				move_vaulting();
	void			generate_zombs();

	void			print_sun();
	void			print_plants();

	void			pea_shoot();
	void			snow_pea_shoot();
	void			load_plants();

	int				ruleaza();


	CLevel();
	virtual ~CLevel();
};

