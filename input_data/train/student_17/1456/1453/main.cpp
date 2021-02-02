#define _CRT_SECURE_NO_WARNINGS

#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "SegmentedContainer.h"
#include "Resource.h"
#include "Plant.h"
#include "Zombie.h"
#include "Proiectil.h"
#include "Log.h"
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;

void getUserInfo(char* username, char* password) {
	
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Username: ";
	std::cin >> username;

	conOut(ROW_TITLE+1, COL_FIRST_STAR_POSITION) << "Password: ";
	std::cin >> password;

	system("cls");
}

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
}

void doLoadingScreen(UserInterface::ConsoleOutput &conOut, int level) {

	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading level "<<level<<"...";//pune cursorul si scrie loading
	time_t start = time(NULL);
	time_t now = time(NULL);
	while ((now - start) <= 3) {
		doLoadingBar();//modifica cursorul si pune spatii sau stelute
		now = time(NULL);
	}
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "                        ";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION) << " ";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 1 * COL_DISTANCE_BETWEEN_STARS) << " ";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 2 * COL_DISTANCE_BETWEEN_STARS) << " ";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 3 * COL_DISTANCE_BETWEEN_STARS) << " ";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) << " ";
}

void doGraphics(Container* &c1, SegmentedContainer* &c2, SegmentedContainer* &c3, SegmentedContainer* &c4, UserInterface::ConsoleOutput &conOut, int level) {
	
	//asta e o versiune mai flexibila a ceea ce foloseam dinainte din ContainerNamespace.h
	//totul se invarte in jurul pctului de inceput
	//si apoi al setului de 4 pct al primului container
	//si apoi in jurul primului pct din ficare container
	//deci daca vreau sa dau tot afisajul mai incolo, nu mi se incurca

	Point p1(10, 5); //blanaaa, se muta :)
	Point p2(p1.getx()+14, p1.gety()+0);
	Point p3(p1.getx()+0, p1.gety()+4);
	Point p4(p1.getx()+14, p1.gety()+4);

	c1 = new Container(p1, p2, p3, p4);

	Point r1, r2, r3, r4;
	
	r1(p2.getx() + 1, p2.gety()+0);
	r2(r1.getx() + 9 * 15, r1.gety() + 0);
	r3(r1.getx() + 0, r1.gety() + 4);
	r4(r1.getx() + 9 * 15, r1.gety() + 4);

	c2 = new SegmentedContainer(r1, r2, r3, r4);
	
	r1(p3.getx()+0, p3.gety() + 1);
	r2(r1.getx() + 14, r1.gety()+0);
	r3(r1.getx() + 0, r1.gety() + 5*5);
	r4(r1.getx() + 14, r1.gety() + 5 * 5);

	c3 = new SegmentedContainer(r1, r2, r3, r4);
	
	int n = 1;

	if (level == 2)
		n = 3;
	else
		if (level == 3)
			n = 5;

	r1(p4.getx() + 1, p4.gety() + 1);
	r2(r1.getx() + 9 * 15, r1.gety() + 0);
	r3(r1.getx() + 0, r1.gety() +  n * 5);
	r4(r1.getx() + 9*15, r1.gety() + n * 5);

	c4 = new SegmentedContainer(r1, r2, r3, r4);

	//am facut chenarele
	c1->doMargin(conOut);
	c2->doMargin(conOut);
	c3->doMargin(conOut);
	c4->doMargin(conOut);

	//fac segmentarile
	c2->doCols(conOut, 15);
	c3->doRows(conOut, 5);
	c4->doCols(conOut, 15);
	c4->doRows(conOut, 5);

}

bool checkDoubleClick(std::string action, Point& position) {

	auto searchForDouble = [](char* string) {
		if (strstr(string, "double"))
			return 1;
		else
			return 0;
	};

	char buffer[250];
	strcpy(buffer, action.c_str());
	if (searchForDouble(buffer)) {
		char* p = strtok(buffer, "(,)");
		p = strtok(NULL, "(,)");
		int x = atoi(p);
		p = strtok(NULL, "(,)");
		int y = atoi(p);
		Point pt(x, y);
		position = pt;
		return true;
	}
	return false;
}

