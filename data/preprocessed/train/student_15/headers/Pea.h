#pragma once
#include "ITickable.h"
#include "IGameElement.h"

namespace Arena
{
	class GameManager;
	class BasicZombie;

	class Pea :
		public ITickable,
		public IGameElement
	{
	protected:
		int gx, gy;
		int cx, cy;
		bool act;

		virtual void tickAction() override;

		virtual void affectZombie(BasicZombie* z);

	public:
		Pea(GameManager* pr, UserInterface::ConsoleOutput conout, int y0, int x0);
		~Pea();

		void update();
		void draw();
		bool active();
	};
}


