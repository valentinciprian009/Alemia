#include "LoginSlide.h"
#include "ArenaSlide.h"
#include "LoadingSlide.h"

#define SECOND_ROW 81
#define MAXNAME 48

LoginSlide::LoginSlide() : Slide(true)
{
	users = User::getFromFile();
	lb = new LoginButton(this);
	
	std::string s = "_-.@"; 
	for (char c = '0'; c <= '9'; c++)
		keyboard.push_back(new LetterButton(this, c, c-'0'));
	for (char c = 'a'; c <= 'z'; c++) 
		keyboard.push_back(new LetterButton(this, c, 10+c-'a'));
	for (int i = 0; i < s.length(); i++) 
		keyboard.push_back(new LetterButton(this, s[i], 36 + i));
	for (char c = 'A'; c <= 'Z'; c++) 
		keyboard.push_back(new LetterButton(this, c, c - 'A' + 40));
	keyboard.push_back(new LetterButton(this, '>', 85));
	keyboard.push_back(new LetterButton(this, '<', 69));

	reinit();
}

void LoginSlide::update()
{
	std::string sec = boxes[0] + "  ";
	conOut(13, 82) << sec;
	std::string sec2 = std::string(boxes[1].length(), '*') + " ";
	conOut(17, 82) << sec2;

	conOut(13 + 4 * (1 - selected), 81) << "|";
	conOut(13 + 4 * selected, 81) << ">";
	
	for (std::string s = conIn.getUserActions(); s != ""; s = conIn.getUserActions())
	{
		for (int i = 0; i < keyboard.size(); i++)
			keyboard[i]->click(s);
		lb->click(s);
	}
}

void LoginSlide::reinit()
{
	Slide::clearZone(conOut, 0, 0);
	boxes[0] = "";
	boxes[1] = "";
	selected = 0;

	if (next != nullptr)
	{
		Arena::ArenaSlide* as = static_cast<Arena::ArenaSlide*>(next);
		if (as->responseSave())
		{
			if (userid != -2) {
				if (userid == -1)
					users.push_back(as->currentUser());
				User::printFile(users);
			}
		}
	}

	lb->draw(conOut);

	Slide::drawAsciiArt("topplayers.txt", conOut, 2, 10);
	Slide::drawAsciiArt("login.txt", conOut, 2, SECOND_ROW - 1);

	conOut(12, 14) << "Name";
	conOut(12, 30) << "Level";
	conOut(12, 36) << "Score";
	for (int i = 0; i < users.size(); i++)
	{
		conOut(14 + 2 * i, 11) << i + 1;
		conOut(14 + 2 * i, 14) << users[i]->name();
		conOut(14 + 2 * i, 30) << users[i]->level();
		conOut(14 + 2 * i, 36) << users[i]->score();
	}

	conOut(11, 81) << "NAME:";
	Slide::drawBox(conOut, SECOND_ROW, 12, 50, 1);

	conOut(15, 81) << "PASSWORD:";
	Slide::drawBox(conOut, SECOND_ROW, 16, 50, 1);

	for (auto it : keyboard)
		it->draw(conOut);
}

LoginSlide::~LoginSlide()
{
	delete lb;
	for (int i = 0; i < users.size(); i++)
		delete users[i];
	for (int i = 0; i < keyboard.size(); i++)
		delete keyboard[i];
}

LoginButton::LoginButton(Slide* lsp) : Button(lsp)
{
	x = SECOND_ROW, y = 36, width = 13, height = 1;
	text = "Login";
};

void LoginButton::pushFunction()
{
	LoginSlide* ls = static_cast<LoginSlide*>(parent);
	std::string pass = ls->boxes[1], name = ls->boxes[0];

	if (name.size() < 3) {
		ls->conOut(39, SECOND_ROW) << "Username must be bigger than 3 characters        ";
		return;
	}
	if (pass.size() < 3) {
		ls->conOut(39, SECOND_ROW) << "Password must be bigger than 3 characters         ";
		return;
	}

	for (int i=0; i < ls->users.size(); i++)
		if (ls->users[i]->name() == name) {
			if (ls->users[i]->check(pass)) {
				parent->next = new Arena::ArenaSlide(ls->users[i]);
				ls->userid = i;
			}
			else 
				ls->conOut(39, SECOND_ROW) << "Wrong password                             ";
			return;
		}
	ls->userid = -1;
	parent->next = new Arena::ArenaSlide(new User(name, pass, 1, 0));
}




LetterButton::LetterButton(Slide * lsp, char c, int index) : Button(lsp)
{
	text = "";
	text += c;
	width = 3, height = 1;
	y = 20 + (index/10) * (height+1);
	x = SECOND_ROW + (width+1) * (index % 10);
}

void LetterButton::pushFunction()
{
	LoginSlide* ls = static_cast<LoginSlide*>(parent);
	if (ls->boxes[ls->selected].length() > MAXNAME)
		return;
	if (text[0] == '<') {
		if (!ls->boxes[ls->selected].empty())
			ls->boxes[ls->selected].pop_back();
	}
	else if (text[0] == '>')
		ls->selected = ls->selected == 0 ? 1 : 0;
	else
		ls->boxes[ls->selected] += text;
}