Point& checkPointContainer(Point &pt, SegmentedContainer& c2, SegmentedContainer& c3, SegmentedContainer& c4) {

	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	int x = pt.getx();
	int y = pt.gety();
	int c2x = c2.getCorner1().getx();
	int c2y = c2.getCorner1().gety();
	int c3x = c3.getCorner1().getx();
	int c3y = c3.getCorner1().gety();
	int c4x = c4.getCorner1().getx();
	int c4y = c4.getCorner1().gety();

	//daca se afla in containerul 2
	if (x > c2x && x<c2x + c2.getnrRepereOriz()*15 && y>c2y&&y < c2y + 5) {
		Point p;
		for (int i = 0; i < c2.getnrRepereOriz(); i++) {
			if (x >= c2x + i * 15 && x < c2x + (i + 1) * 15) {
				Point rand(c2x + i * 15, c2y);
				p = rand;
				break;
			}
		}
		return p;
		
	}
		
	//daca se afla in containerul 3
	else if (x > c3x && x<c3x + 15 && y>c3y && y < c3y + c3.getnrRepereVer()*5) {
		Point p;
		for (int i = 0; i < 2; i++) { //c3.getnrRepereVer(), am deocamdata doar 2 plante => 2 repere
			if (y >= c3y + i * 5 && y < c3y + (i + 1) * 5) {
				Point rand(c3x, c3y + i * 5);
				p = rand;
				break;
			}
		}
		if(p.getx()>0) // sa nu imi dea valoare undefined
			return p;
	}
	
	//daca se afla in containerul 4
	else if (x >= c4x && x<c4x + c4.getnrRepereOriz() * 15 && y>= c4y &&y < c4y + c4.getnrRepereVer() * 5) {
		Point p;
		for (int i = 0; i < c4.getnrRepereOriz(); i++) {
			for (int j = 0; j < c4.getnrRepereVer(); j++)
				if (x >= c4x + i * 15 && x < c4x + (i + 1) * 15 && y >= c4y + j * 5 && y < c4y + (j + 1) * 5) { //ar trebui >= la prima
					Point rand(c4x + i * 15, c4y+j*5);
					p = rand;
					break;
				}
		}
		return p;
		
	}
	
	//eu zic ca functia asta tre sa returneze un pct 
	//si apoi in alta functie vad daca pct e pct pt soare, daca are c2x atunci vad care e c2y si bag planta in buffer si else printez planta
	Point failurePoint(0, 0);
	return failurePoint;
}

void doAction(Point &p, SegmentedContainer &c2, SegmentedContainer &c3, SegmentedContainer &c4, int &score, Sun &sun, std::string &PlantName, std::vector<Peashooter> &mypeashooters, std::vector<SunFlower> &mysunflowers) {

	//actiune pt container 2
	if (p.gety() == c2.getCorner1().gety()) {
		int x = p.getx() + 15 / 2;
		int y = p.gety() + 5 / 2;
		Point pt(x, y);
		if (pt.getx() == sun.builtAround.getx() && pt.gety() == sun.builtAround.gety()) {
			score = score + sun.valoare;
		}
		sun.Delete();
		//daca voi avea alte resurse voi face un if si pentru alea tot aici
	}

	//actiune pt container 3
	else if (p.getx() == c3.getCorner1().getx()) {
		for(int i=0;i<2;i++) //i<c3.getnrRepereVer(), pt cand am toate plantele
			if (p.gety() == c3.getCorner1().gety() + i * 5) {
				switch (i) {
				case(0): 
					if (score >= mypeashooters[0].cost) {
					score = score - mypeashooters[0].cost;
					PlantName = "peashooter";
				}
				break;//aceste buffere ma ajuta cand voi pune plantele in teren, daca e x, plantez x, si dupa ce am pus planta il golesc
				case(1): 
					if (score >= mysunflowers[0].cost) {
					score = score - mysunflowers[0].cost;
					PlantName = "sunflower";
				}
				break;
				//case(2): va urma
				//case(3): va urma
				//case(4): va urma
				}
				break;
			}
				
	}

	//actiune pt container 4
	else {
		int x = p.getx() + int(15 / 2);
		int y = p.gety() + int(5 / 2);
		Point temp(x, y);
		p = temp;
		if (PlantName == "peashooter") {
			mypeashooters.push_back(mypeashooters[0]);//are alt builtAround 
			mypeashooters[mypeashooters.size() - 1].builtAround = p;
			mypeashooters[mypeashooters.size() - 1].Print(p);
			PlantName = "";
		}
		else if (PlantName == "sunflower") {
			mysunflowers.push_back(mysunflowers[0]);
			mysunflowers[mysunflowers.size()-1].Print(p);
			PlantName = "";
			if(sun.refreshRate>2000)
				sun.refreshRate -= 500;
			}
	}

}

