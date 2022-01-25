#pragma once
#include "Drawnable.h"
#include "MoveableObject.h"
#include "Entity.h"
#include "LifeForm.h"
#include <Windows.h>
#include "ConsoleHandler.h"
class Zombie : public Drawnable, public MoveableObject,public LifeForm
{
	std::list<Entity*>& plants;
	int canMove = true;
public:
	int dmg;
	Zombie () = delete;
	Zombie(int x, int y, std::list<Entity*>& aList, int damage, char img, Directions dir,int hp, std::list<Entity*>& plants) : 
		Entity(x, y, aList), Drawnable(x, y, aList,img),MoveableObject(x, y, aList,dir),LifeForm(x, y, aList,hp), plants(plants) {}
	  
	~Zombie(){}


	void update() override
	{
		checkEnd();
		if (canMove)
			MoveableObject::update();
		Drawnable::update();
		LifeForm::update();
		//for (auto i : plants)
		//{
		//	if (i->getX() == getX() + 1)
		//	{
		//		dynamic_cast<LifeForm*>(i)->takedmg(dmg); //// make it work please
		//		canMove = false;
		//		break;
		//	}
		//	else
		//		canMove = true;
		//}
	}
private:
	void dodamage(LifeForm& plant)
	{
		plant.takedmg(dmg);
	}
	void checkEnd()
	{
		if (getX() <= 4)
		{
			system("cls");
			ConsoleHandler& myHandler = ConsoleHandler::getInstance();
			myHandler(30, 30) << "Game Over";
			Sleep(2000);
			exit(0);
		}
	}
};

