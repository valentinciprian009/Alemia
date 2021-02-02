#pragma once
#include "ConsoleOutput.h"
#include <array>
#include "ITickable.h"
#include "ITimer.h"
#include "IGameElement.h"
#include "Constants.h"
#include "ZombieInfo.h"

namespace Arena
{
	class GameManager;
	class SlownessEffect;

	class BasicZombie :
		public ITickable,
		public IGameElement
	{
	public:
		static const std::array<ZombieInfo, 4> zombies;

	protected:
		int gy;
		float gx;
		int cx, cy;
		int hp;
		int id;
		SlownessEffect* eff;

	protected:
		virtual void tickAction() override;
	public:
		BasicZombie(GameManager* pr, UserInterface::ConsoleOutput conout, int y, int id);
		void startMoving();
		~BasicZombie();

		void update();
		void draw();
		bool active();

		bool insideCell(int x);

		void damage(int d);

		void slowDown();

		friend class Pea;
		friend class SlownessEffect;
	};

	class SlownessEffect
		: public ITimer
	{
	private:
		BasicZombie* parent;

	protected:
		virtual void timerAction() override;

	public:
		SlownessEffect(BasicZombie* pr)
			: ITimer(3000, false)
		{
			parent = pr;
			
		}
		
		void apply();
	};
}

