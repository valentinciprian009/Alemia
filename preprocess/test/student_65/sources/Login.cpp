#include "Login.h"

void Login::draw()
{
	UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
	c(20, 85) << "Welcome:";
	c(22, 78) << "Username:";
	c(23, 78) << "Password:";
}
bool Login::return_tasting(string input )
{
	UserInterface::ConsoleOutput c = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput i = UserInterface::ConsoleInput::getInstance();
	static string user_input;
	static string password_input,pass_hide;
	static bool user_done = 0;
	static bool pass_done = 0;
	if(!user_done)
	if (input.find("Mouse") == string::npos)
	{
		if (input[0] == 13)
			user_done = 1;
		if (input[0] == 8 && user_input.size() > 1)
			user_input.pop_back();
		
		else
			if (input.size() > 0 && isalnum(input[0]))
				user_input += input;
		
	}
	c(22, 85) << user_input;
	if (!pass_done&&user_done)
		if (input.find("Mouse") == string::npos)
		{
			if (input[0] == 13&&password_input.size()>2)
				pass_done = 1;
			if (input[0] == 8 && password_input.size() > 1)
			{
				password_input.pop_back();
				pass_hide.pop_back();
			}
			else
			{
				if (input.size() > 0&&isalnum(input[0]))
				{
					password_input += input;
					pass_hide += "*";
				}
			}

		}
	c(23, 85) << pass_hide;
	if (user_done && pass_done)
	{
		set_player(user_input, password_input);
		return 1;
	}
	else
		return 0;
}

void Login::set_player(string nume, string pass)
{
	new_player = new Player(nume, pass);
}

Player* Login::get_player()
{
	return new_player;
}
