#include "UserMenu.h"

UserMenu* UserMenu::instance = nullptr;

UserMenu& UserMenu::getInstance()
{
    if (!UserMenu::instance)
    {
        UserMenu::instance = new UserMenu();
    }
    return *UserMenu::instance;
}

void UserMenu::destroyInstance()
{
    if (UserMenu::instance)
    {
        delete UserMenu::instance;
        UserMenu::instance = nullptr;
    }
}

UserMenu::UserMenu() : Menu(), UserList(), currentUser()
{
    try
    {
        _mkdir("Saved Users Progress");
        ifstream userFile("User List.txt");
        if (!userFile.is_open())
        {
            ofstream newfile("User List.txt");
            newfile.close();
        }
        else
        {
            string username;
            while (userFile >> username)
            {
                User u(username + ".log", "Saved Users Progress");
                UserList.push_back(u);
            }
        }
        userFile.close();
    }
    catch (Exception * e)
    {
        Log::getInstance().write("ERROR: " + e->getMessage());
        delete e;
    }
}

bool UserMenu::newUser(const string& username)
{
    for (auto& user : UserList)
        if (user.getUsername() == username)
            return false;
    User newUser(username);
    currentUser = newUser;
    UserList.push_back(newUser);
    ofstream fout("User List.txt", ios_base::app);
    fout << username << endl;
    fout.close();
    return true;
}

int UserMenu::newUserMenu()
{
    UserInterface::ClearScreen();
    Log::getInstance().write("New User Menu POO vs Zombies...");
    UserInterface::printTitle(consoleOut);
    string username;
    int row_username_input = 34;
    int column_username_input = 83;
    int row_back_button = row_username_input + 5;
    int column_back_button = 88;
    int row_exit_button = row_username_input + 8;
    int column_exit_button = 92;
    consoleOut(row_back_button, column_back_button) << "BACK TO MAIN MENU";
    consoleOut(row_exit_button, column_exit_button) << "EXIT GAME";
    while (true)
    {
        if (UserInterface::pressButton(consoleIn, consoleOut, row_exit_button, column_exit_button, "EXIT GAME"))
        {
            return 3;
        }
        else if (UserInterface::pressButton(consoleIn, consoleOut, row_back_button, column_back_button, "BACK TO MAIN MENU"))
        {
            return 2;
        }
        else if (!UserInterface::readTextInput(consoleIn, consoleOut, row_username_input, column_username_input, "Enter username for new user:  ", username))
        {
            bool checkIfUserCreated = newUser(username);
            if (!checkIfUserCreated)
            {
                consoleOut(row_username_input + 2, column_username_input) << "User " + username + " already exists!";
                try { throw new Exception(1, "User " + username + " already exists!"); }
                catch (Exception * e)
                {
                    Log::getInstance().write("ERROR: " + e->getMessage());
                    delete e;
                }
            }
            else
            {
                return 1;
            } 
        }
    }
}

bool UserMenu::loadUser(const string& username)
{
    for (auto& user : UserList)
        if (user.getUsername() == username)
        {
            currentUser = user;
            return true;
        }
    return false;
}

int UserMenu::loadUserMenu()
{
    UserInterface::ClearScreen();
    Log::getInstance().write("Load User Menu POO vs Zombies...");
    UserInterface::printTitle(consoleOut);
    string username;
    int row_username_input = 34;
    int column_username_input = 83;
    int row_back_button = row_username_input + 5;
    int column_back_button = 88;
    int row_exit_button = row_username_input + 8;
    int column_exit_button = 92;
    consoleOut(row_back_button, column_back_button) << "BACK TO MAIN MENU";
    consoleOut(row_exit_button, column_exit_button) << "EXIT GAME";
    while (true)
    {
        if (UserInterface::pressButton(consoleIn, consoleOut, row_exit_button, column_exit_button, "EXIT GAME"))
        {
            return 3;
        }
        else if (UserInterface::pressButton(consoleIn, consoleOut, row_back_button, column_back_button, "BACK TO MAIN MENU"))
        {
            return 2;
        }
        else if (!UserInterface::readTextInput(consoleIn, consoleOut, row_username_input, column_username_input, "Enter username to load user:  ", username))
        {
            bool checkIfUserCreated = loadUser(username);
            if (!checkIfUserCreated)
            {
                consoleOut(row_username_input + 2, column_username_input) << "User " + username + " does not exist!";
                try { throw new Exception(2, "User " + username + " does not exist!"); }
                catch (Exception * e)
                {
                    Log::getInstance().write("ERROR: " + e->getMessage());
                    delete e;
                }
            }
            else
            {
                return 1;
            }
        }
    }
}