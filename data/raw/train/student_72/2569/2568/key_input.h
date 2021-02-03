#pragma once
#include "string"
#include "ConsoleInput.h"
class key_input
{
public:
	UserInterface::ConsoleInput& conIn = UserInterface::ConsoleInput::getInstance();
	std::string key;

	key_input()
	{
		bool searching = true;
		while (searching){
			std::string input = conIn.getUserActions();
			
			if (strstr(input.c_str(), "key: ") != 0)
			{	
				key = input.substr(4, input.size() - 4);
				if (key[1] != 0x14) /////// CAPSLOCK ////////////
				{
					searching = false;
				}
			}
		}
	}
};

