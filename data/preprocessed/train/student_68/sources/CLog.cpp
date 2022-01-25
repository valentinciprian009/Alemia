#include "CLog.h"

CLog* CLog::object_ = nullptr;
FILE* CLog::fLog_ = nullptr;
const char* CLog::filename_ = nullptr;
const char* CLog::path_ = nullptr;

CLog::CLog()
{
	this->filename_ = "Log.txt";
	this->path_ = "G:\\";
	//CLog::getInstance().printLog("S-a apelat constructorul clasei CLog.\n");
}

CLog::~CLog()
{
	delete[]filename_;//o mai fac si NULL?
	delete[]path_;
	delete[]object_;
	object_ = NULL; //uita te pe foi de la cursul lui Togan cum este o stergere corecta
	fclose(fLog_);
	CLog::getInstance().printLog("S-a apelat destrucorul explicit al clasei CLog.\n");
}

CLog& CLog::getInstance()
{
	if (object_ == nullptr)
	{
		object_ = new CLog();
		char* file = new char[strlen(filename_) + strlen(path_) + 1];
		strcpy(file, path_);
		strcat(file, filename_);
		object_->fLog_ = fopen(file, "a");
	}
	return *object_;
}

void CLog::printLog(const char* message)
{
	fprintf(this->fLog_, "%s\n", message);
}
