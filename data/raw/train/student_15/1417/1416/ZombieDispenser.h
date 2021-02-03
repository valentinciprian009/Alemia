#pragma once
#include "ITickable.h"
#include "Constants.h"
#include <array>
#include <vector>

namespace Arena
{
	typedef std::array<int, 4> WaveSlice;
	typedef struct {
		int spread;
		std::vector<WaveSlice> slices;
	} Wave;
	typedef struct {
		std::vector<Wave> waves;

	} Level;


	class ZombieDispenser :
		public ITickable
	{
	private:
		GameManager* parent;
		
		virtual void tickAction() override;

		int level;
		int left;

	public:
		ZombieDispenser(GameManager* pr, int lvl);

		void reset(int lvl);

		bool done();
		void update();
	};
}


