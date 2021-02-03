#include "Exceptie.h"



Exceptie::Exceptie()
{
}

void Exceptie::afiseaza_exceptia()
{
	system("CLS");
	cout << "Eroare numarul " << cod_eroare << endl;
	cout << mesaj_eroare;
	_getch();
}


Exceptie::~Exceptie()
{
}
