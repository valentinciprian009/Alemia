#include "Proiectil.h"
#include <chrono>
#include "Log.h"
#include <string>

using namespace std::chrono;

void Pea::Print(Point &p) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(p.gety(), p.getx()) << "o";
}

void Pea::Delete(Point &p) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(p.gety(), p.getx()) << " ";
}

void Pea::Draw(SegmentedContainer &c4) {
	
		if (lastProiectilPosition.getx() < c4.getCorner2().getx() - 15 / 2-1) {//sa nu fie iesit din chenar
			
			if (firstLaunch == 1) {
				Point temp(lastProiectilPosition.getx() + 15, lastProiectilPosition.gety());
				lastProiectilPosition = temp;
				Print(lastProiectilPosition);
				firstLaunch = 0;
			
				//-----------------------------------
				//pt log
				std::string sir = "A aparut un proiectil la (";
				sir += std::to_string(lastProiectilPosition.getx());
				sir += ", ";
				sir += std::to_string(lastProiectilPosition.gety());
				sir += ")";
				Log::getInstance().print_log(sir.c_str());
			}
			else {
				Delete(lastProiectilPosition);
				Point temp(lastProiectilPosition.getx() + 15, lastProiectilPosition.gety());
				lastProiectilPosition = temp;
				Print(lastProiectilPosition);
				//-----------------------------------
				//pt log
				std::string sir = "S-a mutat un proiectil la (";
				sir += std::to_string(lastProiectilPosition.getx());
				sir += ", ";
				sir += std::to_string(lastProiectilPosition.gety());
				sir += ")";
				Log::getInstance().print_log(sir.c_str());
			}
		}
		else {
			Delete(lastProiectilPosition);
			lastProiectilPosition = builtAround;
			firstLaunch = 1;
		}
}