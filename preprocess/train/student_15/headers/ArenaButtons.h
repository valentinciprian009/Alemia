#pragma once
#include <string>
#include "Button.h"
#include "Plant.h"

namespace Arena
{
	class ArenaButton :
		public Button
	{
	private:
		void pushFunction();
		int gx, gy;

	public:
		ArenaButton(Slide* pr, int cx, int cy);

		int gridX();
		int gridY();
	};

	class PlantButton :
		public Button,
		public PlantInfo
	{
	private:
		void pushFunction();

	public:
		PlantButton(Slide* pr, PlantInfo pi);
		void draw(UserInterface::ConsoleOutput conOut);

	};

}
