#pragma once
#include "ConsoleInput.h"
#include <iostream>
#include <string>

using namespace std;
class mouse_input
{
	public:
		UserInterface::ConsoleInput& conIn = UserInterface::ConsoleInput::getInstance();
		
		std::string action;
		int x ;
		int y;
		
		
		mouse_input()
		{
			x = 0;
			y = 0;
			while (TRUE)
			{	
				std::string input = conIn.getUserActions();
				if (strstr(input.c_str(), "CLICKED") != 0)
				{

					int pos = input.find(' ');
					input.erase(0, pos+1);
					pos = input.find(' ');

					x = stoi(input.substr(0, pos+1));
					input.erase(0, pos+1);

					 pos = input.find(' ');
					y = stoi(input.substr(0, pos));
					break;
				}
			}
		}

		mouse_input(std::string input)
		{
			int pos = input.find(' ');
			input.erase(0, pos + 1);
			pos = input.find(' ');

			x = stoi(input.substr(0, pos + 1));
			input.erase(0, pos + 1);

			pos = input.find(' ');
			y = stoi(input.substr(0, pos));
		}

		mouse_input(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
};