#include "Log.h"
#include<time.h>


Log::Log()
{

}

Log::~Log()
{
}

void Log::logare(string mesaj)
{
	static bool deschis = false;
	ofstream* f;
	if (deschis)
		f = new ofstream("log.txt", std::fstream::app);
	else
	{
		f = new ofstream("log.txt");
		deschis = true;
	}
	*f <<time(0)<<" "<< mesaj.c_str() << endl;
	(*f).close();
	delete f;
}

