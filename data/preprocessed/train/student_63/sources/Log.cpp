#include "Log.h"




Log::Log()
{
}
void Log::user()
{

	std::cout << "				Please enter your name !		"<<std::endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 15,17 });
	getline(std::cin, username);
	username += ".txt";
	f = fopen(username.c_str(), "a");
	if (f == NULL)
	{
		std::cout << "Eroare la deschidere fisier\n";
	}
	get_user_action(username);
	system("cls");
	fclose(f);
}


void Log::get_user_action(std::string string)
{
	time_t time_1;
	struct tm*time_info;
	time(&time_1);
	time_info = localtime(&time_1);
	f = fopen(username.c_str(), "a");
	fputs(string.c_str(), f);
	fprintf(f, "%s", "		");
	fprintf(f, "%s", asctime(time_info));
	fprintf(f, "%s", "\n");
	fclose(f);
}

void Log::exit()
{
	fclose(f);
}

Log::~Log()
{
}
