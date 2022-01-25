#pragma once
#include "ConsoleOutput.h"
#include "Constants.h"
#include "ITickable.h"
#include <string>

namespace Arena
{
	class ResourceManager :
		public ITickable
	{

	private:
		bool active[15];
		int rate = SUNRATE0; // 1 + no_sunflowers = no_suns / 10second
		UserInterface::ConsoleOutput conOut;

	private:
		static ResourceManager* instance;
		ResourceManager();

	public:
		static ResourceManager* getInstance();
		void addToRate(int i);
		
		void click(std::string s, int& sunCount, UserInterface::ConsoleOutput conOut);
		void update(UserInterface::ConsoleOutput conOut);

		void reset(int& sunCount);

		virtual void tickAction() override;
	};
}

