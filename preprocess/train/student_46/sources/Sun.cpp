#include "Sun.h"


#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define COL_START 1
#define ROW_START 1

Sun::Sun()
{
}

void Sun::drawSun()
{
	cout << "\\ | /" << endl;
	cout << "- O -" << endl;
	cout << "/ | \\" <<endl;
}

void Sun::appearInRandomPlace()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	/*static std::string printedChar1 = "-";
	static std::string printedChar2 = "|";*/

	//for (int i = 1; i < 106; i++)
		//conOut(ROW_START, COL_START + i) << printedChar1;

	//for (int k = 5; k < 106; k++)
		//std::cout << " o " << endl;
		//for (int i = 1; i < 5; i++)
				//for (int j = 5; j <= 20; j += 15)

	for (int i = 1; i < 106; i++)
		conOut(ROW_START, COL_START + i) <<"*";

	for (int i = 0; i < 106; i++)
		conOut(ROW_START + 5, COL_START + i) << "*";
	for (int i = 1; i < 5; i++)
		for (int j = 0; j <= 105; j += 15)
			conOut(ROW_START + i, COL_START + j) << "   ";
			
	std::srand(std::time(0));  
	int r = std::rand() % 150 + 1;
	cout << r<<endl<<endl;

	std::srand(std::time(0));
	int r1 = std::rand() % 60 + 1;

		drawSun();
		
}

int Sun::nrSun()
{
	return 0;
}



Sun::~Sun()
{
}
