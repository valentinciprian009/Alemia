#define _CRT_SECURE_NO_WARNINGS

#include "ArenaSlide.h"
#include "LoginSlide.h"

int main(void)
{
	std::vector<Slide*> slides;
	slides.push_back(new LoginSlide());

	while (true) 
	{
		while (!slides.back()->active) 
		{
			slides.pop_back();
			slides.back()->reinit();
			delete slides.back()->next;
			slides.back()->next = nullptr;
			if (slides.size() == 0)
				break;
		} 
		if (slides.size() == 0)
			break;
		if (slides.back()->next != nullptr)
			slides.push_back(slides.back()->next);
		else
			slides.back()->update();
	}

	return 0;
}

