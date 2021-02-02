#pragma once
#include "ConsoleOutput.h"

namespace Arena
{
	class GameManager;

	class IGameElement
	{
	protected:
		GameManager* parent;
		UserInterface::ConsoleOutput conOut;

	public:
		IGameElement(GameManager* pr, UserInterface::ConsoleOutput conout) : parent(pr), conOut(conout) {};

		virtual void draw() = 0;
		virtual void update() = 0;
		virtual bool active() = 0;
	};
}