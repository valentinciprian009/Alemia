#pragma once
#include "CLevel.h"
class CLevel_1:public CLevel
{
public:

	static CLevel_1&		 getInstance();
	static void				 destroyInstance();

    int						 planteaza(int &a, int&b);
	 void					 print_scena();
	 void					 game();
	~CLevel_1();
private:
	
	static CLevel_1* Instance;
	CLevel_1();

	
};