void doScoreTable (UserInterface::ConsoleOutput conOut, Container &c1, int score) {
	conOut(c1.getCorner1().gety() + 5 / 2 - 1, c1.getCorner1().getx() + 15 / 2 - 2) << "SCORE";
	conOut(c1.getCorner1().gety() + 5 / 2, c1.getCorner1().getx() + 15 / 2) << score;
}

void refreshScore(UserInterface::ConsoleOutput conOut, Container &c1, int score){
	int x = c1.getCorner1().getx()+15/2;
	int y = c1.getCorner1().gety()+5/2;
	conOut (y, x) << "    ";
	conOut (y, x) << score;
}

void DrawAllZombies(std::vector<Zombie> &myZombies, SegmentedContainer &c4) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto beginZ = steady_clock::now();
	auto endZ = steady_clock::now();
	int time = 4567;
	if (duration_cast<milliseconds>(endZ - beginZ).count() > time) {
		//voi alterna intre cele doua stari la fiecare 4500mili
		//adica o perioada e printat intr-un loc si apoi il sterg si il printez in patratelul urmator
		beginZ = endZ;
		for (int i = 0; i < int(myZombies.size()); i++) {
			myZombies[i].Draw(c4);
		}
	}
}

void DrawAllZombies(std::vector<BucketHeadZombie> &myBucketHeadZombies, SegmentedContainer &c4) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto beginBZ = steady_clock::now();
	auto endBZ = steady_clock::now();
	int time = 10000; 
	if (duration_cast<milliseconds>(endBZ - beginBZ).count() > time) {
		//voi alterna intre cele doua stari la fiecare 4500mili
		//adica o perioada e printat intr-un loc si apoi il sterg si il printez in patratelul urmator
		beginBZ = endBZ;
		for (int i = 0; i < int(myBucketHeadZombies.size()); i++) {
			myBucketHeadZombies[i].Draw(c4);
		}
	}
}

void DrawAllProiectils(std::vector<Peashooter> &mypeashooters, SegmentedContainer &c4) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto beginP = steady_clock::now();
	auto endP = steady_clock::now();
	static int prevNumberofProiectile = 1;
	static int initializat = 0;
	if (duration_cast<milliseconds>(endP - beginP).count() > 765) {
		beginP = endP;
		if (prevNumberofProiectile != mypeashooters.size()) {
			for (int i = 1; i < prevNumberofProiectile; i++) {
				conOut(mypeashooters[i].pea.lastProiectilPosition.getx(), mypeashooters[i].pea.lastProiectilPosition.gety())<<" ";
			}
			for (int i = 1; i<int(mypeashooters.size()); i++) {
				{
					prevNumberofProiectile = mypeashooters.size();
					mypeashooters[i].pea.builtAround = mypeashooters[i].builtAround;
					mypeashooters[i].pea.lastProiectilPosition = mypeashooters[i].pea.builtAround;
				}
				mypeashooters[i].pea.Draw(c4);
			}
		}
		else {
			for (int i = 1; i<int(mypeashooters.size()); i++)
				mypeashooters[i].pea.Draw(c4);
		}
	}
}

bool operator==(Point &p1, Point &p2) {
	if (p1.getx() == p2.getx() && p1.gety() == p2.gety()) {
		return true;
	}
	return false;
}

