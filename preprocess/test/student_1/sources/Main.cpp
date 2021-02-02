#include"Game.h"
using namespace UserInterface;

void main()
{
	Log::getInstance().open("POO_vs_Zombies.log");
	Log::getInstance().write("POO_vs_Zombies.exe opened.");
	Game& POOvsZombies = Game::getInstance();
	User user("bogdan.log", "Saved Users Progress");
	Level level(user);
	//while (true)
	//{
	//	//level.start();
	//	//if (level.run() == 2)
	//	//	exit(1);
	//}
	POOvsZombies.runGame();
	ConsoleInput::destroyInstance();
	ConsoleOutput::destroyInstance();
	ConsoleEvent::destroyInstance();
}