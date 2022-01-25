#include "Joc.h"
#include <conio.h>



int main(void)
{
	auto joc = Joc::get_instance();
	joc.initializeaza();
	while (!joc.terminat())
	{
		joc.joaca();
	}

	_getch();
	return 0;
}

