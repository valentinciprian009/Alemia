#include "Logare.h"



Utilizator* Logare::userCurent = nullptr;
Logare::Logare()
{
}

void Logare::citesteUseri(string file)
{
	ifstream f(file);

	while (!f.eof())
	{
		string nume, parola;
		f >> nume >> parola;
		Utilizator U(nume, parola);
		useri.push_back(U);
	}
	f.close();
}

bool Logare::verificaCompatibilitate(string user, string pass)
{
	citesteUseri("user.txt");
	for (int i = 0; i < useri.size(); i++)
	{
		if (useri[i].getName() == user)
		{
			if (useri[i].getPass()!= pass)
				return false;
			else
			{
				Utilizator utilizatorGasit(user, pass);
				userCurent = &utilizatorGasit;
				return true;
			}
		}
	}
	return false;
}

void Logare::addUser(string name, string pass)
{
	fstream f("user.txt", fstream::in | fstream::out | fstream::app);
	f << "\n" << name << " " << pass;

	Utilizator U(name, pass);
	useri.push_back(U);
	f.close();
}

void Logare::DisplayResourceNAMessageBox()
{
	int msgboxID = MessageBox(
		NULL,
		(LPCWSTR)L"Doriti sa va logati?",
		(LPCWSTR)L"Log message",
		 MB_OKCANCEL
	);

	switch (msgboxID)
	{
	
	case IDCANCEL:
		throw Exception("S-a apasat butonul CANCEL.");
		break;

	case IDOK:
		int cod;
		printf("Utilizator NOU  apasa 1\nUtilizator INREGISTRAT apasa 0: ");
		cin >> cod;
		string user, password;
		if (cod == 0)
		{
			printf("Username:");
			cin >> user;
			printf("Password:");
			cin >> password;
			if (verificaCompatibilitate(user, password))
			{
				cout << "OK!!";
				Log::logare("Autentificare reusita.");
			}
			else
			{
				cout << "PAROLA INCORECTA!";
				throw Exception("S-a introdus o parola incorecta!");
			}
		}
		else
		{
			cout << "Introduceti numele de utilizator:";
			cin >> user;
			cout << "Introduceti parola:";
			cin >> password;
			addUser(user, password);
			cout << "Inregistrat cu succes!";

			Log::logare("S-a creat un utilizator nou.");

			ofstream f("history.txt", std::fstream::app);
			if (!f.is_open())
				throw Exception("Fisierul: history.txt nu a fost gasit.");
			f << user <<" 1 0 \n";
			f.close();
		}
		Logare::userCurent = new Utilizator(user, password);
		break;
	}
}

vector<Utilizator> Logare::getUsers()
{
	return useri;
}


Logare::~Logare()
{
}