void checkInteraction(std::vector <Peashooter> &mypeashooters, std::vector<SunFlower> &mysunflowers, std::vector<Zombie> &myzombies, std::vector<BucketHeadZombie> &mybucketheadzombies) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin2 = steady_clock::now();
	auto end2 = steady_clock::now();
	static auto begin3 = steady_clock::now();
	auto end3 = steady_clock::now();
	static auto begin4 = steady_clock::now();
	auto end4 = steady_clock::now();

	if (duration_cast<milliseconds>(end2 - begin2).count() > 750) {
		begin2 = end2;
		//intre pea si zombie
		for (int i = 1; i < mypeashooters.size(); i++) {
			for (int j = 0; j < myzombies.size(); j++) {
				if (mypeashooters[i].pea.lastProiectilPosition == myzombies[j].builtAround) {
					myzombies[j].health = int(myzombies[j].health / 2);
					//-----------------------------------
					//pt log
					std::string sir = "Un proiectil a lovit un zombie la (";
					sir += std::to_string(myzombies[j].builtAround.getx());
					sir += ", ";
					sir += std::to_string(myzombies[j].builtAround.gety());
					sir += ")";
					Log::getInstance().print_log(sir.c_str());
				}
			}
			for (int j = 0; j < mybucketheadzombies.size(); j++) {
				if (mypeashooters[i].pea.lastProiectilPosition == mybucketheadzombies[j].builtAround) {
					mybucketheadzombies[j].health = int(mybucketheadzombies[j].health / 2);
					//-----------------------------------
					//pt log
					std::string sir = "Un proiectil a lovit un bucketheadzombie la (";
					sir += std::to_string(mybucketheadzombies[j].builtAround.getx());
					sir += ", ";
					sir += std::to_string(mybucketheadzombies[j].builtAround.gety());
					sir += ")";
					Log::getInstance().print_log(sir.c_str());
				}
			}
		}
	}

	if (duration_cast<milliseconds>(end3 - begin3).count() > 3500) {
		begin3 = end3;
		
		//intre zombie si plante
		//pt zombie
		for (int i = 0; i < myzombies.size(); i++) {
			for (int j = 1; j < mypeashooters.size(); j++) {
				if (myzombies[i].builtAround == mypeashooters[j].builtAround) {
					mypeashooters[j].nrMaxMuscaturi--;
					//-----------------------------------
					//pt log
					std::string sir = "Un zombie a muscat o peashooter la (";
					sir += std::to_string(myzombies[i].builtAround.getx());
					sir += ", ";
					sir += std::to_string(myzombies[i].builtAround.gety());
					sir += ")";
					Log::getInstance().print_log(sir.c_str());
				}
			}
			for (int j = 1; j < mysunflowers.size(); j++) {
				if (myzombies[i].builtAround == mysunflowers[j].builtAround) {
					mysunflowers[j].nrMaxMuscaturi--;
					//-----------------------------------
					//pt log
					std::string sir = "Un zombie a muscat o sunflower la (";
					sir += std::to_string(myzombies[i].builtAround.getx());
					sir += ", ";
					sir += std::to_string(myzombies[i].builtAround.gety());
					sir += ")";
					Log::getInstance().print_log(sir.c_str());
				}
			}
		}

	}

	if (duration_cast<milliseconds>(end4 - begin4).count() > 7500) {
		begin4 = end4;
		//pt bucketheadzombie
		for (int i = 0; i < mybucketheadzombies.size(); i++) {
			for (int j = 1; j < mypeashooters.size(); j++) {
				if (mybucketheadzombies[i].builtAround == mypeashooters[j].builtAround) {
					mypeashooters[j].nrMaxMuscaturi--;
					//-----------------------------------
					//pt log
					std::string sir = "Un bucketheadzombie a muscat o peashooter la (";
					sir += std::to_string(mybucketheadzombies[i].builtAround.getx());
					sir += ", ";
					sir += std::to_string(mybucketheadzombies[i].builtAround.gety());
					sir += ")";
					Log::getInstance().print_log(sir.c_str());
				}
			}
			for (int j = 1; j < mysunflowers.size(); j++) {
				if (mybucketheadzombies[i].builtAround == mysunflowers[j].builtAround) {
					mysunflowers[j].nrMaxMuscaturi--;
					//-----------------------------------
					//pt log
					std::string sir = "Un bucketheadzombie a muscat o sunflower la (";
					sir += std::to_string(mybucketheadzombies[i].builtAround.getx());
					sir += ", ";
					sir += std::to_string(mybucketheadzombies[i].builtAround.gety());
					sir += ")";
					Log::getInstance().print_log(sir.c_str());
				}
			}
		}
	}
}

