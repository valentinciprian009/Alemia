#include "Resource.h"
#include <chrono>
#include "Log.h"
#include <string>
using namespace std::chrono;

void Sun::Draw(SegmentedContainer &c2) {

	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	static int ok = 1;

	if (duration_cast<milliseconds>(end - begin).count() > refreshRate){   
		//voi alterna intre cele doua stari la fiecare 4000mili
		//adica o perioada e printat, o perioada nu
		begin = end;
		if (ok == 1) {
			ok = 0;
			//n e rand intre 0 si nr repere horiz
			//asta e ca sa puna soarele intr-un patratel random
			int n = rand() % c2.getnrRepereOriz();

			//coltul lui c2+n*distx 
			Point pt1 = c2.getCorner1();
			int x = pt1.getx() + n * 15;
			int y = pt1.gety();

			//determin locul in jurul caruia construiesc
			x += int(15 / 2);
			y += int(5 / 2);
			Point p(x, y);
			builtAround = p;

			//printeaza
			this->Print(builtAround);
			//---------------------------
			//pt log
			std::string sir = "A aparut un soare la (";
			sir += std::to_string(builtAround.getx());
			sir += ", ";
			sir += std::to_string(builtAround.gety());
			sir += ")";
			Log::getInstance().print_log(sir.c_str());
		}
		else {
			this->Delete();
			ok = 1;
		}	
	}
}

void Sun::Print(Point &pt) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(builtAround.gety(), builtAround.getx()) << "S";
}

void Sun::Delete() {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(builtAround.gety(), builtAround.getx()) << " ";
}