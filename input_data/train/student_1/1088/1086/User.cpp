#include"User.h"

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		username = other.username;
		maxLevel = other.maxLevel;
		score = other.score;
	}
	return *this;
}

User::User(const string& usernm) : username(usernm), maxLevel(), score()
{
	ofstream fout("Saved Users Progress/" + username + ".log");
	fout << username << endl << maxLevel << endl << score.getLevel() << endl << score.getScore();
	Log::getInstance().write(username + " created.");
	fout.close();
}

User::User(const string& UserFilename, const string& SaveLocation)
{
	string username;
	int maxLevel, level, score, sunQuantity;
	ifstream fin(SaveLocation + "/" + UserFilename);
	if (fin.is_open())
	{
		fin >> username >> maxLevel >> level >> score;
		this->username = username;
		this->maxLevel = maxLevel;
		ScoreBoard scr(level, score, 0);
		fin.close();
		Log::getInstance().write(username + " loaded.");
	}
	else
	{
		fin.close();
		throw new Exception(4, "Cannot retrieve save file " + string(UserFilename) + "!");
	}
}