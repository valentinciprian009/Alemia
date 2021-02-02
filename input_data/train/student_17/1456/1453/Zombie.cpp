#include "Zombie.h"
#include <chrono>
#include "Log.h"
#include <string>

using namespace std::chrono;

void Zombie::Print(Point &p) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(builtAround.gety(), builtAround.getx()) << "Z";
}

void Zombie::Draw(SegmentedContainer &c4) {
		
		if (stare == "incepator") {//prima data cand apare zombieul se va alege linia rand pe care apare
			stare = "mediocru";
			//n e rand intre 0 si nr repere ver
			//ca sa mi-l puna pe o linie random in joc
			int n = rand() % c4.getnrRepereVer();

			//coltul lui c4
			Point pt1 = c4.getCorner2();
			int x = pt1.getx();
			int y = pt1.gety()+n*5;

			//determin locul in jurul caruia construiesc
			x -= int(15 / 2);
			x--;
			y += int(5 / 2);
			Point p(x, y);
			builtAround = p;

			//printeaza
			this->Print(builtAround);
			//------------------------
			//pt log
			std::string sir = "A aparut un zombie la (";
			sir += std::to_string(builtAround.getx());
			sir += ", ";
			sir += std::to_string(builtAround.gety());
			sir += ")";
			Log::getInstance().print_log(sir.c_str());
		}
		else if (builtAround.getx()>c4.getCorner1().getx()+15) { //cat se afla inca in teren
			this->Delete();
			int x = builtAround.getx() - 15;
			Point temp(x, builtAround.gety());
			builtAround = temp;
			this->Print(builtAround);
			//tot aici pot semnaliza daca a depasit containerul
			//-----------------------------------
			//pt log
			std::string sir = "S-a mutat un zombie la (";
			sir += std::to_string(builtAround.getx());
			sir += ", ";
			sir += std::to_string(builtAround.gety());
			sir += ")";
			Log::getInstance().print_log(sir.c_str());
		}
		else {//nu se mai afla in teren
			this->Delete();
			stare = "castigator";
			//------------------------------
			//pt log
			Log::getInstance().print_log("Un zombie a trecut de limite. Joc pierdut.");
		}
}

void Zombie::Delete() {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(builtAround.gety(), builtAround.getx()) << " ";
}

void BucketHeadZombie::Print(Point &p) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(builtAround.gety(), builtAround.getx()) << "BZ";
}

void BucketHeadZombie::Draw(SegmentedContainer &c4) {

	if (stare == "incepator") {//prima data cand apare zombieul se va alege linia rand pe care apare
		stare = "mediocru";
		//n e rand intre 0 si nr repere ver
		//ca sa mi-l puna pe o linie random in joc
		int n = rand() % c4.getnrRepereVer();

		//coltul lui c4
		Point pt1 = c4.getCorner2();
		int x = pt1.getx();
		int y = pt1.gety() + n * 5;

		//determin locul in jurul caruia construiesc
		x -= int(15 / 2);
		x--; //sa aiba builtAroundul ca plantele si proiectilele care folosesc coltul stgsus nu dreptsus
		y += int(5 / 2);
		Point p(x, y);
		builtAround = p;

		//printeaza
		this->Print(builtAround);
		//------------------------
			//pt log
		std::string sir = "A aparut un bucketheadzombie la (";
		sir += std::to_string(builtAround.getx());
		sir += ", ";
		sir += std::to_string(builtAround.gety());
		sir += ")";
		Log::getInstance().print_log(sir.c_str());
	}
	else if (builtAround.getx() > c4.getCorner1().getx() + 15) { //cat se afla inca in teren
		this->Delete();
		int x = builtAround.getx() - 15;
		Point temp(x, builtAround.gety());
		builtAround = temp;
		this->Print(builtAround);
		//tot aici pot semnaliza daca a depasit containerul
		//-----------------------------------
		//pt log
		std::string sir = "S-a mutat un zombie la (";
		sir += std::to_string(builtAround.getx());
		sir += ", ";
		sir += std::to_string(builtAround.gety());
		sir += ")";
		Log::getInstance().print_log(sir.c_str());
	}
	else {//nu se mai afla in teren
		this->Delete();
		stare = "castigator";
		//------------------------------
		//pt log
		Log::getInstance().print_log("Un bucketheadzombie a trecut de limite. Joc pierdut.");
	}
}

void BucketHeadZombie::Delete() {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(builtAround.gety(), builtAround.getx()) << "  ";
}