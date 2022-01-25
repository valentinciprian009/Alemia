#pragma once
#include "CLevel.h"
class CLevel_2: public CLevel
{
private:
	static CLevel_2*Instance;
	CLevel_2();

public:
	void		game();
	int			planteaza(int &a, int &b);
	void		print_scena();
	static		CLevel_2& getInstance();
	static void destroyInstance();
	~CLevel_2();
};

