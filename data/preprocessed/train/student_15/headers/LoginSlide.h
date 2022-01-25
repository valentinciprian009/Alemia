#pragma once
#include "Slide.h"
#include "User.h"
#include "Button.h"

class LoginButton :
	public Button
{
public:
	LoginButton(Slide* lsp);
private:
	void pushFunction();
};

class LetterButton :
	public Button
{
public:
	LetterButton(Slide* lsp, char c, int index);
private:
	void pushFunction();
};

class LoginSlide :
	public Slide
{
private:
	std::vector<User*> users;
	std::vector<LetterButton*> keyboard;
	LoginButton* lb;
	std::string boxes[2];
	int userid = -2;
	int selected = 0;

public:
	LoginSlide();
	~LoginSlide();

	void update();

	friend class LetterButton;
	friend class LoginButton;

	// Inherited via Slide
	virtual void reinit() override;
};

