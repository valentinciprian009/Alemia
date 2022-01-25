#pragma once

#include"CLevel.h"
#include"IResource.h"
#include"CPlants.h"

class IUser
{
public:
	static IUser& CreateUser(string username, string password);
	virtual void SignIn(string username, string password)=0;
	virtual int LogIn(string username, string password)=0;
	virtual void LogOut(string username)=0;
	virtual void pickResource(IResource& resource) = 0;//adaug val soare
	virtual bool Plant(CPlants& plant)=0;//scad din value disponibil al utilizatorului
	virtual void PassNextLevel()=0;
	virtual void EndGame()=0;
	virtual int GetTotalValue()=0;

	
};

