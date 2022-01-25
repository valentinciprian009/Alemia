#pragma once
#include "Slide.h"
#include "User.h"
#include "Button.h"

class StatusButton :
	public Button
{
private:
	int act;
	virtual void pushFunction() override;
public:
	StatusButton(Slide* prnt, int index, int action, std::string text);
};

class StatusSlide :
	public Slide
{
public:
	static const int GAME_OVER = 1<<0;
	static const int CLEARED = 1<<1;
	static const int PAUSED = 1<<2;

	static const int RESET = 1<<4;
	static const int MENU = 1<<5;
	static const int NOTHING = 1<<6;

	static const int SAVE = 1 << 7;
	static const int NEXTLVL = 1 << 8;

private:
	int status;
	int res;
	std::vector<StatusButton*> buttons;
public:
	StatusSlide(int st);

	void setResponse(int r);
	int response();

	// Inherited via Slide
	virtual void update() override;
	virtual void reinit() override;
};

