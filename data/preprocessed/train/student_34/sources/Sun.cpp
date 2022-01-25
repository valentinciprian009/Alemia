#define _CRT_SECURE_NO_WARNINGS
#include "Sun.h"
#include <time.h>
#include "ConsoleOutput.h"

UserInterface::ConsoleOutput conOut1 = UserInterface::ConsoleOutput::getInstance();
Sun::Sun()
{
}




void Sun::_random()
{  
	srand(time(NULL));
	
	int x = rand() % 8;
	FILE *f = fopen("t.txt", "w");
	fprintf(f, "%d ", x);
	switch (x) {
	case(0): {_delete_after();
		draw(2, 25);
	}break;
	case(1): {
		_delete_after();
		draw(2, 40);
		break; }
	case(2): {
		_delete_after();
		draw(2, 53);
		break; }
	case(3): {
		_delete_after();
		draw(2, 70);
		break; }
	case(4): {
		_delete_after();
		draw(2, 85);
		break; }
	case(5): {
		_delete_after();
		draw(2, 100);
		break; }
	case(6): {
		_delete_after();
		draw(2, 115);
		break;
	}
	case(7): {
		_delete_after();
     	 draw(2, 130);
		 break;
			 }

	}
	fclose(f);
	}

void Sun::_delete_after()
{
	
	
		remove_sun(2, 25);
	
		remove_sun(2, 40);
		
		remove_sun(2, 53); 
		
		remove_sun(2, 70); 
		
		remove_sun(2, 85); 
			 

		remove_sun(2, 100); 
	
		remove_sun(2, 115); 
		remove_sun(2, 130);
	

}

void Sun::draw(int x,int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << " __.'.__ ";
	conOut(x+1, y) << "'-.   .-'";
	conOut(x+2, y) << "  /.'.\\  ";
}

void Sun::remove_sun(int x, int y)
{
	conOut1(x, y) << "         ";
	conOut1(x+1, y) << "         ";
	conOut1(x + 2, y) << "         ";


}




Sun::~Sun()
{
}
