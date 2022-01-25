#pragma once
#include"User.h"
#include"Menu.h"
#include<vector>

class UserMenu : public Menu
{
private:
	UserMenu();
	virtual ~UserMenu() { ; }
	static UserMenu* instance;
	vector<User> UserList;
	User currentUser;
public:
	static UserMenu& getInstance();
	static void destroyInstance();
	const User& getCurrentUser() const { return currentUser; }
	void updateCurrentUser(const User& user) { currentUser = user; }
	bool newUser(const string& username);
	int newUserMenu();
	bool loadUser(const string& username);
	int loadUserMenu();
};