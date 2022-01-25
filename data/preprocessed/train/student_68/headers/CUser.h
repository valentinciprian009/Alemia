#pragma once
#include"IUser.h"


class CUser:public IUser
{
private:
	string UserName_;
	string Password_;
	int level_;
	int totalValue_;
	FILE* User_;
	bool status_;//on=1, off=0

public:
	static FILE* fAccounts_;
	CUser(string username, string password);
	virtual ~CUser();
	void SignIn(string username, string password);
	int LogIn(string username, string password);
	void LogOut(string username);
	void PassNextLevel();
	void pickResource(IResource&resource);
	bool Plant(CPlants& plant);
	void EndGame();

	int GetTotalValue();
};

