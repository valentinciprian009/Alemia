#include "CResource.h"
#include"CResource_Sun.h"

CResource::CResource(int Value, TypeResource type)
{
	this->Value_ = Value;
	this->type_ = type;

}

CResource::~CResource()
{
	CLog::getInstance().printLog("S-a apelat destrucorul explicit al clasei CResource.\n");
}

void CResource::Display(int y, int x, int id, bool status_SunFlower)
{
	
}

int CResource::GetValue()
{
	return this->Value_;
}

IResource& IResource::createResource(int Value, TypeResource type)
{
	if (type == SUN)
	{
		return *new CResource_Sun(Value, type);
	}
	
}