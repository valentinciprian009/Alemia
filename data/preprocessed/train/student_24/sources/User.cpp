#include "User.h"
#include "ConsoleInput.h"
#include "Game.h"

std::string User::retrieveUsername(UserInterface::ConsoleOutput& conOut)
{
	std::string name = "";
	int index = 40;
	char ch;

	ch = _getch();
	while (ch != '\r')
	{
		conOut(21, index) << ch;
		index++;
		name += ch;
		ch = _getch();
	}

	return name;
}

bool User::checkExistence() //checks if the user exists in user.txt
{
	std::ifstream fp("user.txt");

	std::string buffer;
	int nrUsers;

	fp >> nrUsers;
	for (int i = 0; i < nrUsers; i++)
	{
		fp >> buffer;
		if (buffer == this->m_Nume)
		{
			throw MyException("Ati introdus un username deja utilizat\n");
		}
	}
	return false;
}

User::User() : m_Score(0), m_Level(1), m_Resource(0), m_Error(false)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	
	if (isNewUser(conOut) == true)
	{
		conOut(20, 40) << "Introduceti username-ul\n";
		this->m_Nume = retrieveUsername(conOut);

		if (checkExistence() == true)
		{
			conOut(24, 40) << "Username-ul este deja utilizat\n";
			m_Error = true;
		}
		else
		{
			addToUserFile();
			conOut(22, 40) << "User creat. \n";
		}
	}
	else
	{
		conOut(20, 40) << "Introduceti username-ul\n";
		this->m_Nume = retrieveUsername(conOut);

		retrieveStats();
	}
	Sleep(1000);
}

bool User::checkIdentity() const
{
	return m_Error;
}

void User::setScore(int toAdd)
{
	this->m_Score += toAdd;
}

void User::setLevel(int lvl)
{
	this->m_Level = lvl;
}

void User::setResources(int toAdd)
{
	this->m_Resource += toAdd;
}

void User::printDataToFile() const
{
	std::string filename = this->m_Nume + ".txt";
	std::ofstream fp(filename);

	fp << m_Nume << "\n";
	fp << m_Score << "\n";
	fp << m_Level << "\n";
	fp << m_Resource << "\n";

	fp.close();
}

std::string User::getNume() const
{
	return m_Nume;
}

int User::getScore() const
{
	return m_Score;
}

int User::getLevel() const
{
	return m_Level;
}

int User::getResources() const
{
	return m_Resource;
}

std::string User::getUserFile() const
{
	std::string content = "";
	std::ifstream fp("user.txt");

	std::string buff;

	while (!fp.eof())
	{
		fp >> buff;
		if (buff == "")
			return "";

		if (buff == m_Nume)
		{
			if (content != "")
				content.erase(content.length() - 1, content.length());
			return content;
		}
		else
		{
			content += buff;
			content += "\n";
		}
	}

	content.erase(content.length() - 1, content.length());
	fp.close();

	return content;
}

void User::retrieveStats()
{
	std::string filename = this->m_Nume + ".txt";
	std::fstream fp(filename);
	std::string name;
	
	if (fp.is_open() == true)
	{
		fp >> name;
		fp >> m_Score;
		fp >> m_Level;
		fp >> m_Resource;
		fp.close();
	}
	else
	{
		m_Error = true;
		throw MyException("Userul nu exista???");
	}
	
}

bool User::isNewUser(UserInterface::ConsoleOutput& conOut) const
{
	int x, y;
	UserInterface::ConsoleInput conIn;
	std::string coord = "";
	conOut(20, 40) << "Doriti sa creati un user nou?";
	conOut(22, 40) << "Da";
	conOut(22, 50) << "Nu";

	do
	{
		coord = conIn.getUserActions();
	} while (coord == "");

	conIn.getCoordinates(x, y, coord);

	if ((x >= 15) && (x <= 25))
	{
		if ((y >= 35) && (y <= 45))
		{
			conOut(20, 40) << "                              ";
			conOut(22, 40) << "  ";
			conOut(22, 50) << "  ";
			return true;
		}
		else if ((y >= 45) && (y <= 55))
		{
			conOut(20, 40) << "                              ";
			conOut(22, 40) << "  ";
			conOut(22, 50) << "  ";
			return false;
		}
	}
	conOut(20, 40) << "                              ";
	conOut(22, 40) << "  ";
	conOut(22, 50) << "  ";

	return false;
}

void User::addToUserFile()
{
	std::string names ="";
	std::string buff;
	int nr;
	std::ifstream fp("user.txt");

	fp >> nr;

	for (int i = 0; i < nr; i++)
	{
		fp >> buff;
		names += buff;
		names += "\n";
	}
	fp.close();
	std::ofstream ofp{ "user.txt" };
	ofp << nr + 1 << "\n";
	ofp << names;
	ofp << this->m_Nume;
	ofp.close();
}


void User::printDataToScreen() const
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut.setColor(12);
	conOut(37, 29) << "Username:";
	conOut(37, 39) << m_Nume;
	conOut(37, 49) << "Nivel: ";
	conOut(37, 59) << m_Level;
	conOut(37, 69) << "Soare: ";
	conOut(37, 79) << "      ";
	conOut(37, 79) << m_Resource;
	conOut(37, 89) << "Scor: ";
	conOut(37, 99) << m_Score;
}