void checkConditions(std::vector <Peashooter> &mypeashooters, std::vector<SunFlower> &mysunflowers, std::vector<Zombie> &myzombies, std::vector<BucketHeadZombie> &mybucketheadzombies) {
	//pt plante
	for (int i = 1; i < mypeashooters.size(); i++) {
		if (mypeashooters[i].nrMaxMuscaturi == 0) { 
			//-----------------------------------
			//pt log
			std::string sir = "O peashooter a disparut la ";
			sir += "(";
			sir += std::to_string(mypeashooters[i].builtAround.getx());
			sir += ", ";
			sir += std::to_string(mypeashooters[i].builtAround.gety());
			sir += ")";
			Log::getInstance().print_log(sir.c_str());

			mypeashooters[i].Delete(mypeashooters[i].builtAround);
			mypeashooters.erase(mypeashooters.begin() + i);
			i--;
		}
	}
	for (int i = 1; i < mysunflowers.size(); i++) {
		if (mysunflowers[i].nrMaxMuscaturi == 0) {
			//-----------------------------------
			//pt log
			std::string sir = "O sunflower a disparut la ";
			sir += "(";
			sir += std::to_string(mysunflowers[i].builtAround.getx());
			sir += ", ";
			sir += std::to_string(mysunflowers[i].builtAround.gety());
			sir += ")";
			Log::getInstance().print_log(sir.c_str());

			mysunflowers[i].Delete(mysunflowers[i].builtAround);
			mysunflowers.erase(mysunflowers.begin() + i);
			i--;
		}
			
	}

	//pt zombie
	for (int i = 0; i < myzombies.size(); i++) {
		if (myzombies[i].health < 25) {
			//-----------------------------------
			//pt log
			std::string sir = "Un zombie a disparut la ";
			sir += "(";
			sir += std::to_string(myzombies[i].builtAround.getx());
			sir += ", ";
			sir += std::to_string(myzombies[i].builtAround.gety());
			sir += ")";
			Log::getInstance().print_log(sir.c_str());

			myzombies[i].Delete();
			myzombies.erase(myzombies.begin()+i);
			i--;
		}
	}
	//pt mybucketheadzombie
	for (int i = 0; i < mybucketheadzombies.size(); i++) {
		if (mybucketheadzombies[i].health < 25) {
			//-----------------------------------
			//pt log
			std::string sir = "Un bucketheadzombie a disparut la ";
			sir += "(";
			sir += std::to_string(mybucketheadzombies[i].builtAround.getx());
			sir += ", ";
			sir += std::to_string(mybucketheadzombies[i].builtAround.gety());
			sir += ")";
			Log::getInstance().print_log(sir.c_str());

			mybucketheadzombies[i].Delete();
			mybucketheadzombies.erase(mybucketheadzombies.begin() + i);
			i--;
		}
	}

}

int checkZombies(std::vector<Zombie> &myzombies, std::vector<BucketHeadZombie> &mybucketheadzombies) {

	for (int i = 0; i < myzombies.size(); i++) 
		if (myzombies[i].stare == "castigator")
			return 0;
	if (myzombies.empty()) {
		return 1;
		//-----------------------------------
		//pt log
		std::string sir = "Nu mai e niciun zombie. Treci la nivelul urmator.";
		Log::getInstance().print_log(sir.c_str());
	}
	else
		return 2;

}

