#include "PSunflower.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <windows.h>



void PSunflower::pune_planta()
{
	
		UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
		std::string action = conIn.getUserActions();
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		char  c = char(235);
		if (action.find("double clicked") != std::string::npos)
		{
			std::string x, y;
			for (int i = action.find("(") + 1; i < action.find(","); i++)
				x = x + action;
			for (int i = action.find(",") + 1; i < action.find(")"); i++)
				y = y + action;
			int m_x, m_y;
			m_x = stoi(x);
			m_y = stoi(y);
			if (m_x >= 35 && m_x <= 80 && m_y >= 11 && m_y <= 34)
				conOut(m_x, m_y) << c;
		}

		
		
	
}

PSunflower::PSunflower()
{
	cost = 1;
	nr_max_muscaturi = 2;
}


PSunflower::~PSunflower()
{
}
