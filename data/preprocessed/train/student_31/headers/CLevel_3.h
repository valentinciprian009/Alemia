#pragma once
#include "CLevel.h"

class CLevel_3:public CLevel
{

private:
	static CLevel_3*Instance;
	CLevel_3();

public:
	void			game();
	void			print_scena();
	int				planteaza(int &a, int &b);
	static			CLevel_3& getInstance();
	static	void	DestroyInstance();
	~CLevel_3();
};

