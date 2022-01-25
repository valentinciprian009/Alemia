#include "Resurse.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <windows.h>


Resurse::Resurse()
{
	for (int i = 0; i <= 8; i++)
		vect[i] = 0;
}


Resurse::~Resurse()
{
}

void Resurse::creeaza_resurse()
{
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		char  c = char(233);
		int iSecret;
		iSecret = rand() % 91 + 30;
		if (iSecret >= 30 && iSecret < 40)
		{
			conOut(7, 38) << c;
			vect[0] = 1;
		}
		else
			if (iSecret >= 40 && iSecret < 50)
			{
				conOut(7, 48) << c;
				vect[1] = 1;
			}
			else
				if (iSecret >= 50 && iSecret < 60)
				{
					conOut(7, 58) << c;
					vect[2] = 1;
				}
				else
					if (iSecret >= 60 && iSecret < 70)
					{
						conOut(7, 68) << c;
						vect[3] = 1;
					}

					else
						if (iSecret >= 70 && iSecret < 80)
						{
							conOut(7, 78) << c;
							vect[4] = 1;
						}
						else
							if (iSecret >= 80 && iSecret < 90)
							{
								conOut(7, 88) << c;
								vect[5] = 1;
							}
							else
								if (iSecret >= 90 && iSecret < 100)
								{
									conOut(7, 98) << c;
									vect[6] = 1;
								}
								else
									if (iSecret >= 100 && iSecret < 110)
									{
										conOut(7, 108) << c;
										vect[7] = 1;
									}
									else
										if (iSecret >= 110 && iSecret < 120)
										{
											conOut(7, 118) << c;
											vect[8] = 1;
										}
}

void Resurse::numara_resurse()
{
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	std::string action = conIn.getUserActions();
}
	
