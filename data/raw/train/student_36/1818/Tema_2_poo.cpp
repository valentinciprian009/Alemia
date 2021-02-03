#include "Handler.h"

int main()
{
	Handler& H = Handler::getInstance();
	
	H.game();

	return 0;
}