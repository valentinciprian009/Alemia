#include "CLevel.h"

CLevel::CLevel()
{
	CLog::getInstance().printLog("S-a apelat constructorul explicit al clasei CLevel.\n");
}

CLevel::~CLevel()
{
	CLog::getInstance().printLog("S-a apelat destrucorul explicit al clasei CLevel.\n");
}

void CLevel::DrawLand()
{

}
