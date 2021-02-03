#pragma once
#include"CResource.h"
class CResource_Sun:public CResource
{
	int Value_sun_;
	int id_;
	FILE* fSun;
public:
	//static FILE* fSun_;
	CResource_Sun(int Value_sun_, TypeResource type) :CResource(Value_sun_, type) {
		this->id_ = SUN_ID;
		
		//fSun_ = fopen("SunCoord.txt", "a");
		CLog::getInstance().printLog("S-a apelat constructorul clasei CResource_Sun\n");
	}
	virtual ~CResource_Sun();
	void Display( int y, int x, int id_element, bool status_SunFlower) override;
};

