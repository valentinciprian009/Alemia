#include "joc.h"

Joc* Joc::instanta = NULL;

Joc& Joc::get_instance()
{
	if (!instanta)
	{
		instanta = new Joc();
	}
	return *instanta;
}

void Joc::afiseaza_magazin()
{
	conOut(3, 0) << 'F';
	conOut(4, 0) << 'P';
	conOut(5, 0) << 'I';
	conOut(6, 0) << 'C';
	conOut(7, 0) << 'N';
	conOut(3, 25) << "F=Floarea soarelui";
	conOut(4, 25) << "P=Pastaie";
	conOut(5, 25) << "I=Inghetat";
	conOut(6, 25) << "C=Cireasa";
	conOut(7, 25) << "N=Nuca";
}

void Joc::afiseaza_sori()
{
	for (int i = 0; i < 8; i++)
	{
		if (sori_disponibili[i])
		{
			conOut(0, 3 + i) << '+';
		}
		else
		{
			conOut(0, 3 + i) << ' ';
		}
	}
}

void Joc::afiseaza_matrice()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			matrice[i][j] = ' ';
		}
	}
	for (auto i : elemente.plante)
	{
		matrice[i->get_locatie().y-3][i->get_locatie().x-3] = i->get_afisas();
	}
	for (auto i : elemente.zombii)
	{
		matrice[i->get_locatie().y-3][i->get_locatie().x-3] = i->get_afisas();
	}
	for (auto i : elemente.proiectile)
	{
		matrice[i->get_locatie().y-3][i->get_locatie().x-3] = i->get_afisas();
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			conOut(i+3, j+3) << matrice[i][j];
		}
	}
	for (int i = 0; i < 10;i++)
	{
		conOut(2, 2 + i) << '*';
		conOut(8, 2 + i) << '*';
	}
	for (int i = 0; i < 7; i++)
	{
		conOut(2+i, 2) << '*';
		conOut(2+i, 11) << '*';
	}
}

void Joc::afiseaza_bani()
{
	conOut(0, 25) << "Bani:";
	conOut(1, 25) << elemente.jucator.get_bani() << "   ";
}

Joc::~Joc()
{
}

void Joc::afiseaza_infrangere()
{
	curata_ecran();
	conOut(0,0)<< "Chiar si cei mai buni pierd uneori.";
	sfarsit = true;
};

void Joc::afiseaza_victorie()
{
	curata_ecran();
	conOut(0, 0) << "Felicitari! Ai castigat un joc! E posibil sa ai realizari mai mari.";
	sfarsit = true;
};


void Joc::verifica_final()
{
	for (auto i : elemente.zombii)
	{
		if (i->get_locatie().x <= 3)
		{
			afiseaza_infrangere();
			return;
		}
	}
	if (elemente.jucator.get_scor() == 10)
	{
		afiseaza_victorie();
		return;
	}
}

void Joc::curata_ecran()
{
	for (int i = 0; i < 30; i++)
	{
		conOut(i, 0) << "                                                                                                    ";
	}
}