void doWinScreen(UserInterface::ConsoleOutput &conOut) {
	time_t start = time(NULL);
	time_t now = time(NULL);
	while ((now - start) <= 3) {
		conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Ai castigat! :(";
		now = time(NULL);
	}
}

void doLoseScreen(UserInterface::ConsoleOutput &conOut) {
	time_t start = time(NULL);
	time_t now = time(NULL);
	while ((now - start) <= 3) {
		conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Ai pierdut! :(";
		now = time(NULL);
	}
}

void printUserData(char* username, char* password, int score) {
	std::ofstream fout;
	fout.open("UserData.txt", std::ofstream::app);
	fout << username << " " <<password<<" "<<score <<std::endl;
	fout.close();
}


int main(void) {
	
	srand((unsigned int)time(NULL));
	Log::getInstance().clearLogFile();//ca sa goleasca fisierul de log daca m-am mai jucat inainte

	char username[50];
	char password[50];
	static int score = 0;

	int level = 1; //bydefault, va creste daca se castiga nivelul, sau va deveni 0 cand se pierde
	int nr_zombie = 1;
	int nr_buckethead = 1;
	int ok;

	while (level) {
		//la fiece nivel sa stearga ce a fost inainte
		system("cls");
		
		if (level == 1) {
			getUserInfo(username, password);
		}

		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

		if (level == 2) {
			nr_zombie = 2;
			nr_buckethead = 2;
		}
		else if (level == 3) {
			nr_zombie = 3;
			nr_buckethead = 3;
		}
		
		doLoadingScreen(conOut, level);

		//initializare containere
		Container* c1; SegmentedContainer *c2, *c3, *c4;

		//initializare resurse
		Sun sun;

		//initializare plante
		std::vector<Peashooter> mypeashooters(1);
		std::vector<SunFlower> mysunflowers(1);

		//initializare zombie
		std::vector<Zombie> myzombies(nr_zombie);
		std::vector<BucketHeadZombie> mybucketheadzombies(nr_buckethead);

		//grafica initiala
		doGraphics(c1, c2, c3, c4, conOut, level);
		//tabela de scor initiala
		doScoreTable(conOut, *c1, score);

		//pune plante in container-ul 3
		mypeashooters[0].Draw(*c3);
		mysunflowers[0].Draw(*c3);

		//micunealta secreta ce tine minte ce planta va trebui pusa pe teren dupa dublu click pe planta respectiva
		std::string PlantName; 


		while (true)
		{
			//deseneaza toate entitatile la pozitia corespunzatoare
			sun.Draw(*c2);
			DrawAllZombies(myzombies, *c4);
			DrawAllZombies(mybucketheadzombies, *c4);
			DrawAllProiectils(mypeashooters, *c4);

			//verifica interactiunea dintre entitati
			checkInteraction(mypeashooters, mysunflowers, myzombies, mybucketheadzombies);

			//verifica daca unele entitati verifica unele conditii pentru a exista
			checkConditions(mypeashooters, mysunflowers, myzombies, mybucketheadzombies);

			std::string action = conIn.getUserActions(); //move sau double click
			if (action != "") {
				conOut(41, 2) << action;
			}

			Point position;
			//verific daca actiunea e dublu click
			if (checkDoubleClick(action, position)) {
				//daca e dublu click verific daca e intr-un container, in locurile care trebuie
				Point p = checkPointContainer(position, *c2, *c3, *c4);
				if (p.getx() != 0 && p.gety() != 0) {//adica daca nu e fail
					doAction(p, *c2, *c3, *c4, score, sun, PlantName, mypeashooters, mysunflowers);
					refreshScore(conOut, *c1, score);
				}
				
			}

			//verifica daca mai sunt zombie 
			ok = checkZombies(myzombies, mybucketheadzombies);
			if (ok != 2)
				break;
			
		}
		mypeashooters.clear();
		mysunflowers.clear();
		myzombies.clear();
		mybucketheadzombies.clear();

		system("cls");
		if (ok == 0) {
			level = 0;
			doLoseScreen(conOut);
			printUserData(username, password, score);
			break;
		}
		else if (ok == 1) {
			level++;
			//-------------------------
			//pt log
			Log::getInstance().print_log("Ai trecut la nivelul urmator.");
			//aici nu are rost sa printez scorul utilizatorului intr-un fisier fiindca nu s-a terminat jocul
		}
		if (level == 4) {
			doWinScreen(conOut);
			printUserData(username, password, score);
			break;
		}
		delete c1; delete c2; delete c3; delete c4; //dezalocare responsabila 
	}

	return 0;
}