void Joc::verifica_click()
{
	auto actiune = conIn.getUserActions();
	if (actiune)
	{
		if (cumparat)
		{
			switch (cumparat)
			{
			case 'F':
				if (elemente.jucator.get_bani() >= 100)
				{
					elemente.plante.push_back(move(new FloareaSoarelui(*actiune)));
					elemente.jucator.scade_bani(100);
					cumparat = '\0';
				}
				break;
			case 'P':
				if (elemente.jucator.get_bani() >= 100)
				{
					elemente.plante.push_back(move(new Pastaie(*actiune)));
					elemente.jucator.scade_bani(100);
					cumparat = '\0';
				}
				break;
			case 'I':
				if (elemente.jucator.get_bani() >= 150)
				{
					elemente.plante.push_back(move(new PastaieInghetata(*actiune)));
					elemente.jucator.scade_bani(150);
					cumparat = '\0';
				}
				break;
			case 'C':
				if (elemente.jucator.get_bani() >= 150)
				{
					elemente.plante.push_back(move(new Cireasa(*actiune)));
					elemente.jucator.scade_bani(150);
					cumparat = '\0';
				}
				break;
			case 'N':
				if (elemente.jucator.get_bani() >= 100)
				{
					elemente.plante.push_back(move(new	Nuca(*actiune)));
					elemente.jucator.scade_bani(100);
					cumparat = '\0';
				}
				break;
			default:
				break;
			}
		}
		else
		{
 			if (actiune->x == 0)
			{
				switch (actiune->y)
				{
				case 3:
					cumparat = 'F';
					break;
				case 4:
					cumparat = 'P';
					break;
				case 5:
					cumparat = 'I';
					break;
				case 6:
					cumparat = 'C';
					break;
				case 7:
					cumparat = 'N';
					break;
				default:
					break;
				}
			}
			if (actiune->y == 0)
			{
				if (sori_disponibili[actiune->x-3])
				{
					sori_disponibili[actiune->x-3] = false;
					elemente.jucator.adauga_bani(25);
				}
			}
		}
	}
}

void Joc::adauga_elemente()
{
	auto acum = steady_clock::now();
	if (duration_cast<milliseconds>(acum - timp_soare).count() > elemente.jucator.get_rata_soare())
	{
		timp_soare = acum;
		sori_disponibili[rand() % 8] = true;
	}
	if (duration_cast<milliseconds>(acum - timp_zombi).count() > 10000)
	{
		timp_zombi = acum;
		elemente.zombii.push_back(move(new ZombiNormal(coords( 10, rand() % 5 + 3))));
	}
	if (duration_cast<milliseconds>(acum - timp_zombi_galeata).count() > 20000)
	{
		timp_zombi_galeata = acum;
		elemente.zombii.push_back(move(new ZombiGaleata(coords(10, rand() % 5 + 3))));
	}
}

void Joc::refresh_total()
{
	for (auto i : elemente.plante)
	{
		i->refresh(elemente);
	}
	for (auto i : elemente.proiectile)
	{
		i->refresh(elemente);
	}
	for (auto i : elemente.zombii)
	{
		i->refresh(elemente);
	}
}

void Joc::afiseaza_scor()
{
	conOut(10, 25) << "Scor:";
	conOut(11, 25) << elemente.jucator.get_scor()<<"  ";
}

void Joc::joaca()
{	
	verifica_click();
	afiseaza_magazin();
	afiseaza_bani();
	afiseaza_sori();
	adauga_elemente();
	afiseaza_matrice();
	afiseaza_scor();
	refresh_total();
	verifica_final();
}

void Joc::joc_nou()
{
	string nume;
	string parola;
	curata_ecran();
	conOut(0, 0) << "Inrodu un nume";
	cin >> nume;
	curata_ecran();
	conOut(0, 0) << "Introdu o parola";
	cin >> parola;
	curata_ecran();
	ofstream f("nume_parole.txt", ios_base::app);
	f << nume << " " << parola << endl;
	ofstream p("log.log", ios_base::app);
	p << nume << " s-a inregistrat.\n";
}

bool Joc::continua()
{
	string nume;
	string parola;
	curata_ecran();
	conOut(0,0) << "Inrodu numele";
	cin >> nume;
	curata_ecran();
	conOut(0, 0) << "Introdu parola";
	curata_ecran();
	cin >> parola;
	ifstream f("nume_parole.txt");
	ofstream p("log.log",ios_base::app);
	while (!f.eof())
	{
		string nume1, parola1;
		f >> nume1 >> parola1;
		if (nume1 == nume && parola1 == parola)
		{
			p << nume << " s-a logat.\n";
			return true;
		}
	}
	p << "Nume sau parola gresita\n";
	return false;
}

void Joc::initializeaza()
{
	cout << "Apasa c pentru a continua jocul sau n pentru un joc nou.";
	char c;
	cin >> c;
	if (c == 'c')
	{
		if (!continua())
			sfarsit = true;
		return;
	}
	if (c == 'n')
	{
		joc_nou();
		return;
	}
	sfarsit = true;

}
